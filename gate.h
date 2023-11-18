#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"

void gate(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    //Sofa Seat
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.8, 0.3, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2f, 5.5f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0, 1.0);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.2, 0.3, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2f, 5.5f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.7529, 0.7529, 0.7529);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.6, 0.3, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2f, 5.5f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0, 1.0);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1, 0.3, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2f, 5.5f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.7529, 0.7529, 0.7529);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(.4, 0.3, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2f, 5.5f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0, 1.0);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-.2, 0.3, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2f, 5.5f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.7529, 0.7529, 0.7529);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-.8, 0.3, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2f, 5.5f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0, 1.0);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.25, 5.0, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2f, 4.3f, 0.5f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, .0f, 1.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0, 1.0);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.25, 1.0, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2f, 4.3f, 0.5f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, .0f, 1.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0, 1.0);


}
#pragma once
