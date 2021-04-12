#include "DXUT.h"
#include "RankingScene.h"

RankingScene::RankingScene()
{
}

RankingScene::~RankingScene()
{
}

void RankingScene::Init()
{
	text = IMAGE->FindImage("SCORE");
	for(int i = 0 ; i < 5; i++)
	if (GAME->l_Score.size() < 5)
	{
		GAME->l_Score.push_back(new CScore("None",0));
	}
		GAME->l_Score.sort([](CScore* s1, CScore* s2) {return s1->score > s2->score; });
	if (GAME->l_Score.size() > 5)
	{
		GAME->l_Score.pop_back();
	}
}

void RankingScene::Update()
{
	if (DXUTWasKeyPressed(VK_SPACE))
	{
		SCENE->ChangeScene("Title");
	}
}

void RankingScene::Render()
{
	IMAGE->Render(text,Vec2(0,0),Vec2(1,1),0);
	int a = 0;
	for (auto iter : GAME->l_Score)
	{
		a ++;
		IMAGE->DarwText(iter->name + " : " + to_string(iter->score), Vec2(WINX / 2 - 300, a * 100),Vec2(4,4),D3DCOLOR_XRGB(255,255,255));
	}

}

void RankingScene::Release()
{
}
