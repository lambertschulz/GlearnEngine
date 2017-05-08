////////////////////////////////////////////////////////////////////////////////////////////////
// This is the window.h file written for the GlearnEngine by Adrian Beckmann
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _WINDOW_H
#define _WINDOW_H

#include <windows.h>

#include "input.h"
#include "renderer.h"

namespace GlearnWindow {
	class Window
	{
	public:
		Window();							// constructor
		Window(const Window&);				// copy-constructor
		~Window();							// destructor


		bool Init();
		bool Run();
		bool Cleanup();

		LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);
	private:
		bool Frame();
		void InitializeWindows(int& screenWidth, int& screenHeight);
		void CleanupWindows();


	private:
		LPCWSTR m_appName;					// pointer to the application name
		HINSTANCE m_hInstance;				// handle of the application
		HWND m_hwnd;						// handle of the window

		GlearnRenderer::Renderer* m_Renderer;
		GlearnInput::Input* m_Input;
	};

	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // function prototype

	static Window* AppHandle = 0;
}

#endif // !_WINDOW_H