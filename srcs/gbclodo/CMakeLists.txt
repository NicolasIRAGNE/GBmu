cmake_minimum_required(VERSION 3.15)

add_executable(gbclodo)

include(FetchIfMissing)

FetchIfMissing(
    SDL2
    URL            https://www.libsdl.org/release/SDL2-2.0.18.zip
)

FetchIfMissing(
    GLEW
    GIT_REPOSITORY "https://github.com/Perlmint/glew-cmake"
    GIT_TAG glew-cmake-release
)

FetchIfMissing(
    cxxopts
    GIT_REPOSITORY "https://github.com/jarro2783/cxxopts"
    GIT_TAG v3.0.0
)

find_package(OpenGL REQUIRED)

FetchContent_MakeAvailable(
	SDL2 GLEW cxxopts
)
set(FETCHED_TARGETS)

set(SHADERS
	renderer/shaders/basic.vert
	renderer/shaders/basic.frag
	renderer/shaders/rain.frag)

target_include_directories(gbclodo PUBLIC renderer)
target_include_directories(gbclodo PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_sources(gbclodo
    PRIVATE
        main.cpp
        clodo_loop.c
        init_sdl.c
        video_loop.c
        vram_viewer.c
        input_functions.c
        handle_joypad.c
        main_window_loop.c
	    savestate.c
        tile.c
        renderer/renderer_opengl.cpp
        renderer/rescale.cpp
        renderer/gl_utils/compile_program.cpp
	    renderer/wrapper_c/wrapper.cpp
        gbclodo.h
        renderer.h
        renderer/renderer_opengl.h
        renderer/rescale.h
        renderer/gl_utils/compile_program.h
        renderer/gl_utils/glerr.h
        renderer/wrapper_c/wrapper.h)
        
foreach(shader ${SHADERS})
target_compile_definitions(gbclodo PRIVATE "SHADERS_LOCATION=\"${CMAKE_CURRENT_LIST_DIR}/renderer/shaders\"")
get_filename_component(filename ${shader} NAME)
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/shaders/${filename}
    # DEPENDS ${shader}
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/${shader} ${CMAKE_CURRENT_BINARY_DIR}/shaders/${filename}
    COMMENT "Copying shader ${filename} to ${CMAKE_CURRENT_BINARY_DIR}/shaders/"
    )
    set (GENERATED_SHADERS ${GENERATED_SHADERS} ${CMAKE_CURRENT_BINARY_DIR}/shaders/${filename})
# add_custom_target(gbmu_shader_${filename} ALL
# 	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/${shader} ${CMAKE_CURRENT_BINARY_DIR}/shaders/${filename}
# 	DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/shaders/${filename}
# 	COMMENT "Copying shader ${filename} to ${CMAKE_CURRENT_BINARY_DIR}/shaders/"
# 	SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${shader}
# )
# add_dependencies(gb gbmu_shader_${filename})
endforeach()

add_custom_target(gbmu_shaders ALL DEPENDS ${GENERATED_SHADERS})

add_dependencies(gbclodo gbmu_shaders)
target_link_libraries(gbclodo gb)
target_link_libraries(gbclodo SDL2-static)
target_link_libraries(gbclodo SDL2main)
target_link_libraries(gb ${OPENGL_LIBRARIES})
target_link_libraries(gbclodo cxxopts::cxxopts)
target_link_libraries(gbclodo libglew_static)
