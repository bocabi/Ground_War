#include "DXUT.h"
#include "shEffect.h"

shEffect::shEffect(Vec2 Pos)
{
	text = IMAGE->FindImage("sd");
	Dir = { sinf(rand() % 360 - 180),sinf(rand() % 360 - 180) };
	t = new CDXUTTimer;
	t->Start();
	this->Pos = { 0,0 };
}

void shEffect::Update()
{
	Pos += Dir * 0.2;
}

void shEffect::Render()
{
	IMAGE->CenterRender(text,OBJ->player->Pos + Pos,Vec2(0.4,0.4),0,D3DCOLOR_ARGB(100,255,255,255));
	if (t->GetTime() > 2)
	{
		Live = true;
	}
}

void shEffect::UIRender()
{
}

void shEffect::Coll(Object* obj)
{
}
