#include "Shapes.hpp"

namespace Engine {
	Line::Line(Vector2i start, Vector2i end, uint32_t color) :
		start{ start },
		end{ end },
		color{ color } 
	{}

	Line::Line(int startX, int startY, int endX, int endY, uint32_t color) :
		start{ startX, startY },
		end{ endX, endY },
		color{ color }
	{}

	Triangle::Triangle(Vector2i a, Vector2i b, Vector2i c, uint32_t color) :
		a{ a },
		b{ b },
		c{ c },
		color{ color }
	{}

	Triangle::Triangle(int ax, int ay, int bx, int by, int cx, int cy, uint32_t color) :
		a{ ax, ay },
		b{ bx, by },
		c{ cx, cy },
		color{ color }
	{}

	Rectangle::Rectangle(Vector2i position, Vector2i size, uint32_t color) :
		position{ position },
		size{ size },
		color{ color } 
	{}

	Rectangle::Rectangle(int x, int y, int w, int h, uint32_t color) :
		position{ x, y },
		size{ w, h },
		color{ color }
	{}
}