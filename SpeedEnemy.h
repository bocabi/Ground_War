#pragma once
#include "Object.h"
class SpeedEnemy : public Object
{
public:
	Texture* text;
	float Speed = 4;
	CDXUTTimer* timer;
	Vec2 Dir = {1,1};
	
	Vec2 Pos;
	bool booooo = false;
	SpeedEnemy(Vec2 Pos = {0,0});
	~SpeedEnemy();
public:
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	void Boost();
	float randX(int x);
	float randY(int y);
	void BulletBoom();

	// Object을(를) 통해 상속됨
	virtual void Coll(Object* obj) override;
};

