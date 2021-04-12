#pragma once
class Object abstract
{
public:
	string T = "";
	Vec2 CollPos;
	bool CollTrue = false;
	bool Live = false;
public:
	Object() {}
	~Object() {}
public:
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void UIRender() PURE;
	virtual void Coll(Object* obj) PURE;
};

