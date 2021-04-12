#pragma once
#include "Scene.h"
class EndScene : public Scene
{
public:
	EndScene();
	~EndScene();
	Texture* text;
	int num = 'A';
	string a ="";
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

