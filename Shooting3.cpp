#include "DXUT.h"
#include "Shooting3.h"

Shooting3::Shooting3(Vec2 Pos)
	:Pos(Pos)
{
	T = "Bullet";
	text = IMAGE->FindImage("BulletEnemy");
}

Shooting3::~Shooting3()
{
}

void Shooting3::Update()
{
	
	
}

void Shooting3::Render()
{
	CollPos = Pos;
	IMAGE->CenterRender(text, Pos,Vec2(1,1),0);
	Live = true;
}

void Shooting3::UIRender()
{
}

void Shooting3::Coll(Object* obj)
{
	if (obj->T=="Enemy")
	{
		obj->Live = true;
		OBJ->player->da.pop_back();

	}
}
