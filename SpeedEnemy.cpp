#include "DXUT.h"
#include "SpeedEnemy.h"
#include "EnemyBullet.h"
#include "BB.h"
SpeedEnemy::SpeedEnemy(Vec2 Pos)
	:Pos(Pos)
{
	T = "Enemy";
	text = IMAGE->FindImage("SpeedEnemy");
	if(Pos.x = 0)
	this->Pos = { float(rand() % (WINX/2 )+ WINX/4 ),float(rand() % (WINY / 2) +WINX / 4 )};
	Dir = { randX(rand()%3-1),randY(rand()%3-1)};
	timer = TIME;
	OBJ->player->da.push_back(this);
}

SpeedEnemy::~SpeedEnemy()
{

}

void SpeedEnemy::Update()
{
	CollPos = Pos;

	Pos += Dir * Speed;
	if (Pos.x <= 0 || Pos.x >= WINX)
	{
		Pos.x *= -1;
	}
	else if (Pos.y <= 0 || Pos.y >= WINY)
	{
		Pos.y *= -1;
	}
	else
	for (int i = 0; i < Speed + (text->info.Width*0.5) / 2; i++)
	{
		if (OBJ->player->Map[int(Pos.y)][int(Pos.x + i * Dir.x)] == OBJ->player->NowLine)
		{
			OBJ->player->DelLine();
			break;
		}
		if (OBJ->player->Map[int(Pos.y + i * Dir.y)][int(Pos.x)] == OBJ->player->NowLine)
		{
			OBJ->player->DelLine();
			break;
		}
		if (OBJ->player->Map[int(Pos.y)][int(Pos.x+i*Dir.x)]!=OBJ->player->Normal&& OBJ->player->Map[int(Pos.y)][int(Pos.x + i * Dir.x)] != OBJ->player->OVER)
		{
			booooo = true;
			timer->Reset();
			timer->Start();
			BulletBoom();
			Dir.x *= -1;
			break;
		}
		if (OBJ->player->Map[int(Pos.y + i * Dir.y)][int(Pos.x )] != OBJ->player->Normal&& OBJ->player->Map[int(Pos.y + i * Dir.y)][int(Pos.x)] != OBJ->player->OVER)
		{
			booooo = true;
			timer->Start();
			timer->Reset();
			BulletBoom();
			Dir.y *= -1;
			break;
		}
		
	}
	if (OBJ->player->Map[int(Pos.y)][int(Pos.x)] == OBJ->player->Field)
	{
		OBJ->player->Life += 50;
		OBJ->player->MaxEnerge += 30;
		OBJ->AddObj(new BB(Pos), 3);
		OBJ->player->da.pop_back();

		Live = true;
 }
	if (booooo)
	{
		Boost();
	}
	else
	{
		Speed = 4;
	}

}

void SpeedEnemy::Render()
{
	IMAGE->CenterRender(text, Pos, Vec2(0.3, 0.3), 0);
}

void SpeedEnemy::UIRender()
{
}

void SpeedEnemy::Boost()
{
	if (timer->GetTime() < 0.1)
	{
		Speed = 12;
	}
	else
	{
		timer->Stop();
		timer->Reset();
		booooo = false;
	}
}

float SpeedEnemy::randX(int x)
{
	if (x == 0)
	{
		return randX(rand() % 3-1);
	}
	else
	return x;
}

float SpeedEnemy::randY(int y)
{
	if (y== 0)
	{
		return randY(rand() % 3-1);
	}
	else
		return y;
}

void SpeedEnemy::BulletBoom()
{
	float rot = 0;
	for (int i = 0; i < 10; i++, rot += 2 * D3DX_PI / 10)
	{
	OBJ->AddObj(new EnemyBullet(Pos,rot),2);

	}
}

void SpeedEnemy::Coll(Object* obj)
{
}
