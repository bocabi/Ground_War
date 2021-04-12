#pragma once
#include "Object.h"
class Self : public Object
{
public:
	Texture* text;
	Vec2 Pos, Dir,Startpos;
	Self(Vec2 Pos,float e,float rot);
	float e = 0;
	float ar;
	float a = 0; 
	float se = 0;
	float rot = 0;
	CDXUTTimer* t;

	~Self();
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

