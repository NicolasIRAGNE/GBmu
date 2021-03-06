#pragma once

#include <fstream>
#include <string>

#include <GL/glew.h>

GLuint compileShader(const char* source, GLuint shaderType);
GLuint compileProgram(const char* vtxFile, const char* fragFile);
int linkProgram(GLuint program);
