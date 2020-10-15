#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include"Init.h"
#include"World.h"
#include<png.h>
#include"Tiles.h"
#include"Entity.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}  

void processInput(GLFWwindow *window, World* world) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        world->getEntitiesPointer()->at(0).move(0);

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        world->getEntitiesPointer()->at(0).move(2);

    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        world->getEntitiesPointer()->at(0).move(1);

    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        world->getEntitiesPointer()->at(0).move(3);
}

int main(int argc, char** argv) {   
    _glfwInit();

    GLFWwindow* window = createWindow(framebuffer_size_callback);

    _glewInit();

    if(window == nullptr) {
        return -1;
    }

    glViewport(0, 0, 800, 600);

    glEnable(GL_DEPTH_TEST);  

    int program = shaderInit();
    int texprogram = texShaderInit();

    Tiles::tileInit();

    float player_vertices[] = {
        0.4, 0.15, -1,
        0.6, 0.15, -1,
        0.6, 0.85, -1,
        0.4, 0.15, -1,
        0.4, 0.85, -1,
        0.6, 0.85, -1
    };

    World world = World();
    Entity player = Entity(0, 0, "player", player_vertices);
    player.loadTexture("player.png");
    
    world.parseWorld("world.txt");
    world.addEntity(player);

    while(!glfwWindowShouldClose(window)) {
        processInput(window, &world);
        glfwSwapBuffers(window);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        world.render(program, texprogram);

        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}
