/*
** EPITECH PROJECT, 2022
** Learning
** File description:
** main file
*/

#include <stdio.h>
#include <iostream>

#include "system.hpp"

static void init(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

void framebuffer_size_callback(GLFWwindow *window, int w, int h)
{
    glViewport(0, 0, w, h);
}

float mixValue;

static void setup(void)
{
    GLFWwindow *window = glfwCreateWindow(1920, 1080, "Minecraft_V2", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Couldn't open window\n");
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed to init GLAD\n");
        return;
    }
    glViewport(0, 0, 1920, 1080);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    mixValue = 0.2f;

    main_loop(window);
}

int main(void)
{
    init();
    setup();
    return 0;
}