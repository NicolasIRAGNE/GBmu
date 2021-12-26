#include "compile_program.h"

#include <stdio.h>
#include <fstream>
#include <string>
#include <iterator>

#include "GL/glew.h"
#include "glerr.h"
#include <iostream>

GLuint compileShader(const char* source, GLuint shaderType)
{
    GLuint shader_id = glCreateShader(shaderType); GLERR;
    glShaderSource(shader_id, 1, &source, NULL); GLERR;
    glCompileShader(shader_id); GLERR;

    GLint shaderCompiled;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &shaderCompiled); GLERR;
    if (shaderCompiled != GL_TRUE) {
        GLint logLength;
        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &logLength); GLERR;
        if (logLength > 0) {
            std::string log(logLength, '\0');
            glGetShaderInfoLog(shader_id, logLength, &logLength, log.data()); GLERR;
            printf("opengl compile shader error : %s\n", log.c_str());
        }
        glDeleteShader(shader_id); GLERR;
        return 0;
    }

    return shader_id;
}

GLuint compileProgram(const char* vtxFile, const char* fragFile)
{
    GLuint programId = 0;
    GLuint vtxShaderId, fragShaderId;
    programId = glCreateProgram(); GLERR;

    #ifdef SHADERS_LOCATION
    auto vtxFileAbsolutePath = std::string(SHADERS_LOCATION) + "/"  + vtxFile;
    auto fragFileAbsolutePath = std::string(SHADERS_LOCATION) + std::string("/") + std::string(fragFile);
    #else
    auto vtxFileAbsolutePath = std::string(vtxFile);
    auto fragFileAbsolutePath = std::string(fragFile);
    #endif

    std::ifstream f(fragFileAbsolutePath);
    if (!f.is_open()) {
        std::cout << "Unable to open fragment shader file " << fragFileAbsolutePath << std::endl;
        return 0;
    }

    std::string source;
    f.seekg(0, std::ios::end);
    source.reserve(f.tellg());
    f.seekg(0, std::ios::beg);
    source.assign(
        (std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    fragShaderId = compileShader(source.c_str(), GL_FRAGMENT_SHADER);

    f = std::ifstream(vtxFileAbsolutePath);
    if (!f.is_open()) {
        printf("Failed to open file %s\n", vtxFileAbsolutePath);
        return 0;
    }

    source = std::string(
        (std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    vtxShaderId = compileShader(source.c_str(), GL_VERTEX_SHADER);

    if (!vtxShaderId || !fragShaderId) {
        printf("opengl: Failed to compile shaders\n");
        glDeleteShader(vtxShaderId); GLERR;
        glDeleteShader(fragShaderId); GLERR;
        return 0;
    }

    // Associate shader with program
    glAttachShader(programId, vtxShaderId); GLERR;
    glAttachShader(programId, fragShaderId); GLERR;

    return programId;
}

int linkProgram(GLuint program) {
    glLinkProgram(program); GLERR;
    glValidateProgram(program); GLERR;

    // Check the status of the compile/link
    GLint status;
    glGetProgramiv(program, GL_VALIDATE_STATUS, &status); GLERR;
    if (status != GL_TRUE) {
        GLint logLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength); GLERR;
        if (logLength > 0) {
            std::string log(logLength, '\0');
            glGetProgramInfoLog(program, logLength, &logLength, log.data()); GLERR;
            printf("opengl program error : %s\n", log.c_str()); GLERR;
        }
        return -1;
    }

    return 0;
}
