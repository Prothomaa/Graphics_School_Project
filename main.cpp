//
//  main.cpp
//  3D Object Drawing
//
//  Created by Nazirul Hasan on 4/9/23.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "camera.h"
#include "basic_camera.h"
#include "cube.h"
#include "stb_image.h"

#include "pointLight.h"
#include "directionalLight.h"
#include "SpotLight.h"
#include "sphere.h"

#include "walls.h"
#include "chair.h"
#include "table.h"
#include "seasaw.h"
#include "slipper.h"
#include "row.h"
#include "stair.h"
#include "roundshape.h"
#include "standlamp.h"
#include "sofa.h"
#include "merry.h"
#include "swing.h"
#include "raling.h"
#include "library.h"
#include "gate.h"
#include "car.h"
#include "computerLab.h"
#include "fan.h"
#include "clock.h"

#include <iostream>
struct Point {
    float x;
    float y;
    float z;
};
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);
void drawCube(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 model, float r, float g, float b);
unsigned int loadTexture(char const* path, GLenum textureWrappingModeS, GLenum textureWrappingModeT, GLenum textureFilteringModeMin, GLenum textureFilteringModeMax);
// bc suru
unsigned int drawControlPoints();
//void saveControlPoints();
long long nCr(int n, int r);
void BezierCurve(double t, float xy[2], GLfloat ctrlpoints[], int L);// ekhane xy[2] call by reference, array diye pass korle always
unsigned int hollowBezier(GLfloat ctrlpoints[], int L);
//bc shesh

// settings
const unsigned int SCR_WIDTH = 1800;
const unsigned int SCR_HEIGHT = 950;

//bc suru
// model, view & projection matrix
/*
glm::mat4 model = glm::mat4(1.0f);
glm::mat4 view = glm::mat4(1.0f);
glm::mat4 projection = glm::mat4(1.0f);
*/
// viewport
GLint viewport[4];

/////////////////////////////////////////////////////////////
float wcsClkDn[3], wcsClkUp[3];
//vector <float> cntrlPoints;
vector <float> coordinates;
vector <float> normals;
vector <int> indices;
vector <float> vertices;

vector <float> cntrlPoints2{
    -1.215, 2.175, 5.1000,
    -1.105, 1.86, 5.1000,
    -.75, 1.605, 5.1000,
    -.41, 1.47, 5.1000,
    -.32, 1.265, 5.1,
    -.365, .98, 5.1,
    -.475, .75, 5.1
};
class point
{
public:
    point()
    {
        x = 0;
        y = 0;
    }
    int x;
    int y;
} clkpt[2];
int mouseButtonFlag = 0;
FILE* fp;
const double pi = 3.14159265389;
const int nt = 40;
const int ntheta = 20;
bool showControlPoints = false;
bool loadBezierCurvePoints = true;
bool showHollowBezier = true;
bool lineMode = false;
unsigned int bezierVAO;
//bc shesh


// modelling transform
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
float rotate_Now = 0.0;
float rotate_Now2 = 0.0;
float rotate_Now3 = 1.5;
float rotate_Now4 = -1.5;
float time2 = 0.0f;
float amplitude = 5.0f;
float frequency = 0.2f;
float translate_Now = -10.0;
float translate_level = 0.0;
bool trans_bool = true;
//car
float rotate_Now5 = 0.0;
float rotate_level5 = 0.0;
float translate_Now5 = 30.0;
float translate_level5 = 0.0;
float scale_Now = 4.0;
float scale_level = 0.0;
//fan
float rotate_Now6 = 0.0;
float rotate_level6 = 0.0;


