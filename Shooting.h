#pragma once
#include "Object.h"
class Shooting : public Object
{
public:
	Shooting(Vec2 Pos);
	~Shooting();
	Texture* text;
	Vec2 Pos, Dir;
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

