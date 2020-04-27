#include "renderer_opengl.h"

#include <iostream>
#include <vector>

#include "gl_utils/compile_program.h"

static void checkGlError() {
    GLenum aaa = glGetError();
    if (aaa != GL_NO_ERROR) {
        printf("%#x\n", aaa);
    }
}

namespace GBMU {

Renderer::Renderer(SDL_Window* window, gb_cpu_s* gb) : m_Window(window), m_Gb(gb) {}

Renderer::~Renderer() {
    Destroy();
}

int Renderer::Init()
{
    m_GlContext = SDL_GL_CreateContext(m_Window);

    GLenum ret = glewInit();
    if (ret != GLEW_OK) {
        printf("failed to init glew\n");
        return -1;
    }

    float vertices[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.0f,  0.5f,
    };

    m_Program = compileProgram(
        "C:/Users/iwan/GBmu/srcs/renderer/shaders/vertex.glsl",
        "C:/Users/iwan/GBmu/srcs/renderer/shaders/fragment.glsl");

    if (!m_Program) {
        printf("failed to create program\n");
        return -1;
    }
    
    glBindAttribLocation(m_Program, 0, "inVertex");

    float quad[] = {
        -1.f, -1.f,
        -1.f,  1.f,
         1.f, -1.f,
         1.f,  1.f,
    };

    glGenVertexArrays(1, &m_Vao);
    glBindVertexArray(m_Vao);
    glGenBuffers(1, &m_Vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(1.f, 0.f, 0.f, 1.0f);

    glGenTextures(1, &m_Texture);
    glBindTexture(GL_TEXTURE_2D, m_Texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);

    m_InfosLoc = glGetUniformLocation(m_Program, "infos");

    return 0;
}

int Renderer::Destroy()
{
    if (m_GlContext) {
        SDL_GL_DeleteContext(m_GlContext);
    }

    return 0;
}

int Renderer::Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    glGenBuffers(1, &m_Pbo);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, m_Pbo);
    glBufferData(GL_PIXEL_UNPACK_BUFFER, VRAM_SIZE, NULL, GL_STREAM_DRAW);
    void* mappedBuffer = glMapBuffer(GL_PIXEL_UNPACK_BUFFER, GL_WRITE_ONLY);

    memcpy(mappedBuffer, m_Gb->vram, VRAM_SIZE);

    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, m_Pbo);
    glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);
    glBindTexture(GL_TEXTURE_2D, m_Texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, 128, 64, 0, GL_RED, GL_UNSIGNED_BYTE, 0);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);

    int scy = read_8(m_Gb, SCY_OFFSET);
    int scx = read_8(m_Gb, SCX_OFFSET);
    uint8_t lcdc = (read_8(m_Gb, LCDC_OFFSET));
    glUniform3ui(m_InfosLoc, scx, scy, lcdc);

    glUseProgram(m_Program);
    glBindVertexArray(m_Vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBindTexture(GL_TEXTURE_2D, m_Texture);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);

    SDL_GL_SwapWindow(m_Window);

    return 0;
}

int Renderer::Loop() {
    while (1) {
        Render();
    }

    return 0;
}

}