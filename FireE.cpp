#include "DXUT.h"
#include "FireE.h"
#include "FireA.h"
#include "Particle.h"
FireE::FireE(Vec2 Pos)
	:Pos(Pos)
{
}

void FireE::Update()
{
	Pos.y-=2;
	if (abs(OBJ->player->Pos.y - Pos.y )> 200)
	{
		for (int i = 0; i < 100; i++)
		{
		OBJ->AddObj(new FireA(Pos),2);
		OBJ->AddObj(new FireA(Pos), 2);
		OBJ->AddObj(new FireA(Pos), 2);
		OBJ->AddObj(new FireA(Pos), 2);

		}
		Live = true;
	}
}

void FireE::Render()
{
}

void FireE::UIRender()
{
	OBJ->AddObj(new Particle(Pos,0,0,1),2);
}

void FireE::Coll(Object* obj)
{
}
