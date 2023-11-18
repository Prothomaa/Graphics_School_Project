#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "book.h"

void library(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    //vertical wall er pashe
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.7, -1.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 4.4f, 1.0f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.8235, 0.4117f, 0.1176f);

    //vertical
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, -1.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 4.4f, 1.0f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.8235, 0.4117f, 0.1176f);

    //horizontal nich theke
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.7, -1.3, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, .06f, 1.0f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5450, 0.2705f, 0.0745f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.7, -0.3, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, .06f, 1.0f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5450, 0.2705f, 0.0745f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.7, 0.7, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, .06f, 1.0f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5450, 0.2705f, 0.0745f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.7, 1.7, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, .06f, 1.0f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5450, 0.2705f, 0.0745f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.7, 2.7, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, .06f, 1.0f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5450, 0.2705f, 0.0745f);
    //ekdom nicher tay
    book(cubeVAO, lightingShader, als);
    // ekdom upor tay
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 3.1, 0.5));
    book(cubeVAO, lightingShader, als * translateMatrix);
    //upor theke 2nd row
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.5, 2.1, -12.5));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    book(cubeVAO, lightingShader, als * translateMatrix * rotateYMatrix);

    // nich theke 2nd row
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.0, -0.3, -6.5));
    model = als * translateMatrix * glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::scale(identityMatrix, glm::vec3(.12f, .8f, .6f));;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.4, -0.3, -6.5));
    model = als * translateMatrix * glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::scale(identityMatrix, glm::vec3(.12f, .65f, .6f));
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0f, 0.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0, -0.2, -6.5));
    model = als * translateMatrix * glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::scale(identityMatrix, glm::vec3(.12f, .65f, .6f));
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.0f, 1.0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, -0.2, -6.5));
    model = als * translateMatrix * glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::scale(identityMatrix, glm::vec3(.12f, .65f, .6f));
    drawCube(cubeVAO, lightingShader, model, 0.0, 0.8f, 0.8f);

}
#pragma once
