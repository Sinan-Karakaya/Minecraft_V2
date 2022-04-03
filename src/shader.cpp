/*
** EPITECH PROJECT, 2022
** minecraft clone
** File description:
** shader compilation
*/

#include <iostream>

#include "system.hpp"
#include "shader.hpp"



Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    // Retrieve the fragment source code from filepath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // Ensure ifstream objects can throw exceptions
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        // Open file
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer content into stream
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    } catch (std::ifstream::failure e) {
        fprintf(stderr, "ERROR: SHADER: FILE_NOT_SUCCESSFULLY_READ\n");
    }
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();

    // Now we compile the shaders
    GLuint vertex, fragment;
    int success;
    char infoLog[512];

    //vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    // Print compile errors
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        fprintf(stderr, "ERROR: SHADER: VERTEX: COMPILATION_FAILED:\n%s", infoLog);
    }
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    // Print compile errors
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        fprintf(stderr, "ERROR: SHADER: FRAGMENT: COMPILATION_FAILED:\n%s", infoLog);
    }
    Shader::ID = glCreateProgram();
    glAttachShader(Shader::ID, vertex);
    glAttachShader(Shader::ID, fragment);
    glLinkProgram(Shader::ID);
    // Print linking errors if any
    glGetProgramiv(Shader::ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(Shader::ID, 512, NULL, infoLog);
        fprintf(stderr, "ERROR: SHADER: PROGRAM: LINKING_FAILED:\n%s", infoLog);
    }
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(Shader::ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(Shader::ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(Shader::ID, name.c_str()), value);
}

void Shader::use()
{
    glUseProgram(Shader::ID);
}

// GLuint compile_shaders(void)
// {
//     // Compile vertex shader
//     GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
//     glShaderSource(vertex_shader, 1, &vertex_shader_src, NULL);
//     glCompileShader(vertex_shader);
//     // Check errors during compilation
//     int success;
//     char infoLog[512];
//     glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
//     if (!success) {
//         glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
//         std::cout << "ERROR: SHADER: VERTEX: COMPILATION FAILED:\n" << infoLog << std::endl;
//     }


//     // Compile Fragment shaders
//     GLuint frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
//     glShaderSource(frag_shader, 1, &frag_shader_src, NULL);
//     glCompileShader(frag_shader);
//     // Check errors during compilation
//     glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &success);
//     if (!success) {
//         glGetShaderInfoLog(frag_shader, 512, NULL, infoLog);
//         std::cout << "ERROR: SHADER: FRAGMENT: COMPILATION FAILED:\n" << infoLog << std::endl;
//     }

//     // Program shader
//     GLuint program_shader = glCreateProgram();
//     glAttachShader(program_shader, vertex_shader);
//     glAttachShader(program_shader, frag_shader);
//     glLinkProgram(program_shader);
//     glGetProgramiv(program_shader, GL_LINK_STATUS, &success);
//     if (!success) {
//         glGetProgramInfoLog(program_shader, 512, NULL, infoLog);
//         std::cout << "ERROR: SHADER: LINK: COMPILATION FAILED:\n" << infoLog << std::endl;
//     }
//     glUseProgram(program_shader);
//     glDeleteShader(vertex_shader);
//     glDeleteShader(frag_shader);

//     return program_shader;
// }
