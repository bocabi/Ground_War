#include "DXUT.h"
#include "Mouse.h"

Mouse::Mouse()
{
	text = IMAGE->FindImage("cur");
}

Mouse::~Mouse()
{
}

void Mouse::Update()
{
	HCURSOR cor;
	SetCursor(cor);
	 GetCursorPos(&pt);
	 SetCursorPos(500,500);
	 Pos = { float(pt.x),float(pt.y )};
}

void Mouse::Render()
{
}

void Mouse::UIRender()
{
	IMAGE->CenterRender(text, Pos,Vec2(1,1),0);
}

void Mouse::Coll(Object* obj)
{
}
