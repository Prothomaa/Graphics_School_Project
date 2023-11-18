#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"


void stair(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(16.5, -0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5, .5, .5));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.8235, 0.4117f, 0.1176f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(16.5, 0.0, -7.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5, .5, .5));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5450, 0.2705f, 0.0745f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(16.5, 0.5, -7.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5, .5, .5));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.8235, 0.4117f, 0.1176f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(16.5, 1.0, -8.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5, .5, .5));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5450, 0.2705f, 0.0745f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(16.5, 1.5, -8.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5, .5, .5));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.8235, 0.4117f, 0.1176f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(16.5, 2.0, -9.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5, .5, .5));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5450, 0.2705f, 0.0745f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(16.5, 2.5, -9.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5, .5, .5));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.8235, 0.4117f, 0.1176f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(16.5, 3.0, -10.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5, .5, .5));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5450, 0.2705f, 0.0745f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(16.5, 3.5, -12.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5, .2, 2.5));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.8235, 0.4117f, 0.1176f);

   
}
#pragma once
