#pragma once

#include <SDL3/SDL.h>

namespace Engine {
	class SDLRenderer {
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_gameCanvas;
		SDL_Texture* m_imguiCanvas;

	public:
		SDLRenderer();
		~SDLRenderer();

		SDL_Window* GetWindow();
		SDL_Renderer* GetRenderer();
	};
}