#pragma once
#include "Object.h"
class Shooting : public Object
{
public:
	Shooting(Vec2 Pos);
	~Shooting();
	Texture* text;
	Vec2 Pos, Dir;
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

