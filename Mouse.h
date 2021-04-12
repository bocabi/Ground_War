#pragma once
#include "Object.h"
class Mouse : public Object
{
public:
public:
	Vec2 Pos;
	Mouse();
	~Mouse();
	Texture* text;
	POINT pt;
	// Object을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;

	virtual void UIRender() override;

	virtual void Coll(Object* obj) override;

};

