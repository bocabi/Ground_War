#pragma once
#include "Object.h"
class Player : public Object
{
public:
	Texture* text5;
	bool Die = false;;
	enum Tag
	{
		Normal,
		Field,
		Line,
		NowLine,
		None,
		OVER,
		OVERNONE
	};
	bool NeverDie = false;
	CDXUTTimer* Dietimer;
	Vec2 CamPos;
	vector<Vec2>v_CamPos;
	Texture* te;
	Vec2 StartLine;
	Vec2 Scroll = {0,0};
	int MoveEnerge = 80;
	int MaxEnerge = 100;
	float d = 0;
	int Life = 500;
	void DelLine();
	long long int Score = 0;
	  double MaxPer=0, NowPer=0;
	Texture* text;
	
	Texture* Back;
	Texture* MapBack;
	int Map[WINY + 1][WINX + 1] = {0};
	int OVERd = 0;
	Player(int Stage);
	~Player();
	int Boom2 = 0;
	float Speed = 5; 
	Vec2 Pos, Dir = Vec2(0,0);
public:
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	vector <Object* >da;
	bool LineT = false;
	void Move();
	CDXUTTimer* Skill2Timer;
	void AbleMove();
	CDXUTTimer* t;
	bool inv = false;
	void LineMove();
	void AbleLineMove();
	float rot = 0;
	void FloodFill(Vec2 Pos);
	void Change();
	void Paint();
	void DrawLine(Vec2 Pos);
	CDXUTTimer* SpeedTimer;
	CDXUTTimer* invTimer;
	bool SpeedT = false;
	void Boom();
	bool Start = false;
	int NextBoom =0 ;
	CDXUTTimer* Boomtimer;
	CDXUTTimer* SkillTimer;
	bool S1 = false, S2 = false, S3 = false, S4=false;
	// Object을(를) 통해 상속됨
	virtual void Coll(Object* obj) override;
};

