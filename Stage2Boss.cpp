#include "DXUT.h"
#include "Stage2Boss.h"
#include "Boss2T.h"

#include "FlashEnemy.h"
#include "SpeedEnemy.h"
#include "OverrodEnemy.h"
Stage2Boss::Stage2Boss()
{
	timer1=TIME;
	timer2=TIME;
	timer3=TIME;
	timer1	->Start();
	timer2	->Start();
	timer3	->Start();
	Pos = {WINX/2,WINY/2};
	OBJ->boss2 = this;
	text = IMAGE->FindImage("Boss2");
	v_tail.push_back(new Boss2T(0));
	v_tail.push_back(new Boss2T(1));
	SKilltimer = TIME; ActionTimer = TIME;  BulletTimer = TIME;
	SKilltimer->Start();
	ActionTimer->Start();
	BulletTimer->Start();
}

Stage2Boss::~Stage2Boss()
{
	OBJ->boss2 = nullptr;

}

void Stage2Boss::Update()
{
	if (timer1->GetTime() > 5)
	{
		OBJ->AddObj(new SpeedEnemy(Pos), 2);

		OBJ->AddObj(new SpeedEnemy(Pos),2);
		timer1->Reset();
	}
	if (timer2->GetTime() > 10)
	{
		OBJ->AddObj(new FlashEnemy(Pos), 2);

		OBJ->AddObj(new FlashEnemy(Pos), 2);
		timer2->Reset();
	}
	if (timer3->GetTime() > 15)
	{
		OBJ->AddObj(new OverrodEnemy(Pos), 2);
		timer3->Reset();
	}
	if (SKilltimer->GetTime() > 10)
	{
		switch (num)
		{
		case 0 :
		CIRT = true;
			break;
		case 1:
			Ang();
			break;
		case 2:
			Ang();

			break;
		}
	}
	else
	{
		CIRT = false;
		ActionTimer->Reset();
		num = rand() % 3;
		Speed = 4;

	for (auto iter : v_tail)
	{
		iter->Update();
	}
	}
Pos += Dir * Speed;
	for (int i = 0; i < Speed + (text->info.Width * 0.5) / 2; i++)
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
		if (OBJ->player->Map[int(Pos.y)][int(Pos.x + i * Dir.x)] != OBJ->player->Normal && OBJ->player->Map[int(Pos.y)][int(Pos.x + i * Dir.x)] != OBJ->player->OVER)
		{
			Dir.x *= -1;
			break;
		}
		if (OBJ->player->Map[int(Pos.y + i * Dir.y)][int(Pos.x)] != OBJ->player->Normal && OBJ->player->Map[int(Pos.y + i * Dir.y)][int(Pos.x)] != OBJ->player->OVER)
		{
			Dir.y *= -1;
			break;
		}
	}
}

void Stage2Boss::Render()
{
	for (auto iter : v_tail)
	{
		iter->Render();
	}
	float a = atan2(-Dir.y, -Dir.x);
	IMAGE->CenterRender(text,Pos,Vec2(0.5,0.5),a+1.6);
}

void Stage2Boss::UIRender()
{
}

void Stage2Boss::Coll(Object* obj)
{
}

void Stage2Boss::CIR()
{
	for (auto iter : v_tail)
	{
		iter->Update();
	}
	if (ActionTimer->GetTime() < 4)
	{
		CIRT = true;
		Speed = 0;
	}
	else
		SKilltimer->Reset();
}

void Stage2Boss::Ang()
{
	for (auto iter : v_tail)
	{
		iter->Update();
	}
	if (ActionTimer->GetTime() < 2)
	{
		Speed = 0;
	}
	else if (ActionTimer->GetTime() < 6)
	{
		Speed = 9;
		CIRT = true;
	}
	else
		SKilltimer->Reset();

}
