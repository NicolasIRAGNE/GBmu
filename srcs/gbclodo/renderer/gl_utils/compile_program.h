#pragma once

#include <GL/glew.h>
#include <fstream>
#include <string>

GLuint compileShader(const char* source, GLuint shaderType);
GLuint compileProgram(const char* vtxFile, const char* fragFile);
int linkProgram(GLuint program);
