#include "DXUT.h"
#include "SoundManager.h"

SoundManager::SoundManager()
{
	manager = new CSoundManager;
	manager->Initialize(DXUTGetHWND(),2);
}

SoundManager::~SoundManager()
{
	
}

void SoundManager::AddSound(string key, wstring path)
{
	
	CSound* sound;
	manager->Create(&sound,(LPWSTR)path.c_str(),DSBCAPS_CTRLPAN);
	m_sound[key] = sound;
}

void SoundManager::Play(string key, bool loop)
{
	m_sound[key]->Play(0,loop);
}

void SoundManager::Copy(string key,int SoundPos)
{
	LPDIRECTSOUNDBUFFER b;
	manager->GetDirectSound()->DuplicateSoundBuffer(m_sound[key]->GetBuffer(0) ,&b);
	b->SetCurrentPosition(0);
	b->SetPan(SoundPos);
	b->Play(0,0,0);
}

void SoundManager::Stop(string key)
{
	m_sound[key]->Stop();
}

void SoundManager::Reset(string key)
{
	m_sound[key]->Reset();
}
