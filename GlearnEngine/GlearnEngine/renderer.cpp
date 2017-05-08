#include "renderer.h"

namespace GlearnRenderer {

	Renderer::Renderer() {
	}
	Renderer::Renderer(const Renderer&) {
	}
	Renderer::~Renderer() {
	}

	//public

	bool Renderer::Init(int, int, HWND) {
		return true;
	}

	void Renderer::Cleanup() {
		return;
	}
	
	bool Renderer::Frame() {
		return true;
	}

	// private

	bool Renderer::Render() {
		return true;
	}

}