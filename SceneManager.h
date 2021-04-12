#pragma once
#include "singleton.h"
#include "Scene.h"
class SceneManager :public singleton<SceneManager>
{
public:
	Scene* NextScene = nullptr;
	map <string,Scene*> m_Scene;
	Scene* NowScene = nullptr;
public:
	SceneManager() {}
	~SceneManager() { Release(); }
	void AddScene(string key, Scene* newScene);
	void ChangeScene(string key);
	void Update();
	void Render();
	void Release();
};

#define SCENE SceneManager::GetInstance()