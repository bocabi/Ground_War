#include "DXUT.h"
#include "ImageManager.h"

ImageManager::ImageManager()
{
	D3DXCreateSprite(Device,&sprite);
	D3DXCreateFontA(Device, 0, 0, 100, 0, FALSE, HANGUL_CHARSET, 0, 0, 0, "±Ã¼­", &Font);
}

ImageManager::~ImageManager()
{
	SAFE_RELEASE(Font);
	sprite->Release();
	for (auto iter : m_MTtext)
	{
		for (auto iter_ : iter.second->v_text)
		{
			iter_->texturePtr->Release();
			SAFE_DELETE(iter_);
		}
		iter.second->v_text.clear();
		SAFE_DELETE(iter.second);
	}
	for (auto iter :m_text)
	{
		iter.second->texturePtr->Release();
		SAFE_DELETE(iter.second);
	}
	m_text.clear();
}

void ImageManager::AddImage(string key, const string path, int count)
{
	if (count == 0)
	{
		LPDIRECT3DTEXTURE9 texturePtr;
		D3DXIMAGE_INFO info;
		if (D3DXCreateTextureFromFileExA(Device, path.c_str(), -2, -2, 0, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, -1, -1, 0, &info, nullptr, &texturePtr) == S_OK)
		{
			Texture* text = new Texture(texturePtr, info);
			m_text[key] = text;
		}
		else
		{
			cout << "gd";
		}
	}
	else
	{
		MultiTexture* mt = new MultiTexture;
		for (int i = 0; i < count; i++)
		{
			LPDIRECT3DTEXTURE9 texturePtr;
			D3DXIMAGE_INFO info;
			string c = path + "(" + to_string(i) + ").png";
			if (D3DXCreateTextureFromFileExA(Device, c.c_str(), -2, -2, 0, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, -1, -1, 0, &info, nullptr, &texturePtr) == S_OK)
			{
				Texture* text = new Texture(texturePtr, info);
				mt->v_text.push_back( text);
				m_MTtext[key] = mt;
			}
			else
			{
				exit(0);
			}
		}
	}
}

Texture* ImageManager::FindImage(string key)
{
	return m_text[key];
}

MultiTexture * ImageManager::FindImages(string key)
{
	return m_MTtext[key];
}

void ImageManager::Begin()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND| D3DXSPRITE_OBJECTSPACE);
}

void ImageManager::End()
{
	sprite->End();
}

void ImageManager::ResetDevcie()
{
	sprite->OnResetDevice();
}

void ImageManager::Lostdevice()
{
	sprite->OnLostDevice();
}

void ImageManager::Render(Texture* text, Vec2 Pos, Vec2 Size, float rot, D3DCOLOR color)
{
	D3DXMATRIXA16 mat;
	D3DXMatrixTransformation2D(&mat,nullptr,0,&Size,0,rot,&Pos);
	sprite->SetTransform(&mat);
	sprite->Draw(text->texturePtr,nullptr, nullptr, nullptr,color);
}

void ImageManager::CenterRender(Texture* text, Vec2 Pos, Vec2 Size, float rot, D3DCOLOR color)
{
	D3DXMATRIXA16 mat;
	D3DXMatrixTransformation2D(&mat, nullptr, 0, &Size, 0, rot, &Pos);
	sprite->SetTransform(&mat);
	sprite->Draw(text->texturePtr, nullptr, &Vec3(text->info.Width/2,text->info.Height/2,0), nullptr, color);
}

void ImageManager::Cam(Vec2 Pos, float Size)
{
	D3DXMATRIXA16 matV, matP;
	D3DXMatrixOrthoLH(&matP,WINX*Size,-WINY*Size,0,200);
	D3DXMatrixLookAtLH(&matV, &Vec3(Pos.x, Pos.y, 0), &Vec3(Pos.x, Pos.y, 10), &Vec3(0, 1, 0));
	Device->SetTransform(D3DTS_PROJECTION, &matP);

	Device->SetTransform(D3DTS_VIEW,&matV);
}

void ImageManager::DarwText(string str, Vec2 Pos, Vec2 Size, D3DCOLOR color)
{

	D3DXMATRIXA16 mat;
	D3DXMatrixTransformation2D(&mat, nullptr, 0, &Size, 0, 0, &Vec2(Pos.x-Size.x/2,Pos.y));
	sprite->SetTransform(&mat);
	Font->DrawTextA(sprite,str.c_str(),str.size(),0,0,color);
}
