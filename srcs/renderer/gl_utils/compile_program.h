#pragma once
#define GL_GLEXT_PROTOTYPES

#include <fstream>
#include <string>

#include <GL/gl.h>
#include <GL/glu.h>

GLuint compileShader(const char* source, GLuint shaderType);
GLuint compileProgram(const char* vtxFile, const char* fragFile);
