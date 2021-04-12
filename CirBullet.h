#pragma once
#include "Object.h"
#include "Particle.h"
class CirBullet : public Object
{
public:
	CirBullet(Vec2 Pos,float rot);
	~CirBullet();
	Vec2 Pos, Dir;
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

