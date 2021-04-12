#pragma once
#include "Object.h"
class FireAttack : public Object
{
public:
	Vec2 Pos;
	FireAttack(Vec2 Pos, float rot);
	~FireAttack();
	Vec2 Dir;
	Vec2 StartPos;


	// Object을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;

	virtual void UIRender() override;


	// Object을(를) 통해 상속됨
	virtual void Coll(Object* obj) override;

};

