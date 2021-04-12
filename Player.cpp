#include "DXUT.h"
#include "Player.h"
#include "Particle.h"
#include "Shooting3.h"
#include "SpeedEffect.h"
#include "FireE.h"
#include "BoomAttack.h"
#include "BB.h"
#include "shEffect.h"
#include "Self.h"
#include "Item.h"
#include "ScoreUp.h"
#include "FAS.h"

#include "Shooting.h"
void Player::DelLine()
{
	if (inv == false && NeverDie == false)
	{
		OBJ->AddObj(new BB(Pos), 2);
		Pos = StartLine;
		for (int i = 0; i < WINY; i++)
		{
			for (int ig = 0; ig < WINX; ig++)
			{
				if (Map[i][ig] == NowLine)
				{
					Map[i][ig] = Normal;
				}
			}
		}

		Paint();
		Life -= 30;

		LineT = false;
		Dietimer->Start();
		Dietimer->Reset();
	}
}
Player::Player(int Stage)
{
	float ro;
	da.clear();

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> X(0, 1);
	uniform_int_distribution<int> Y(0, 1);

	OBJ->AddObj(new Item("Speed", 0), 3);
	OBJ->AddObj(new Item("Speed", 1), 3);
	OBJ->AddObj(new Item("Speed", 2), 3);
	OBJ->AddObj(new Item("Speed", 3), 3);
	OBJ->AddObj(new Item("Speed", 4), 3); // 이거고치세ㅐㅁ
	OBJ->AddObj(new Item("Speed", 6), 3);

	Pos.x = X(rd) * WINX;
	Pos.y = Y(rd) * WINY;
	SpeedTimer = new CDXUTTimer;
	CamPos = Pos;
	Dietimer = TIME;
	Dietimer->Start();
	text5 = IMAGE->FindImage("BACK");
	t = TIME;
	te = IMAGE->FindImage("ASFD");
	t->Start();
	for (int i = 0; i < 50; i++)
	{
		Vec2 Lerp;
		D3DXVec2Lerp(&Lerp, &Pos, &Vec2(WINX / 2, WINY / 2), i * 0.02);
		v_CamPos.push_back(Lerp);
	}
	text = IMAGE->FindImage("Player");
	if (Stage == 1)
		MapBack = IMAGE->FindImage("Stage1");
	else
		MapBack = IMAGE->FindImage("Stage2image");
	Back = IMAGE->FindImage("124");
	OBJ->player = this;

	D3DLOCKED_RECT rt2;
	te->texturePtr->LockRect(0, &rt2, 0, 0);
	DWORD* cr = (DWORD*)rt2.pBits;
	for (int i = 0; i <= WINY; i++)
	{
		for (int j = 0; j <= WINX; j++)
		{
			int idx = i * WINX + j;
			D3DXCOLOR texturecolor = cr[idx];
			texturecolor.g = 0;
			cr[idx] = texturecolor;
		}
	}
	te->texturePtr->UnlockRect(0);


	D3DLOCKED_RECT rt;
	MapBack->texturePtr->LockRect(0, &rt, 0, 0);
	DWORD* c = (DWORD*)rt.pBits;
	for (int i = 0; i <= WINY; i++)
	{
		for (int j = 0; j <= WINX; j++)
		{
			if (i == WINY || i == 0 || j == WINX || j == 0)
			{
				int idx = i * WINX + j;
				D3DXCOLOR texturecolor = c[idx];
				texturecolor.a = 1;
				c[idx] = texturecolor;
				Map[i][j] = Line;
			}
			else
			{
				MaxPer++;
				int idx = i * WINX + j;
				D3DXCOLOR texturecolor = c[idx];
				texturecolor.a = 0;
				c[idx] = texturecolor;
			}


		}
	}
	SkillTimer = TIME;
	MapBack->texturePtr->UnlockRect(0);
	invTimer = TIME;
	invTimer->Start();
	Boomtimer = TIME;
	Boomtimer->Start();
	Skill2Timer = TIME;
	SkillTimer->Start();
	Skill2Timer->Start();
}

