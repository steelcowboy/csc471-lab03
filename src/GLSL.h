//
//    Many useful helper functions for GLSL shaders - gleaned from various sources including orange book
//    Created by zwood on 2/21/10.
//    Modified by sueda 10/15/15.
//

#pragma once
#ifndef LAB471_GLSL_H_INCLUDED
#define LAB471_GLSL_H_INCLUDED

#include <glad/glad.h>

///////////////////////////////////////////////////////////////////////////////
// For printing out the current file and line number                         //
///////////////////////////////////////////////////////////////////////////////
#include <string>

#define GET_FILE_LINE (std::string(__FILE__) + ":" + std::to_string(__LINE__)).c_str()
///////////////////////////////////////////////////////////////////////////////

namespace GLSL
{

	void checkError(const char *str = 0);
	void printProgramInfoLog(GLuint program);
	void printShaderInfoLog(GLuint shader);
	void checkVersion();
	GLint getAttribLocation(const GLuint program, const char varname[], bool verbose = true);
	GLint getUniformLocation(const GLuint program, const char varname[], bool verbose = true);
	void enableVertexAttribArray(const GLint handle);
	void disableVertexAttribArray(const GLint handle);
	void vertexAttribPointer(const GLint handle, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
}

#endif // LAB471_GLSL_H_INCLUDED
