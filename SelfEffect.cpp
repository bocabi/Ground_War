#include "DXUT.h"
#include "SelfEffect.h"

SelfEffect::SelfEffect(Vec2 Pos, Vec2 StartPos)
	:Pos(Pos),StartPos(StartPos)
{
	text = IMAGE->FindImage("B");
	Size = { 1.5,1.5 };
}

void SelfEffect::Update()
{
	float a = sqrt((Pos.x-StartPos.x)*(Pos.x - StartPos.x)+(Pos.y - StartPos.y)*(Pos.y - StartPos.y));
	if (a > 150)
	{
		Live = true;
	}

	Size.x -= 0.01;
	Size.y -= 0.01;

	if (Size.x < 0)
	{
		Live = true;
	}
}

void SelfEffect::Render()
{
IMAGE->CenterRender(text, Pos, Size, 0, D3DCOLOR_XRGB(0, 255, 0));
}

void SelfEffect::UIRender()
{
}

void SelfEffect::Coll(Object* obj)
{
}
