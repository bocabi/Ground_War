#pragma once
#include "Object.h"
class SpeedEffect  : public  Object
{
public:
	Texture* text;
	Vec2 Pos; float rot;
	int Alpha = 255;

	SpeedEffect(Vec2 Pos,float rot,Texture * text );
	~SpeedEffect();

	float size = 1;
	 
	// Object을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;

	virtual void UIRender() override;

	virtual void Coll(Object* obj) override;

};

