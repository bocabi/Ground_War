#pragma once
#include "Object.h"
class Particle : public Object
{
public:
	Particle(Vec2 Pos, D3DCOLOR color,float TimeSclae,float Speed);
	~Particle();
public:
	Texture* text;
	float Speed = 0;
	Vec2 Size = {1.0,1};
	Vec2 Pos, Dir;
	D3DCOLOR color;
	float TimeSclae = 0;
	CDXUTTimer* timer;
		// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;

	// Object을(를) 통해 상속됨
	virtual void Coll(Object* obj) override;
};

