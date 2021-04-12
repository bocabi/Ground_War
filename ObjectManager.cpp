#include "DXUT.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::AddObj(Object* obj, int Tag)
{
	l_Obj[Tag].push_back(obj);
}

void ObjectManager::Update()
{
	for (int i = 0; i < 10; i++)
	{

		for (auto iter = l_Obj[i].begin(); iter != l_Obj[i].end();)
		{
			if((*iter)->T != "")
				{
			for (int j = 0; j < 10; j++)
			{
					for (auto iter_ : l_Obj[j])
					{
						if ((*iter)->T != iter_->T)
						{

							if (Coll(*iter, iter_) == true)
							{
								(*iter)->Coll(iter_);
							}
						}
					}
			}
				}
			(*iter)->Update();
			if ((*iter)->Live)
			{
				SAFE_DELETE(*iter);
				iter = l_Obj[i].erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}
}

void ObjectManager::Render()
{
	for (int i = 0; i < 10; i++)
	{

		for (auto iter : l_Obj[i])
		{
			iter->Render();
		}
	}
}

void ObjectManager::UIRender()
{
	for (int i = 0; i < 10; i++)
	{

		for (auto iter : l_Obj[i])
		{
			iter->UIRender();
		}
	}
}

void ObjectManager::Release()
{
	boss1 = nullptr;
	boss2 = nullptr;
	player = nullptr;
	for (int i = 0; i < 10; i++)
	{

		for (auto iter : l_Obj[i])
		{
			SAFE_DELETE(iter);
		}
		l_Obj[i].clear();
	}
}

bool ObjectManager::Coll(Object* Obj1, Object* Obj2)
{
	float s = sqrt((Obj1->CollPos.x - Obj2->CollPos.x) * (Obj1->CollPos.x - Obj2->CollPos.x) + (Obj1->CollPos.y - Obj2->CollPos.y) * (Obj1->CollPos.y - Obj2->CollPos.y));
	if (s < 50/2)
	{
		return true;
	}
	return false;
}
