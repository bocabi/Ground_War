#pragma once
#include "Scene.h"
class Intro  : public Scene
{
public:
	Texture* text;
	Texture* Fade;
	Vec2 Pos;
	Intro();
	Vec2 Every;
	~Intro();
	bool next = false;
public:
	int alhpa = 255;

	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;

	virtual void Update() override;

	virtual void Render() override;

	virtual void Release() override;

};

