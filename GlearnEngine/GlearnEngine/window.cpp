#include "window.h"

namespace GlearnWindow {

	Window::Window()
		: m_Input(0),m_Graphics(0){
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

		// Initialize Graphics
		m_Graphics = new GlearnGraphics::Graphics;
		if (!m_Graphics) {
			return false;
		}
		if (!m_Graphics->Init(screenWidth, screenHeight, m_hwnd)) {
			return false;
		}

		return true;
	}

	void InitializeWindows(int& screenWidth, int& screenHeight) {

	}
}