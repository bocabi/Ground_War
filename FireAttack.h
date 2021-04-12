#pragma once
#include "Object.h"
class FireAttack : public Object
{
public:
	Vec2 Pos;
	FireAttack(Vec2 Pos, float rot);
	~FireAttack();
	Vec2 Dir;
	Vec2 StartPos;


	// Object��(��) ���� ��ӵ�
	virtual void Update() override;

	virtual void Render() override;

	virtual void UIRender() override;


	// Object��(��) ���� ��ӵ�
	virtual void Coll(Object* obj) override;

};

