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

		//TODO: go on from here
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