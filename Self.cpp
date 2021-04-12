#include "DXUT.h"
#include "Self.h"
#include "SelfEffect.h"
#include "Particle.h"
Self::Self(Vec2 Pos,float e,float rot )
	:Startpos(Pos),e(e)
{
	t = TIME;
	t->Start();
}

Self::~Self()
{
}

void Self::Update()
{
	if (t->GetTime() > 3)
	{
		Live = true;
	}
	if(se <= 200)
	se+=3;
	a += DXUTGetElapsedTime()*12;
	rot = sinf(0.5* e +a*1.33);
	Dir = {Startpos.x + se*sinf(a)* rot,Startpos.y+ se *cosf(a)*rot};
	Pos = Dir;
	OBJ->AddObj(new SelfEffect(Pos,Startpos),3);
}

void Self::Render()
{
}

void Self::UIRender()
{
}

void Self::Coll(Object* obj)
{
}
