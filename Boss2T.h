#pragma once
class Boss2T
{
public:
	Texture* text;
	Boss2T(int num);
	~Boss2T();
	Vec2 Pos;
	Vec2 Dir;
	float rot = 0;
	int num = 0;
public:
	void Update();
	void Render();
	bool COOOOO = false;
	void CIR();
	Vec2 LastBossPos;
	void Bullet();
	void TaewoongPunch();
	int x = 100;
};