Player::~Player()
{
	OBJ->player = nullptr;

}

void Player::Update()
{

	if (Boom2 == 1)
	{
		Boom();
	}
	int a = 0;
	Vec2 EndPos;
	if (NeverDie == true)
	{
		MoveEnerge = 100;
	}
	if (S1)
	{
		if (DXUTWasKeyPressed(VK_SPACE))
		{
			SOUND->Copy("q", Pos.x - WINX / 2);

			OBJ->AddObj(new Shooting(Pos), 2);
		}
	}

	if (S2)
	{
		if (DXUTWasKeyPressed(VK_SPACE))
		{

		}
	}

	if (S3)
	{
		if (DXUTWasKeyPressed(VK_SPACE))
		{
			SOUND->Copy("q", Pos.x - WINX / 2);
			for (int i = 1; i < 1000; i++)
			{
				if (Pos.x + i * Dir.x > 0 && Pos.x + i * Dir.x < WINX && Pos.y + i * Dir.y> 0 && Pos.y + i * Dir.y < WINY)
				{

					if (Map[int(Pos.y + i * Dir.y)][int(Pos.x + i * Dir.x)] == Normal || Map[int(Pos.y + i * Dir.y)][int(Pos.x + i * Dir.x)] == OVER)
					{

						a++;
						EndPos = { Pos.x + i * Dir.x ,Pos.y + i * Dir.y };
						if (i % 10 == 1)
							OBJ->AddObj(new Shooting3(EndPos), 2);
					}
					else
					{
						break;
					}
				}
				else
					break;

			}
		}
	}
	if (S1)
	{
		if (SkillTimer->GetTime() > 5)
			S1 = false;

	}
	else if (!S1)
	{
		SkillTimer->Reset();
	}
	if (S3)
	{
		if (Skill2Timer->GetTime() > 5)
			S3 = false;

	}
	else if (!S3)
	{
		Skill2Timer->Reset();
	}

	for (float i = 0; i < a; i++)
	{
		Vec2 rwe;
		D3DXVec2Lerp(&rwe, &Pos, &EndPos, 1 / a * i);

	}
	if (inv == false)
	{
		invTimer->Reset();
	}
	else
	{
		OBJ->AddObj(new shEffect(Pos), 2);

		if (invTimer->GetTime() > 3)
		{
			inv = false;
		}
	}
	if (SpeedT == false)
	{
		Speed = 5;
		SpeedTimer->Reset();
	}
	else
	{
		Speed = 10;
		if (t->GetTime() > 0.05)
		{
			OBJ->AddObj(new SpeedEffect(Pos, rot, text), 2);
			t->Reset();
		}
		if (SpeedTimer->GetTime() > 5)
		{
			SpeedT = false;
		}
	}
	if (Dietimer->GetTime() > 2)
	{

		D3DXVec2Lerp(&CamPos, &Pos, &CamPos, 0.35);
		if (Life <= 0)
		{
			Die = true;
		}
		CollPos = Pos;
		if (!LineT)
			Move();
		else
			LineMove();
	}
}

