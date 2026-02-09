#include "Vector2.hpp"

namespace Engine {
	template<typename T>
	Vector2<T> Vector2<T>::operator+(Vector2<T> rhs) {
		return { x + rhs.x, y + rhs.y };
	}

	template<typename T>
	Vector2<T> Vector2<T>::operator-(Vector2<T> rhs) {
		return { x - rhs.x, y - rhs.y };
	}
	
	template<typename T>
	Vector2<T> Vector2<T>::operator*(Vector2<T> rhs) {
		return { x * rhs.x, y * rhs.y };
	}

	template<typename T>
	Vector2<T> Vector2<T>::operator/(Vector2<T> rhs) {
		return { x * rhs.x, y * rhs.y };
	}
}