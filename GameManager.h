#pragma once
#include "singleton.h"

class CScore
{
public:
	CScore(string name, long long int score)
		:name(name), score(score)
	{

	}
	~CScore();
	string name;
	long long int score;
};
class GameManager : public singleton<GameManager>
{
public:
	GameManager() {}
	~GameManager() {}
	long long int Score = 0;
	list<CScore*>l_Score;
};

#define GAME GameManager::GetInstance()