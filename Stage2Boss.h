#pragma once
#include "Object.h"
#include "Boss2T.h"
class Stage2Boss : public Object
{
	public :
		Texture* text;
		Stage2Boss();
		~Stage2Boss();
public:
	vector<Boss2T* >v_tail;
	Vec2 Pos, Dir = {-1,1};
	float Speed = 4;
	// Object을(를) 통해 상속됨
	virtual void Update() override;

	CDXUTTimer* timer1;
	CDXUTTimer* timer2;
	CDXUTTimer* timer3;

	virtual void Render() override;

	virtual void UIRender() override;

	virtual void Coll(Object* obj) override;
	bool COOOOO = false;
	void CIR();
	void Ang();
	int num = 0;
	bool CIRT= false;
	CDXUTTimer* SKilltimer,*ActionTimer,*BulletTimer;
};

