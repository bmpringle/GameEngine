#ifndef INIT_H
#define INIT_H

#include<vector>
#include<GLFW/glfw3.h>
#include<string>

void _glfwInit();

void _glewInit();

int shaderInit();

int texShaderInit();

GLFWwindow* createWindow(GLFWframebuffersizefun callback);

//gauranteed to give a int array in the following format: {VAO, VBOV, VBOC} (if pass true, also passes VBOT)
std::vector<unsigned int> allocateVAO();

#endif 