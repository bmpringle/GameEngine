#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include"Init.h"
#include"World.h"
#include"Tiles.h"
#include"Entity.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}  

auto start = std::chrono::system_clock::now();

void processInput(GLFWwindow *window, World* world) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now()-start;
    
    if(elapsed_seconds.count() > 0.25) {
        if((glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) ||
           (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)) {
            world->getPlayer()->move(0);  
            start = std::chrono::system_clock::now();       
        }
        if((glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) ||
           (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)) {
            world->getPlayer()->move(2);  
            start = std::chrono::system_clock::now();       
        }
        if((glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) ||
           (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)) {
            world->getPlayer()->move(1);  
            start = std::chrono::system_clock::now();       
        }
        if((glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) ||
           (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)) {
            world->getPlayer()->move(3);  
            start = std::chrono::system_clock::now();       
        }
    }
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE) {
        world->getPlayer()->interact();
    } 
}

int main(int argc, char** argv) {   
    _glfwInit();

    GLFWwindow* window = createWindow(framebuffer_size_callback);

    glfwSetWindowSize(window, 799, 600);

    _glewInit();

    if(window == nullptr) {
        return -1;
    }

    glViewport(0, 0, 800, 600);

    glEnable(GL_DEPTH_TEST);  

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    int program = shaderInit();
    int texprogram = texShaderInit();

    Tiles::tileInit();

    World world = World();

    world.parseWorld("world.txt");

    while(!glfwWindowShouldClose(window)) {
        processInput(window, &world);
        glfwSwapBuffers(window);
        _glfwFixMacOSWindow(window);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        world.render(program, texprogram);

        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}
