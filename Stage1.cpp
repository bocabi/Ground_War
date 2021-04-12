#include "DXUT.h"
#include "Stage1.h"
#include "Player.h"
#include "Boss1.h"
#include "OverrodEnemy.h"
#include "SpeedEnemy.h"
#include "Item.h"
#include "FireE.h"
#include "BigEnemy.h"
Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}

void Stage1::Init()
{
	OBJ->AddObj(new Player(1), 1);
	DXUTSetCursorSettings(false, false);
	OBJ->AddObj(new BigEnemy(),2);
	a.clear();
	s = 0;
	SOUND->Play("d",true);
	text = IMAGE->FindImage("FadeOut");
	te = IMAGE->FindImage("FadeOut");
	GameEnd = true;
	one = 1;
	OBJ->AddObj(new Boss1(), 2);
	FirstPos = { 100,0 };
	OBJ->AddObj(new SpeedEnemy({ WINX / 2,WINY / 2 }), 2);
	OBJ->AddObj(new OverrodEnemy, 2);
	ac = 49;
	LerpSpeed = TIME;
	LerpSpeed->Start();
	Alpha = 0;
	GameClear = false;
	GameEnd = false;
	Texttimer = TIME;
	Texttimer->Start();
	GameOff = true;
	Size = 1;
	GameOver = false;
}

void Stage1::Update()
{
	if (100 / OBJ->player->MaxPer * OBJ->player->OVERd > 60)
	{
		GameOver = true;
	}
	if (DXUTWasKeyPressed(VK_F1))
	{
		if(OBJ->player->NeverDie == false)
		OBJ->player->NeverDie = true;
		else
			OBJ->player->NeverDie = false;
	}
	if (DXUTWasKeyPressed(VK_F2))
	{
		OBJ->AddObj(new Item("", rand() % 7, OBJ->player->Pos), 3);
	}
	if (DXUTWasKeyPressed(VK_F8))
	{
		OBJ->player->OVERd -= 100000;

	}
	if (DXUTWasKeyPressed(VK_F7))
	{
		OBJ->player->OVERd += 100000;

	}
	if (DXUTWasKeyPressed(VK_F5))
	{
		OBJ->player->MoveEnerge+=30;
	}
	if (DXUTWasKeyPressed(VK_F6))
	{
		OBJ->player->MoveEnerge -= 30;

	}
	if (DXUTWasKeyPressed(VK_F4))
	{
		OBJ->player->Life -= 50;
	}
	if (DXUTWasKeyPressed(VK_F3))
	{
		OBJ->player->Life += 50;

	}
	if (DXUTWasKeyPressed(VK_F9))
	{
		GameClear = true;
	}
	if (100 / OBJ->player->MaxPer * OBJ->player->NowPer > 80)
	{
		GameClear = true;
		GameEnd = true;
	}
	if (OBJ->player->Die == true)
	{
		GameEnd = true;
		GameOver = true;
	}
	if (GameOff)
	{
		if (ac > 1)
		{
			if (LerpSpeed->GetTime() > 0.01)
			{
				IMAGE->Cam(OBJ->player->v_CamPos[ac], Size);
				Size -= 0.01;
				ac--;
				LerpSpeed->Reset();
			}
		}
		else
		{
			GameOff = false;
		}
	}
	else
	{
		IMAGE->Cam(OBJ->player->CamPos, 0.5);
	}
	if(!GameClear)
		if (!GameEnd)
		{

			OBJ->Update();
		}
}

