#include "ImGuiCanvas.hpp"
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlrenderer3.h>

namespace Engine {
	ImGuiCanvas::ImGuiCanvas(SDLRenderer& renderer) : m_renderer{ renderer } {
		ImGui_ImplSDLRenderer3_NewFrame();
		ImGui_ImplSDL3_NewFrame();
		ImGui::NewFrame();
	}

	ImGuiCanvas::~ImGuiCanvas() {
		ImGui::Render();
		SDL_SetRenderDrawColor(m_renderer.GetRenderer(), 0, 0, 0, 0);
		SDL_RenderClear(m_renderer.GetRenderer());
		ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), m_renderer.GetRenderer());
	}
}