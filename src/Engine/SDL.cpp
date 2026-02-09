#include "../Logger.hpp"
#include "SDL.hpp"
#include <format>
#include <SDL3_image/SDL_image.h>

namespace Engine {
	SDL::SDL() { 
		if (!SDL_Init(SDL_INIT_VIDEO))
			Logger::Error(SDL_GetError());

		m_window = std::make_shared<SDL_Window>(
			SDL_CreateWindow("Engine", 1600, 900, 0),
			[](SDL_Window* window){ 
				SDL_DestroyWindow(window); 
				Logger::Info("SDL window destroyed");
			}
		);
		if (m_window == nullptr)
			Logger::Error(SDL_GetError());

		m_renderer = std::make_shared<SDL_Renderer>(
			SDL_CreateRenderer(m_window.get(), nullptr),
			[](SDL_Renderer* renderer) {
				SDL_DestroyRenderer(renderer);
				Logger::Info("SDL renderer destroyed");
			}
		);
		if (m_renderer == nullptr)
			Logger::Error(SDL_GetError());
	}

	SDL::~SDL() {
		SDL_Quit();
		Logger::Info("SDL has been deinitialised");
	}

	std::unique_ptr<SDL_Texture> SDL::NewTexture(int w, int h) {
		std::unique_ptr<SDL_Texture> texture = std::make_unique<SDL_Texture>(
			SDL_CreateTexture(m_renderer.get(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h),
			[](SDL_Renderer* renderer){
				SDL_DestroyRenderer(renderer);
				Logger::Info("Destroyed texture");
			}
		);
		if (texture == nullptr)
			Logger::Error(SDL_GetError());
		else
			Logger::Info(std::format("Created texture with size {}x{}", w, h));

		return texture;
	}

	std::unique_ptr<SDL_Texture> SDL::NewTexture(const std::string_view& path) {
		std::unique_ptr<SDL_Texture> texture = std::make_unique<SDL_Texture>(
			IMG_LoadTexture(m_renderer.get(), path.data()),
			[](SDL_Texture* texture) {
				Logger::Info("Destroyed image texture");
			}
		);
		if (texture == nullptr)
			Logger::Error(SDL_GetError());
		else
			Logger::Info(std::format("Created image texture \"{}\"", path));

		return texture;

	}

	std::unique_ptr<SDL_Window> SDL::GetWindow() {
		return m_window;
	}

	std::unique_ptr<SDL_Renderer> SDL::GetRenderer() {
		return m_renderer;
	}
	void SetRenderTexture(std::unique_ptr<SDL_Texture> texture);
	void ResetRenderTexture();
}