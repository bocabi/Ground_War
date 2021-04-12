#pragma once
#include "Scene.h"
class Title : public Scene
{
public:
	Texture* text;
public:
	int num = 0;
	Title();
	Texture* text1,*text2, *text3;
	~Title();
	virtual void Init() override;
	bool action = false;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

