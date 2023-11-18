#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"

void clock(unsigned int& cubeVAO, unsigned int& cubeVAO5, int size, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.0, -2.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.20, 0.20, 0.01));
    drawCubeCy(cubeVAO5, lightingShader, size, als * translateMatrix * rotateYMatrix * scaleMatrix, 1.0, 1.0, .0);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.0, -2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.08f, .5f, .04f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, .0, .0, .0);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.0, -2.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.08f, .4f, .08f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, .0, .0, .0);
}
#pragma once
