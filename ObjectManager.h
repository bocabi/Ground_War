#pragma once
#include "Object.h"
#include "singleton.h"
#include "Boss1.h"
#include "Stage2Boss.h"
#include "Player.h"
class ObjectManager : public singleton<ObjectManager>
{
public:
	list<Object*> l_Obj[10];
public:
	ObjectManager();
	~ObjectManager();
	void AddObj(Object* obj, int Tag);
	void Update();
	void Render();
	void UIRender();
	void Release();
	Stage2Boss* boss2 = nullptr;
	Player* player = nullptr;
	Boss1* boss1 = nullptr;
	bool Coll(Object* Obj1, Object* Obj2);
};

#define OBJ ObjectManager::GetInstance()