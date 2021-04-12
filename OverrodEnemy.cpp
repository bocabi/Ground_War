#include "DXUT.h"
#include "OverrodEnemy.h"
#include "Particle.h"
OverrodEnemy::OverrodEnemy(Vec2 Pos)
{
	if (Pos.x != 0)
	{
		this->Pos = Pos;
	}
	OBJ->player->da.push_back(this);
}

OverrodEnemy::~OverrodEnemy()
{
}

void OverrodEnemy::Update()
{
	Pos += Dir * Speed;
	if (OBJ->player->Map[int(Pos.y)][int(Pos.x)] == OBJ->player->Field)
	{
		OBJ->player->Life += 50;
		OBJ->player->da.pop_back();
		OBJ->player->MaxEnerge += 30;
		Live = true;
	}
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

	random_device rd;
	mt19937 mt(rd());
	RECT rt = { Pos.x - 30,Pos.y - 30,Pos.x + 30,Pos.y + 30 };
	uniform_int_distribution<int> X(rt.left, rt.right);
	uniform_int_distribution<int> Y(rt.top, rt.bottom);

	OBJ->AddObj(new Particle({ float(X(rd)),float(Y(rd)) }, D3DCOLOR_XRGB(rand() % 150, 255, 0), 0, 1), 2);
	OBJ->AddObj(new Particle({ float(X(rd)),float(Y(rd)) }, D3DCOLOR_XRGB(rand() % 150, 255, 0), 0, 1), 2);
	OBJ->AddObj(new Particle({ float(X(rd)),float(Y(rd)) }, D3DCOLOR_XRGB(rand() % 150, 255, 0), 0, 1), 2);
	OBJ->AddObj(new Particle({ float(X(rd)),float(Y(rd)) }, D3DCOLOR_XRGB(rand() % 150, 255, 0), 0, 1), 2);
	OBJ->AddObj(new Particle({ float(X(rd)),float(Y(rd)) }, D3DCOLOR_XRGB(rand() % 150, 255, 0), 0, 1), 2);
	D3DLOCKED_RECT rgd;
	OBJ->player->te->texturePtr->LockRect(0, &rgd,0,0);
	DWORD* d = (DWORD*)rgd.pBits;

	for (int i = rt.left; i < rt.right; i++)
	{
		for (int j = rt.top; j < rt.bottom; j++)
		{
			if (i < WINX && i > 0 && j < WINY && j > 0)
			{
				int idx = j * WINX + i;
				if (OBJ->player->Map[j][i] == OBJ->player->Normal)
				{
					D3DXCOLOR color = d[idx];
					color.g = 0.5;
					d[idx] = color;
					OBJ->player->OVERd++;
					OBJ->player->Map[j][i] = OBJ->player->OVER;
				}
			}
		}
	}
	OBJ->player->te->texturePtr->UnlockRect(0);
}

void OverrodEnemy::Render()
{
}

void OverrodEnemy::UIRender()
{
}

void OverrodEnemy::Coll(Object* obj)
{
}
