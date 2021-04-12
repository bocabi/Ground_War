#include "DXUT.h"
#include "Main.h"
#include"Title.h"
#include "Stage1.h"
#include "RankingScene.h"
#include "Stage2.h"
#include "Intro.h"
#include "EndScene.h"

Main::Main()
{
}

Main::~Main()
{
}

void Main::Init()
{
	SOUND->AddSound("r",L"./sd/M.wav");
	SOUND->AddSound("x",L"./sd/x.wav");
	SOUND->AddSound(" ",L"./sd/.wav");
	SOUND->AddSound("q",L"./sd/q.wav");
	SOUND->AddSound("w",L"./sd/w.wav");
	SOUND->AddSound("F",L"./sd/F.wav");
	SOUND->AddSound("d", L"./sd/d.wav");
	SOUND->AddSound("t",L"./sd/t.wav");
	SOUND->AddSound("v",L"./sd/v.wav");
	IMAGE->AddImage("124","./image/124.png");
	SOUND->AddSound("SFXGameOver",L"./sd/SFXGameOver.wav");
	GAME->Score = 0;
	SCENE->AddScene("End",new EndScene);
	IMAGE->AddImage("Boss2","./image/11.png");
	IMAGE->AddImage("Boss2T", "./image/12.png");
	SCENE->AddScene("Ranking",new RankingScene);
	IMAGE->AddImage("Credit", "./image/Credit.png");
	IMAGE->AddImage("Big","./image/Big.png");
	IMAGE->AddImage("game","./image/game.png");
	IMAGE->AddImage("cur","./image/cur.png");
	IMAGE->AddImage("Life", "./image/Life.png");
	IMAGE->AddImage("Inv", "./image/Inv.png");

	IMAGE->AddImage("S1","./image/S1.png");
	IMAGE->AddImage("S3", "./image/S3.png");

	IMAGE->AddImage("S4", "./image/S4.png");
	IMAGE->AddImage("SCORE","./image/SCORE.png");
	IMAGE->AddImage("sd","./image/sh.png");
	IMAGE->AddImage("FF","./image/FF/",32);
	IMAGE->AddImage("Stage2image","./image/4532.png");
	SCENE->AddScene("Stage2",new Stage2);
	IMAGE->AddImage("BB", "./image/e/",24);
	IMAGE->AddImage("Speed","./image/Speed.png");
	IMAGE->AddImage("BACK","./image/BACK.png");
	IMAGE->AddImage("ASFD","./image/ASFD.png");
	IMAGE->AddImage("F","./image/F/",32);
	IMAGE->AddImage("Intro","./image/Intro.png");
	IMAGE->AddImage("PlayerCom","./image/PlayerCom.png");
	IMAGE->AddImage("BossTail","./image/BossTail.png");
	IMAGE->AddImage("P","./image/P.png");
	IMAGE->AddImage("B", "./image/B.png");
	IMAGE->AddImage("Flash","./image/Flash.png");
	IMAGE->AddImage("Stage1Boss","./image/Stage1Boss.png");
	IMAGE->AddImage("BulletEnemy","./image/BulletEnemy.png");
	IMAGE->AddImage("SpeedEnemy","./image/SpeedEnemy.png");
	IMAGE->AddImage("Particle", "./image/Particle.png");
	IMAGE->AddImage("Help","./image/Help.png");
	IMAGE->AddImage("Player","./image/Player.png");
	IMAGE->AddImage("Stage1","./image/Stage1/1.png");
	IMAGE->AddImage("Title","./image/Title/1.png");
	IMAGE->AddImage("FadeOut","./image/FadeOut.png");
	SCENE->AddScene("Title",new Title);
	SCENE->AddScene("Stage1", new Stage1);
	SCENE->AddScene("Intro",new Intro);
	SCENE->ChangeScene("Intro");
}

void Main::Update()
{
	if (DXUTWasKeyPressed(VK_F10))
	{
		SCENE->ChangeScene("Title");
	}
	SCENE->Update();
}

void Main::Render()
{
	IMAGE->Begin();
	OBJ->Render();
	SCENE->Render();
	OBJ->UIRender();
	IMAGE->End();
}

void Main::Release()
{
	ObjectManager::ReleaseInstance();
	ImageManager::ReleaseInstance();
	SceneManager::ReleaseInstance();
	SoundManager::ReleaseInstance();
	GameManager::ReleaseInstance();
}

void Main::ResetDevice()
{
	IMAGE->ResetDevcie();
}

void Main::LostDevcie()
{
	IMAGE->Lostdevice();
}
