#pragma once
#include "Object.h"
class Shooting3 : public Object
{
public:
	Vec2 Pos;
	Vec2 Dir;
	int a = 0;
	Texture* text;
	Shooting3(Vec2 Pos);
	~Shooting3();

	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

