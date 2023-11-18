#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"

void slipper(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    //stand
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.05, -.8, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, 4.0f, .5f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.1, 0.1f, 0.1f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.05, 3.2, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.8f, .1f, .8f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.05, -1.0, -0.9));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 6.0f, .8f));
    model = als * translateMatrix* rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.05, -1.0, -1.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.25f, 6.0f, .1f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, .0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.05, -1.0, -0.1));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.25f, 6.0f, .1f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, .0f, 0.0f);
    //
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-.5, -1.0, -0.1));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 5.0f, .1f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, .0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-.5, -1.0, -0.9));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 5.0f, .1f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, .0f, 0.0f);
    //stair nich theke
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-.2, -.5, -0.9));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, .1f, .8f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, .0f, .0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(.1, -.0, -0.9));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, .1f, .8f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, .0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(.4, .5, -0.9));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, .1f, .8f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, .0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(.7, 1.0, -0.9));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, .1f, .8f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, .0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(.95, 1.5, -0.9));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, .1f, .8f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, .0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.25, 2.0, -0.9));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, .1f, .8f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, .0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.5, 2.5, -0.9));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, .1f, .8f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, .0f, 0.0f);

}

#pragma once
