/*
** PERSONNAL PROJECT, 2022
** minecraft clone
** File description:
** class SHADER
*/

#pragma once

#include <glad/glad.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Shader {
public:
    // Program ID
    unsigned int ID;

    // constructor reads and builds the shader
    Shader(const char *vertexPath, const char *fragmentPath);
    // use/activate the shader
    void use();
    // Utility uniform location
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};