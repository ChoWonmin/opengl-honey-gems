# Uniform

- 변수명으로 cpu에서 gpu로 데이터 전송하는 방법

## Usage


### Step 1. 색상 적용
```shader
#version 330 core

layout(location = 0) out vec4 fragmentColor;

uniform vec4 u_Color;

void main()
{
    fragmentColor = u_Color;
};
```

``` cpp
unsigned int program = createShader(source.VertexSource, source.FragmentSource);
glUseProgram(program);

int location = glGetUniformLocation(program, "u_Color");
ASSERT(location != -1);
glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f);
```
- shader에서 uniform 변수 선언
- cpp에서 glGetUniformLocation()으로 변수명에 대한 location 할당
- glUniform~() 으로 location에 해당하는 데이터 정의

### Step 2. 실시간 색상 변화
``` cpp
// glfwSwapInterval(1);

unsigned int program = createShader(source.VertexSource, source.FragmentSource);
glUseProgram(program);

float r = 0.2f;
float addR = 0.0001f;

int location = glGetUniformLocation(program, "u_Color");

/* Loop until the user closes the window */
while (!glfwWindowShouldClose(window))
{
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    glUniform4f(location, r, 0.3f, 0.8f, 1.0f);

    r += addR;
    if (r >= 1.f || r <= 0.f) {
        addR = -addR;
    }

    GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
}
```
