#include "DXUT.h"
#include "Title.h"
#include "Mouse.h"
Title::Title()
{
}

Title::~Title()
{
}

void Title::Init()
{
	DXUTSetCursorSettings(true, true);
	OBJ->AddObj(new Mouse(), 5);
	text = IMAGE->FindImage("Title");
	num = 0;
	text1 = IMAGE->FindImage("Help");
	action = false;
	text2 = IMAGE->FindImage("Credit");
	text3 = IMAGE->FindImage("game");
}

void Title::Update()
{
	IMAGE->Cam({ WINX / 2,WINY / 2 }, 1);
	if (action == false)
	{

		if (DXUTWasKeyPressed(VK_UP))
		{

			SOUND->Copy("x");
			if (num != 0)
				num--;
		}
		if (DXUTWasKeyPressed(VK_DOWN))
		{
			SOUND->Copy("x");
			if (num != 5)
				num++;
		}
	}
	if (DXUTWasKeyPressed(VK_SPACE))
	{
		switch (num)
		{
		case 0:
			SCENE->ChangeScene("Stage1");
			break;
		case 1:
			if (action == false)
				action = true;
			else
				action = false;
			break;
		case 2:
			SCENE->ChangeScene("Ranking");
			break;
		case 3:
			exit(0);
			break;
		case 4:
			if (action == false)
				action = true;
			else
				action = false;
			break;
		case 5:
			if (action == false)
				action = true;
			else
				action = false;
			break;

		}

	}
}

void Title::Render()
{
	IMAGE->Render(text, Vec2(0, 0), Vec2(1, 1), 0, D3DCOLOR_XRGB(255, 255, 255));
	if (num == 0)
		IMAGE->DarwText("GAME START", Vec2(WINX / 2 + 400, WINY / 2 - 200), Vec2(4, 5), D3DCOLOR_XRGB(255, 0, 0));
	else
		IMAGE->DarwText("GAME START", Vec2(WINX / 2 + 400, WINY / 2 - 200), Vec2(4, 5), D3DCOLOR_XRGB(255, 255, 255));

	if (num == 1)
		IMAGE->DarwText("HELP", Vec2(WINX / 2 + 400, WINY / 2 - 100), Vec2(4, 5), D3DCOLOR_XRGB(255, 0, 0));
	else
		IMAGE->DarwText("HELP", Vec2(WINX / 2 + 400, WINY / 2 - 100), Vec2(4, 5), D3DCOLOR_XRGB(255, 255, 255));

	if (num == 2)
		IMAGE->DarwText("RANKING", Vec2(WINX / 2 + 400, WINY / 2 + 0), Vec2(4, 5), D3DCOLOR_XRGB(255, 0, 0));
	else
		IMAGE->DarwText("RANKING", Vec2(WINX / 2 + 400, WINY / 2 + 0), Vec2(4, 5), D3DCOLOR_XRGB(255, 255, 255));

	if (num == 3)
		IMAGE->DarwText("EXIT", Vec2(WINX / 2 + 400, WINY / 2 + 100), Vec2(4, 5), D3DCOLOR_XRGB(255, 0, 0));
	else
		IMAGE->DarwText("EXIT", Vec2(WINX / 2 + 400, WINY / 2 + 100), Vec2(4, 5), D3DCOLOR_XRGB(255, 255, 255));
	if (num == 4)
		IMAGE->DarwText("Credit", Vec2(WINX / 2 + 400, WINY / 2 + 200), Vec2(4, 5), D3DCOLOR_XRGB(255, 0, 0));
	else
		IMAGE->DarwText("Credit", Vec2(WINX / 2 + 400, WINY / 2 + 200), Vec2(4, 5), D3DCOLOR_XRGB(255, 255, 255));
	if (num == 5)
		IMAGE->DarwText("게임설명", Vec2(WINX / 2 + 400, WINY / 2 + 300), Vec2(4, 5), D3DCOLOR_XRGB(255, 0, 0));
	else
		IMAGE->DarwText("게임설명", Vec2(WINX / 2 + 400, WINY / 2 + 300), Vec2(4, 5), D3DCOLOR_XRGB(255, 255, 255));
	if (action == true)
	{
		switch (num)
		{

		case 1:
			IMAGE->CenterRender(text1, Vec2(WINX / 2, WINY / 2), Vec2(1, 1), 0);
			break;
		case 4:
			IMAGE->CenterRender(text2, Vec2(WINX / 2, WINY / 2), Vec2(1, 1),0);
			break;
		case 5:
			IMAGE->CenterRender(text3,Vec2(WINX/2,WINY/2),Vec2(1,1),0);
			break;
		}
	}
}

void Title::Release()
{
	//SOUND->Stop("t");
	//SOUND->Reset("t");
}
