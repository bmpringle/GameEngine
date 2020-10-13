#ifndef INIT_H
#define INIT_H

#include<vector>
#include<GLFW/glfw3.h>

void _glfwInit();

void _glewInit();

int shaderInit();

GLFWwindow* createWindow(GLFWframebuffersizefun callback);

//gauranteed to give a int array in the following format: {VAO, VBOV, VBOC}
std::vector<unsigned int> allocateVAO();

#endif 