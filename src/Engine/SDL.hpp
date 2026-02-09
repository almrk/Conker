#pragma once

#include <memory>
#include <string_view>
#include <SDL3/SDL.h>

namespace Engine {
	class SDL {
		std::shared_ptr<SDL_Window> m_window;
		std::shared_ptr<SDL_Renderer> m_renderer;

	public:
		SDL();
		~SDL();

		std::unique_ptr<SDL_Texture> NewTexture(int w, int h);
		std::unique_ptr<SDL_Texture> NewTexture(const std::string_view& path);
		std::shared_ptr<SDL_Window> GetWindow();
		std::shared_ptr<SDL_Renderer> GetRenderer();
	};
}