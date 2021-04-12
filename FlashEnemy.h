#pragma once
#include "Object.h"
class FlashEnemy : public Object
{
public :
	CDXUTTimer* timer;
	Texture* text;
	Vec2 Dir = {1,1};
	float time = 1;
	FlashEnemy(Vec2 Pos);
	float Speed = 1;
	~FlashEnemy();
	Vec2 Pos;
	bool f = false;
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	// Object��(��) ���� ��ӵ�
	virtual void Coll(Object* obj) override;
};

