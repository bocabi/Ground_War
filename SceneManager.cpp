#include "DXUT.h"
#include "SceneManager.h"

void SceneManager::AddScene(string key, Scene* newScene)
{
	m_Scene[key] = newScene;
}

void SceneManager::ChangeScene(string key)
{
	NextScene = m_Scene[key];
}

void SceneManager::Update()
{
	if (NextScene)
	{
		if (NowScene)
		{
			NowScene->Release();
			OBJ->Release();
		}
		NowScene = NextScene;
		NowScene->Init();
		NextScene = nullptr;
	}
	if (NowScene)
	{
		NowScene->Update();
	}
}

void SceneManager::Render()
{
	if (NowScene)
	{
		NowScene->Render();
	}
}

void SceneManager::Release()
{
	if (NowScene)
	{
		OBJ->Release();

		NowScene->Release();
	}
	for (auto iter : m_Scene)
	{
		SAFE_DELETE(iter.second);
	}
	m_Scene.clear();
}
