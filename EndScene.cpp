#include "DXUT.h"
#include "EndScene.h"
EndScene::EndScene()
{
}

EndScene::~EndScene()
{
}

void EndScene::Init()
{
	text = IMAGE->FindImage("SCORE");
	
	num = 'A';
	a = "";
}

void EndScene::Update()
{
	IMAGE->Cam({ WINX / 2, WINY / 2 }, 1);
}

void EndScene::Render()
{

	if (DXUTWasKeyPressed(VK_DOWN))
	{
		SOUND->Copy("x");
		if(num != 'Z')
		num++;
	}
	if (DXUTWasKeyPressed(VK_UP))
	{
		SOUND->Copy("x");
		if(num != 'A')
		num--;

	}
		IMAGE->Render(text, { 0,0 }, Vec2(1, 1), 0);
	for (char i = 'A'; i < 'Z'; i++)
	{
		if (num == i)
		{
			if (DXUTWasKeyPressed(VK_SPACE))
			{
				a += i;
				num = 'A';
			}
	IMAGE->DarwText(a+i, Vec2(WINX / 2, WINY / 2), Vec2(5, 5), D3DCOLOR_XRGB(255, 255, 255));
		}
	}
	if (a.size() == 3)
	{
		SCENE->ChangeScene("Ranking");
		GAME->l_Score.push_front(new CScore(a,GAME->Score));
	}
	IMAGE->DarwText("SCORE : " + to_string(GAME->Score), Vec2(WINX / 2-300, WINY / 2 - 300), Vec2(7, 7), D3DCOLOR_XRGB(255, 255, 255));

}

void EndScene::Release()
{
}
