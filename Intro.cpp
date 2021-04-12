#include "DXUT.h"
#include "Intro.h"

Intro::Intro()
{
	text = IMAGE->FindImage("Intro");
	Fade = IMAGE->FindImage("FadeOut");
}

Intro::~Intro()
{
}

void Intro::Init()
{
	IMAGE->Cam({ WINX / 2,WINY / 2 }, 1);
	next = false;
}

void Intro::Update()
{
	if (next == false)
	{

		if (alhpa > 5)
		{
			alhpa--;
		}
		else next = true;
	}
	else if (next == true)
		if (alhpa < 255)
		{
			alhpa++;
		}
	else
	{
		SCENE->ChangeScene("Title");
	}
}

void Intro::Render()
{
	IMAGE->Render(text, Vec2(0, 0), Vec2(1, 1), 0);
	IMAGE->DarwText("바이러스 퇴치!!!!!", Vec2(WINX / 2 - 900, WINY / 2), Vec2(15, 10), D3DCOLOR_XRGB(rand() % 255, rand() % 255, rand() % 255));
	IMAGE->Render(Fade, Vec2(0, 0), Vec2(1, 1), 0, D3DCOLOR_ARGB(alhpa, 255, 255, 255));
}

void Intro::Release()
{
}
