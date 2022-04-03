/*
** PERSONNAL PROJECT, 2022
** minecraft_V2
** File description:
** matrices trans
*/

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "system.hpp"

glm::mat4 trans_vertices(void)
{
    glm::mat4 trans = glm::mat4(1.f);
    
    trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
    trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.f));

    return trans;
}