void Player::Render()
{

	if (inv == true)
		MoveEnerge = MaxEnerge;
	string a = to_string(100 / MaxPer * NowPer);
	a.pop_back();
	a.pop_back();
	a.pop_back();
	a.pop_back();
	string gf = "오염도" + to_string(100 / MaxPer * OVERd);
	gf.pop_back();
	gf.pop_back();
	gf.pop_back();
	gf.pop_back();
	d += DXUTGetElapsedTime() * 0.1;
	IMAGE->CenterRender(Back, Scroll, Vec2(2, 2), d);
	IMAGE->CenterRender(text5, Vec2(WINX / 2, WINY / 2), Vec2(1, 1), 0);
	IMAGE->Render(te, Vec2(0, 0), Vec2(1, 1), 0);
	IMAGE->Render(MapBack, Vec2(0, 0), Vec2(1, 1), 0);
	if (Dietimer->GetTime() > 2)
		IMAGE->CenterRender(text, Pos, Vec2(0.2, 0.2), D3DXToRadian(rot));
	IMAGE->DarwText("Score : " + to_string(GAME->Score+Score), Vec2(Pos.x - 150, Pos.y - 200), Vec2(1, 1), D3DCOLOR_XRGB(255, 255, 255));
	IMAGE->DarwText(a + " % ", Vec2(Pos.x - 150, Pos.y - 150), Vec2(1, 1), D3DCOLOR_XRGB(255, 255, 255));
	IMAGE->DarwText(gf + "%", Vec2(Pos.x - 150, Pos.y - 100), Vec2(1, 1), D3DCOLOR_XRGB(255, 255, 255));
	IMAGE->DarwText("MoveE : " + to_string(MoveEnerge), Vec2(Pos.x, Pos.y + 200), Vec2(1, 1), D3DCOLOR_XRGB(255, 255, 255));
	IMAGE->DarwText("Life : " + to_string(Life), Vec2(Pos.x, Pos.y + 100), Vec2(1, 1), D3DCOLOR_XRGB(255, 255, 255));
	IMAGE->DarwText("Enemy" + to_string(da.size()),Vec2(Pos.x -400,Pos.y),Vec2(3,3),D3DCOLOR_XRGB(255,255,255));
}

void Player::UIRender()
{
}

void Player::Move()
{
	if (DXUTIsKeyDown(VK_LEFT))
	{
		SOUND->Play("r", false);
		Dir = { -1,0 };
		rot = -90;
		AbleMove();
	}
	else if (DXUTIsKeyDown(VK_DOWN))
	{
		SOUND->Play("r", false);
		Dir = { 0,1 };
		rot = 180;
		AbleMove();
	}
	else if (DXUTIsKeyDown(VK_UP))
	{
		SOUND->Play("r", false);
		Dir = { 0,-1 };
		AbleMove();
		rot = 0;
	}
	else if (DXUTIsKeyDown(VK_RIGHT))
	{
		SOUND->Play("r", false);
		Dir = { 1,0 };
		rot = 90;
		AbleMove();
	}
	else
	{
		SOUND->Reset("r");
		SOUND->Stop("r");
		if (MoveEnerge < MaxEnerge)
			MoveEnerge++;

	}
}

void Player::AbleMove()
{


	if (Dir.x != 0)
	{
		int c = 0;
		if (Dir.x > 0)
		{
			c = WINX;
		}
		else if (Dir.x < 0)
		{
			c = 0;
		}
		if (Pos.x + Dir.x * Speed < WINX && Pos.x + Dir.x * Speed > 0)
		{
			if (Map[int(Pos.y)][int(Pos.x + Dir.x)] != Normal && Map[int(Pos.y)][int(Pos.x + Dir.x)] != OVER)
			{
				int M = 0;
				for (int i = 1; i <= Speed; i++)
				{
					if (Map[int(Pos.y)][int(Pos.x + i * Dir.x)] != Normal && Map[int(Pos.y)][int(Pos.x + i * Dir.x)] != OVER)
					{
						M++;

					}
					else
					{

						break;
					}
				}
				Pos.x += M * Dir.x;
			}
			else
			{
				if (DXUTWasKeyPressed(VK_SPACE))
				{
					StartLine = Pos;
					LineT = true;
					Pos.x += Dir.x;
					Map[int(Pos.y)][int(Pos.x)] = NowLine;
				}
			}
		}
		else
		{
			Pos.x = c;
		}
	}
	else if (Dir.y != 0)
	{
		int c = 0;
		if (Dir.y > 0)
		{
			c = WINY;
		}
		else if (Dir.y < 0)
		{
			c = 0;
		}
		if (Pos.y + Dir.y * Speed < WINY && Pos.y + Dir.y * Speed > 0)
		{
			if (Map[int(Pos.y + Dir.y)][int(Pos.x)] != Normal && Map[int(Pos.y + Dir.y)][int(Pos.x)] != OVER)
			{
				int M = 0;
				for (int i = 1; i <= Speed; i++)
				{
					if (Map[int(Pos.y + i * Dir.y)][int(Pos.x)] != Normal && Map[int(Pos.y + i * Dir.y)][int(Pos.x)] != OVER)
					{
						M++;
					}
					else
					{

						break;
					}
				}
				Pos.y += M * Dir.y;
			}
			else
			{
				if (DXUTWasKeyPressed(VK_SPACE))
				{
					LineT = true;
					StartLine = Pos;
					Pos.y += Dir.y;
					Map[int(Pos.y)][int(Pos.x)] = NowLine;
				}
			}
		}
		else
		{
			Pos.y = c;
		}
	}
}

