#pragma once
#include "Object.h"
class FAS : public Object
{
public:
	Vec2 Pos;
	Vec2 StartPos;
	Vec2 Dir;
	float rot;
	FAS(Vec2 Pos);
	~FAS();
	bool Start = false;

	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

