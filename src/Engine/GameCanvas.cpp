#include "GameCanvas.hpp"

namespace Engine {
	GameCanvas::GameCanvas(SDLRenderer& Renderer) : m_renderer{ Renderer } {
	}

	void GameCanvas::Clear(uint32_t color) const {
		SDL_Color sdlColor = ColorToSDLColor(color);
		SDL_SetRenderDrawColor(m_renderer.GetRenderer(), sdlColor.r, sdlColor.g, sdlColor.b, sdlColor.a);
		SDL_RenderClear(m_renderer.GetRenderer());
	}

	void GameCanvas::DrawLine(const Line& line) const {
		SDL_Vertex vertexArray[2];
		LineToSDLVertex(line, vertexArray);
		SDL_RenderGeometry(m_renderer.GetRenderer(), nullptr, vertexArray, 2, nullptr, 0);
	}

	void GameCanvas::DrawTriangle(const Triangle& triangle) const {
		SDL_Vertex vertexArray[3];
		TriangleToSDLVertex(triangle, vertexArray);
		SDL_RenderGeometry(m_renderer.GetRenderer(), nullptr, vertexArray, 3, nullptr, 0);
	}

	void GameCanvas::DrawRectangle(const Rectangle& rectangle) const {
		SDL_FRect sdlFrect = RectangleToSDLFrect(rectangle);
		SDL_Color sdlColor = ColorToSDLColor(rectangle.color);
		SDL_SetRenderDrawColor(m_renderer.GetRenderer(), sdlColor.r, sdlColor.g, sdlColor.b, sdlColor.a);
		SDL_RenderFillRect(m_renderer.GetRenderer(), &sdlFrect);
	}

	void GameCanvas::DrawTile(const Rectangle& tile, Vector2i position) const {
		// TODO
	}

	SDL_Color GameCanvas::ColorToSDLColor(uint32_t color) const {
		SDL_Color sdlColor = {
			color >> 24,
			(color >> 16) & 0xff,
			(color >> 8) & 0xff,
			color & 0xff
		};
		return sdlColor;
	}

	SDL_FColor GameCanvas::ColorToSDLFColor(uint32_t color) const {
		SDL_Color sdlColor = ColorToSDLColor(color);
		SDL_FColor sdlFcolor = {
			sdlColor.r / 255.f,
			sdlColor.g / 255.f,
			sdlColor.b / 255.f,
			sdlColor.a / 255.f
		};
		return sdlFcolor;
	}

	SDL_FRect GameCanvas::RectangleToSDLFrect(const Rectangle& rectangle) const {
		SDL_FRect sdlFrect = {
			static_cast<float>(rectangle.position.x),
			static_cast<float>(rectangle.position.y),
			static_cast<float>(rectangle.size.x),
			static_cast<float>(rectangle.size.y)
		};
		return sdlFrect;
	}

	void GameCanvas::TriangleToSDLVertex(const Triangle& triangle, SDL_Vertex* sdlVertexArray) const {
		SDL_FColor sdlFcolor = ColorToSDLFColor(triangle.color);
		sdlVertexArray[0] = { 
			{ static_cast<float>(triangle.a.x), static_cast<float>(triangle.a.y) }, 
			sdlFcolor 
		};
		sdlVertexArray[1] = { 
			{ static_cast<float>(triangle.b.x), static_cast<float>(triangle.b.y) }, 
			sdlFcolor 
		};
		sdlVertexArray[2] = { 
			{ static_cast<float>(triangle.c.x), static_cast<float>(triangle.c.y) }, 
			sdlFcolor 
		};
	}

	void GameCanvas::LineToSDLVertex(const Line& line, SDL_Vertex* sdlVertexArray) const {
		SDL_FColor sdlFcolor = ColorToSDLFColor(line.color);
		sdlVertexArray[0] = { 
			{ static_cast<float>(line.start.x), static_cast<float>(line.start.y) }, 
			sdlFcolor 
		};
		sdlVertexArray[1] = { 
			{ static_cast<float>(line.end.x), static_cast<float>(line.end.y) }, 
			sdlFcolor 
		};
	}
}
