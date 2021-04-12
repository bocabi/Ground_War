#include "DXUT.h"
#include "FlashEnemy.h"
#include "BB.h"
#include "Self.h"
FlashEnemy::FlashEnemy(Vec2 Pos)
	:Pos(Pos)
{
	T = "Enemy";
	text = IMAGE->FindImage("Flash");
	timer = new CDXUTTimer;
	timer->Start();
	OBJ->player->da.push_back(this);
}

FlashEnemy::~FlashEnemy()
{
}

void FlashEnemy::Update()
{
	CollPos = Pos;
	if (OBJ->player->Map[int(Pos.y)][int(Pos.x)] == OBJ->player->Field)
	{
		OBJ->AddObj(new BB(Pos),3);
		OBJ->player->da.pop_back();
		OBJ->player->Life += 50;
		OBJ->player->MaxEnerge += 30;
		Live = true; 
	}
	Pos += Dir;
	if (timer->GetTime() > time)
	{
		time -= 0.025;
		timer->Reset();
		if (f)
		{
			f = false;
		}
		else f = true;
	}
	if (time < 0.05)
	{
		for (int i = 0; i < 10; i++)
		{

			OBJ->AddObj(new Self(Pos, i, 0), 3);
			OBJ->AddObj(new Self(Pos, i, 0), 3);
		}
		Live = true;
	}
	Pos += Dir * Speed;
	Speed += 0.003;
	for (int i = 0; i < Speed + (40) / 2; i++)
	{
		if (OBJ->player->Map[int(Pos.y)][int(Pos.x + i * Dir.x)] == OBJ->player->NowLine)
		{
			OBJ->player->DelLine();
		}
		if (OBJ->player->Map[int(Pos.y + i * Dir.y)][int(Pos.x)] == OBJ->player->NowLine)
		{
			OBJ->player->DelLine();
		}
		if (OBJ->player->Map[int(Pos.y)][int(Pos.x + i * Dir.x)] != OBJ->player->Normal && OBJ->player->Map[int(Pos.y)][int(Pos.x + i * Dir.x)] != OBJ->player->OVER)
		{

			Dir.x *= -1;
		}
		if (OBJ->player->Map[int(Pos.y + i * Dir.y)][int(Pos.x)] != OBJ->player->Normal && OBJ->player->Map[int(Pos.y + i * Dir.y)][int(Pos.x)] != OBJ->player->OVER)
		{
			Dir.y *= -1;
		}
	}
}

void FlashEnemy::Render()
{
	if(!f)
	IMAGE->CenterRender(text,Pos,Vec2(0.2,0.2),0);
	else
		IMAGE->CenterRender(text, Pos, Vec2(0.2, 0.2), 0,D3DCOLOR_XRGB(50,50,50));

}

void FlashEnemy::UIRender()
{
}

void FlashEnemy::Coll(Object* obj)
{
}
