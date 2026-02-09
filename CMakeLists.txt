cmake_minimum_required(VERSION 3.30)
project("Conker")

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

include(FetchContent)

# Add SDL to the projcet
FetchContent_Declare(
	SDL3
	GIT_REPOSITORY https://github.com/libsdl-org/SDL
	GIT_TAG release-3.4.0
)
FetchContent_MakeAvailable(SDL3)

# Add SDL_image to the project
FetchContent_Declare(
	SDL3_image
	GIT_REPOSITORY https://github.com/libsdl-org/SDL_image
	GIT_TAG release-3.4.0
)
set(SDLIMAGE_VENDORED ON)
set(SDLIMAGE_AVIF OFF)
set(SDLIMAGE_BMP OFF)
set(SDLIMAGE_JPEG OFF)
set(SDLIMAGE_WEBP OFF)
set(SDLIMAGE_PNG_LIBPNG OFF)
FetchContent_MakeAvailable(SDL3_image)

# Add SDL_mixer to the project
FetchContent_Declare(
	SDL3_mixer
	GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer
	GIT_TAG prerelease-3.1.2
)
set(SDLMIXER_MIDI_NATIVE OFF)
set(SDLMIXER_GME OFF)
set(SDLMIXER_WAVPACK OFF)     
set(SDLMIXER_MOD OFF)
set(SDLMIXER_MOD_XMP OFF)
set(SDLMIXER_OPUS OFF)
set(SDLMIXER_MP3_MPG123 OFF)
set(SDLMIXER_VORBIS_VORBISFILE OFF)
set(SDLMIXER_FLAC_LIBFLAC OFF)
set(SDLMIXER_VENDORED ON) 
FetchContent_MakeAvailable(SDL3_mixer)

# Add ImGui to the project
FetchContent_Declare(
	imgui
	GIT_REPOSITORY https://github.com/ocornut/imgui
	GIT_TAG v1.92.5
)
FetchContent_MakeAvailable(imgui)

aux_source_directory("src/" SRCS)
aux_source_directory("src/Engine" ENGINE_SRCS)
add_executable(
	Conker
	# ImGui source
	"out/build/x64-debug/_deps/imgui-src/imgui.cpp"
	"out/build/x64-debug/_deps/imgui-src/imgui_demo.cpp"
	"out/build/x64-debug/_deps/imgui-src/imgui_draw.cpp"
	"out/build/x64-debug/_deps/imgui-src/imgui_tables.cpp"
	"out/build/x64-debug/_deps/imgui-src/imgui_widgets.cpp"
	"out/build/x64-debug/_deps/imgui-src/backends/imgui_impl_sdl3.cpp"
	"out/build/x64-debug/_deps/imgui-src/backends/imgui_impl_sdlrenderer3.cpp"
	# Project source
	"src/Main.cpp"
	"src/Logger.cpp"
	"src/Engine/GameCanvas.cpp"
	"src/Engine/SDLRenderer.cpp"
	"src/Engine/Shapes.cpp"
	"src/Engine/Vector2.cpp"
 "src/Engine/ImGuiCanvas.cpp" "src/Engine/Scene.cpp")
target_compile_features(Conker PRIVATE cxx_std_20)
target_include_directories(Conker PRIVATE "out/build/x64-debug/_deps/imgui-src" "out/build/x64-debug/_deps/imgui-src/backends")
target_link_libraries(Conker PRIVATE SDL3::SDL3-shared SDL3_image::SDL3_image-shared SDL3_mixer::SDL3_mixer-shared)
