#include "SDLRenderer.hpp"
#include "../Logger.hpp"

namespace Engine {
	SDLRenderer::SDLRenderer() { 
		if (!SDL_Init(SDL_INIT_VIDEO))
			Logger::Error(SDL_GetError());

		m_window = SDL_CreateWindow("Engine", 1600, 900, 0);
		if (m_window == nullptr)
			Logger::Error(SDL_GetError());

		m_renderer = SDL_CreateRenderer(m_window, nullptr);
		if (m_renderer == nullptr)
			Logger::Error(SDL_GetError());

		Logger::Info("SDL Renderer has been constructed");
	}

	SDLRenderer::~SDLRenderer() {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();

		Logger::Info("SDL Renderer has been destructed");
	}

	SDL_Window* SDLRenderer::GetWindow() {
		return m_window;
	}

	SDL_Renderer* SDLRenderer::GetRenderer() {
		return m_renderer;
	}
}