#include "DXUT.h"
#include "EnemyBullet.h"
#include "Particle.h"
EnemyBullet::EnemyBullet(Vec2 Pos, float rot)
	:Pos(Pos), rot(rot)
{
	text = IMAGE->FindImage("BulletEnemy");
	Dir = { cosf(rot), sinf(rot) };
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Update()
{
	Pos += Dir * 10;
	OBJ->AddObj(new Particle(Pos, D3DCOLOR_XRGB(rand() % 150, 255, 255), 0, 1), 2);
	if (Pos.x >= WINX || Pos.x <= 0 || Pos.y >= WINY || Pos.y <= 0)
	{
		Live = true;
	}
	else if (OBJ->player->Map[int(Pos.y)][int(Pos.x)] != OBJ->player->Normal && OBJ->player->Map[int(Pos.y)][int(Pos.x)] != OBJ->player->OVER)
	{
		Live = true;
	}
	if (OBJ->player->inv == false && OBJ->player->LineT == true && OBJ->player->NeverDie== false)
	{
		float s = sqrt((OBJ->player->Pos.x - Pos.x) * (OBJ->player->Pos.x - Pos.x) + (OBJ->player->Pos.y - Pos.y) * (OBJ->player->Pos.y - Pos.y));
		if (s < 30)
		{
			OBJ->player->DelLine();
		}
	}
}

void EnemyBullet::Render()
{
	//IMAGE->CenterRender(text, Pos,Vec2(1,1),0);
}

void EnemyBullet::UIRender()
{
}

void EnemyBullet::Coll(Object* obj)
{
}
