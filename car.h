#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"

void car(unsigned int& cubeVAO, unsigned int& cubeVAO4, unsigned int& cubeVAO5, int size, Shader& lightingShader, glm::mat4 als, glm::mat4 alr)
{

    float rotateAngle_Y = 0.0;


    glm::mat4 rotateY = glm::mat4(1.0f);
    glm::mat4 rotateZ = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    //base
    for (float i = 0.0f; i < 360.0f; i += 2.50f) {
        //Center

        translateMatrix = glm::translate(identityMatrix, glm::vec3(2.8, 1.3, 1.9));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + i), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.35, 0.35, 0.35));
        model = als * translateMatrix * alr * rotateYMatrix * scaleMatrix;
        drawCube(cubeVAO, lightingShader, model, .0, 0.8078f, .8196f); //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
        //glBindVertexArray(VAO);
    }
    for (float i = 0.0f; i < 360.0f; i += 2.50f) {
        //Center

        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.8, 1.3, 1.9));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + i), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.35, 0.35, 0.35));
        model = als * translateMatrix * alr * rotateYMatrix * scaleMatrix;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.8078f, .8196f); //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
        //glBindVertexArray(VAO);

    }
    for (float i = 0.0f; i < 360.0f; i += 2.50f) {
        //Center

        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.8, 1.3, -1.2));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + i), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.35, 0.35, 0.35));
        model = als * translateMatrix * alr * rotateYMatrix * scaleMatrix;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.8078f, .8196f); //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
        //glBindVertexArray(VAO);

    }
    for (float i = 0.0f; i < 360.0f; i += 2.50f) {
        //Center

        translateMatrix = glm::translate(identityMatrix, glm::vec3(2.8, 1.3, -1.2));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + i), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.35, 0.35, 0.35));
        model = als * translateMatrix * alr * rotateYMatrix * scaleMatrix;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.8078f, .8196f); //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
        //glBindVertexArray(VAO);

    }
    /*
    //Cylinder Circle code start
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.8, 1.3, 1.9));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.20, 0.20, 0.20));
    drawCubeCy(cubeVAO5, lightingShader, size, als * translateMatrix  * rotateYMatrix * scaleMatrix, 1.0, 1.0, .0);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.8, 1.3, 1.9));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.20, 0.20, 0.20));
    drawCubeCy(cubeVAO5, lightingShader, size, als * translateMatrix * rotateYMatrix * scaleMatrix, 1.0, 1.0, .0);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.8, 1.3, -1.2));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.20, 0.20, 0.20));
    drawCubeCy(cubeVAO5, lightingShader, size, als * translateMatrix * rotateYMatrix * scaleMatrix, 1.0, 1.0, .0);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.8, 1.3, -1.2));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(.0f, .0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.20, 0.20, 0.20));
    drawCubeCy(cubeVAO5, lightingShader, size, als * translateMatrix * rotateYMatrix * scaleMatrix, 1.0, 1.0, .0);
    */
    ///
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.8, 1.3, -1.2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.5f, 1.0f, 2.8f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 1.0, .0, 1.0);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.8, 1.3, 1.65));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 3.0f, 2.8f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = als * translateMatrix * scaleMatrix;
    drawCubeP(cubeVAO4, lightingShader, als * translateMatrix * rotateYMatrix * scaleMatrix, 1.0, 1.0, 1.0);

}
#pragma once
