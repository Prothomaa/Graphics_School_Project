#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "chair.h"
#include "table.h"



void row(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether)
{
    
    float rotateAngle_X = 0.0;
    float rotateAngle_Y = 0.0;
    float rotateAngle_Z = 0.0;
    float rotateAxis_X = 0.0;
    float rotateAxis_Y = 0.0;
    float rotateAxis_Z = 1.0;
    float translate_X = 0.0;
    float translate_Y = 0.0;
    float translate_Z = 0.0;
    float scale_X = 1.0;
    float scale_Y = 1.0;
    float scale_Z = 1.0;
    
    void table(unsigned int& cubeVAO, Shader & lightingShader, glm::mat4 als);
    void chair(unsigned int& cubeVAO, Shader & lightingShader, glm::mat4 als);
    
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
    

    //chair1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X, translate_Y, -0.6));
    model = alTogether * translateMatrix;
    chair(cubeVAO, lightingShader, model);
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.8, translate_Y, -1.5));

    //table1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 0.3, translate_Y + 0.4, 0.5));
    model = model * translateMatrix;
    table(cubeVAO, lightingShader, model);
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.8, translate_Y, -1.5));

    //chair2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 0.2, translate_Y - 0.4, -1.0 + 2));
    model = model * translateMatrix;
    chair(cubeVAO, lightingShader, model);
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.8, translate_Y, -1.5));

    //table2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 0.3, translate_Y + 0.4, 0.5));
    model = model * translateMatrix;
    table(cubeVAO, lightingShader, model);
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.8, translate_Y, -1.5));

    //chair3
    translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 0.2, translate_Y - 0.4, -1.0 + 2));
    model = model * translateMatrix;
    chair(cubeVAO, lightingShader, model);
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.8, translate_Y, -1.5));

    //table3
    translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 0.3, translate_Y + 0.4, 0.5));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    //model = model * rotateXMatrix * translateMatrix;
    model = model * translateMatrix;
    table(cubeVAO, lightingShader, model);
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.8, translate_Y, -1.5));

    
}
#pragma once
