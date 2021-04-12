#pragma once
#include "Object.h"
class shEffect : public Object
{
public:
	shEffect(Vec2 Pos);
	~shEffect() {}
	Vec2 Pos;
	Vec2 Dir;
	Texture* text;
	CDXUTTimer* t;

	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

