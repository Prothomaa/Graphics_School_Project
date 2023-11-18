#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
void chair(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    //Sofa Seat
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.3, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5f, .2f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.6f, 0.125f);

    //Sofa Head
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.3 + 0.5 * 0.2, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5f, .5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.0, 0.5019f, 0.5019f);

    //Sofa leg1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.3 + 0.5 * 0.2, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.025f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.0, 0.5019f, 0.5019f);

    //Sofa leg3
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.3 + 0.5 * 0.2, -0.9 + 0.5 - 0.05));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.025f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.0, 0.5019f, 0.5019f);

    //Sofa leg2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.5 - 0.025, 0.3 + 0.5 * 0.2, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.025f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.0, 0.5019f, 0.5019f);

    //Sofa leg4
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.5 - 0.025, 0.3 + 0.5 * 0.2, -0.9 + 0.5 - 0.05));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.025f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.0, 0.5019f, 0.5019f);



}
#pragma once
