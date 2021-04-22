# Vertex Array Object
- 연결한 Attribute의 링크 정보를 저장한 Array
- Gen -> Bind의 순서
```cpp
// 링크정보를 넣어줄 vao를 생성
glGenVertexArrays(1, vao);
// Attribute를 Bind
glBindVertexArrays(vao);
```

## Vertex Buffer Object
- 그리기 위해 필요한 실제 데이터 버퍼
- Gen -> Bind -> Data
```cpp
glGenBuffers(2, Buffers);
glBindBuffer(GL_ARRAY_BUFFER, Buffers[0]);
glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), 
```

---
##
``` cpp
glUseProgram(0);
glBindBuffer(GL_ARRAY_BUFFER, 0);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

while (!glfwWindowShouldClose(window))
{
    /* Render here */ 
    glClear(GL_COLOR_BUFFER_BIT);

    r += addR;
    if (r >= 1.f || r <= 0.f) {
        addR = -addR;
    }

    glUseProgram(program );
    glUniform4f(location, r, 0.3f, 0.8f, 1.0f);

    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);


    GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
}
```
