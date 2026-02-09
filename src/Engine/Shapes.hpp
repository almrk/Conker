#pragma once

#include <cstdint>
#include "Vector2.hpp"

namespace Engine {
	struct Line {
		Vector2i start;
		Vector2i end;
		uint32_t color;

		Line(Vector2i start, Vector2i end, uint32_t color);
		Line(int startX, int startY, int endX, int endY, uint32_t color);
	};

	struct Triangle {
		Vector2i a;
		Vector2i b;
		Vector2i c;
		uint32_t color;

		Triangle(Vector2i a, Vector2i b, Vector2i c, uint32_t color);
		Triangle(int ax, int ay, int bx, int by, int cx, int cy, uint32_t color);
	};

	struct Rectangle {
		Vector2i position;
		Vector2i size;
		uint32_t color;

		Rectangle(Vector2i position, Vector2i size, uint32_t color);
		Rectangle(int x, int y, int w, int h, uint32_t color);
	};
}