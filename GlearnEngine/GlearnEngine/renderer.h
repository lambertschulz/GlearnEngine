#ifndef _RENDERER_H
#define _RENDERER_H

#include "globalDefines.h"
#include "d3d.h"

namespace GlearnGraphics {
	const bool FULL_SCREEN = true;
	const bool VSYNC_ENABLED = true;
	const float SCREEN_DEPTH = 1000.0f;
	const float SCREEN_NEAR = 0.1f;

	class Renderer
	{
	public:
		Renderer();
		Renderer(const Renderer&);
		~Renderer();

		bool Init(int, int, HWND);
		void Cleanup();
		bool Frame();

	private:
		bool Render();

	private:
		d3d* m_Direct3D;
	};
}

#endif // !_RENDERER_H
