#pragma once
#include <iostream>
#include <map>
#include <random>
#include <vector>
#include <list>
#include <algorithm>
#include <math.h>
#include <string>
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dsound.lib")

#pragma comment(lib,"dxerr.lib")
using namespace std;

#define Vec2 D3DXVECTOR2
#define Vec3 D3DXVECTOR3
#define TIME new CDXUTTimer
#define Device DXUTGetD3D9Device()

const int WINX = 1920;
const int WINY = 1080;

#include "SDKsound.h"
#include "ImageManager.h"
#include "SoundManager.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "GameManager.h"