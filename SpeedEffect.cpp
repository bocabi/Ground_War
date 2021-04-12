#include "DXUT.h"
#include "SpeedEffect.h"


SpeedEffect::SpeedEffect(Vec2 Pos, float rot, Texture* text)
	:Pos(Pos), rot(rot),text(text)
{
}

SpeedEffect::~SpeedEffect()
{
}

void SpeedEffect::Update()
{
}

void SpeedEffect::Render()
{
	if (Alpha > 5)
	{
		Alpha -= 5;
		size -= 0.01;
	}
	else
	{
		Live = true;
	}
	IMAGE->CenterRender(text,Pos,Vec2(0.2*size,0.2*size),D3DXToRadian(rot +1.6) ,D3DCOLOR_ARGB(Alpha,255,255,255));
}

void SpeedEffect::UIRender()
{
}

void SpeedEffect::Coll(Object* obj)
{
}
