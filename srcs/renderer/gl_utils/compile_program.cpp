#include "compile_program.h"

#include <fstream>
#include <string>
#define checkGl if (glGetError()){ printf("LINE: %d\n", __LINE__); }


GLuint compileShader(const char* source, GLuint shaderType)
{
    GLuint shader_id = glCreateShader(shaderType);
    glShaderSource(shader_id, 1, &source, NULL);checkGl
    glCompileShader(shader_id);checkGl

    GLint shaderCompiled;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &shaderCompiled);
    if (shaderCompiled != GL_TRUE) {
        GLint logLength;
        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &logLength);
        if (logLength > 0) {
            std::string log(logLength, '\0');
            glGetShaderInfoLog(shader_id, logLength, &logLength, log.data());
            printf("opengl compile shader error : %s\n", log.c_str());
        }
        glDeleteShader(shader_id);checkGl
        return 0;
    }
checkGl
    return shader_id;
}

GLuint compileProgram(const char* vtxFile, const char* fragFile)
{
    GLuint programId = 0;
    GLuint vtxShaderId, fragShaderId;
    programId = glCreateProgram();checkGl

    std::ifstream f(fragFile);
    if (!f.is_open()) {
        printf("Failed to open file %s\n", fragFile);
        return 0;
    }
checkGl
    std::string source;
    f.seekg(0, std::ios::end);
    source.reserve(f.tellg());
    f.seekg(0, std::ios::beg);
    source.assign(
        (std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    fragShaderId = compileShader(source.c_str(), GL_FRAGMENT_SHADER);

    f = std::ifstream(vtxFile);
    if (!f.is_open()) {
        printf("Failed to open file %s\n", vtxFile);checkGl
        return 0;
    }

    source = std::string(
        (std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    vtxShaderId = compileShader(source.c_str(), GL_VERTEX_SHADER);

    if (!vtxShaderId || !fragShaderId) {
        printf("opengl: Failed to compile shaders\n");checkGl
        glDeleteShader(vtxShaderId);checkGl
        glDeleteShader(fragShaderId);checkGl
        return 0;
    }

    // Associate shader with program
    glAttachShader(programId, vtxShaderId);checkGl
    glAttachShader(programId, fragShaderId);checkGl
    glLinkProgram(programId);checkGl
    glValidateProgram(programId);checkGl

    // Check the status of the compile/link
    GLint status;
    glGetProgramiv(programId, GL_VALIDATE_STATUS, &status);checkGl
    if (status != GL_TRUE) {
        GLint logLength;
        glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &logLength);checkGl
        if (logLength > 0) {
            std::string log(logLength, '\0');
            glGetProgramInfoLog(programId, logLength, &logLength, log.data());checkGl
            printf("opengl program error : %s\n", log.c_str());
        }
        programId = 0;
    }

    return programId;
}
