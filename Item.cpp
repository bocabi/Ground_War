#include "DXUT.h"
#include "Item.h"
#include "FAS.h"

Item::Item(string key, int num, Vec2 Pos)
	:num(num)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution <int> d(1,1900);
	uniform_int_distribution <int> dx(1, 1000);
	timer = TIME;
	switch (num)
	{
	case 0:
		text = IMAGE->FindImage("Speed");
		break;
	case 1:
		text = IMAGE->FindImage("Inv");
		break;
	case 2:
		text = IMAGE->FindImage("Life");
		break;
	case 3:
		text = IMAGE->FindImage("S1");
		break;
	case 4:

		text = IMAGE->FindImage("S3");
		break;
	case 5:
		text = IMAGE->FindImage("S3");
		break;
	case 6:
		text = IMAGE->FindImage("S4");
		break;

	}
	timer->Start();
	if (Pos.x == 0 && Pos.y == 0)
		this->Pos = { float(d(rd)),float(dx(rd)) };
	else
		this->Pos = Pos;
}

Item::~Item()
{
}

void Item::Update()
{
	if (OBJ->player->Map[int(Pos.y)][int(Pos.x)] == OBJ->player->Field)
	{
		i = true;
		switch (num)
		{
		case 0:
			Speed();
			break;
		case 1:
			Inv();
			break;
		case 2:
			Life();
			break;
		case 3:
			Shooting();
			break;
		case 4:
			Shooting2();
			break;
		case 5:
			Shooting2();
			break;
		case 6:
			Shooting4();
			break;
		}
	}
	else
		timer->Reset();
}

void Item::Render()
{
	if (i == true&& num != 4)
	{
		IMAGE->CenterRender(text,Pos,Vec2(1,1),0);
	}
}

void Item::UIRender()
{
}

void Item::Coll(Object* obj)
{
}

void Item::Speed()
{
	if (timer->GetTime() > 5)

	{
		Live = true;
	}
	OBJ->player->SpeedT = true;
	OBJ->player->SpeedTimer->Reset();
	
}

void Item::Inv()
{
	if (timer->GetTime() > 5)
	{
		Live = true;
	}
		OBJ->player->inv = true;
	OBJ->player->invTimer->Reset();
}

void Item::Life()
{
	if (onemore == 1)
	{
		onemore--;
		OBJ->player->Life += 50;
	}
	if (timer->GetTime() > 5)
	{
		Live = true;
	}
}

void Item::Shooting()
{
	if (timer->GetTime() > 5)

	{
		Live = true;
	}
	OBJ->player->S1 = true;
}

void Item::Shooting1()
{
	if (timer->GetTime() > 5)
	{
		Live = true;
	}
	OBJ->player->S1 = true;
}

void Item::Shooting2()
{
	if (timer->GetTime() > 5)
	{
		Live = true;
	}
	OBJ->player->S3 = true;

}

void Item::Shooting3()
{
	if (timer->GetTime() > 5)
	{
		Live = true;
	}
	OBJ->player->S3 = true;

}

void Item::Shooting4()
{
	if (onemore == 1)
	{
		onemore--;
		OBJ->AddObj(new FAS(Pos),3);
	}

	if (timer->GetTime() > 5)
	{
		Live = true;
	}
}
