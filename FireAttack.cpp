#include "DXUT.h"
#include "FireAttack.h"
#include "Particle.h"
FireAttack::FireAttack(Vec2 Pos,float rot)
	:Pos(Pos)
{
	Dir = { cosf(rot),sinf(rot) };
	StartPos = Pos;

}

FireAttack::~FireAttack()
{
}

void FireAttack::Update()
{
	random_device  rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> X(-10, 10);

	float  a = sqrt((StartPos.x - Pos.x)*(StartPos.x-Pos.x)+ (StartPos.y - Pos.y) * (StartPos.y - Pos.y));
	if (a > 500)
	{
		Live = true;
	}
	Pos += Dir * 25;
	OBJ->AddObj(new Particle({ Pos.x + X(rd),Pos.y + X(rd) }, D3DCOLOR_XRGB(255, 0, 0), 0, 0), 1);

	OBJ->AddObj(new Particle({Pos.x +X(rd),Pos.y+ X(rd)}, D3DCOLOR_XRGB(255, 0, 0), 0, 0), 1);
	if (Pos.x >= WINX || Pos.x <= 0 || Pos.y >= WINY || Pos.y <= 0)
	{
		Live = true;
	}
	else if(OBJ->player->Map[int(Pos.y)][int(Pos.x)] != OBJ->player->Normal&&OBJ->player->Map[int(Pos.y)][int(Pos.x)] != OBJ->player->OVER)
	{
		Live = true;
	}
	if (OBJ->player->inv == false && OBJ->player->LineT == true && OBJ->player->NeverDie == false)
	{
		float s = sqrt((OBJ->player->Pos.x - Pos.x) * (OBJ->player->Pos.x - Pos.x) + (OBJ->player->Pos.y - Pos.y) * (OBJ->player->Pos.y - Pos.y));
		if (s < 30)
		{
			OBJ->player->DelLine();
		}
	}
}

void FireAttack::Render()
{
}

void FireAttack::UIRender()
{
}

void FireAttack::Coll(Object* obj)
{
}
