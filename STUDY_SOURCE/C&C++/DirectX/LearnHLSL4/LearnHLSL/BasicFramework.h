#pragma once

// https://kblog.popekim.com/2011/12/01-part-2.html

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")


// 선언
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// 함수 프로토 타입

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void ProcessInput(HWND hWnd, WPARAM wParam);

// 초기화 관련

bool InitEverything(HWND hWnd);
bool InitD3D(HWND hWnd);
bool LoadAssets();
LPD3DXEFFECT LoadShader(const char* filename);
LPDIRECT3DTEXTURE9 LoadTexture(const char* filename);
LPD3DXMESH LoadModel(const char* filename);

// 게임 루프 관련
void PlayDemo();
void Update();

// 렌더링 관련
void RenderFrame();
void RenderScene();
void RenderInfo();

// 뒷정리 관련
void Cleanup();


