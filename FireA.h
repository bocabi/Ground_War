#pragma once
#include "Object.h"
class FireA  : public Object
{
public:
	Texture* text;
	Vec2 Pos;
	Vec2 Dir;
	FireA(Vec2 Pos);
	~FireA();
	float Size = 0;
	float Graviti = 0;
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