// camera
Camera camera(glm::vec3(10.0f, 10.0f, 60.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float eyeX = 0.0, eyeY = 1.0, eyeZ = 3.0;
float lookAtX = 0.0, lookAtY = 0.0, lookAtZ = 0.0;
glm::vec3 V = glm::vec3(0.0f, 1.0f, 0.0f);
BasicCamera basic_camera(eyeX, eyeY, eyeZ, lookAtX, lookAtY, lookAtZ, V);


// positions of the point lights
glm::vec3 pointLightPositions[] = {
    glm::vec3(30.50f, 10.0f,  0.0f),
    glm::vec3(25.5f,  7.0f,  20.50f),// dolna
    glm::vec3(-3.5f,  10.5f,  -.5f),// library
    glm::vec3(-10.5f,  7.0f,   20.50f),//gate
    glm::vec3(7.5f,  10.0f,   2.50f),// teacher
    glm::vec3(5.5f,  7.0f,   20.50f)//road
};
PointLight pointlight1(

    pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z,  // position
    1.0f, 1.0f, 1.0f,    // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,       // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    1       // light number
);
PointLight pointlight2(

    pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z,  // position
    1.0f, 1.0f, 1.0f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,         // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    2       // light number
);
//library er vitor
PointLight pointlight3(

    pointLightPositions[2].x, pointLightPositions[2].y, pointLightPositions[2].z,  // position
    0.2f, 0.2f, 0.2f,   // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    0.8f, 0.8f, 0.8f,        // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    3       // light number
);
PointLight pointlight4(

    pointLightPositions[3].x, pointLightPositions[3].y, pointLightPositions[3].z,  // position
    1.0f, 1.0f, 1.0f,     // ambient
    0.9f, 0.9f, 0.9f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    4       // light number
);
//teacher room er
PointLight pointlight5(

    pointLightPositions[4].x, pointLightPositions[4].y, pointLightPositions[4].z,  // position
    0.2f, 0.2f, 0.2f,     // ambient
    0.2f, 0.2f, 0.2f,     // diffuse
    0.5f, 0.5f, 0.5f,      // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    5       // light number
);
PointLight pointlight6(

    pointLightPositions[4].x, pointLightPositions[4].y, pointLightPositions[4].z,  // position
    1.0f, 1.0f, 1.0f,     // ambient
    0.9f, 0.9f, 0.9f,     // diffuse
    1.0f, 1.0f, 1.0f,      // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    6       // light number
);

DirLight dirLight(
    -0.2f, -1.0f, -0.3f,
    0.5f, 0.5f, 0.5f,
    0.6f, 0.6f, 0.6f,     // diffuse
    0.5f, 0.5f, 0.5f
);

SpotLight spotLight(
    -3.50f, 4.0f, -2.0f,
    0.6f, -1.0f, 0.5f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,
    0.09f,
    0.032f,
    12.5f,
    15.0f
);

// light settings
bool pointLightOn = true;
bool dirLightOn = true;
bool spotLightOn = true;
bool ambientToggle = true;
bool diffuseToggle = true;
bool specularToggle = true;


// timing
float deltaTime = 0.0f;    // time between current frame and last frame
float lastFrame = 0.0f;

int main()
{
    cout << "Press 1 = Point light" << endl;
    cout << "Press 2 = Directional light" << endl;
    cout << "Press 3 = Spot light" << endl;
    cout << "Press 4 = Gate" << endl;
    cout << "Press 5 = Car" << endl;
    cout << "Press 6 = Projector" << endl;
    cout << "Press 7 = Ambient of Point light" << endl;
    cout << "Press 8 = Diffusion of Point light" << endl;
    cout << "Press 9 = Specular of Point light" << endl;
    cout << "Press W = Near" << endl;
    cout << "Press S = Far" << endl;
    cout << "Press A = Left" << endl;
    cout << "Press D = Right" << endl;

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "CSE 4208: Computer Graphics Laboratory", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    Shader lightingShader("vertexShaderForPhongShading.vs", "fragmentShaderForPhongShading.fs");
    //Shader lightingShader("vertexShaderForGouraudShading.vs", "fragmentShaderForGouraudShading.fs");
    Shader ourShader("vertexShader.vs", "fragmentShader.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------

    float cube_vertices[] = {
        // positions      // normals
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        1.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,

        1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

        0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,

        0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

        1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,

        0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        1.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f
    };
    unsigned int cube_indices[] = {
        0, 3, 2,
        2, 1, 0,

        4, 5, 7,
        7, 6, 4,

        8, 9, 10,
        10, 11, 8,

        12, 13, 14,
        14, 15, 12,

        16, 17, 18,
        18, 19, 16,

        20, 21, 22,
        22, 23, 20
    };

    float cube_verticesX[] = {//hexa gonal
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,//0

    -.8f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,//1
    -0.4f, 0.75f, 0.0f, 0.0f, 0.0f, -1.0f,//2
    0.0f, 0.75f, 0.0f, 0.0f, 0.0f, -1.0f,//3
    0.4f, 0.75f, 0.0f, 0.0f, 0.0f, -1.0f,//4

    .8f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,//5
    0.4f, -0.75f, 0.0f, 0.0f, 0.0f, -1.0f,//6
    0.0f, -0.75f, 0.0f, 0.0f, 0.0f, -1.0f,//7
    -0.4f, -0.75f, 0.0f, 0.0f, 0.0f, -1.0f,//8

    0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,//0+9

    -.8f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,//1+9
    -0.4f, 0.75f, 1.0f, 1.0f, 0.0f, 1.0f,
    0.0f, 0.75f, 1.0f, 1.0f, 0.0f, 1.0f,
    0.4f, 0.75f, 1.0f, 1.0f, 0.0f, 1.0f,

    .8f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
    0.4f, -0.75f, 1.0f, 1.0f, 0.0f, 1.0f,
    0.0f, -0.75f, 1.0f, 1.0f, 0.0f, 1.0f,
    -0.4f, -0.75f, 1.0f, 1.0f, 0.0f, 1.0f
    };
    unsigned int cube_indicesX[] = {//hexa gonal
    1, 0, 2,
    1, 0, 8,
    8, 0, 7,

    7, 0, 6,
    6, 0, 5,

    5, 0, 4,
    4, 0, 3,
    3, 0, 2,
    2, 0, 1,//

    10, 9, 11,
    10, 9, 17,
    17, 9, 16,

    16, 9, 15,
    15, 9, 14,

    14, 9, 13,
    13, 9, 12,
    12, 9, 11,
    11, 9, 10,//

    11, 1, 2,
    10, 1, 11,

    17, 1, 8,
    10, 1, 17,

    16, 8, 7,
    17, 8, 16,

    15, 7, 6,
    16, 7, 15,

    14, 6, 5,
    15, 6, 14,

    13, 5, 4,
    14, 5, 13,

    12, 4, 3,
    13, 4, 12,

    11, 3, 2,
    12, 3, 11,

    10, 2, 1,
    11, 2, 10
    };

    float cube_verticesXC[] = {// hexa conok
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,//0

    -.8f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,//1
    -0.4f, 0.75f, 0.0f, 0.0f, 0.0f, -1.0f,//2
    0.0f, 0.75f, 0.0f, 0.0f, 0.0f, -1.0f,//3
    0.4f, 0.75f, 0.0f, 0.0f, 0.0f, -1.0f,//4

    .8f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,//5
    0.4f, -0.75f, 0.0f, 0.0f, 0.0f, -1.0f,//6
    0.0f, -0.75f, 0.0f, 0.0f, 0.0f, -1.0f,//7
    -0.4f, -0.75f, 0.0f, 0.0f, 0.0f, -1.0f,//8

    0.0f, 0.0f, 2.0f, 1.0f, 0.0f, 1.0f//0+9
    };
    unsigned int cube_indicesXC[] = {//hexa conok
    1, 0, 2,
    1, 0, 8,
    8, 0, 7,

    7, 0, 6,
    6, 0, 5,

    5, 0, 4,
    4, 0, 3,
    3, 0, 2,
    2, 0, 1,//

    9, 1, 2,
    9, 2, 3,
    9, 3, 4,
    9, 4, 5,
    9, 5, 6,
    9, 6, 7,
    9, 7, 8,
    9, 8, 1
    };

    float cube_verticesP[] = {//trapizium
        // positions      // normals
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        1.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,

        1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

        0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,

        0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

        1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,

        0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        1.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,

        1.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,//24
        1.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f //25
    };
    unsigned int cube_indicesP[] = {//trapizium
        0, 3, 2,
        2, 1, 0,

        //4, 5, 7,
        //7, 6, 4,

        8, 9, 10,
        10, 11, 8,

        12, 13, 14,
        14, 15, 12,

        16, 17, 18,
        18, 19, 16,

        20, 21, 22,
        22, 23, 20,

        25, 7, 6,
        5, 4, 24,

        5, 7, 25,
        25, 5, 24,

        6, 4, 25,
        25, 4, 24
    };

    unsigned int cubeVAO, cubeVBO, cubeEBO;
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &cubeVBO);
    glGenBuffers(1, &cubeEBO);

    glBindVertexArray(cubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_indices), cube_indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // vertex normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)12);
    glEnableVertexAttribArray(1);

    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
    unsigned int lightCubeVAO;
    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
    // note that we update the lamp's position attribute's stride to reflect the updated buffer data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    /////////////////////////////////////////// hexa gonal
    unsigned int cubeVAO2, cubeVBO2, cubeEBO2;
    glGenVertexArrays(1, &cubeVAO2);
    glGenBuffers(1, &cubeVBO2);
    glGenBuffers(1, &cubeEBO2);

    glBindVertexArray(cubeVAO2);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_verticesX), cube_verticesX, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO2);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_indicesX), cube_indicesX, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // vertex normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)12);
    glEnableVertexAttribArray(1);

    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
    unsigned int lightCubeVAO2;
    glGenVertexArrays(1, &lightCubeVAO2);
    glBindVertexArray(lightCubeVAO2);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO2);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO2);
    // note that we update the lamp's position attribute's stride to reflect the updated buffer data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    ///////////////////////////////////////////////////// hexa conok
    unsigned int cubeVAO3, cubeVBO3, cubeEBO3;
    glGenVertexArrays(1, &cubeVAO3);
    glGenBuffers(1, &cubeVBO3);
    glGenBuffers(1, &cubeEBO3);

    glBindVertexArray(cubeVAO3);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO3);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_verticesXC), cube_verticesXC, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO3);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_indicesXC), cube_indicesXC, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // vertex normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)12);
    glEnableVertexAttribArray(1);

    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
    unsigned int lightCubeVAO3;
    glGenVertexArrays(1, &lightCubeVAO3);
    glBindVertexArray(lightCubeVAO3);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO3);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO3);
    // note that we update the lamp's position attribute's stride to reflect the updated buffer data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    ///////////////////////////////////////////////////// trapizium
    unsigned int cubeVAO4, cubeVBO4, cubeEBO4;
    glGenVertexArrays(1, &cubeVAO4);
    glGenBuffers(1, &cubeVBO4);
    glGenBuffers(1, &cubeEBO4);

    glBindVertexArray(cubeVAO4);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO4);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_verticesP), cube_verticesP, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO4);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_indicesP), cube_indicesP, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // vertex normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)12);
    glEnableVertexAttribArray(1);

    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
    unsigned int lightCubeVAO4;
    glGenVertexArrays(1, &lightCubeVAO4);
    glBindVertexArray(lightCubeVAO4);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO4);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO4);
    // note that we update the lamp's position attribute's stride to reflect the updated buffer data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
