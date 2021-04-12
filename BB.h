#pragma once
#include "Object.h"
class BB : public Object
{
public:
	Vec2 Pos;
	int Frame =0 ;

	MultiTexture* text;
	BB(Vec2 Pos);
	~BB();
	CDXUTTimer* deltime;

	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

