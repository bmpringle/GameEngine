#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include"Init.h"
#include"World.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}  

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main(int argc, char** argv) {
    
    _glfwInit();

    GLFWwindow* window = createWindow(framebuffer_size_callback);

    _glewInit();

    if(window == nullptr) {
        return -1;
    }

    glViewport(0, 0, 800, 600);

    int program = shaderInit();

    World w = World();
    w.addTile(Tile(0, 0));
    w.addTile(Tile(1, 0));
    w.addTile(Tile(2, 0));
    w.addTile(Tile(-1, 0));
    w.addTile(Tile(-2, 0));

    while(!glfwWindowShouldClose(window)) {
        processInput(window);
        glfwSwapBuffers(window);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        w.renderTiles(program);

        glUseProgram(program); 


        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}
