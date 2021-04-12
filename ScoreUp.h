#pragma once
#include "Object.h"
class ScoreUp : public Object
{
public:
	Vec2 Pos;
	float size = 1;
	int Alpha = 255;
	long long int score;
	ScoreUp(Vec2 Pos,long long int score);
	~ScoreUp() {};
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Coll(Object* obj) override;
};

