#pragma once
#include "Object.h"
class BoomAttack : public Object
{
public:
	MultiTexture *text; CDXUTTimer* timer;
	int Frame = 0;
	BoomAttack(Vec2 Pos,float rot,int Fr);
	Vec2 Pos;
	~BoomAttack();
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

