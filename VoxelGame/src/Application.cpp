#include "Application.h"
#include"Log.h"

#include"shader.h"

Kepeca::Application::Application(AppSpecs specs)
    :m_Specs(specs),m_Window(nullptr)
{
}

Kepeca::Application::~Application()
{
}

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.8f, 0.9f, 1.0f);\n"
"}\n\0";

void Kepeca::Application::Run()
{
    Kepeca::Log::Init();

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


    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);


    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);




	while (!glfwWindowShouldClose(m_Window))
	{
        glClearColor(m_Specs.r, m_Specs.g, m_Specs.b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        shader.use();
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3);


        glfwSwapBuffers(m_Window);
        glfwPollEvents();
	}
}
