#include "DXUT.h"
#include "BigEnemy.h"


BigEnemy::BigEnemy()
{
	text = IMAGE->FindImage("Big");
	random_device rd; 
	mt19937 mt(rd());
	uniform_int_distribution <int> X(0, WINX);
	uniform_int_distribution <int> Y(0, WINY);

	OBJ->player->da.push_back(this);
	Pos = {float(X(rd)),float(Y(rd))};
}

BigEnemy::~BigEnemy()
{
	 OBJ->player->da.pop_back();

}

void BigEnemy::Update()
{
	Dir = OBJ->player->Pos - Pos;
	D3DXVec2Normalize(&Dir,&Dir);
	Pos += Dir * Speed;
}

void BigEnemy::Render()
{
	float rot = atan2(OBJ->player->Pos.y - Pos.y, OBJ->player->Pos.x - Pos.x);
	IMAGE->CenterRender(text,Pos,Vec2(0.5,0.5),rot+1.6);
	float S = sqrt((OBJ->player->Pos.x-Pos.x)* (OBJ->player->Pos.x - Pos.x)+ (OBJ->player->Pos.y - Pos.y)* (OBJ->player->Pos.y - Pos.y));
	if(OBJ->player->LineT == true &&OBJ->player->NeverDie == false && OBJ->player->inv ==false)
	if (S < 70)
	{
		OBJ->player->DelLine();
	}
}

void BigEnemy::UIRender()
{
}

void BigEnemy::Coll(Object* obj)
{
}
