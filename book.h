#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"

void book(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.55, -1.3, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.15f, .6f, .6f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.38, -1.3, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.12f, .6f, .6f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.0, 1.0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.21, -1.3, -6.5));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.7098, .4627f, 0.7098f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.04, -1.3, -6.5));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.0, .0f, 1.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.9, -1.3, -6.5));
    model = als * translateMatrix * glm::scale(identityMatrix, glm::vec3(.12f, .7f, .6f));
    drawCube(cubeVAO, lightingShader, model, 0.0, 1.0f, 1.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.0, -1.3, -6.5));
    model = als * translateMatrix * glm::rotate(identityMatrix, glm::radians(30.0f), glm::vec3(0.0f, 0.0f, 1.0f)) * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.0f, 0.4980f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.7, -1.3, -6.5));
    model = als * translateMatrix * glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::scale(identityMatrix, glm::vec3(.12f, .8f, .6f));
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.8f, 0.8f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.8, -1.3, -6.5));
    model = als * translateMatrix * glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f)) * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.0, 1.0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.6, -1.3, -6.5));
    model = als * translateMatrix * glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::scale(identityMatrix, glm::vec3(.12f, .8f, .6f));;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.0, -1.3, -6.5));
    model = als * translateMatrix * glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::scale(identityMatrix, glm::vec3(.12f, .65f, .6f));
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.7, -1.2, -6.5));
    model = als * translateMatrix * glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::scale(identityMatrix, glm::vec3(.12f, .65f, .6f));
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.0f, 1.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.5, -1.08, -6.5));
    model = als * translateMatrix * glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::scale(identityMatrix, glm::vec3(.12f, .65f, .6f));
    drawCube(cubeVAO, lightingShader, model, 0.0, 0.8f, 0.8f);

}
#pragma once
