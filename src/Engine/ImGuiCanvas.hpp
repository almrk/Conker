#pragma once

#include "SDLRenderer.hpp"

namespace Engine {
	class ImGuiCanvas {
	private:
		SDLRenderer& m_renderer;

	public:
		ImGuiCanvas(SDLRenderer& renderer);
		~ImGuiCanvas();
	};
}