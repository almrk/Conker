#pragma once

namespace Engine {
	template<typename T>
	struct Vector2 {
		T x;
		T y;

		Vector2<T> operator+(Vector2<T> rhs);
		Vector2<T> operator-(Vector2<T> rhs);
		Vector2<T> operator*(Vector2<T> rhs);
		Vector2<T> operator/(Vector2<T> rhs);
	};

	using Vector2i = Vector2<int>;
	using Vector2u = Vector2<unsigned int>;
	using Vector2f = Vector2<float>;
	using Vector2d = Vector2<double>;
}