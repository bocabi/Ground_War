#include "DXUT.h"
#include "Boss1.h"
#include "EnemyBullet.h"
#include "OverrodEnemy.h"
#include "FlashEnemy.h"
#include "SpeedEnemy.h"
Boss1::Boss1()
{
	//T = "Enemy";
	Flash = new CDXUTTimer;
	Flash->Start();
	SpawnTimer = TIME;
	SpawnTimer->Start();
	updateTimer = new CDXUTTimer;
	updateTimer->Start();
	text = IMAGE->FindImage("Stage1Boss");
	OBJ->boss1 = this;
	Dir = { 1,1 };
	SoundTimer = TIME;
	SoundTimer->Start();
	for (int i = 0; i < 15; i++)
	{
		v_tail.push_back(new BossTail(i));
	}
	SkillTimer = TIME;
	BulletTimer = TIME;
	ActionTimer = TIME;
	SkillTimer->Start();
	BulletTimer->Start();
	ActionTimer->Start();
	CollTimer = TIME;
	CollTimer->Start();
	Flash->Start();
}

Boss1::~Boss1()
{
	OBJ->boss1 = nullptr;

}

void Boss1::Update()
{
	CollPos = Pos;
	if (Flash->GetTime() > 10)
	{
		OBJ->AddObj(new FlashEnemy(Pos),2);
		OBJ->AddObj(new FlashEnemy(Pos), 2);

		Flash->Reset();
		OBJ->AddObj(new SpeedEnemy(Pos),2);
		OBJ->AddObj(new SpeedEnemy(Pos), 2);

	}
	if (dsfasdafsdaf == true)
	{
		if (SpawnTimer->GetTime() > 5)
		{
			OBJ->AddObj(new OverrodEnemy(Pos), 1);
			dsfasdafsdaf = false;
		}
	}
	else
	{

		SpawnTimer->Reset();
		dsfasdafsdaf = false;
	}
	if (Pos.x < WINX || Pos.x > 0)
	{
		Dir.x *= -1;
	}
	if (SkillTimer->GetTime() > 5)
	{
		switch (num)
		{
		case 0:

			Cir();
			break;
		case 1:
			Boost();
			break;
		case 2:
			Fire();
			break;
		}
	}
	else
	{
		num = rand() % 3;
		StartPos = Pos;
		rot -= 0.1;
		Dir.x = 1 + sinf(rot);
		Pos.y += Dir.y * Speed;
		Pos.x += Dir.x * Where.x * Speed;
		Speed = 2;
		CCC = false;
		ActionTimer->Reset();
		BulletTimer->Reset();
	}

	if (updateTimer->GetTime() > 0.1 / Speed)
	{
		v_tail[0]->PosUpdate(Pos, Speed);
		updateTimer->Reset();
	}
	if (CCC == false)
		for (auto iter : v_tail)
		{
			iter->Update();
		}
	else
	{
		for (auto iter : v_tail)
		{
			iter->Cir(StartPos);
		}
	}

	if (CollTimer->GetTime() > 0.1)
		for (int i = 0; i < Speed + (text->info.Width * 0.5) / 2; i++)
		{
			if (OBJ->player->Map[int(Pos.y)][int(Pos.x + i *Where.x)] == OBJ->player->NowLine)
			{
				OBJ->player->DelLine();
			}
			else if (OBJ->player->Map[int(Pos.y)][int(Pos.x + i *Where.x)] != OBJ->player->Normal && OBJ->player->Map[int(Pos.y)][int(Pos.x + i * Where.x)] != OBJ->player->OVER)
			{
				Dir.x *= -1;
				Where.x *= -1;
				CollTimer->Reset();
			}
			if (OBJ->player->Map[int(Pos.y + i * Dir.y)][int(Pos.x)] == OBJ->player->NowLine)
			{
				OBJ->player->DelLine();

			}
			else if (OBJ->player->Map[int(Pos.y + i * Dir.y)][int(Pos.x)] != OBJ->player->Normal && OBJ->player->Map[int(Pos.y + i * Dir.y)][int(Pos.x)] != OBJ->player->OVER)
			{
				Dir.y *= -1;
				CollTimer->Reset();
			}
		}
}

void Boss1::Render()
{
	for (auto iter : v_tail)
	{
		if (iter != v_tail[0])
			iter->Render();
		else
		{
			iter->NewRender(text);
		}
	}
	float r = atan2((Pos.y + Dir.y) - Pos.y, (Pos.x + Dir.x) - Pos.x);
	//IMAGE->CenterRender(text, Pos,Vec2(0.5,0.5), r-1.6);

}

void Boss1::UIRender()
{
}

void Boss1::Coll(Object* obj)
{
}

void Boss1::Boost()
{
	Pos += Dir * Speed;
	Dir.x *= Where.x;
	if (ActionTimer->GetTime() < 3)
	{
		Speed = 0;
	}
	else if (ActionTimer->GetTime() < 6)
	{
		if (SoundTimer->GetTime() > 0.1)
		{
			SOUND->Copy("F",Pos.x - WINX/2);
			SoundTimer->Reset();
		}
		if (BulletTimer->GetTime() > 0.7)
		{
			Bullet();
			BulletTimer->Reset();
		}
		Speed = 10;
	}
	else
	{
		SkillTimer->Reset();
	}
}

void Boss1::Bullet()
{
	float a = 0;
	for (int i = 0; i < 12; i++, a += 2 * D3DX_PI / 12)
	{
		OBJ->AddObj(new EnemyBullet(Pos, a), 2);
	}
}

void Boss1::Fire()
{
	//SOUND->Copy("F",1000);
	if (ActionTimer->GetTime() < 1)
	{
		Speed = 0;
	}
	else if (ActionTimer->GetTime() < 5)
	{
		if (SoundTimer->GetTime() > 0.2)
		{
			SOUND->Copy("F", Pos.x - WINX / 2);
			SoundTimer->Reset();
		}
		Speed = 2;
		v_tail[0]->FireB();
	}
	else
	{
		SkillTimer->Reset();
	}
}

void Boss1::Cir()
{
	if (ActionTimer->GetTime() > 5)
	{
		CCC = false;
		SkillTimer->Reset();
	}
	else
	{
		if (SoundTimer->GetTime() > 0.1)
		{
			SOUND->Copy("F", Pos.x - WINX / 2);
			SoundTimer->Reset();
		}
		CCC = true;
	}
}