void Player::LineMove()
{
	if (MoveEnerge > 0)
	{
		if (DXUTIsKeyDown(VK_LEFT))
		{
			SOUND->Play("r", false);
			Dir = { -1,0 };
			MoveEnerge--;
			AbleLineMove();
			rot = -90;
		}
		else if (DXUTIsKeyDown(VK_DOWN))
		{
			SOUND->Play("r", false);
			Dir = { 0,1 };
			MoveEnerge--;
			AbleLineMove();
			rot = 180;
		}
		else if (DXUTIsKeyDown(VK_UP))
		{
			SOUND->Play("r", false);
			rot = 0;
			Dir = { 0,-1 };
			MoveEnerge--;
			AbleLineMove();
		}
		else if (DXUTIsKeyDown(VK_RIGHT))
		{
			SOUND->Play("r", false);
			Dir = { 1,0 };
			rot = 90;
			MoveEnerge--;
			AbleLineMove();
		}
	}
	else
	{
		OBJ->AddObj(new BB(Pos), 2);
		SOUND->Reset("r");
		SOUND->Stop("r");
		DelLine();
	}
}

void Player::AbleLineMove()
{
	if (Dir.x != 0)
	{


		int M = 0;
		for (int i = 0; i < Speed; i++)
		{
			if (Map[int(Pos.y)][int(Pos.x + i * Dir.x)] == Normal || Map[int(Pos.y)][int(Pos.x + i * Dir.x)] == OVER)
			{
				M++;
				Map[int(Pos.y)][int(Pos.x + i * Dir.x)] = NowLine;
				DrawLine({ Pos.x + i * Dir.x ,Pos.y });
			}
			else if (Map[int(Pos.y)][int(Pos.x + i * Dir.x)] == NowLine)
			{
			}
			else
			{
				LineT = false;
				if (OBJ->boss1 != nullptr)
					FloodFill(OBJ->boss1->Pos);
				else
					FloodFill(OBJ->boss2->Pos);

				Change();
				Paint();
				break;

			}
		}
		Pos.x += M * Dir.x;
	}
	else if (Dir.y != 0)
	{
		int M = 0;
		for (int i = 0; i < Speed; i++)
		{
			if (Map[int(Pos.y + i * Dir.y)][int(Pos.x)] == Normal || Map[int(Pos.y + i * Dir.y)][int(Pos.x)] == OVER)
			{
				M++;
				Map[int(Pos.y + i * Dir.y)][int(Pos.x)] = NowLine;
				DrawLine({ Pos.x ,Pos.y + i * Dir.y });
			}
			else if (Map[int(Pos.y + i * Dir.y)][int(Pos.x)] == NowLine)
			{
			}
			else
			{
				LineT = false;
				if (OBJ->boss1 != nullptr)
					FloodFill(OBJ->boss1->Pos);
				else
					FloodFill(OBJ->boss2->Pos);

				Change();
				Paint();
				break;
			}
		}
		Pos.y += M * Dir.y;



	}
}

