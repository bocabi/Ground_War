#pragma once
#include "Object.h"
class FireE : public Object
{
public:
	FireE(Vec2 Pos);
	Vec2 Pos;
	~FireE();
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

