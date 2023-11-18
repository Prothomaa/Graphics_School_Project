#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "pillow.h"

void merry(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether, glm::mat4 alr)
{

    float rotateAngle_Y = 0.0;


    glm::mat4 rotateY = glm::mat4(1.0f);
    glm::mat4 rotateZ = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, translateMatrix2, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model, model22, model33;

    translateMatrix2 = glm::translate(identityMatrix, glm::vec3(2.05, 4.0, -0.9));

    //base
    for (float i = 0.0f; i < 360.0f; i += 2.50f) {
        //Center

        translateMatrix = glm::translate(identityMatrix, glm::vec3(2.05, -1.0, -0.9));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + i), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 0.15, 1.0));
        model = alTogether * translateMatrix * alr * rotateYMatrix * scaleMatrix;
        drawCube(cubeVAO, lightingShader, model, 0.7372f, 0.5607f, 0.5607f); 

    }
    model22 =  model ;

    //stand
    for (float i = 0.0f; i < 360.0f; i += 2.50f) {
        //Center

        translateMatrix = glm::translate(identityMatrix, glm::vec3(2.05, -1.0, -0.9));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + i), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.05f, 1.5f, .05f));
        model = alTogether * translateMatrix *alr * rotateYMatrix * scaleMatrix;
        
        drawCube(cubeVAO, lightingShader, model, 0.8588, 0.4392f, 0.5764f);
    }
    
    
    
    /*
    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.5, 0.35, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 2.9f, .1f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = alTogether *  translateMatrix *  rotateZMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5450, 0.2705f, 0.0745f);
    */

    //translateMatrix = glm::translate(identityMatrix, glm::vec3(3.35, 0.45, -0.9));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0, 0.45, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 9.1f, .1f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = model22 * alr * translateMatrix *  rotateZMatrix * scaleMatrix;
    model33 = model;
    drawCube(cubeVAO, lightingShader, model, 0.7803, 0.0823f, 0.5215f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.12, 0.45, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 9.1f, .1f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = model22 * alr * translateMatrix *  rotateZMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.7803, 0.0823f, 0.5215f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.12, 0.45, 0.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 9.1f, .1f));
    model = model22 * alr * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.7803, 0.0823f, 0.5215f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.9, 0.45, .9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 9.1f, .1f));
    model = model22 * alr * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.7803, 0.0823f, 0.5215f);
    
    //
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0, 9.5, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.45f, .1f, .1f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(40.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = model22 * alr * translateMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.7803, 0.0823f, 0.5215f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.12, 9.5, -0.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.45f, .1f, .1f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(140.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = model22 * alr * translateMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.7803, 0.0823f, 0.5215f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.08, 9.5, 0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.45f, .1f, .1f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(215.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = model22 * alr * translateMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.7803, 0.0823f, 0.5215f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.99, 9.5, .9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.45f, .1f, .1f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = model22 * alr * translateMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.7803, 0.0823f, 0.5215f);


    
}
#pragma once

#pragma once
