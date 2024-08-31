#include "Application.h"
#include"Log.h"
#include"glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

#include"OpenGLObjects.h"

namespace Kepeca
{
    Application::Application(AppSpecs specs)
        :m_Specs(specs),m_Window(nullptr)
    {
    }

    Application::~Application()
    {
    }

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

        glViewport(0, 0, m_Specs.width, m_Specs.height);


    
        Shader shader("res/shaders/default.vert", "res/shaders/default.frag");
        float vertices[] = {
            //      COORDS          UV              NORMAL
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   0.0f, 0.0f, 1.0f, // left  
             0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   0.0f, 0.0f, 1.0f, // right 
            -0.5f,  0.5f, 0.0f,   0.0f, 1.0f,   0.0f, 0.0f, 1.0f, // top left

             0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   0.0f, 0.0f, 1.0f, // right   
             0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   0.0f, 0.0f, 1.0f, // top right
            -0.5f,  0.5f, 0.0f,   0.0f, 1.0f,   0.0f, 0.0f, 1.0f  // top left
        
        };
        VertexBufferObject VBO(vertices, sizeof(vertices));
        VertexArrayObect VAO;

        VBO.UnBind();
        VAO.UnBind();
    

        bool wireframe = false;
        bool wireframePressedLastFrame = false;

        glm::mat4 model(1.0f);

        glm::mat4 view(1.0f);
        view = glm::translate(view, glm::vec3(0, 0, -3.0f));

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)m_Specs.width/ (float)m_Specs.height, 0.1f, 100.f);

        
	    while (!glfwWindowShouldClose(m_Window))
	    {
            glClearColor(m_Specs.r, m_Specs.g, m_Specs.b, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);


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

            if (wireframe)
            {
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            }
            else
            {
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            }

            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(sin(glfwGetTime()), 0.0f, 0.0f));

            shader.Bind();
        
            shader.SetMat4("model", model);
            shader.SetMat4("view", view);
            shader.SetMat4("projection", projection);
        
            VAO.Bind();
            glDrawArrays(GL_TRIANGLES, 0, 6);


            glfwSwapBuffers(m_Window);
            glfwPollEvents();
	    }
    }
}

