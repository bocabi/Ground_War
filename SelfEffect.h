#pragma once
#include "Object.h"
class SelfEffect : public Object
{
public:
	SelfEffect(Vec2 Pos,Vec2 StartPos);
	Vec2 StartPos;
	Texture* text;
	Vec2 Pos;
	~SelfEffect() {}
	Vec2 Size = {2,2};
	Vec2 Dir;
	int Alpha = 255;
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

