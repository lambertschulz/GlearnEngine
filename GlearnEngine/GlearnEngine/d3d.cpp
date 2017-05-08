#include "d3d.h"

namespace GlearnGraphics {

	d3d::d3d():
		m_swapChain(0),
		m_device(0),
		m_deviceContext(0),
		m_renderTargetView(0),
		m_depthStencilBuffer(0),
		m_depthStencilState(0),
		m_depthStencilView(0),
		m_rasterState(0){
	}
	d3d::d3d(const d3d&) {
	}
	d3d::~d3d() {
	}

// public

	bool d3d::Init(int screenWidth, int screenHeight, bool vsync, HWND hwnd, bool fullscreen, float screenDepth, float screenNear) {
		HRESULT result;
		IDXGIFactory* factory;
		IDXGIAdapter* adapter;
		IDXGIOutput* adapterOutput;
		unsigned int numModes, i, numerator, denominator;
		unsigned long long stringLength;
		DXGI_MODE_DESC* displayModeList;
		DXGI_ADAPTER_DESC adapterDesc;
		int error;
		DXGI_SWAP_CHAIN_DESC swapChainDesc;
		D3D_FEATURE_LEVEL featureLevel;
		ID3D11Texture2D* backBufferPtr;
		D3D11_TEXTURE2D_DESC depthBufferDesc;
		D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
		D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
		D3D11_RASTERIZER_DESC rasterDesc;
		D3D11_VIEWPORT viewport;
		float fieldOfView, screenAspect;

		m_vsync_enabled = vsync;									// store the vsync settings


		result = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);
		if (FAILED(result)) {
			return false;
		}

		result = factory->EnumAdapters(0, &adapter);
		if (FAILED(result)) {
			return false;
		}

		result = adapter->EnumOutputs(0, &adapterOutput);
		if (FAILED(result)) {
			return false;
		}

		result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);
		if (FAILED(result)) {
			return false;
		}

		displayModeList = new DXGI_MODE_DESC[numModes];
		if (!displayModeList) {
			return false;
		}

		result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);
		if (FAILED(result)) {
			return false;
		}

		for (i = 0; i < numModes; i++) {
			if (displayModeList[i].Width == (unsigned int)screenWidth) {
				if (displayModeList[i].Height == (unsigned int)screenHeight) {
					numerator = displayModeList[i].RefreshRate.Numerator;
					denominator = displayModeList[i].RefreshRate.Denominator;
				}
			}
		}

		result = adapter->GetDesc(&adapterDesc);
		if (FAILED(result)) {
			return false;
		}

		m_videoCardMemory = (int)(adapterDesc.DedicatedVideoMemory / 1024 / 1024);


		//TODO: Fix That Shit

		error = wcstombs_s(&stringLength, m_videoCardDescription, 128, adapterDesc.Description, 128); //hהההה
		if (error != 0) {
			return false;
		}




	}
	void d3d::Cleanup() {

	}

	void d3d::BeginScene() {

	}
	void d3d::EndScene() {

	}

	ID3D11Device* d3d::GetDevice() {

	}
	ID3D11DeviceContext* d3d::GetDeviceContext() {

	}

	void d3d::GetProjectionMatrix(XMMATRIX&) {

	}
	void d3d::GetWorldMatrix(XMMATRIX&) {

	}
	void d3d::GetOrthoMatrix(XMMATRIX&) {

	}

	void d3d::GetVideoCardInfo(char*, int&) {

	}
}