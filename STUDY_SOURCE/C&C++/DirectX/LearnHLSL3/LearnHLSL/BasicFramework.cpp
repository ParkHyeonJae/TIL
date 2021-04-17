#include "BasicFramework.h"

// https://kblog.popekim.com/2011/12/01-part-2.html

// ----------------------------------------------------------------------------------
// ���� ����
// ----------------------------------------------------------------------------------


// D3D ����
LPDIRECT3D9			gpD3D					= NULL;		// D3D
LPDIRECT3DDEVICE9	gpD3DDevice				= NULL;			// D3D ��ġ


// ��Ʈ
ID3DXFont*			gpFont					= NULL;

// ��
LPD3DXMESH gpSphere = NULL;
// ���̴�
LPD3DXEFFECT gpTextureMappingShader = NULL;

//�ؽ���
LPDIRECT3DTEXTURE9 gpEarthDM = NULL;

// ���α׷� �̸�
const char* gAppName = "�� ���� ���̴� ���� �����ӿ�ũ";

#define PI 3.14159265f
#define FOV (PI / 4.0f)										// �þ߰�
#define ASPECT_RATIO (WIN_WIDTH / (float)WIN_HEIGHT)		// ȭ���� ��Ⱦ��
#define NEAR_PLANE 1										// ���� ���
#define FAR_PLANE 10000										// ���Ÿ� ���

float gRotationY = 0.0f;

D3DXVECTOR4 gWorldLightPosition(500.0f, 500.0f, -500.0f, 1.0f);
D3DXVECTOR4 gWorldCameraPosition(0, 0, -200, 1.0f);


// ----------------------------------------------------------------------------------
// ���α׷� ������ / �޽��� ����
// ----------------------------------------------------------------------------------

// ������
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, INT)
{
	WNDCLASSEX wc = { sizeof(WNDCLASSEX),CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, gAppName, NULL };
	RegisterClassEx(&wc);

	DWORD style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
	HWND hWnd = CreateWindow(gAppName, gAppName, style, CW_USEDEFAULT, 0, WIN_WIDTH, WIN_HEIGHT, GetDesktopWindow(), NULL, wc.hInstance, NULL);


	// CLIENT Rect ũ�Ⱑ WIN_WIDTH, WIN_HEIGHT�� ������ ũ�⸦ ����
	POINT ptDiff;
	RECT rcClient, rcWindow;

	GetClientRect(hWnd, &rcClient);
	GetWindowRect(hWnd, &rcWindow);

	ptDiff.x = (rcWindow.right - rcWindow.left) - rcClient.right;
	ptDiff.y = (rcWindow.bottom - rcWindow.top) - rcClient.bottom;

	MoveWindow(hWnd, rcWindow.left, rcWindow.top, WIN_WIDTH + ptDiff.x, WIN_HEIGHT + ptDiff.y, TRUE);

	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	if (!InitEverything(hWnd))
	{
		PostQuitMessage(1);
	}

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			PlayDemo();
		}
	}
	UnregisterClass(gAppName, wc.hInstance);

	return 0;
}


LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_KEYDOWN:
		ProcessInput(hWnd, wParam);
		break;
	case WM_DESTROY:
		Cleanup();
		PostQuitMessage(0);
		return 0;
	default:
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void ProcessInput(HWND hWnd, WPARAM keyPress)
{
	switch (keyPress)
	{
	case VK_ESCAPE:
		PostMessage(hWnd, WM_DESTROY, 0L, 0L);
		break;
	default:
		break;
	}
}


bool InitEverything(HWND hWnd)
{
	if (!InitD3D(hWnd))
	{
		return false;
	}

	if (!LoadAssets())
	{
		return false;
	}
	if (FAILED(D3DXCreateFont(gpD3DDevice, 20, 10, FW_BOLD
		, 1, FALSE, DEFAULT_CHARSET
		, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY
		, (DEFAULT_PITCH | FF_DONTCARE), "Arial", &gpFont)))
	{
		return false;
	}
	return true;
}


bool InitD3D(HWND hWnd)
{
	gpD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (!gpD3D)
	{
		return false;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.BackBufferWidth = WIN_WIDTH;
	d3dpp.BackBufferHeight = WIN_HEIGHT;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.Windowed = TRUE;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24X8;
	d3dpp.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
	d3dpp.FullScreen_RefreshRateInHz = 0;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

	if (FAILED(gpD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp, &gpD3DDevice)))
	{
		return false;
	}

	return true;
}

bool LoadAssets()
{
	// �ؽ��� �ε�
	gpEarthDM = LoadTexture("Earth.jpg");
	if (!gpEarthDM)
	{
		return false;
	}

	// ���̴� �ε�
	gpTextureMappingShader = LoadShader("TextureMapping.fx");

	if (!gpTextureMappingShader)
	{
		return false;
	}

	// �� �ε�

	gpSphere = LoadModel("sphere.x");
	if (!gpSphere)
	{
		return false;
	}

	return true;
}


LPD3DXEFFECT LoadShader(const char* filename)
{
	LPD3DXEFFECT ret = NULL;
	LPD3DXBUFFER pError = NULL;
	DWORD dwShaderFlags = 0;

#if _DEBUG
	dwShaderFlags |= D3DXSHADER_DEBUG;
#endif

	// .fx�������� ����� ���̴� ������ �ҷ����� �ε� �� ������
	D3DXCreateEffectFromFile(gpD3DDevice, filename, NULL, NULL, dwShaderFlags, NULL, &ret, &pError);

	// ���̴� �ε��� ������ ��� outputâ�� ���̴�
	// ������ ������ ����Ѵ�.

	if (!ret && pError)
	{
		int size = pError->GetBufferSize();
		void* ack = pError->GetBufferPointer();

		if (ack)
		{
			char* str = new char[size];
			wsprintf(str, (const char*)ack, size);
			OutputDebugString(str);
			delete[] str;
		}

	}

	return ret;
}

