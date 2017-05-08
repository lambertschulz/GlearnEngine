#include "window.h"
#include "globalDefines.h"

namespace GlearnWindow {

	Window::Window()
		: m_Input(0), m_Renderer(0){
	}
	Window::Window(const Window&){
	}
	Window::~Window(){
	}


	bool Window::Init() {
		int screenWidth = 0;
		int screenHeight = 0;

		InitializeWindows(screenWidth, screenHeight);

		// Initializing Input
		m_Input = new GlearnInput::Input;
		if (!m_Input) {
			return false;
		}
		m_Input->Init();

		// Initialize Renderer
		m_Renderer = new GlearnRenderer::Renderer;
		if (!m_Renderer) {
			return false;
		}
		if (!m_Renderer->Init(screenWidth, screenHeight, m_hwnd)) {
			return false;
		}

		return true;
	}

	bool Window::Cleanup() {
		if (m_Renderer) {
			m_Renderer->Cleanup();
			delete m_Renderer;
			m_Renderer = nullptr;
		}
		if (m_Input) {
			delete m_Input;
			m_Input = nullptr;
		}
		CleanupWindows();

		return true;
	}

	bool Window::Run() {
		MSG msg;

		//Initialize the Message
		ZeroMemory(&msg, sizeof(MSG));

		//Main Loop
		while (true) {
			//windoes message handling
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			if (msg.message == WM_QUIT) {
				return false;
			} else {
				if (!Frame()) {
					return false;
				}
			}
		}
		return true;
	}


	void Window::CleanupWindows() {

	}
	void Window::InitializeWindows(int& screenWidth, int& screenHeight) {
		WNDCLASSEX wc;
		DEVMODE dmScreenSettings;
		int posX, posY;

		AppHandle = this;							// gets an external pointer to this object

		m_hInstance = GetModuleHandle(NULL);		// gets an handle of this application

		m_appName = APP_NAME;						// app_name taken from the global defines

	}

	bool Window::Frame() {
		if (m_Input->IsKeyDown(VK_ESCAPE)) {		// if user pressed ESC return false to close the application
			return false;							
		}
		if (!m_Renderer->Frame()) {					// if user didnt press ESC render the frame
			return false;
		}
		return true;
	}

	LRESULT CALLBACK Window::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam) {
		switch (umsg){
			case WM_KEYDOWN: {
				m_Input->KeyDown((unsigned int)wparam);
				return 0;
			}
			case WM_KEYUP: {
				m_Input->KeyUp((unsigned int)wparam);
				return 0;
			}
			default: {
				return DefWindowProc(hwnd, umsg, wparam, lparam);
			}
		}
	}

}//End of namespace GlearnWindow