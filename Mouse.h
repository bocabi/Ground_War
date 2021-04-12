#pragma once
#include "Object.h"
class Mouse : public Object
{
public:
public:
	Vec2 Pos;
	Mouse();
	~Mouse();
	Texture* text;
	POINT pt;
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;

	virtual void Render() override;

	virtual void UIRender() override;

	virtual void Coll(Object* obj) override;

};

