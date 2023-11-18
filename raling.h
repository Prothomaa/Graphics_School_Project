#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"

void raling(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    //Sofa Seat
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.3, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(22.0f, .10f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0, 1.0);
}

#pragma once
