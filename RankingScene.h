#pragma once
#include "Scene.h"
class RankingScene : public Scene
{
public:
	Texture* text;
	RankingScene();
	~RankingScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

