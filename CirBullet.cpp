#include "DXUT.h"
#include "CirBullet.h"
CirBullet::CirBullet(Vec2 Pos, float rot)
{
	this->Pos = Pos;
	Dir = { cosf(rot), sinf(rot) };
}

CirBullet::~CirBullet()
{
}

void CirBullet::Update()
{
	OBJ->AddObj(new Particle(Pos,0,0,0),2);
	Pos += Dir * 5;
	if (Pos.x >= WINX || Pos.x <= 0 || Pos.y >= WINY || Pos.y <= 0)
	{
		Live = true;
	}
	else if (OBJ->player->Map[int(Pos.y)][int(Pos.x)] != OBJ->player->Normal && OBJ->player->Map[int(Pos.y)][int(Pos.x)] != OBJ->player->OVER)
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

void CirBullet::Render()
{
}

void CirBullet::UIRender()
{
}

void CirBullet::Coll(Object* obj)
{
}
