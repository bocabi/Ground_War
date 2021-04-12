#pragma once
#include "Object.h"
class OverrodEnemy : public Object
{
public:
	OverrodEnemy(Vec2 Pos = {0,0});
	float Speed = 3;
	Vec2 Dir = { -1,1 };
	~OverrodEnemy();
	Vec2 DIr;

	Vec2 Pos = {rand()%WINX,rand()%WINY};
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;

	virtual void Render() override;

	virtual void UIRender() override;


	// Object��(��) ���� ��ӵ�
	virtual void Coll(Object* obj) override;

};

