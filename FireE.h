#pragma once
#include "Object.h"
class FireE : public Object
{
public:
	FireE(Vec2 Pos);
	Vec2 Pos;
	~FireE();
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

