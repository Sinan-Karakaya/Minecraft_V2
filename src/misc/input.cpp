/*
** EPITECH PROJECT, 2022
** Minecraft clone
** File description:
** handle inputs
*/

#include "system.hpp"

void process_input(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        GLint mode[2];
        glGetIntegerv(GL_POLYGON_MODE, mode);

        if (mode[0] == GL_FILL) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            return;
        } else if (mode[0] == GL_LINE) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            return;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        mixValue = 1.0f;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        mixValue = 0.0f;
    }
}
