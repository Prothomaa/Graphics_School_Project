#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "chair.h"
#include "table.h"



void computerLab(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether)
{
    void row(unsigned int& cubeVAO, Shader & lightingShader, glm::mat4 als);

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, -0.6));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 1.0, 1.5));
    model = alTogether * translateMatrix * scaleMatrix;
    row(cubeVAO, lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, .8, -1.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.1, .7, .1));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(20.0f), glm::vec3(1.0f, .0f, .0f));
    model = alTogether * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.1254f, 0.1254f, 0.1254f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, .9, -2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.1, .1, .6));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.1254f, 0.1254f, 0.1254f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, .8, .7));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.1, .7, .1));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(20.0f), glm::vec3(1.0f, .0f, .0f));
    model = alTogether * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.1254f, 0.1254f, 0.1254f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, .9, .2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.1, .1, .6));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.1254f, 0.1254f, 0.1254f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, .8, 2.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.1, .7, .1));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(20.0f), glm::vec3(1.0f, .0f, .0f));
    model = alTogether * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.1254f, 0.1254f, 0.1254f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, .9, 2.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.1, .1, .6));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.1254f, 0.1254f, 0.1254f);
}
#pragma once

