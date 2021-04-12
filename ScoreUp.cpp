#include "DXUT.h"
#include "ScoreUp.h"

ScoreUp::ScoreUp(Vec2 Pos, long long int score)
	:Pos(Pos),score(score)
{
}

void ScoreUp::Update()
{
}

void ScoreUp::Render()
{
	IMAGE->DarwText(to_string(score),Pos,Vec2(size,size),D3DCOLOR_ARGB(Alpha,255,255,255));
	if (Alpha > 5)
	{
		size += 0.1;
		Alpha -= 5;
	}
	else
		Live = true;

}

void ScoreUp::UIRender()
{

}

void ScoreUp::Coll(Object* obj)
{
}