void Stage1::Render()
{
	

	IMAGE->CenterRender(text, Vec2(OBJ->player->Pos.x, OBJ->player->Pos.y), Vec2(2, 2), 0, D3DCOLOR_ARGB(Alpha, 255, 255, 255));
	if (GameClear == true)
	{
		if (one == 1)
		{
			SOUND->Copy("v");
			one--;
		SOUND->Stop("d");
		}

		if (Alpha < 200)
			Alpha += 3;
		else
		{
			if (Texttimer->GetTime() > 0.5)
			{
				switch (s)
				{
				case 0:
					a.push_back('G');
					break;
				case 1:
					a.push_back('A');
					break;
				case 2:
					a.push_back('M');
					break;
				case 3:
					a.push_back('E');
					break;
				case 4:
					a.push_back(' ');
					break;
				case 5:
					a.push_back('C');
					break;
				case 6:
					a.push_back('L');
					break;
				case 7:
					a.push_back('A');
					break;
				case 8:
					a.push_back('E');
					break;
				case 9:
					a.push_back('R');
					break;
				case 10:
					OBJ->AddObj(new FireE(Vec2(OBJ->player->Pos.x - 200, OBJ->player->Pos.y + 200)), 2);
					OBJ->AddObj(new FireE(Vec2(OBJ->player->Pos.x + 200, OBJ->player->Pos.y + 200)), 2);
					break;
				}
				Texttimer->Reset();
				s++;
			}
			if (FirstPos.y > -200)
			{
				if (s > 9)
				{
					FirstPos.y -= 3;
				}
			}
			else
			{
			IMAGE->DarwText(to_string(OBJ->player->Score),Vec2(OBJ->player->Pos.x -200, OBJ->player->Pos.y),Vec2(2,2),D3DCOLOR_XRGB(255,255,255));
			if (DXUTWasKeyPressed(VK_SPACE))
			{
				GAME->Score += OBJ->player->Score;
				SCENE->ChangeScene("Stage2");
			}
			}
			IMAGE->DarwText(a, Vec2(OBJ->player->Pos.x - FirstPos.x, OBJ->player->Pos.y + FirstPos.y), Vec2(2, 2), D3DCOLOR_XRGB(255, 255, 255));
		}
	}
	if (GameOver)
	{
		if (one == 1)
		{
			SOUND->Copy("SFXGameOver");
			one--;
		SOUND->Stop("d");
		}

		if (Alpha < 200)
			Alpha += 3;
		else
		{
			if (Texttimer->GetTime() > 0.5)
			{
				switch (s)
				{
				case 0:
					a.push_back('G');
					break;
				case 1:
					a.push_back('A');
					break;
				case 2:
					a.push_back('M');
					break;
				case 3:
					a.push_back('E');
					break;
				case 4:
					a.push_back(' ');
					break;
				case 5:
					a.push_back('O');
					break;
				case 6:
					a.push_back('V');
					break;
				case 7:
					a.push_back('E');
					break;
				case 8:
					a.push_back('R');
					break;
				
			
				}
				Texttimer->Reset();
				s++;
			}
			if (FirstPos.y > -200)
			{
				if (s > 8)
				{
					FirstPos.y -= 3;
				}
			}
			else
			{
				IMAGE->DarwText(to_string(OBJ->player->Score), Vec2(OBJ->player->Pos.x - 200, OBJ->player->Pos.y), Vec2(2, 2), D3DCOLOR_XRGB(255, 0, 0));
				if (DXUTWasKeyPressed(VK_SPACE))
				{
					SCENE->ChangeScene("Title");
				}
			}
			IMAGE->DarwText(a, Vec2(OBJ->player->Pos.x - FirstPos.x, OBJ->player->Pos.y + FirstPos.y), Vec2(2, 2), D3DCOLOR_XRGB(255, 0, 0));
		}
	}
	IMAGE->CenterRender(te,OBJ->player->Pos,Vec2(3,3),0,D3DCOLOR_ARGB(ALPHA,255,255,255));
	if (ALPHA > 5)
	{
		ALPHA -= 2;
		IMAGE->DarwText("Stage1", Vec2(OBJ->player->Pos.x - FirstPos.x, OBJ->player->Pos.y + FirstPos.y), Vec2(4, 4), D3DCOLOR_XRGB(255, 0, 0));
	}
}

void Stage1::Release()
{
	SOUND->Stop("d");
	SOUND->Reset("d");
}
