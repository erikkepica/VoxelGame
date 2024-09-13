#include "Application.h"
#include"Log.h"

#include"glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

#include"OpenGLObjects.h"
#include"Chunk.h"
#include"Color.h"

#include"Camera.h"

#include"stb_image.h"

namespace Kepeca
{
    Application::Application(AppSpecs specs)
        :m_Specs(specs),m_Window(nullptr)
    {
    }

    Application::~Application()
    {
    }

    glm::vec2 mousePos(0.0f);

    void Application::Run()
    {
        Log::Init();

        if (glfwInit())
        {
            LOG_TRACE("Initialized glfw!");
        }
        else
        {
            LOG_ERROR("Failed to initialize glfw!");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow(m_Specs.width, m_Specs.height, m_Specs.title.c_str(), NULL, NULL);

        if (m_Window == NULL)
        {
            LOG_ERROR("Failed to create the window!");
            glfwTerminate();
            return;
        }
        else
        {
            LOG_TRACE("Window created!");
        }

        glfwMakeContextCurrent(m_Window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOG_ERROR("Failed to initialize glad!");
        }
        else
        {
            LOG_TRACE("Initialized glad!");
        }

        glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        glViewport(0, 0, m_Specs.width, m_Specs.height);

        glfwSetCursorPosCallback(m_Window, mouse_callback);
        glEnable(GL_DEPTH_TEST);
        stbi_set_flip_vertically_on_load(true);
        float vertices[] = {
            //      COORDS          UV              NORMAL
            //front
            -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,   0.0f, 0.0f, 1.0f,  // left  
             0.5f, -0.5f,  0.5f,   1.0f, 0.0f,   0.0f, 0.0f, 1.0f,  // right 
             0.5f,  0.5f,  0.5f,   1.0f, 1.0f,   0.0f, 0.0f, 1.0f,  // top right
            -0.5f,  0.5f,  0.5f,   0.0f, 1.0f,   0.0f, 0.0f, 1.0f,  // top left

            //left
            -0.5f, -0.5f, -0.5f,   1.0f, 0.0f,   -1.0f, 0.0f, 0.0f, // back left 
            -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,   -1.0f, 0.0f, 0.0f, // left  
            -0.5f,  0.5f,  0.5f,   0.0f, 1.0f,   -1.0f, 0.0f, 0.0f, // top left
            -0.5f,  0.5f, -0.5f,   1.0f, 1.0f,   -1.0f, 0.0f, 0.0f, // top back left

            //back
             0.5f, -0.5f, -0.5f,   0.0f, 0.0f,   0.0f, 0.0f, -1.0f,  // back right 
            -0.5f, -0.5f, -0.5f,   1.0f, 0.0f,   0.0f, 0.0f, -1.0f,  // back left
            -0.5f,  0.5f, -0.5f,   1.0f, 1.0f,   0.0f, 0.0f, -1.0f,  // top back left 
             0.5f,  0.5f, -0.5f,   0.0f, 1.0f,   0.0f, 0.0f, -1.0f,  // top back right

            //right
            0.5f, -0.5f, -0.5f,   1.0f, 0.0f,   1.0f, 0.0f, 0.0f, // back left 
            0.5f, -0.5f,  0.5f,   0.0f, 0.0f,   1.0f, 0.0f, 0.0f, // left  
            0.5f,  0.5f,  0.5f,   0.0f, 1.0f,   1.0f, 0.0f, 0.0f, // top left
            0.5f,  0.5f, -0.5f,   1.0f, 1.0f,   1.0f, 0.0f, 0.0f, // top back left

            //top
            -0.5f,  0.5f,  0.5f,   0.0f, 0.0f,   0.0f, 1.0f, 0.0f,  // top left  
             0.5f,  0.5f,  0.5f,   1.0f, 0.0f,   0.0f, 1.0f, 0.0f,  // top right 
             0.5f,  0.5f, -0.5f,   1.0f, 1.0f,   0.0f, 1.0f, 0.0f,  // top back right
            -0.5f,  0.5f, -0.5f,   0.0f, 1.0f,   0.0f, 1.0f, 0.0f,  // top back left
        
            //bottom
            -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,   0.0f, -1.0f, 0.0f,  // top left  
             0.5f, -0.5f,  0.5f,   1.0f, 0.0f,   0.0f, -1.0f, 0.0f,  // top right 
             0.5f, -0.5f, -0.5f,   1.0f, 1.0f,   0.0f, -1.0f, 0.0f,  // top back right
            -0.5f, -0.5f, -0.5f,   0.0f, 1.0f,   0.0f, -1.0f, 0.0f,  // top back left
        };

        int indices[] = {
            0,1,3,
            1,2,3,
            4,5,7,
            5,6,7,
            8,9,11,
            9,10,11,
            12,13,15,
            13,14,15,
            16,17,19,
            17,18,19,
            20,21,23,
            21,22,23
        };

        bool wireframe = false;
        bool wireframePressedLastFrame = false;

        Camera cam(45.0f, (float)m_Specs.width / (float)m_Specs.height, 0.1f, 100.0f, this);
        
        Chunk chunk(glm::ivec3(16));

        chunk.InitCamera(&cam);

        Color skyColor(143, 211, 255, 255, false);
        skyColor.NormalizeColor();
        cam.position = glm::vec3(0, 0, -1);

	    while (!glfwWindowShouldClose(m_Window))
	    {
            glClearColor(skyColor.r, skyColor.g, skyColor.b, skyColor.a);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


            if (glfwGetKey(m_Window, GLFW_KEY_0))
            {
                if (!wireframePressedLastFrame)
                {
                    wireframe = !wireframe;
                    wireframePressedLastFrame = true;
                    LOG_INFO("Wireframe: {0}", wireframe);
                }
            }
            else
            {
                wireframePressedLastFrame = false;
            }

            if (!wireframe)
            {
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            }
            else
            {
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            }

            cam.Update(mousePos);

            chunk.GetShader()->SetVec3("lightPos", glm::vec3(sin(glfwGetTime()), 1, cos(glfwGetTime())));
            
            Color lightColor(glm::vec4(143, 211, 255, 255), false);
            lightColor.NormalizeColor();
            chunk.GetShader()->SetVec3("lightColor", lightColor.GetColorVector());

            chunk.Draw();

            glfwSwapBuffers(m_Window);
            glfwPollEvents();
	    }
    }
    GLFWwindow* Application::GetWindow()
    {
        return m_Window;
    }
    void mouse_callback(GLFWwindow* window, double xpos, double ypos)
    {
        mousePos.x = xpos;
        mousePos.y = ypos;
    }
}

