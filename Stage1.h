#pragma once
#include "Scene.h"
class Stage1 : public Scene
{
public:
	Stage1();
	~Stage1();
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
	Vec2 FirstPos = {100,0};
	string a;
	int ALPHA = 255;
	Texture* te;
	int one = 1;
};

