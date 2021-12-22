#pragma once

#define GLERR do {\
        GLuint glerr;\
        while((glerr = glGetError()) != GL_NO_ERROR)\
            fprintf(stderr, "%s:%d glGetError() = 0x%04x\n", __FILE__, __LINE__, glerr);\
    } while (0)
