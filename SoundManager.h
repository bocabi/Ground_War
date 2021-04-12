#pragma once
#include "singleton.h"
class CSoundManager;
class CSound;
class SoundManager : public singleton<SoundManager>
{
public:
	SoundManager();
	~SoundManager();
	CSoundManager* manager;
	map<string,CSound*>m_sound;

public:
	void AddSound(string key, wstring path);
	void Play(string key, bool loop);
	void Copy(string key, int SoundPos = 0);
	void Stop(string key);
	void Reset(string key);
};

#define SOUND SoundManager::GetInstance()