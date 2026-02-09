#pragma once

#include "Shapes.hpp"
#include "SDLRenderer.hpp"

namespace Engine {
	class GameCanvas {
	private:
		SDLRenderer& m_renderer;

	public:
		GameCanvas(SDLRenderer& renderer);

		void Clear(uint32_t color) const;
		void DrawLine(const Line& line) const;
		void DrawTriangle(const Triangle& triangle) const;
		void DrawRectangle(const Rectangle& rectangle) const;
		void DrawTile(const Rectangle& tile, Vector2i position) const;

	private:
		SDL_Color ColorToSDLColor(uint32_t color) const;
		SDL_FColor ColorToSDLFColor(uint32_t color) const;
		SDL_FRect RectangleToSDLFrect(const Rectangle& rectangle) const;
		void TriangleToSDLVertex(const Triangle& triangle, SDL_Vertex* sdlVertexArray) const;
		void LineToSDLVertex(const Line& triangle, SDL_Vertex* sdlVertexArray) const;
	};
}