#pragma once
#include "cBoom.h"
class CBoom;
class BossTail
{
public:
	CDXUTTimer* timer;
	Texture* text;
	BossTail(int num);
	~BossTail(); float  Crot = 0;
	int count = 0;
public:
	Vec2 Dir;
	int num = 0;
	Vec2 Pos, NextPos;
	float Speed = 3;
	void Update();
	float rot = 0;
	void Render();
	void PosUpdate(Vec2 Pos, float Speed);
	void NewRender(Texture* text);
	void FireB();
	void Cir(Vec2 StartPos);
	void CBoom();
};

