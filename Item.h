#pragma once
#include "Object.h"
class Item : public Object
{
public:
	Item(string key, int num, Vec2 Pos = {0,0});
	~Item();
	Vec2 Pos;
	int num = 0;
	CDXUTTimer* timer;
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	int onemore = 1;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
	void Speed();
	void Inv();
	void Life();
	Texture* text;
	void Shooting();
	void Shooting1();
	void Shooting2();
	void Shooting3();
	void Shooting4();
	bool i = false;
};

