#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"

void swing(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als, glm::mat4 alr)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;


    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.5, -3.5, 10.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2, .2, 4));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.098, 0.098f, 0.4392f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(12.5, -3.5, 10.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2, .2, 4));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.098, 0.098f, 0.4392f);

    //
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.5, -3.5, 12.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2, 6, .2));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.098, 0.098f, 0.4392f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(12.5, -3.5, 12.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2, 6, .2));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.098, 0.098f, 0.4392f);

    //
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.5, 2.5, 11.2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.2, .9, 1.9));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.098, 0.098f, 0.4392f);

    //dori 1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.8, -2.5, 12.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1, 5.4, .1));
    model = als * alr * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.2745, 0.5098f, 0.7058f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(9.3, -2.5, 12.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1, 5.4, .1));
    model = als * alr * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.2745, 0.5098f, 0.7058f);

    //dori 2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(10.2, -2.5, 12.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1, 5.4, .1));
    model = als * alr * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.2745, 0.5098f, 0.7058f);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(11.7, -2.5, 12.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1, 5.4, .1));
    model = als * alr * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.2745, 0.5098f, 0.7058f);

    //Sofa Seat1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.75, -2.5, 11.75));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.7f, .2f, 1.5f));
    model = als * alr * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5294, 0.8078f, 0.9215f);

    //Sofa Seat2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(10.15, -2.5, 11.75));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.7f, .2f, 1.5f));
    model = als * alr * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.5294, 0.8078f, 0.9215f);
}
#pragma once