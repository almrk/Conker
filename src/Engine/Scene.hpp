#pragma once

#include "SDLEvent.hpp"
#include "SDLRenderer.hpp"
#include "GameCanvas.hpp"
#include "ImGuiCanvas.hpp"

namespace Engine {
	class Scene {
	private:
		SDLEvent& m_event;
		SDLRenderer& m_renderer;

	public:
		Scene();
		~Scene();

		virtual void OnGameDraw(const GameCanvas& canvas) = 0;
		virtual void OnImGui(const ImGuiCanvas& canvas) = 0;
		virtual void OnKeyboardEvent(const KeyboardEvent& keyboard) = 0;
		virtual void OnMouseEvent(const MouseEvent& mouse) = 0;
		virtual void OnWindowEvent(const WindowEvent& window) = 0;
	};
}