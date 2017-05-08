#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <windows.h>

namespace GlearnGraphics {
	const bool FULL_SCREEN = false;
	const bool VSYNC_ENABLED = true;
	const float SCREEN_DEPTH = 1000.0f;
	const float SCREEN_NEAR = 0.1f;

	class Graphics
	{
	public:
		Graphics();
		Graphics(const Graphics&);
		~Graphics();

		bool Init(int, int, HWND);
		bool Cleanup();
		bool Run();

	private:
		bool Render();
	};
}

#endif // !_GRAPHICS_H