///////////////////////////////////////////////////
        //CYLINDER CIRCLE POINTS START
    std::vector<Point> cylindercircle;
    //cylinder.push_back({ 0, 0, -8 });
    float radiusSh = 3.0;
    for (float theta = 0; theta <= 360; theta += 1) {
        float x = radiusSh * glm::cos(glm::radians(theta));
        float y = radiusSh * glm::sin(glm::radians(theta));

        cylindercircle.push_back({ x, y, 0.0f });
        cylindercircle.push_back({ x, y, -2.0f }); // normal cylinder
        //cylinder.push_back({ x * .5f, y * .5f, -8.0f }); // cylinder with different circle radius
    }

    unsigned int cubeVBO5, cubeVAO5;
    glGenVertexArrays(1, &cubeVAO5);
    glGenBuffers(1, &cubeVBO5);

    glBindVertexArray(cubeVAO5);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO5);
    glBufferData(GL_ARRAY_BUFFER, sizeof(struct Point) * cylindercircle.size(), cylindercircle.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(struct Point), (void*)0);
    glEnableVertexAttribArray(0);

    //Sphere sphere = Sphere();

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    Shader lightingShaderWithTexture("vertexShaderForPhongShadingWithTexture.vs", "fragmentShaderForPhongShadingWithTexture.fs");

    string diffuseMapPath = "container4.png";
    string specularMapPath = "container2_specular.png";
    unsigned int diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube = Cube(diffMap, specMap, 32.0f, 0.0f, 0.0f, 5.0f, 1.0f);

    string diffuseMapPath2 = "container5.png";
    string specularMapPath2 = "container2_specular.png";
    unsigned int diffMap2 = loadTexture(diffuseMapPath2.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap2 = loadTexture(specularMapPath2.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube2 = Cube(diffMap2, specMap2, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);

    string diffuseMapPath3 = "container6.png";
    string specularMapPath3 = "container2_specular.png";
    unsigned int diffMap3 = loadTexture(diffuseMapPath3.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap3 = loadTexture(specularMapPath3.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube3 = Cube(diffMap3, specMap3, 32.0f, 0.0f, 0.0f, 4.0f, 1.0f);

    string diffuseMapPath4 = "container10.png";
    string specularMapPath4 = "container2_specular.png";
    unsigned int diffMap4 = loadTexture(diffuseMapPath4.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap4 = loadTexture(specularMapPath4.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube4 = Cube(diffMap4, specMap4, 32.0f, 0.0f, 0.0f, 2.0f, 1.0f);

    string diffuseMapPath5 = "container9.png";
    string specularMapPath5 = "container2_specular.png";
    unsigned int diffMap5 = loadTexture(diffuseMapPath5.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap5 = loadTexture(specularMapPath5.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube5 = Cube(diffMap5, specMap5, 32.0f, 0.0f, 0.0f, 4.0f, 1.0f);

    string diffuseMapPath6 = "container12.png";
    string specularMapPath6 = "container2_specular.png";
    unsigned int diffMap6 = loadTexture(diffuseMapPath6.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap6 = loadTexture(specularMapPath6.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube6 = Cube(diffMap6, specMap6, 32.0f, 0.0f, 0.0f, 1.5f, 2.0f);

    string diffuseMapPath7 = "container14.png";
    string specularMapPath7 = "container2_specular.png";
    unsigned int diffMap7 = loadTexture(diffuseMapPath7.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap7 = loadTexture(specularMapPath7.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube7 = Cube(diffMap7, specMap7, 32.0f, 0.0f, 0.0f, 20.0f, 1.0f);

    string diffuseMapPath8 = "container15.png";
    string specularMapPath8 = "container2_specular.png";
    unsigned int diffMap8 = loadTexture(diffuseMapPath8.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap8 = loadTexture(specularMapPath8.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube8 = Cube(diffMap8, specMap8, 32.0f, 0.0f, 0.0f, 20.0f, 0.5f);

    string diffuseMapPath9 = "container16.png";
    string specularMapPath9 = "container2_specular.png";
    unsigned int diffMap9 = loadTexture(diffuseMapPath9.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap9 = loadTexture(specularMapPath9.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube9 = Cube(diffMap9, specMap9, 32.0f, 0.0f, 0.0f, 20.0f, 0.5f);

    string diffuseMapPath10 = "container17.png";
    string specularMapPath10 = "container2_specular.png";
    unsigned int diffMap10 = loadTexture(diffuseMapPath10.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap10 = loadTexture(specularMapPath10.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube10 = Cube(diffMap10, specMap10, 32.0f, 0.0f, 0.0f, 20.0f, 0.5f);

    string diffuseMapPath11 = "container18.png";
    string specularMapPath11 = "container2_specular.png";
    unsigned int diffMap11 = loadTexture(diffuseMapPath11.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap11 = loadTexture(specularMapPath11.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube11 = Cube(diffMap11, specMap11, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);


    //ourShader.use();
    //lightingShader.use();

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        //bc suru
        if (lineMode)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
        else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
        //bc shesh
        
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // be sure to activate shader when setting uniforms/drawing objects
        lightingShader.use();
        lightingShader.setVec3("viewPos", camera.Position);

        // point light 1
        pointlight1.setUpPointLight(lightingShader);
        // point light 2
        pointlight2.setUpPointLight(lightingShader);
        // point light 3
        pointlight3.setUpPointLight(lightingShader);
        // point light 4
        pointlight4.setUpPointLight(lightingShader);
        // point light 5
        pointlight5.setUpPointLight(lightingShader);
        // point light 6
        pointlight6.setUpPointLight(lightingShader);

        dirLight.setUpDirLight(lightingShader);

        spotLight.setUpSpotLight(lightingShader);
        
        /*
        lightingShader.setVec3("directionalLight.direction", 0.5f, -3.3f, -3.0f);
        lightingShader.setVec3("directionalLight.ambient", .2, .2, .2);
        lightingShader.setVec3("directionalLight.diffuse", .8, .8, .8);
        lightingShader.setVec3("directionalLight.specular", 1.0f, 1.0f, 1.0f);
        lightingShader.setVec3("spotLight.position", 0.0, 4, -2.0);
        lightingShader.setVec3("spotLight.direction", 0, 1, 0);
        lightingShader.setVec3("spotLight.ambient", .2, .2, .2);
        lightingShader.setVec3("spotLight.diffuse", .8, .8, .8);
        lightingShader.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
        lightingShader.setFloat("spotLight.k_c", 1.0f);
        lightingShader.setFloat("spotLight.k_l", 0.09);
        lightingShader.setFloat("spotLight.k_q", 0.032);
        lightingShader.setFloat("cos_theta", glm::cos(glm::radians(5.5f)));
        */

        // activate shader
        lightingShader.use();

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        //glm::mat4 projection = glm::ortho(-2.0f, +2.0f, -1.5f, +1.5f, 0.1f, 100.0f);
        lightingShader.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        //glm::mat4 view = basic_camera.createViewMatrix();
        lightingShader.setMat4("view", view);

        // Modelling Transformation
        glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model, model2, model3, model_bc;
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X, translate_Y, translate_Z));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(scale_X, scale_Y, scale_Z));
        model = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
        model_bc = model;
        lightingShader.setMat4("model", model);

        //glBindVertexArray(cubeVAO);
        //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        //glDrawArrays(GL_TRIANGLES, 0, 36);

        //bed(cubeVAO, lightingShader, model);
        
        //bc suru
        lightingShader.setMat4("model", model_bc * glm::translate(identityMatrix, glm::vec3(-9.5, -.5, 1.5)) * glm::scale(identityMatrix, glm::vec3(1.3, 1.5, 1.3)));
        if (loadBezierCurvePoints)
        {
            bezierVAO = hollowBezier(cntrlPoints2.data(), ((unsigned int)cntrlPoints2.size() / 3) - 1);
            loadBezierCurvePoints = false;
            showHollowBezier = true;
        }
        if (showHollowBezier)
        {
            lightingShader.use();
            lightingShader.setVec3("material.ambient", glm::vec3(1.0f, .5f, 1.0f));
            lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 1.0f));
            lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
            lightingShader.setFloat("material.shininess", 32.0f);

            glBindVertexArray(bezierVAO);
            glDrawElements(GL_TRIANGLES,                    // primitive type
                (unsigned int)indices.size(),          // # of indices
                GL_UNSIGNED_INT,                 // data type
                (void*)0);                       // offset to indices

            // unbind VAO
            glBindVertexArray(0);
        }
        //bc shesh

        //walls
        walls(cubeVAO, cubeVAO4, lightingShader, model);

        //row 1
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 2.0, translate_Y, translate_Z - 3.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        row(cubeVAO, lightingShader, model * translateMatrix * rotateYMatrix);

        //row 2
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 2.0, translate_Y, translate_Z + 1.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        row(cubeVAO, lightingShader, model * translateMatrix * rotateYMatrix);
        /*
        //chair1
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X, translate_Y, -0.6));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        //model = model * translateMatrix;
        chair(cubeVAO, lightingShader, model * translateMatrix * rotateYMatrix);

        //table1
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 0.3, translate_Y + 0.4, 0.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        //model = model * translateMatrix;
        table(cubeVAO, lightingShader, model* translateMatrix * rotateYMatrix);
        
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
        */

        //fan1
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 4.7f, 0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 1.0f, 0.1f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(225.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        drawCube(cubeVAO, lightingShader, model * rotateYMatrix * scaleMatrix * translateMatrix , .0, 0.8078f, .8196f);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.6f, .0f));
        rotate_Now6 = (rotate_Now6 + rotate_level6);
        if (rotate_Now6 >= 360.0)
            rotate_Now6 = 0.0;
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotate_Now6), glm::vec3(0.0f, 1.0f, 0.0f));
        fan(cubeVAO, lightingShader, model * rotateYMatrix * translateMatrix);
        //fan2
        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0f, 4.7f, 0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 1.0f, 0.1f));
        drawCube(cubeVAO, lightingShader, model * translateMatrix * scaleMatrix, .0, 0.8078f, .8196f);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.2f, 0.6f, .0f));
        /*rotate_Now6 = (rotate_Now6 + rotate_level6);
        if (rotate_Now6 >= 360.0)
            rotate_Now6 = 0.0;*/
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotate_Now6), glm::vec3(.0f, 1.0f, 0.0f));
        fan(cubeVAO, lightingShader, model  * translateMatrix* rotateYMatrix);
        //fan3
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 10.6f, 0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 1.0f, 0.1f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(225.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        drawCube(cubeVAO, lightingShader, model * rotateYMatrix * scaleMatrix * translateMatrix, .0, 0.8078f, .8196f);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 6.4f, .0f));
        /*rotate_Now6 = (rotate_Now6 + rotate_level6);
        if (rotate_Now6 >= 360.0)
            rotate_Now6 = 0.0;*/
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotate_Now6), glm::vec3(0.0f, 1.0f, 0.0f));
        fan(cubeVAO, lightingShader, model * rotateYMatrix * translateMatrix);
        //fan4
        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0f, 10.7f, 0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 1.0f, 0.1f));
        drawCube(cubeVAO, lightingShader, model* translateMatrix* scaleMatrix, .0, 0.8078f, .8196f);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.2f, 6.4f, .0f));
        /*rotate_Now6 = (rotate_Now6 + rotate_level6);
        if (rotate_Now6 >= 360.0)
            rotate_Now6 = 0.0;*/
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotate_Now6), glm::vec3(.0f, 1.0f, 0.0f));
        fan(cubeVAO, lightingShader, model * translateMatrix * rotateYMatrix);

        //clock
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.0, 1.5, -4.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, 1.0));
        clock(cubeVAO, cubeVAO5, cylindercircle.size(), lightingShader, model * translateMatrix * scaleMatrix);

        //lab
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 8.0, translate_Y, translate_Z - 3.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        computerLab(cubeVAO, lightingShader, model* translateMatrix* rotateYMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 8.0, translate_Y, translate_Z + 1.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        computerLab(cubeVAO, lightingShader, model* translateMatrix* rotateYMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 14.7, translate_Y + 4.0, translate_Z - 9.0));
        scale_Now = (scale_Now + scale_level);
        if (scale_Now <= .2)
            scale_Now = .2;
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2, -scale_Now, 6.0));
        drawCube(cubeVAO, lightingShader, model2* translateMatrix * scaleMatrix, 1.0, 1.0, 1.0);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 14.7, translate_Y + 4.0, translate_Z - 6.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.8, .2, .2));
        drawCube(cubeVAO, lightingShader, model2 * translateMatrix * scaleMatrix, .0, .0, .0);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 14.6, translate_Y + 4.0, translate_Z - 9.1));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.3, .2, 6.2));
        drawCube(cubeVAO, lightingShader, model2 * translateMatrix * scaleMatrix, .0, .0, .0);

        //library
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 2.4, translate_Y + 7.5, translate_Z + 1.0));
        library(cubeVAO, lightingShader, model* translateMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 2.4, translate_Y + 7.5, translate_Z + 4.0));
        library(cubeVAO, lightingShader, model* translateMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 5.65, translate_Y + 7.5, translate_Z - 5.0));
        library(cubeVAO, lightingShader, model* translateMatrix * glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f)));

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 2.75, translate_Y + 7.0, translate_Z + 4.0));
        table(cubeVAO, lightingShader, model* translateMatrix* glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)) * glm::scale(identityMatrix, glm::vec3(8.0, 1.5, 2.7)));

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 0.5, translate_Y + 7.0, translate_Z + 3.0 - 0.7));
        drawCubeX(cubeVAO2, lightingShader, model* translateMatrix* glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(.0f, .0f, 1.0f))* glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(1.0f, .0f, .0f))* glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, .0f))* glm::scale(identityMatrix, glm::vec3(.6, .6, .1)), .6, 0.0f, .2980f);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.0, 0.1));
        drawCube(cubeVAO, lightingShader, model * glm::translate(identityMatrix, glm::vec3(translate_X - 0.6, translate_Y + 6.0, translate_Z + 3.0 - 0.7)) * scaleMatrix, 1.0, 1.0, 0.0);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3, .2, 0.3));
        drawCube(cubeVAO, lightingShader, model* glm::translate(identityMatrix, glm::vec3(translate_X - 0.7, translate_Y + 6.0, translate_Z + 3.0 - 0.7))* scaleMatrix, .6, 0.0f, .2980f);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 0.5, translate_Y + 7.0, translate_Z + 1.0 - 1.3));
        drawCubeX(cubeVAO2, lightingShader, model* translateMatrix* glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(.0f, .0f, 1.0f))* glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(1.0f, .0f, .0f))* glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, .0f))* glm::scale(identityMatrix, glm::vec3(.6, .6, .1)), .6, 0.0f, .2980f);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.0, 0.1));
        drawCube(cubeVAO, lightingShader, model* glm::translate(identityMatrix, glm::vec3(translate_X - 0.6, translate_Y + 6.0, translate_Z + .8 - 1.3))* scaleMatrix, 1.0, 1.0, 0.0);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3, .2, 0.3));
        drawCube(cubeVAO, lightingShader, model* glm::translate(identityMatrix, glm::vec3(translate_X - 0.7, translate_Y + 6.0, translate_Z + .8 - 1.3))* scaleMatrix, .6, 0.0f, .2980f);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 0.5, translate_Y + 7.0, translate_Z - 1.0 - 2.0));
        drawCubeX(cubeVAO2, lightingShader, model* translateMatrix* glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(.0f, .0f, 1.0f))* glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(1.0f, .0f, .0f))* glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, .0f))* glm::scale(identityMatrix, glm::vec3(.6, .6, .1)), .6, 0.0f, .2980f);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.0, 0.1));
        drawCube(cubeVAO, lightingShader, model* glm::translate(identityMatrix, glm::vec3(translate_X - 0.6, translate_Y + 6.0, translate_Z - 1.4-2.0))* scaleMatrix, 1.0, 1.0, 0.0);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3, .2, 0.3));
        drawCube(cubeVAO, lightingShader, model* glm::translate(identityMatrix, glm::vec3(translate_X - 0.7, translate_Y + 6.0, translate_Z - 1.4-2.0))* scaleMatrix, .6, 0.0f, .2980f);
        //****
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 2.3, translate_Y + 7.0, translate_Z + 3.0 - 0.7));
        drawCubeX(cubeVAO2, lightingShader, model* translateMatrix* glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(.0f, .0f, 1.0f))* glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(1.0f, .0f, .0f))* glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, .0f))* glm::scale(identityMatrix, glm::vec3(.6, .6, .1)), .6, 0.0f, .2980f);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.0, 0.1));
        drawCube(cubeVAO, lightingShader, model* glm::translate(identityMatrix, glm::vec3(translate_X + 2.3, translate_Y + 6.0, translate_Z + 3.0 - 0.7))* scaleMatrix, 1.0, 1.0, 0.0);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3, .2, 0.3));
        drawCube(cubeVAO, lightingShader, model* glm::translate(identityMatrix, glm::vec3(translate_X + 2.2, translate_Y + 6.0, translate_Z + 2.9 - 0.7))* scaleMatrix, .6, 0.0f, .2980f);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 2.3, translate_Y + 7.0, translate_Z + 1.0 - 1.3));
        drawCubeX(cubeVAO2, lightingShader, model* translateMatrix* glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(.0f, .0f, 1.0f))* glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(1.0f, .0f, .0f))* glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, .0f))* glm::scale(identityMatrix, glm::vec3(.6, .6, .1)), .6, 0.0f, .2980f);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.0, 0.1));
        drawCube(cubeVAO, lightingShader, model* glm::translate(identityMatrix, glm::vec3(translate_X + 2.3, translate_Y + 6.0, translate_Z + .8 - 1.3))* scaleMatrix, 1.0, 1.0, 0.0);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3, .2, 0.3));
        drawCube(cubeVAO, lightingShader, model* glm::translate(identityMatrix, glm::vec3(translate_X + 2.2, translate_Y + 6.0, translate_Z + .8 - 1.3))* scaleMatrix, .6, 0.0f, .2980f);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 2.3, translate_Y + 7.0, translate_Z - 1.0 - 2.0));
        drawCubeX(cubeVAO2, lightingShader, model* translateMatrix* glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(.0f, .0f, 1.0f))* glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(1.0f, .0f, .0f))* glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, .0f))* glm::scale(identityMatrix, glm::vec3(.6, .6, .1)), .6, 0.0f, .2980f);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.0, 0.1));
        drawCube(cubeVAO, lightingShader, model* glm::translate(identityMatrix, glm::vec3(translate_X + 2.3, translate_Y + 6.0, translate_Z - 1.4 - 2.0))* scaleMatrix, 1.0, 1.0, 0.0);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3, .2, 0.3));
        drawCube(cubeVAO, lightingShader, model* glm::translate(identityMatrix, glm::vec3(translate_X + 2.2, translate_Y + 6.0, translate_Z - 1.4 - 2.0))* scaleMatrix, .6, 0.0f, .2980f);

        //seasaw
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X, translate_Y + .5 , 0.5 + 5));
        model = model * translateMatrix;
        if (rotate_Now >= 15.0)
        {
            while (rotate_Now >= -15.0)
            {
                rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotate_Now), glm::vec3(-0.03f, 0.0f, 1.0f));

                seasaw(cubeVAO, lightingShader, model, rotateZMatrix );

                rotate_Now -= 0.5;
            }
            rotate_Now = -15.0;
        }
        else
        {
            rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotate_Now), glm::vec3(-0.03f, 0.0f, 1.0f));
            seasaw(cubeVAO, lightingShader, model, rotateZMatrix);
            rotate_Now += 0.5;
        }
        
        //slipper
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 0.3, translate_Y + 0.3, 0.5));
        model = model * translateMatrix;
        model2 = model;
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 30.0, translate_Y + 0.3, 8.5));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-120.0f), glm::vec3(0.0f, 1.0f, .0f));
        slipper(cubeVAO, lightingShader, model * translateMatrix * rotateZMatrix);

        //stair
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 1.0, translate_Y - 0.2 , 3.7));
        model = model * translateMatrix;
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 29.5, translate_Y - 0.2, 12.7));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, .0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.5, 1.0));
        stair(cubeVAO, lightingShader, model * translateMatrix * rotateZMatrix * scaleMatrix);

        //roundshape table
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 13.0, translate_Y + 5.5, -7.0));
        model = model * translateMatrix;
        model3 = model;
        roundshape(cubeVAO, lightingShader, model);

        //standlamp
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + .5, translate_Y - .5, 4.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        standlamp(cubeVAO, lightingShader, model * translateMatrix * rotateYMatrix);

        //sofa
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 0.5, translate_Y + 0.5, -3.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.75, 1.5, 1.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = model * rotateYMatrix * translateMatrix * scaleMatrix;
        sofa(cubeVAO, lightingShader, model);

        //sofa
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.0, 0.0, -4.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6, 1.05, 1.05));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = model * rotateYMatrix * translateMatrix *  scaleMatrix;
        sofa(cubeVAO, lightingShader, model);

        //teacher sofa
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.0, .6, -9.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.75, 1.5, 1.5));
        sofa(cubeVAO, lightingShader, model3 * translateMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.0, .6, -9.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.75, 1.5, 1.5));
        sofa(cubeVAO, lightingShader, model3 * translateMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(.0, .6, -9.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.75, 1.5, 1.5));
        sofa(cubeVAO, lightingShader, model3 * translateMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(-8.8, .6, -4.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.75, 1.5, 1.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        sofa(cubeVAO, lightingShader, model3 * translateMatrix * rotateYMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(-8.8, .6, -1.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.75, 1.5, 1.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        sofa(cubeVAO, lightingShader, model3 * translateMatrix * rotateYMatrix * scaleMatrix);

        //merry go round base
        /*
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 5.6, translate_Y - 1.0, 4.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, .5f, .5f));
        drawCube(cubeVAO, lightingShader, model2 * translateMatrix * scaleMatrix, 0.1, 0.1f, 0.1f);
        */
        for (float i = 0.0f; i < 360.0f; i += 2.50f) {
            //Center

            translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 5.86, translate_Y - 1.0, 4.77));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2f, .5f, .2f));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + i), glm::vec3(0.0f, 1.0f, 0.0f));
            //model = translateMatrix * rotateYMatrix * scaleMatrix;
            drawCube(cubeVAO, lightingShader, model2 * translateMatrix * rotateYMatrix * scaleMatrix , 0.5019, 0.0f, 0.5019f);

        }

        //merry go round
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 3.8 , translate_Y + 0.3  , 5.7));
        rotate_Now2 = (rotate_Now2 + 2.0);
        if (rotate_Now2 >= 360.0)
            rotate_Now2 = 0.0;
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotate_Now2), glm::vec3(0.0f, 1.0f, 0.0f));
        merry(cubeVAO, lightingShader, model2 * translateMatrix, rotateZMatrix);

        //swing
        /* minu diyese
        float time = 0.0f;
        float amplitude = 30.0f;
        float frequency = 0.1f;
        float angle = amplitude * sin(frequency * time);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(20.5104, 2.97897, 2.15003));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, -4.5f, 0.1f));
        model = translateMatrix * rotateZMatrix * scaleMatrix;
        test(cube, lightingShader, model);
        time += 0.01;
        */
        float angle = amplitude * sin(frequency * time2);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 12.5, translate_Y + 2.7, 12.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(angle), glm::vec3(-16.5f, -15.5, -10.5f));
        swing(cubeVAO, lightingShader, model2 * rotateYMatrix * translateMatrix, rotateZMatrix);
        time2 += 0.5;
        //translateMatrix = glm::translate(identityMatrix, glm::vec3(4.0, 5.0, -3.0));
        /*
        rotate_Now3 = (rotate_Now3 - 0.05);
        if (rotate_Now3 <= -1.5)
        {
            rotate_Now4 = (rotate_Now4 + 0.05);
            rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotate_Now4), glm::vec3(-0.0f, 1.0f, 0.0f));
            swing(cubeVAO, lightingShader, model2 * rotateYMatrix * translateMatrix, rotateZMatrix);
            if (rotate_Now4 >= 1.5) rotate_Now3 = 1.5;
            
        }
        else
        {
            rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotate_Now3), glm::vec3(-0.0f, 1.0f, 0.0f));
            swing(cubeVAO, lightingShader, model2 * rotateYMatrix * translateMatrix, rotateZMatrix);
        }
        */

        /*
        //raling
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-18.0, 0.5, 5.0));
        model = model3 * translateMatrix ;
        raling(cubeVAO, lightingShader, model);
        */

        //boundary hexa conok
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 18.0, translate_Y - 4.0, translate_Z + 23.0));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, .8));
        drawCubeXC(cubeVAO3, lightingShader, model * translateMatrix * rotateZMatrix * rotateXMatrix * rotateYMatrix * scaleMatrix, .7529f, .7529f, .7529f);
        
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 20.0, translate_Y - 4.0, translate_Z + 19.0));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, .8));
        drawCubeXC(cubeVAO3, lightingShader, model * translateMatrix * rotateZMatrix * rotateXMatrix * rotateYMatrix * scaleMatrix, 1.0f, .0f, .0f);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 22.0, translate_Y - 4.0, translate_Z + 17.0));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, .8));
        drawCubeXC(cubeVAO3, lightingShader, model * translateMatrix * rotateZMatrix * rotateXMatrix * rotateYMatrix * scaleMatrix, .7529f, .7529f, .7529f);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 18.0, translate_Y - 4.0, translate_Z + 15.0));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, .8));
        drawCubeXC(cubeVAO3, lightingShader, model * translateMatrix * rotateZMatrix * rotateXMatrix * rotateYMatrix * scaleMatrix, 1.0f, .0f, .0f);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 20.0, translate_Y - 4.0, translate_Z + 13.0));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, .8));
        drawCubeXC(cubeVAO3, lightingShader, model * translateMatrix * rotateZMatrix * rotateXMatrix * rotateYMatrix * scaleMatrix, .7529f, .7529f, .7529f);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + 20.0, translate_Y - 4.0, translate_Z + 8.0));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, .8));
        drawCubeXC(cubeVAO3, lightingShader, model * translateMatrix * rotateZMatrix * rotateXMatrix * rotateYMatrix * scaleMatrix, 1.0f, .0f, .0f);

        //gate
        if (trans_bool == true)
        {
            if (translate_Now > -15.1)
                translate_Now = (translate_Now - translate_level);
            if (translate_Now <= -15.0)
            {
                trans_bool = false;
                translate_level = 0.0;
            }
        }
        if (trans_bool == false)
        {
            if (translate_Now <= -10.0)
                translate_Now = (translate_Now + translate_level);
            if (translate_Now >= -10.0)
            {
                trans_bool = true;
                translate_level = 0.0;
            }
        }
     
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_Now, translate_Y - 1.5, 18.5));
        gate(cubeVAO, lightingShader, model2 * translateMatrix);
        
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X - 15.0, translate_Y - 1.5, 19.0));
        gate(cubeVAO, lightingShader, model2* translateMatrix);

        //car
        rotate_Now5 = (rotate_Now5 + rotate_level5);
        if (rotate_Now5 == 361.0)
            rotate_Now5 = 0.0;
        translate_Now5 = (translate_Now5 + translate_level5);
        if (translate_Now5 <= -18.0)
            translate_Now5 = -18.0;

        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotate_Now5), glm::vec3(0.0f, 0.0f, 1.0f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_Now5, translate_Y - 1.5, 20.0));
        car(cubeVAO, cubeVAO4, cubeVAO5, cylindercircle.size(), lightingShader, model2 * translateMatrix, rotateZMatrix);

        //toilet
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-14.95, 6.5, -9.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.5f, .3f, 6.5f));
        drawCube(cubeVAO, lightingShader, model2 * translateMatrix * scaleMatrix, 0.8784, 0.8784, 0.8784);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(-14.8, -1.0, -9.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0f, .3f, 6.5f));
        drawCube(cubeVAO, lightingShader, model2 * translateMatrix * scaleMatrix, 0.8784, 0.8784, 0.8784);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(-8.0, 2.0, -5.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 2.0f, 2.0f));
        drawCube(cubeVAO, lightingShader, model2 * translateMatrix * scaleMatrix, 0.7, 0.7, 0.7);
        /*
        glm::mat4 modelForSphere = glm::mat4(1.0f);
        modelForSphere = glm::translate(model, glm::vec3(1.5f, 1.2f, 0.5f));
        sphere.drawSphere(lightingShader, modelForSphere);
        */
        // also draw the lamp object(s)
        ourShader.use();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);

        // we now draw as many light bulbs as we have point lights.
        glBindVertexArray(lightCubeVAO);
        for (unsigned int i = 0; i < 6; i++)
        {
            model = glm::mat4(1.0f);
            model = glm::translate(model, pointLightPositions[i]);
            model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
            ourShader.setMat4("model", model);
            ourShader.setVec3("color", glm::vec3(0.8f, 0.8f, 0.8f));
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
            //glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        lightingShaderWithTexture.use();
        lightingShaderWithTexture.setVec3("viewPos", camera.Position);
        lightingShaderWithTexture.setMat4("projection", projection);
        lightingShaderWithTexture.setMat4("view", view);

        // Modelling Transformation
        //glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        //glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X, translate_Y, translate_Z));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(scale_X, scale_Y , scale_Z ));
        model = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;

        lightingShaderWithTexture.use();
        // point light 1
        pointlight1.setUpPointLight(lightingShaderWithTexture);
        // point light 2
        pointlight2.setUpPointLight(lightingShaderWithTexture);
        // point light 3
        pointlight3.setUpPointLight(lightingShaderWithTexture);
        // point light 4
        pointlight4.setUpPointLight(lightingShaderWithTexture);
        // point light 5
        pointlight5.setUpPointLight(lightingShaderWithTexture);
        // point light 6
        pointlight6.setUpPointLight(lightingShaderWithTexture);

        //grass
        glm::mat4 modelMatrixForContainer = glm::mat4(1.0f);
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-6.5, -0.5, 3.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(33, .5, 10));
        cube.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-6.5, -0.5, 13.5));
        cube.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-16.5, -0.5, 24.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        cube.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * rotateYMatrix * glm::scale(identityMatrix, glm::vec3(34, .5, 10)));

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(25.5, -0.5, 23.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        cube.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * rotateYMatrix * scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-6.5, -0.5, -9.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(33, .5, 5));
        cube.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        //blackboard
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(2.95, 0.5, -4.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 3, 6));
        cube2.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        //floor
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-6.5, -0.4, -6.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(22, .5, 10));
        cube3.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer  * scaleMatrix);

        //floor 2nd floor
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-6.5, 6.0, -6.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(22.2, .1, 13));
        cube3.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        //walls
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-6.5, -0.5, -6.3));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(12.6, 6, 0.25));
        cube4.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(6.0, -0.5, -6.3));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(9.6, 6, 0.25));
        cube4.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(3.0, -0.45, -6.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30, 6, 10));
        cube4.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(15.0, -0.45, -6.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30, 6, 10));
        cube4.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        //road
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-18.0, -0.5, 24.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(55, .5, 4));
        cube5.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        //walls 2nd floor
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-6.5, 5.5, -6.3));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(12.6, 6, 0.25));
        cube4.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(6.0, 5.5, -6.3));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(9.6, 6, 0.25));
        cube4.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(3.0, 5.45, -6.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30, 6, 10));
        cube4.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(15.0, 5.45, -6.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30, 6, 10));
        cube4.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        //brick floor
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(15.5, -0.4, -6.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(11, .5, 10));
        cube6.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer * scaleMatrix);

        //teacher
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(translate_X - 7.0, translate_Y + 0.0, -5.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0, 1.0, 1.5));
        cube7.drawCubeWithTexture(lightingShaderWithTexture, model3* modelMatrixForContainer* scaleMatrix);
        
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(translate_X - 0.5, translate_Y + 0.0, -6.95));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0, 1.0, 1.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        cube7.drawCubeWithTexture(lightingShaderWithTexture, model3* rotateYMatrix* modelMatrixForContainer* scaleMatrix);
        
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(translate_X - 7.0, translate_Y + 1.1, -5.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0, .2, 1.5));
        cube8.drawCubeWithTexture(lightingShaderWithTexture, model3* modelMatrixForContainer* scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(translate_X - 0.5, translate_Y + 1.1, -6.95));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.5, .2, 1.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        cube8.drawCubeWithTexture(lightingShaderWithTexture, model3* rotateYMatrix* modelMatrixForContainer* scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(translate_X - .2, translate_Y - 0.0, -5.7));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 1.1, 1.8));
        cube9.drawCubeWithTexture(lightingShaderWithTexture, model3* modelMatrixForContainer* scaleMatrix);
        
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(translate_X + 2.5, translate_Y + 0.0, -6.95));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 1.1, 1.6));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        cube9.drawCubeWithTexture(lightingShaderWithTexture, model3* rotateYMatrix* modelMatrixForContainer* scaleMatrix);

        //boundary
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-7.25, -0.5, 23.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(43.0, 2.0, 1.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        cube10.drawCubeWithTexture(lightingShaderWithTexture, model * modelMatrixForContainer* scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-17.25, -0.5, 24.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(35.0, 2.0, 1.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        cube10.drawCubeWithTexture(lightingShaderWithTexture, model* modelMatrixForContainer * rotateYMatrix * scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-17.25, -0.5, -10.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(53.0, 2.0, 1.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        cube10.drawCubeWithTexture(lightingShaderWithTexture, model* modelMatrixForContainer* scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(35.25, -0.5, 24.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(35.0, 2.0, 1.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        cube10.drawCubeWithTexture(lightingShaderWithTexture, model* modelMatrixForContainer* rotateYMatrix* scaleMatrix);

        //toilet
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-15.25, -0.5, -3.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0, 8.0, .5));
        cube11.drawCubeWithTexture(lightingShaderWithTexture, model* modelMatrixForContainer* scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-15.25, -0.5, -3.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5, 8.0, 6.5));
        cube11.drawCubeWithTexture(lightingShaderWithTexture, model* modelMatrixForContainer* scaleMatrix);

        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-7.25, -0.5, -3.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5, 8.0, 6.5));
        cube11.drawCubeWithTexture(lightingShaderWithTexture, model* modelMatrixForContainer* scaleMatrix);
        
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightCubeVAO);
    glDeleteBuffers(1, &cubeVBO);
    glDeleteBuffers(1, &cubeEBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}
/*
void drawCube(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 model = glm::mat4(1.0f), float r = 1.0f, float g = 1.0f, float b = 1.0f)
{
    lightingShader.use();

    lightingShader.setVec3("material.ambient", glm::vec3(r, g, b));
    lightingShader.setVec3("material.diffuse", glm::vec3(r, g, b));
    lightingShader.setVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f));
    lightingShader.setFloat("material.shininess", 32.0f);

    lightingShader.setMat4("model", model);

    glBindVertexArray(cubeVAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
*/

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.ProcessKeyboard(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
    {
        if (rotateAxis_X) rotateAngle_X -= 0.1;
        else if (rotateAxis_Y) rotateAngle_Y -= 0.1;
        else rotateAngle_Z -= 0.1;
    }
    if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) translate_Y += 0.001;
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) translate_Y -= 0.001;
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) translate_X += 0.001;
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) translate_X -= 0.001;
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) translate_Z += 0.001;
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) translate_Z -= 0.001;
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) 
    {
        //scale_X += 0.001;
        rotate_level6 = rotate_level6 + 5.0;
        /*if (rotate_level6 == 3.0)
            rotate_level6 = 0.0;*/
    }
    if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS) scale_X -= 0.001;
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) scale_Y += 0.001;
    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) scale_Y -= 0.001;
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) scale_Z += 0.001;
    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) scale_Z -= 0.001;

    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
    {
        rotateAngle_X += 0.7;
        rotateAxis_X = 1.0;
        rotateAxis_Y = 0.0;
        rotateAxis_Z = 0.0;
    }
    if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
    {
        rotateAngle_Y += 0.8;
        rotateAxis_X = 0.0;
        rotateAxis_Y = 1.0;
        rotateAxis_Z = 0.0;
    }
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    {
        rotateAngle_Z += 0.5;
        rotateAxis_X = 0.0;
        rotateAxis_Y = 0.0;
        rotateAxis_Z = 1.0;
    }

    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
    {
        eyeX += 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
    {
        eyeX -= 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
    {
        eyeZ += 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
    {
        eyeZ -= 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        eyeY += 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        eyeY -= 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_1 && action == GLFW_PRESS)
    {
        if (pointLightOn)
        {
            pointlight1.turnOff();
            pointlight2.turnOff();
            pointlight3.turnOff();
            pointlight4.turnOff();
            pointlight5.turnOff();
            pointLightOn = !pointLightOn;
        }
        else
        {
            pointlight1.turnOn();
            pointlight2.turnOn();
            pointlight3.turnOn();
            pointlight4.turnOn();
            pointlight5.turnOn();
            pointLightOn = !pointLightOn;
        }
    }

    if (key == GLFW_KEY_2 && action == GLFW_PRESS)
    {
        if (dirLightOn)
        {
            dirLight.turnOff();
            dirLightOn = !dirLightOn;
        }
        else
        {
            dirLight.turnOn();
            dirLightOn = !dirLightOn;
        }
    }

    if (key == GLFW_KEY_3 && action == GLFW_PRESS)
    {
        if (spotLightOn)
        {
            spotLight.turnOff();
            spotLightOn = !spotLightOn;
        }
        else
        {
            spotLight.turnOn();
            spotLightOn = !spotLightOn;
        }
    }

    if (key == GLFW_KEY_7 && action == GLFW_PRESS)
    {
        if (ambientToggle)
        {
            pointlight1.turnAmbientOff();
            pointlight2.turnAmbientOff();
            pointlight3.turnAmbientOff();
            pointlight4.turnAmbientOff();
            pointlight5.turnAmbientOff();
            ambientToggle = !ambientToggle;
        }
        else
        {
            pointlight1.turnAmbientOn();
            pointlight2.turnAmbientOn();
            pointlight3.turnAmbientOn();
            pointlight4.turnAmbientOn();
            pointlight5.turnAmbientOn();
            ambientToggle = !ambientToggle;
        }
    }

    if (key == GLFW_KEY_8 && action == GLFW_PRESS)
    {
        if (diffuseToggle)
        {
            pointlight1.turnDiffuseOff();
            pointlight2.turnDiffuseOff();
            pointlight3.turnDiffuseOff();
            pointlight4.turnDiffuseOff();
            pointlight5.turnDiffuseOff();
            diffuseToggle = !diffuseToggle;
        }
        else
        {
            pointlight1.turnDiffuseOn();
            pointlight2.turnDiffuseOn();
            pointlight3.turnDiffuseOn();
            pointlight4.turnDiffuseOn();
            pointlight5.turnDiffuseOn();
            diffuseToggle = !diffuseToggle;
        }
    }

    if (key == GLFW_KEY_9 && action == GLFW_PRESS)
    {
        if (specularToggle)
        {
            pointlight1.turnSpecularOff();
            pointlight2.turnSpecularOff();
            pointlight3.turnSpecularOff();
            pointlight4.turnSpecularOff();
            pointlight5.turnSpecularOff();
            specularToggle = !specularToggle;
        }
        else
        {
            pointlight1.turnSpecularOn();
            pointlight2.turnSpecularOn();
            pointlight3.turnSpecularOn();
            pointlight4.turnSpecularOn();
            pointlight5.turnSpecularOn();
            specularToggle = !specularToggle;
        }
    }
    if (key == GLFW_KEY_4 && action == GLFW_PRESS)
    {
        translate_level = translate_level + .2;
    }
    if (key == GLFW_KEY_5 && action == GLFW_PRESS)
    {
        translate_level5 = translate_level5 - .2;
        rotate_level5 = rotate_level5 + .2;
    }
    if (key == GLFW_KEY_6 && action == GLFW_PRESS)
    {
        scale_level = scale_level - .05;
    }
   
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

//bc suru
unsigned int drawControlPoints()
{
    unsigned int controlPointVAO;
    unsigned int controlPointVBO;

    glGenVertexArrays(1, &controlPointVAO);
    glGenBuffers(1, &controlPointVBO);

    glBindVertexArray(controlPointVAO);

    glBindBuffer(GL_ARRAY_BUFFER, controlPointVBO);
    glBufferData(GL_ARRAY_BUFFER, (unsigned int)cntrlPoints2.size() * sizeof(float), cntrlPoints2.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return controlPointVAO;
}
/*
void saveControlPoints()
{
    if (cntrlPoints2.size())
    {
        fp = fopen("points you can copy.txt", "w");
        if (fp == NULL)
        {
            cout << "File Opening Failed" << endl;
        }
        else
        {
            fprintf(fp, "{\n");
            size_t count = cntrlPoints2.size();
            for (int i = 0; i < count / 3; i++)
            {
                int j = i * 3;
                fprintf(fp, "%0.4f, %0.4f, %0.4f,\n", cntrlPoints2[j], cntrlPoints2[j + 1], cntrlPoints2[j + 2]);
            }
            fprintf(fp, "}");
            fclose(fp);
        }
    }
}*/
long long nCr(int n, int r)
{
    if (r > n / 2)
        r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

//polynomial interpretation for N points
void BezierCurve(double t, float xy[2], GLfloat ctrlpoints[], int L)
{
    double y = 0;
    double x = 0;
    t = t > 1.0 ? 1.0 : t;
    for (int i = 0; i < L + 1; i++)
    {
        long long ncr = nCr(L, i);
        double oneMinusTpow = pow(1 - t, double(L - i));
        double tPow = pow(t, double(i));
        double coef = oneMinusTpow * tPow * ncr;
        x += coef * ctrlpoints[i * 3];
        y += coef * ctrlpoints[(i * 3) + 1];

    }
    xy[0] = float(x);
    xy[1] = float(y);
}

unsigned int hollowBezier(GLfloat ctrlpoints[], int L)
{
    int i, j;
    float x, y, z, r;                //current coordinates
    float theta;
    float nx, ny, nz, lengthInv;    // vertex normal


    const float dtheta = 2 * pi / ntheta;        //angular step size

    float t = 0;
    float dt = 1.0 / nt;
    float xy[2];

    for (i = 0; i <= nt; ++i)              //step through y
    {
        BezierCurve(t, xy, ctrlpoints, L);
        r = xy[0];
        y = xy[1];
        theta = 0;
        t += dt;
        lengthInv = 1.0 / r;

        for (j = 0; j <= ntheta; ++j)
        {
            double cosa = cos(theta);
            double sina = sin(theta);
            z = r * cosa;
            x = r * sina;

            coordinates.push_back(x);
            coordinates.push_back(y);
            coordinates.push_back(z);

            // normalized vertex normal (nx, ny, nz)
            // center point of the circle (0,y,0)
            nx = (x - 0) * lengthInv;
            ny = (y - y) * lengthInv;
            nz = (z - 0) * lengthInv;

            normals.push_back(nx);
            normals.push_back(ny);
            normals.push_back(nz);

            theta += dtheta;
        }
    }

    // generate index list of triangles
    // k1--k1+1
    // |  / |
    // | /  |
    // k2--k2+1

    int k1, k2;
    for (int i = 0; i < nt; ++i)
    {
        k1 = i * (ntheta + 1);     // beginning of current stack
        k2 = k1 + ntheta + 1;      // beginning of next stack

        for (int j = 0; j < ntheta; ++j, ++k1, ++k2)
        {
            // k1 => k2 => k1+1
            indices.push_back(k1);
            indices.push_back(k2);
            indices.push_back(k1 + 1);

            // k1+1 => k2 => k2+1
            indices.push_back(k1 + 1);
            indices.push_back(k2);
            indices.push_back(k2 + 1);
        }
    }

    size_t count = coordinates.size();
    for (int i = 0; i < count; i += 3)
    {
        vertices.push_back(coordinates[i]);
        vertices.push_back(coordinates[i + 1]);
        vertices.push_back(coordinates[i + 2]);

        vertices.push_back(normals[i]);
        vertices.push_back(normals[i + 1]);
        vertices.push_back(normals[i + 2]);
    }

    unsigned int bezierVAO;
    glGenVertexArrays(1, &bezierVAO);
    glBindVertexArray(bezierVAO);

    // create VBO to copy vertex data to VBO
    unsigned int bezierVBO;
    glGenBuffers(1, &bezierVBO);
    glBindBuffer(GL_ARRAY_BUFFER, bezierVBO);           // for vertex data
    glBufferData(GL_ARRAY_BUFFER,                   // target
        (unsigned int)vertices.size() * sizeof(float), // data size, # of bytes
        vertices.data(),   // ptr to vertex data
        GL_STATIC_DRAW);                   // usage

    // create EBO to copy index data
    unsigned int bezierEBO;
    glGenBuffers(1, &bezierEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bezierEBO);   // for index data
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,           // target
        (unsigned int)indices.size() * sizeof(unsigned int),             // data size, # of bytes
        indices.data(),               // ptr to index data
        GL_STATIC_DRAW);                   // usage

    // activate attrib arrays
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // set attrib arrays with stride and offset
    int stride = 24;     // should be 24 bytes
    glVertexAttribPointer(0, 3, GL_FLOAT, false, stride, (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, stride, (void*)(sizeof(float) * 3));

    // unbind VAO, VBO and EBO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    return bezierVAO;
}
//bc shesh

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
/*
void seat(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.45, 0.3, .9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5f, .2f, .5f));
    model =  als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.6f, 0.125f);
}
*/
unsigned int loadTexture(char const* path, GLenum textureWrappingModeS, GLenum textureWrappingModeT, GLenum textureFilteringModeMin, GLenum textureFilteringModeMax)//magni filtering
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);//stbi header theke asche
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureWrappingModeS);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureWrappingModeT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, textureFilteringModeMin);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, textureFilteringModeMax);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}
