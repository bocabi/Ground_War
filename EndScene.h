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
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

