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
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

