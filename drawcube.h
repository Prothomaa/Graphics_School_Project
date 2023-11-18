#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
void drawCube(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 model = glm::mat4(1.0f), float r = 1.0f, float g = 1.0f, float b = 1.0f)
{
    lightingShader.use(); //activate shader
    //setting the materialistic properties of the object.
    lightingShader.setVec3("material.ambient", glm::vec3(r, g, b)); //setting ambient and diffuse same because, light will hit differently at different place, so if we reduce ambient here, the net calculation after applying lighting will make it almost zero. this is why, the ambient and diffuse is kept same. reducing it once instead of reducing it twice, which will make it appear almost black 
    lightingShader.setVec3("material.diffuse", glm::vec3(r, g, b)); //original color
    lightingShader.setVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f)); //specular
    lightingShader.setFloat("material.shininess", 32.0f); //shining

    lightingShader.setMat4("model", model); //setting the object, sending the value in vertex shader. the calculation of transformation will be applied before calling the function

    glBindVertexArray(cubeVAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
void drawCubeX(unsigned int& cubeVAO2, Shader& lightingShader, glm::mat4 model = glm::mat4(1.0f), float r = 1.0f, float g = 1.0f, float b = 1.0f)
{
    lightingShader.use(); //activate shader
    //setting the materialistic properties of the object.
    lightingShader.setVec3("material.ambient", glm::vec3(r, g, b)); //setting ambient and diffuse same because, light will hit differently at different place, so if we reduce ambient here, the net calculation after applying lighting will make it almost zero. this is why, the ambient and diffuse is kept same. reducing it once instead of reducing it twice, which will make it appear almost black 
    lightingShader.setVec3("material.diffuse", glm::vec3(r, g, b)); //original color
    lightingShader.setVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f)); //specular
    lightingShader.setFloat("material.shininess", 32.0f); //shining

    lightingShader.setMat4("model", model); //setting the object, sending the value in vertex shader. the calculation of transformation will be applied before calling the function

    glBindVertexArray(cubeVAO2);
    glDrawElements(GL_TRIANGLES, 108, GL_UNSIGNED_INT, 0);
}
void drawCubeXC(unsigned int& cubeVAO3, Shader& lightingShader, glm::mat4 model = glm::mat4(1.0f), float r = 1.0f, float g = 1.0f, float b = 1.0f)
{
    lightingShader.use(); //activate shader
    //setting the materialistic properties of the object.
    lightingShader.setVec3("material.ambient", glm::vec3(r, g, b)); //setting ambient and diffuse same because, light will hit differently at different place, so if we reduce ambient here, the net calculation after applying lighting will make it almost zero. this is why, the ambient and diffuse is kept same. reducing it once instead of reducing it twice, which will make it appear almost black 
    lightingShader.setVec3("material.diffuse", glm::vec3(r, g, b)); //original color
    lightingShader.setVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f)); //specular
    lightingShader.setFloat("material.shininess", 32.0f); //shining

    lightingShader.setMat4("model", model); //setting the object, sending the value in vertex shader. the calculation of transformation will be applied before calling the function

    glBindVertexArray(cubeVAO3);
    glDrawElements(GL_TRIANGLES, 51, GL_UNSIGNED_INT, 0);
}
void drawCubeP(unsigned int& cubeVAO4, Shader& lightingShader, glm::mat4 model = glm::mat4(1.0f), float r = 1.0f, float g = 1.0f, float b = 1.0f)
{
    lightingShader.use(); //activate shader
    //setting the materialistic properties of the object.
    lightingShader.setVec3("material.ambient", glm::vec3(r, g, b)); //setting ambient and diffuse same because, light will hit differently at different place, so if we reduce ambient here, the net calculation after applying lighting will make it almost zero. this is why, the ambient and diffuse is kept same. reducing it once instead of reducing it twice, which will make it appear almost black 
    lightingShader.setVec3("material.diffuse", glm::vec3(r, g, b)); //original color
    lightingShader.setVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f)); //specular
    lightingShader.setFloat("material.shininess", 32.0f); //shining

    lightingShader.setMat4("model", model); //setting the object, sending the value in vertex shader. the calculation of transformation will be applied before calling the function

    glBindVertexArray(cubeVAO4);
    glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_INT, 0);
}
void drawCubeCy(unsigned int& cubeVAO5, Shader& lightingShader, int size, glm::mat4 model = glm::mat4(1.0f), float r = 1.0f, float g = 1.0f, float b = 1.0f)
{
    lightingShader.use(); //activate shader
    //setting the materialistic properties of the object.
    lightingShader.setVec3("material.ambient", glm::vec3(r, g, b)); //setting ambient and diffuse same because, light will hit differently at different place, so if we reduce ambient here, the net calculation after applying lighting will make it almost zero. this is why, the ambient and diffuse is kept same. reducing it once instead of reducing it twice, which will make it appear almost black 
    lightingShader.setVec3("material.diffuse", glm::vec3(r, g, b)); //original color
    lightingShader.setVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f)); //specular
    lightingShader.setFloat("material.shininess", 32.0f); //shining

    lightingShader.setMat4("model", model); //setting the object, sending the value in vertex shader. the calculation of transformation will be applied before calling the function

    glBindVertexArray(cubeVAO5);
    glDrawArrays(GL_TRIANGLE_FAN, 0, size);
}
#pragma once
