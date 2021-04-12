#pragma once
#include "Scene.h"
class Stage2 : public Scene
{
public:
	Stage2();
	~Stage2() {}
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	int ac = 50;
	bool GameClear = false;
	bool PlayerDie = false;
	Texture* text;
	bool GameEnd = false;
	int Alpha = 0;
	int s = 0;
	float Size = 1;
	bool GameOver = false;
	bool GameOff = true;
	CDXUTTimer* LerpSpeed;
	CDXUTTimer* Texttimer;
	Vec2 FirstPos = { 100,0 };
	string a;
	int one = 1;
	int ALPHA = 255;
	Texture* te;
};

