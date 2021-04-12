#pragma once
#include "Object.h"
class cBoom : public Object
{
public:
	MultiTexture* text;
	cBoom(Vec2 Pos);
	~cBoom();
	Vec2 Pos;
	Vec2 Dir;
	CDXUTTimer* timer;
	int Frame = 0;
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

