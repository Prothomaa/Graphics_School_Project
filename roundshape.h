#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"

void roundshape(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether)
{

    float rotateAngle_Y = 0.0;


    glm::mat4 rotateY = glm::mat4(1.0f);
    glm::mat4 rotateZ = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    //base
    for (float i = 0.0f; i < 360.0f; i += 2.50f) {
        //Center

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, 0.6, 0.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + i), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.75, 0.15, 0.75));
        model = alTogether * translateMatrix * rotateYMatrix * scaleMatrix;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.8078f, .8196f); //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
        //glBindVertexArray(VAO);

    }

    for (float i = 0.0f; i < 360.0f; i += 2.50f) {
        //Center

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, -0.05, 0.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + i), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 0.15, 0.25));
        model = alTogether * translateMatrix * rotateYMatrix * scaleMatrix;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.5019f, 0.5019f); //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
        //glBindVertexArray(VAO);

    }

    for (float i = 0.0f; i < 360.0f; i += 2.50f) {
        //Center

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, -0.05, 0.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + i), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.08, 0.75, 0.08));
        model = alTogether * translateMatrix * rotateYMatrix * scaleMatrix;
        drawCube(cubeVAO, lightingShader, model, 1.0, 1.0, 0.0); //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
        //glBindVertexArray(VAO);

    }


    /*
    //leg 1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, 0.7, 0.0));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(30.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, -0.85, 0.05));
    model = alTogether * translateMatrix * rotateZMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0, 0.0);

    //leg 2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, 0.7, 0.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, -0.85, 0.05));
    model = alTogether * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0, 0.0);
    //leg 3
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, 0.7, 0.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(-1.0f, 0.0f, -1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, -0.85, 0.05));
    model = alTogether * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0, 0.0);
    //leg 4
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, 0.7, 0.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(30.0f), glm::vec3(-1.0f, 0.0f, -1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, -0.85, 0.05));
    model = alTogether * translateMatrix * rotateYMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, 1.0, 0.0);
    */

}

#pragma once
