#include "DXUT.h"
#include "FireA.h"

FireA::FireA(Vec2 Pos)
:Pos(Pos)
{
	text = IMAGE->FindImage("Particle");
	Size = rand() % 2 ;
	Dir = { sinf(rand() % 180),cosf(rand() & 180) };
}

FireA::~FireA()
{
}

void FireA::Update()
{
	Graviti += 0.005;
	Pos += Dir * 0.5;
	Pos.y += Graviti;
	Size -= 0.005;
	if (Size <= 0)
	{
		Live = true;
	}
}

void FireA::Render()
{
}

void FireA::UIRender()
{
	IMAGE->CenterRender(text,Pos,Vec2(Size, Size),0,D3DCOLOR_XRGB(255,0,0));
}

void FireA::Coll(Object* obj)
{
}
