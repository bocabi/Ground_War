#include "DXUT.h"
#include "Shooting.h"

Shooting::Shooting(Vec2 Pos)
	:Pos(Pos)
{
	T = "Bullet";
	CollTrue = true;
	text = IMAGE->FindImage("BulletEnemy");
	Dir = OBJ->player->Dir;
}

Shooting::~Shooting()
{
}

void Shooting::Update()
{
	CollPos = Pos;
	if (Pos.x > WINX || Pos.x < 0 || Pos.y >WINY || Pos.y < 0)
	{
		Live = true;
	}
	Pos += Dir * 20;
}

void Shooting::Render()
{
	IMAGE->CenterRender(text,Pos,Vec2(1,1),0);
}

void Shooting::UIRender()
{
}

void Shooting::Coll(Object* obj)
{
	if (obj->T == "Enemy")
	{
		obj->Live = true;
		OBJ->player->da.pop_back();
		Live = true;
	}
}
