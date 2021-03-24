#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

static unsigned int compileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();

    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        
        char* message = (char*) malloc( length * sizeof(char) );

        glGetShaderInfoLog(id, length, &length, message);
        
        std::cout << "Failed to compile shader!!" << std::endl;
        std::cout << message << std::endl;

        free(message);
        glDeleteShader(id);
        return 0;
    }

    return id;
}

static int createShader(const std::string& vertextShader, const std::string& fragmentShader, const std::string& geometryShader = "")
{
    unsigned int program = glCreateProgram();

    std::cout << "compile vertext shader" << std::endl;
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    unsigned int gs;
    if (geometryShader.length() > 0) {
        std::cout << "compile geometry shader" << std::endl;
        gs = compileShader(GL_GEOMETRY_SHADER, geometryShader);
    }

    std::cout << "compile fragment shader" << std::endl;
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertextShader);

    glAttachShader(program, vs);
    if (geometryShader.length() > 0) {
        glAttachShader(program, gs);
    }
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    if (geometryShader.length() > 0) {
        glDeleteShader(gs);
    }
    
    glDeleteShader(fs);
 
    return program;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "GLEW ERROR!!" << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    float position[] = {
        0.0f,  0.5f, 0.0f, //vertex 1  위 중앙
        0.5f, -0.5f, 0.0f, //vertex 2  오른쪽 아래
        -0.5f, -0.5f, 0.0f //vertex 3  왼쪽 아래
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), position, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

    std::string vertexShader =
        "#version 330 core\n"
        "layout(location = 0) in vec4 position;\n"
        "void main()"
        "{"
        "gl_Position = position;"
        "}";

    const GLchar* geometryShaderSource =
        "#version 330 core\n"
        "layout (points) in;"
        "layout (line_strip, max_vertices = 256) out;"
        ""
        "void makePoint(int num, vec3 point, float length, float angle)"
        "{"
        ""
        "EmitVertex();"
        "}"
        ""
        "void main()"
        "{"
        "gl_Position = gl_in[0].gl_Position + vec4(-0.1, 0.0, 0.0, 0.0);"
        "EmitVertex();"
        "gl_Position = gl_in[0].gl_Position + vec4( 0.1, 0.0, 0.0, 0.0);"
        "EmitVertex();"
        "gl_Position = gl_in[0].gl_Position + vec4( 0.1, 0.1, 0.1, 0.0);"
        "EmitVertex();"
        "EndPrimitive();"
        "}";

    std::string fragmentShader =
        "#version 330 core\n"
        "out vec4 fragmentColor;"
        "void main()"
        "{"
        "fragmentColor = vec4(0.0, 1.0, 1.0, 1.0);"
        "}";

    unsigned int program = createShader(vertexShader, fragmentShader, geometryShaderSource);
    glUseProgram(program);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_POINTS, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(program);

    glfwTerminate();
    return 0;
}