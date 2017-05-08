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
		ShowCursor(true);							// show the curser again

		if (FULL_SCREEN) {
			ChangeDisplaySettings(NULL, 0);
		}

		DestroyWindow(m_hwnd);
		m_hwnd = nullptr;

		UnregisterClass(APP_NAME, m_hInstance);
	}

	void Window::InitializeWindows(int& screenWidth, int& screenHeight) {
		WNDCLASSEX wc = {};
		DEVMODE devmode = {};
		int posX, posY;

		AppHandle = this;								// gets an external pointer to this object
		m_hInstance = GetModuleHandle(NULL);			// gets an handle of this application

		// defining window class
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = WndProc;
		wc.hInstance = m_hInstance;
		wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
		wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wc.lpszClassName = APP_NAME;					// app_name taken from the global defines

		RegisterClassEx(&wc);							// register the window class

		screenWidth = GetSystemMetrics(SM_CXSCREEN);	// gets the users screen width
		screenHeight = GetSystemMetrics(SM_CYSCREEN);	// and height

		EnumDisplaySettings(nullptr, ENUM_CURRENT_SETTINGS, &devmode);

		if (FULL_SCREEN) {								// set screen to max size and 32bit depth
			devmode.dmPelsWidth = (unsigned long)screenWidth;
			devmode.dmPelsHeight = (unsigned long)screenHeight;
			ChangeDisplaySettings(&devmode, CDS_FULLSCREEN);
			posX = posY = 0;							// set top left corner
		} else {										// set screen too 800x600
			screenWidth = 800;
			screenHeight = 600;
			posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
			posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
		}
		DWORD wndStyle = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP;
		m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, APP_NAME, APP_NAME, wndStyle, posX, posY, screenWidth, screenHeight, NULL, NULL, m_hInstance, NULL);

		ShowWindow(m_hwnd, SW_SHOW);					// shows window
		SetForegroundWindow(m_hwnd);					// set this application in foreground
		SetFocus(m_hwnd);								// give focus to this application

		ShowCursor(false);								// dont show the curser

		return;
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