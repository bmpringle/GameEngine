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

auto start_logic_timer = std::chrono::system_clock::now();

void update(World* world) {
    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now()-start_logic_timer;
    if(elapsed_seconds.count() > 0.05) {
        start_logic_timer = std::chrono::system_clock::now();
        world->update();
    }
}

auto start_input_timer = std::chrono::system_clock::now();

void processInput(GLFWwindow *window, World* world) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now()-start_input_timer;
    
    if(elapsed_seconds.count() > 0.25) {
        if((glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) ||
           (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)) {
            world->getPlayer()->move(Entity::EDIR_UP);  
            start_input_timer = std::chrono::system_clock::now();       
        }
        if((glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) ||
           (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)) {
            world->getPlayer()->move(Entity::EDIR_LEFT);  
            start_input_timer = std::chrono::system_clock::now();       
        }
        if((glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) ||
           (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)) {
            world->getPlayer()->move(Entity::EDIR_DOWN);  
            start_input_timer = std::chrono::system_clock::now();       
        }
        if((glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) ||
           (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)) {
            world->getPlayer()->move(Entity::EDIR_RIGHT);  
            start_input_timer = std::chrono::system_clock::now();       
        }

        if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS) {
            world->cycleTextOffset();
            start_input_timer = std::chrono::system_clock::now();
        }
    }
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
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
        update(&world);
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
