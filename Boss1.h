#pragma once
#include "BossTail.h"
#include "Object.h"
class Boss1 : public Object
{
public:
	bool dsfasdafsdaf = false;
	CDXUTTimer* SpawnTimer;
	CDXUTTimer* Flash;
	Texture* text;
	Vec2 Dir;
	CDXUTTimer* SkillTimer, * BulletTimer, * ActionTimer;
	CDXUTTimer* SoundTimer;
	float Speed = 4;
	Vec2 Where = { 1,1 };
	CDXUTTimer* updateTimer;
	int num = 0;
	float rot = 0;
	vector<BossTail*> v_tail;
	Vec2 StartPos;
public:
	Vec2 Pos = {WINX/2,WINY/2};
	Boss1();
	~Boss1();
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
	void Boost();
	void Bullet();
	void Fire();
	float Crot = 0;
	CDXUTTimer* CollTimer;
	void Cir(); bool CCC =false;
	// Object을(를) 통해 상속됨
};