void Player::FloodFill(Vec2 Pos)
{
	if (Map[int(Pos.y)][int(Pos.x)] == Normal)
	{
		Map[int(Pos.y)][int(Pos.x)] = None;
		FloodFill(Vec2(Pos.x, Pos.y - 1));
		FloodFill(Vec2(Pos.x, Pos.y + 1));
		FloodFill(Vec2(Pos.x - 1, Pos.y));
		FloodFill(Vec2(Pos.x + 1, Pos.y));
	}
	if (Map[int(Pos.y)][int(Pos.x)] == OVER)
	{
		Map[int(Pos.y)][int(Pos.x)] = OVERNONE;
		FloodFill(Vec2(Pos.x, Pos.y - 1));
		FloodFill(Vec2(Pos.x, Pos.y + 1));
		FloodFill(Vec2(Pos.x - 1, Pos.y));
		FloodFill(Vec2(Pos.x + 1, Pos.y));
	}
}

void Player::Change()
{
	long long int P = 0;
	SOUND->Copy("w", Pos.x - WINX / 2);
	for (int i = 0; i < WINY; i++)
	{
		for (int k = 0; k < WINX; k++)
		{
			if (Map[i][k] == NowLine)
			{
				Map[i][k] = Line;
				NowPer++;

			}
			if (Map[i][k] == Normal)
			{
				Map[i][k] = Field;
				NowPer++;
				P++;
			}
			else if (Map[i][k] == OVER)
			{
				Map[i][k] = Field;
				NowPer++;
				P++;
				OVERd--;

			}
			else if (Map[i][k] == None)
			{
				Map[i][k] = Normal;
			}
			else if (Map[i][k] == OVERNONE)
			{
				Map[i][k] = OVER;
			}
		}
	}
	Score += P * P;
	OBJ->AddObj(new ScoreUp(Pos, P * P), 3);
}

void Player::Paint()
{
	D3DLOCKED_RECT rt;
	MapBack->texturePtr->LockRect(0, &rt, 0, 0);
	DWORD* c = (DWORD*)rt.pBits;
	for (int i = 0; i < WINY; i++)
	{
		for (int k = 0; k < WINX; k++)
		{
			int idx = i * WINX + k;
			if (Map[i][k] == Line)
			{
				D3DXCOLOR x = c[idx];
				x.a = 1;
				c[idx] = x;
			}
			if (Map[i][k] == Field)
			{
				D3DXCOLOR x = c[idx];
				x.a = 1;
				c[idx] = x;
			}
			if (Map[i][k] == Normal)
			{
				D3DXCOLOR x = c[idx];
				x.a = 0;
				c[idx] = x;
			}
		}
	}

	MapBack->texturePtr->UnlockRect(0);
}

void Player::DrawLine(Vec2 Pos)
{
	D3DLOCKED_RECT rt;
	MapBack->texturePtr->LockRect(0, &rt, 0, 0);
	DWORD* c = (DWORD*)rt.pBits;
	int idx = Pos.y * WINX + Pos.x;
	D3DXCOLOR x = c[idx];
	x.a = 1;
	c[idx] = x;
	MapBack->texturePtr->UnlockRect(0);
}

void Player::Boom()
{
	float z = 0;
	int F = 0;
	if (NextBoom < 4)
		if (Boomtimer->GetTime() > 0.5)
		{
			switch (NextBoom)
			{
			case 0:
				F = 200;
				SOUND->Copy("F", Pos.x - WINX / 2);
				break;
			case 1:
				F = 150;
				SOUND->Copy("F", Pos.x - WINX / 2);

				break;
			case 2:
				F = 100;
				SOUND->Copy("F", Pos.x - WINX / 2);

				break;
			case 3:
				F = 50;
				Boom2 = 0;
				SOUND->Copy("F", Pos.x - WINX / 2);

				break;

			}
			NextBoom++;
			for (int i = 0; i < 10; i++, z += 2 * D3DX_PI / 10)
				OBJ->AddObj(new BoomAttack(Pos, z, F), 2);
			Boomtimer->Reset();
		}
	if (NextBoom == 4)
	{
		NextBoom = 0;
	}

	float a = 0;
}

void Player::Coll(Object* obj)
{
}
