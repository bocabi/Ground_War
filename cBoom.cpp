#include "DXUT.h"
#include "cBoom.h"

cBoom::cBoom(Vec2 Pos)
	:Pos(Pos)
{
	text = IMAGE->FindImages("F");
	timer = new CDXUTTimer;
	timer->Start();
	Dir = Pos - OBJ->player->Pos;
	D3DXVec2Normalize(&Dir, &Dir);
}

cBoom ::~cBoom()
{
}

void cBoom::Update()
{
	float c = sqrt((OBJ->player->Pos.x - Pos.x) * (OBJ->player->Pos.x - Pos.x) + (OBJ->player->Pos.y - Pos.y) * (OBJ->player->Pos.y - Pos.y));

	if (OBJ->player->LineT&&OBJ->player->inv == false && OBJ->player->NeverDie == false)
		if (c < text->v_text[0]->info.Width / 4)
		{
			OBJ->player->DelLine();
		}
	if (OBJ->boss1->CCC == false)
	{
		Pos -= Dir * 8;
	}
	if (Pos.x > WINX + 500 || Pos.x <0 - 500 || Pos.y > WINY + 500 || Pos.y < 0 - 500)
	{
		Live = true;
	}
}

void cBoom::Render()
{
	if (timer->GetTime() > 0.1)
	{
		Frame++;
		if (Frame > text->v_text.size() - 1)
		{
			Frame = 0;
		}
	}
	IMAGE->CenterRender(text->v_text[Frame], Pos, Vec2(0.5, 0.5), 0);

}

void cBoom::UIRender()
{
}

void cBoom::Coll(Object* obj)
{
}
