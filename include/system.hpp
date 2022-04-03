/*
** EPITECH PROJECT, 2022
** learning OpenGL
** File description:
** system header
*/

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

extern float mixValue;

int main_loop(GLFWwindow *window);
void process_input(GLFWwindow *window);
GLuint compile_shaders(void);
GLuint vertex_setup(float *vertices);
GLuint load_texture(char *filepath);
glm::mat4 trans_vertices(void);
