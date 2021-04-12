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
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;

	// Object을(를) 통해 상속됨
	virtual void Coll(Object* obj) override;
};

