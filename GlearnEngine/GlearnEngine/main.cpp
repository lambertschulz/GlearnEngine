////////////////////////////////////////////////////////////////////////////////////////////////
// This is the main.cpp file written for the GlearnEngine by Adrian Beckmann
////////////////////////////////////////////////////////////////////////////////////////////////
// this programm is written as a project for university and heavily relies on two main sources:
// - this code contains parts written by other students of HSRW 
// - and parts borrowed from the tutorials on www.rastertek.com
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "window.h"

GlearnWindow::Window* m_window;		// the pointer to the object that creates the window

int WINAPI WinMain(
	HINSTANCE	hInstance,			// the handle to this instance of this programm
	HINSTANCE	hPrevInstance,		// is allways NULL
	PSTR		pCmdLineArgs,		// contains the command-line arguments as unicode string
	int			iCmdshow			// is a flag that says whether the main application window will be minimized, maximized, or shown normally
){				
	m_window = new GlearnWindow::Window;
	if (!m_window) {
		return 0;
	}

	if (!m_window->Init()) {
		return 0;
	}

	if (!m_window->Run()) {
		return 0;
	}

	if (!m_window->Cleanup()) {
		return 0;
	}

	delete m_window;
	m_window = nullptr;

	return 0;
}