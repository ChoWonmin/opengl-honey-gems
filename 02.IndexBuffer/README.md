``` cpp
    float position[] = {
        -0.5f,  -0.5f, // 0
         0.5f,  -0.5f, // 1
         0.5f,   0.5f, // 2
        -0.5f,  0.5f, // 3
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };
```

## Bind Element Buffer
``` cpp
    unsigned int ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
```

## Draw Element
``` cpp
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
```
- count는 indices number
- 이미 바인드를 했기 때문에 nullptr
