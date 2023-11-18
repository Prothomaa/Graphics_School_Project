#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"


void walls(unsigned int& cubeVAO, unsigned int& cubeVAO4, Shader& lightingShader, glm::mat4 alTogether)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    //floor
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, -0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(33, .5, 10));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5647, 0.6509f, 0.5176f);
    /*
    //back wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, -0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(13, 6, 0.25));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5647, 0.6509f, 0.5176f);
    */
    /*
    //front wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, -0.5, 3.5));

    scaleMatrix = glm::scale(identityMatrix, glm::vec3(13, 6, 0.25));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5647, 0.6509f, 0.5176f);
    


    //left wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6, -0.45, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 8, 25));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.0f, 0.125f);
    
    //right wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, -0.45, 6));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 8, -25));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.0f, 0.125f);
    */
    
    //ceiling
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, 6 - 0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(22.2, .5, 10));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.8470, 0.7490, 0.8470);

    //ceiling 2nd floor
    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.6, 11.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.1, 3.5, 10));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCubeP(cubeVAO4, lightingShader, model, 1.0f, .5f, .0f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.6, 11.5, 3.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.1, 3.5, 10));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = alTogether * translateMatrix* rotateYMatrix * scaleMatrix;
    drawCubeP(cubeVAO4, lightingShader, model, 1.0f, .5f, .0f);

    //left wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, -0.45, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 6, 10));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5647, 0.6509f, 0.5176f);

    //left wall 2nd floor
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, 5.45, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 6, 10));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5647, 0.6509f, 0.5176f);
    

}

#pragma once
