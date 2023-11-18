#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"

void seasaw(unsigned int& cubeVAO, Shader& lightingShader , glm::mat4 als, glm::mat4 alr)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    
    //Seat

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05 -1, 0.0, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5f, .2f, .5f));
    //rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotate_Now), glm::vec3(0.0f, 0.0f, 1.0f));
    model = als * alr * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.7215, 0.5254f, 0.0431f);
    //rotate_Now += 1;
    
    //stand
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1, -0.5, -0.85));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2f, .5f, .2f));
    //model = model * translateMatrix * rotateYMatrix;
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.4117, 0.4117f, 0.4117f);

    //base
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, -0.5, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.3f, .2f, .3f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.1, 0.1f, 0.1f);

    //handle
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, -0.5, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.3f, .2f, .3f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.1, 0.1f, 0.1f);
}

#pragma once
