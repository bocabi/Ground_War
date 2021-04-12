#include "DXUT.h"
#include "Particle.h"

Particle::Particle(Vec2 Pos, D3DCOLOR color,float TimeSclae, float Speed)
	:Pos(Pos),color(color),TimeSclae(TimeSclae),Speed(Speed)
{
	text = IMAGE->FindImage("B");
	Dir = { sinf(rand() % 360-180),sinf(rand() % 360-180) };
	timer = TIME;
	timer->Start();
}

Particle::~Particle()
{
}

void Particle::Update()
{
	Size.x -= 0.02;
	Size.y -= 0.02;

	if (Size.x < 0)
	{
		Live = true;
	}
	Pos += Dir * Speed;
}

void Particle::Render()
{
	IMAGE->CenterRender(text , Pos ,Size,0,D3DCOLOR_XRGB(rand()%150,255,0));
}

void Particle::UIRender()
{
}

void Particle::Coll(Object* obj)
{
}
