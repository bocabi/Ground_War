#include "DXUT.h"
#include "BoomAttack.h"

BoomAttack::BoomAttack(Vec2 Pos, float rot,int Fr)
{
	text = IMAGE->FindImages("FF");
	this->Pos = Vec2(Pos.x + Fr * sinf(rot), Pos.y + Fr * cosf(rot));
	timer = new CDXUTTimer;
	timer->Start();
	T = "Bullet";
}

BoomAttack::~BoomAttack()
{
}



void BoomAttack::Update()
{
}

void BoomAttack::Render()
{
	
	CollPos = Pos;
	if (timer->GetTime() > 0.1)
	{
		Frame++;
		if (Frame > text->v_text.size() - 3)
		{
			Live = true;
		}
	}
	if (Frame < text->v_text.size() - 2)
	{
	IMAGE->CenterRender(text->v_text[Frame], Pos, Vec2(3, 3), 0);
	}
}

void BoomAttack::UIRender()
{
}

void BoomAttack::Coll(Object* obj)
{
	if (obj->T == "Enemy")
	{
		obj->Live = true;
	}
}
