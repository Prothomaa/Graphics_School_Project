#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"

void sofa(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;


    //Sofa Seat
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.1 + 0.15, 0.875));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .125f, 0.55f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.0, 0.8078f, .8196f);

    //Sofa Head
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.1 + 0.5 * 0.2, 0.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .65f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.0, 0.5019f, 0.5019f);

    //Sofa Head frame
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.15, 0.1 + 0.5 * 0.2, 0.7));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, .75f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);

    //frame
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05 - 0.1, 0.1, 0.72));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.15f, .25f, 0.7f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);

    //Sofa leg1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.1 + 0.5 * 0.2, 0.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);

    //Sofa leg3
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.1 + 0.5 * 0.2, 0.8 + 0.5 - 0.05));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);

    //Sofa leg2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.05 - 0.25, 0.1 + 0.5 * 0.2, 0.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);

    //Sofa leg4
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.05 - 0.025, 0.1 + 0.5 * 0.2, 0.8 + 0.5 - 0.05));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);
}

#pragma once

