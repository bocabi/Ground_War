#include "DXUT.h"
#include "Boss2T.h"
#include "CirBullet.h"
Boss2T::Boss2T(int num)
	:num(num)
{
	text = IMAGE->FindImage("Boss2T");
}

Boss2T::~Boss2T()
{
}

void Boss2T::Update()
{
	if (OBJ->boss2->CIRT == true)
	{
		if (num == 1)
			OBJ->AddObj(new CirBullet(Pos, rot), 2);
		else
		{
			OBJ->AddObj(new CirBullet(Pos, rot + 3.14), 2);

		}
		rot += DXUTGetElapsedTime() * 30;
	}
	else
		rot += DXUTGetElapsedTime() * 4;
	if (num == 1)
		Pos = { OBJ->boss2->Pos.x + 100 * cosf(rot),OBJ->boss2->Pos.y + 100 * sinf(rot) };
	else
		Pos = { OBJ->boss2->Pos.x + 100 * cosf(rot + 3.14),OBJ->boss2->Pos.y + 100 * sinf(rot + 3.14) };

	float S = sqrt((OBJ->player->Pos.x - Pos.x) * (OBJ->player->Pos.x - Pos.x) + (OBJ->player->Pos.y - Pos.y) * (OBJ->player->Pos.y - Pos.y));
	if (OBJ->player->LineT == true && OBJ->player->NeverDie == false && OBJ->player->inv == false)
		if (S < 40)
		{
			OBJ->player->DelLine();
		}
	LastBossPos = OBJ->boss2->Pos;
	COOOOO = false;
}

void Boss2T::Render()
{
	float r = atan2(OBJ->boss2->Pos.y - Pos.y, OBJ->boss2->Pos.y - Pos.y);
	IMAGE->CenterRender(text, Pos, Vec2(0.5, 0.5), r);
}

void Boss2T::CIR()
{
}

void Boss2T::Bullet()
{
}

void Boss2T::TaewoongPunch()
{
	if (COOOOO == false)
	{
	if (Pos.x >= WINX || Pos.x <= 0 || Pos.y >= WINY || Pos.y < 0)
	{
		COOOOO = true;
	}
	else if(OBJ->player->Map[int(Pos.y)][int(Pos.x)]!=OBJ->player->Normal&&OBJ->player->Map[int(Pos.y)][int(Pos.x)] != OBJ->player->OVER)
	{
		COOOOO = true;
	}
	else if (x < 500)
	{
		x += 3;
	}
	}
	else
	{
		if (x >100)
		{
			x -= 1;
		}
	}
	if (num == 1)
		Pos = { LastBossPos.x + x * cosf(rot),LastBossPos.y + 100 * sinf(rot) };
	else
		Pos = { LastBossPos.x + x * cosf(rot + 3.14),LastBossPos.y + 100 * sinf(rot + 3.14) };
}
