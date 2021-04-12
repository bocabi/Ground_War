#pragma once
#include "singleton.h"
class Texture
{
public:
	Texture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info) :
		texturePtr(texturePtr), info(info)
	{

	}
		~Texture() {};
	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;
};
class MultiTexture
{
public:
	MultiTexture() {}
	~MultiTexture() {}
	vector<Texture* >v_text;
};
class ImageManager :public singleton<ImageManager>
{
public:
	map<string, Texture* > m_text;
	map<string, MultiTexture* > m_MTtext;
	LPD3DXSPRITE sprite;
	LPD3DXFONT Font;
public:
	ImageManager();
	~ImageManager();
public:
	void AddImage(string key , const string path, int count = 0);
	Texture * FindImage(string key);
	MultiTexture* FindImages(string key);
	void Begin();
	void End();
	void ResetDevcie();
	void Lostdevice();
	void Render(Texture* text, Vec2 Pos, Vec2 Size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(Texture * text , Vec2 Pos , Vec2 Size ,float rot , D3DCOLOR color= D3DCOLOR_XRGB(255,255,255));
	void Cam(Vec2 Pos, float Size);
	void DarwText(string str, Vec2 Pos, Vec2 Size, D3DCOLOR color);
};

#define IMAGE ImageManager::GetInstance()