#include "DXUT.h"
#include "BossTail.h"
#include "FireAttack.h"
BossTail::BossTail(int num):num(num)
{
	text = IMAGE->FindImage("BossTail");
	Dir = { 0,0 };
	Pos = { WINX / 2,WINY / 2 };
	NextPos = Pos;
	timer = new CDXUTTimer; 
	timer->Start();
}

BossTail::~BossTail()
{
}

void BossTail::Update()
{
	Dir = NextPos- Pos;
	D3DXVec2Normalize(&Dir, &Dir);
	Pos.x += Dir.x * Speed*1.4;
	count = 0;
	Pos.y += Dir.y * Speed*1.4;
	rot = atan2(Pos.y - OBJ->boss1->Pos.y , Pos.x - OBJ->boss1->Pos.x);
}

void BossTail::Render()
{
	IMAGE->CenterRender(text,Pos,Vec2(0.5,0.5), rot+1.6);
}

void BossTail::PosUpdate(Vec2 Pos ,float Speed)
{
	if (num < OBJ->boss1->v_tail.size() - 1)
	{
		OBJ->boss1->v_tail[num + 1]->PosUpdate(NextPos, Speed);
	}
	this->Speed = Speed;
	NextPos = Pos;
}

void BossTail::NewRender(Texture *text)
{
	IMAGE->CenterRender(text, Pos, Vec2(0.5, 0.5), rot+1.6);
}

void BossTail::FireB()
{
	OBJ->AddObj(new FireAttack(Pos,rot-3.14),1);
}

void BossTail::Cir(Vec2 StartPos)
{
	Crot+= DXUTGetElapsedTime()*5 ;
	Pos = {StartPos.x + 200 * sinf(num+ Crot),StartPos.y +200* cosf(num+ Crot) };
	if(timer->GetTime() > 0.1)
	if (this == OBJ->boss1->v_tail[0])
	{
		count++;
		timer->Reset();
		OBJ->AddObj(new cBoom(Pos),1);
	}
	if (count == 12)
	{
		OBJ->boss1->SkillTimer->Reset();
		OBJ->boss1->CCC = false;
	}
	float S = sqrt((OBJ->player->Pos.x - Pos.x) * (OBJ->player->Pos.x - Pos.x) + (OBJ->player->Pos.y - Pos.y) * (OBJ->player->Pos.y - Pos.y));
	if (OBJ->player->LineT == true && OBJ->player->NeverDie == false && OBJ->player->inv == false)
		if (S < 40)
		{
			OBJ->player->DelLine();
		}
}

void BossTail::CBoom()
{
}
