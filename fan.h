#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"

void fan(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als)
{
    float rotateAngle_Y = 0.0;


    glm::mat4 rotateY = glm::mat4(1.0f);
    glm::mat4 rotateZ = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;



    for (float i = 0.0f; i < 360.0f; i += 2.50f) {
        //Center

        translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.09f, 4.09f, 0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + i), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.35, 0.25, 0.35));
        model = als * translateMatrix * rotateYMatrix * scaleMatrix;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.8078f, .8196f); //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
        //glBindVertexArray(VAO);

    }
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 52.5f, 0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 0.08f, 0.5f));
    model = als * scaleMatrix * translateMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.6f, 0.125f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(.0f, 52.5f, -.6));//,translate_X, translate_Y, translate_Z
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 0.08f, 0.5f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = als * rotateYMatrix * scaleMatrix * translateMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.6f, 0.125f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 52.5f, -0.5f));//,
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 0.08f, 0.5f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(225.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = als * rotateYMatrix * scaleMatrix * translateMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.6f, 0.125f);
}
#pragma once
