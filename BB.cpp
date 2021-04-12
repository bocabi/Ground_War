#include "DXUT.h"
#include "BB.h"

BB::BB(Vec2 Pos)
	:Pos(Pos)
{
	deltime = TIME;
	deltime->Start();
	text = IMAGE->FindImages("BB");
	SOUND->Copy(" ",Pos.x - WINX/2);
}

BB::~BB()
{
}

void BB::Update()
{
	
}

void BB::Render()
{
	if (deltime->GetTime() > 0.05)
	{
		Frame++;
		if (Frame > text->v_text.size() - 3)
		{
			Frame = 0;
			Live = true;
		}
		deltime->Reset();
	}
	
	IMAGE->CenterRender(text->v_text[Frame],Pos,Vec2(1,1),0);
}

void BB::UIRender()
{
}

void BB::Coll(Object* obj)
{
}
