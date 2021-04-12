#include "DXUT.h"
#include "FAS.h"
#include "Particle.h"
FAS::FAS(Vec2 Pos)
{
	StartPos = Pos;
	this->Pos = Pos;
}

FAS::~FAS()
{
}

void FAS::Update()
{
	rot += DXUTGetElapsedTime();
	Dir = { float(sin(rot)),float(cos(rot*1.44) )};
	Pos = { OBJ->player->Pos.x + 50 * Dir.x + sin(rot),OBJ->player->Pos.y + 50 * Dir.y + cos(rot) };
	OBJ->AddObj(new Particle(Pos,D3DCOLOR_XRGB(255,255,255),0,0),2);
	if (DXUTWasKeyPressed(VK_SPACE))
	{
		Start = true;
		Live = true;
	}
	if (Start == true)
		OBJ->player->Boom2=1;
}

void FAS::Render()
{
}

void FAS::UIRender()
{
}

void FAS::Coll(Object* obj)
{
}
