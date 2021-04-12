#pragma once
#include "Object.h"
class BigEnemy : public Object
{
public:
	Texture* text;
public:
	BigEnemy();
	~BigEnemy();
public:

	Vec2 Pos;
	float Speed = 0.5;
	Vec2 Dir = {-1,1};

	// Object을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;

	virtual void UIRender() override;

	virtual void Coll(Object* obj) override;

};