LPD3DXMESH LoadModel(const char* filename)
{
	LPD3DXMESH ret = NULL;

	if (FAILED(D3DXLoadMeshFromX(filename, D3DXMESH_SYSTEMMEM, gpD3DDevice, NULL, NULL, NULL, NULL, &ret)))
	{
		OutputDebugString("�� �ε� ���� : ");
		OutputDebugString(filename);
		OutputDebugString("\n");
	}
	return ret;
}

LPDIRECT3DTEXTURE9 LoadTexture(const char* filename)
{
	LPDIRECT3DTEXTURE9 ret = NULL;
	if (FAILED(D3DXCreateTextureFromFile(gpD3DDevice, filename, &ret)))
	{
		OutputDebugString("�ؽ��� �ε� ���� : ");
		OutputDebugString(filename);
		OutputDebugString("\n");
	}

	return ret;
}

void PlayDemo()
{
	Update();
	RenderFrame();
}


// ���� ���� ������Ʈ
void Update()
{

}


// ----------------------------------------------------------------------------------
// ������
// ----------------------------------------------------------------------------------
void RenderFrame()
{
	// �Ķ�
	D3DCOLOR bgColor = 0xFF0000FF;

	gpD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER), bgColor, 1.0f, 0);

	gpD3DDevice->BeginScene();
	{
		RenderScene();		//3D ��ü ���� �׸���.
		RenderInfo();		// ����� ���� ���� ����Ѵ�.
	}

	gpD3DDevice->EndScene();

	gpD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void RenderScene()
{
	// �� ����� �����
	D3DXMATRIXA16 matView;
	D3DXVECTOR3 vEyePt(D3DXVECTOR3(gWorldCameraPosition.x, gWorldCameraPosition.y, gWorldCameraPosition.z));
	D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);

	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);

	// ���� ����� �����.
	D3DXMATRIXA16 matProjection;
	D3DXMatrixPerspectiveFovLH(&matProjection, FOV, ASPECT_RATIO, NEAR_PLANE, FAR_PLANE);

	// ���� ����� �����.
	
	// ������ ���� 0.4���� ȸ���� ��Ų�� -> PI / 180 : ����-> ����, 180 / PI -> ���� -> ����
	gRotationY += 0.4f * PI / 180.0f;
	if (gRotationY > 2 * PI)
	{
		gRotationY -= 2 * PI;
	}

	D3DXMATRIXA16 matWorld;
	/*D3DXMatrixIdentity(&matWorld);*/
	D3DXMatrixRotationY(&matWorld, gRotationY);

	gpTextureMappingShader->SetMatrix("gWorldMatrix", &matWorld);
	gpTextureMappingShader->SetMatrix("gViewMatrix", &matView);
	gpTextureMappingShader->SetMatrix("gProjectionMatrix", &matProjection);

	gpTextureMappingShader->SetTexture("DiffuseMap_Tex", gpEarthDM);
	gpTextureMappingShader->SetVector("gWorldLightPosition", &gWorldLightPosition);
	gpTextureMappingShader->SetVector("gWorldCameraPosition", &gWorldCameraPosition);

	UINT numPasses = 0;
	gpTextureMappingShader->Begin(&numPasses, NULL);
	{
		for (UINT i = 0; i < numPasses; i++)
		{
			gpTextureMappingShader->BeginPass(i);
			{
				// ��ü�� �׸���

				gpSphere->DrawSubset(0);
			}
			gpTextureMappingShader->EndPass();
		}
	}
	gpTextureMappingShader->End();
}

void RenderInfo()
{

	// �ؽ�Ʈ ����
	D3DCOLOR fontColor = D3DCOLOR_ARGB(255, 255, 255, 255);

	// �ؽ�Ʈ�� ����� ��ġ
	RECT rct;
	rct.left = 5;
	rct.right = WIN_WIDTH / 3;
	rct.top = 5;
	rct.bottom = WIN_HEIGHT / 3;

	gpFont->DrawText(NULL, "���� �����ӿ�ũ\n\nESC : ��������", -1, &rct, 0, fontColor);


}

// ----------------------------------------------------------------------------------
// ������ �ڵ�
// ----------------------------------------------------------------------------------

void Cleanup()
{
	// ��Ʈ�� release �Ѵ�
	if (gpFont)
	{
		gpFont->Release();
		gpFont = NULL;
	}

	// ���� release �Ѵ�

	if (gpSphere)
	{
		gpSphere->Release();
		gpSphere = NULL;
	}

	// ���̴��� release �Ѵ�

	if (gpTextureMappingShader)
	{
		gpTextureMappingShader->Release();
		gpTextureMappingShader = NULL;
	}

	// �ؽ��ĸ� release�Ѵ�
	if (gpEarthDM)
	{
		gpEarthDM->Release();
		gpEarthDM = NULL;
	}

	//D3D�� release�Ѵ�

	if (gpD3DDevice)
	{
		gpD3DDevice->Release();
		gpD3DDevice = NULL;
	}

	if (gpD3D)
	{
		gpD3D->Release();
		gpD3D = NULL;
	}
}