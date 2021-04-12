#pragma once
#include "Object.h"
class EnemyBullet : public Object
{
public:
	Texture* text;
	Vec2 Pos;
	float rot; 
	Vec2 Dir;
	EnemyBullet(Vec2 Pos,float rot);
	~EnemyBullet();
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;

	// Object��(��) ���� ��ӵ�
	virtual void Coll(Object* obj) override;
};

