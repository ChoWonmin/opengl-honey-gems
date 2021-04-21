# Dealing with errors in opengl

## OpenGL functions
1. glDebugMessageCallback
    - http://docs.gl/gl4/glDebugMessageCallback
2. glGetError

---

## Usage

``` cpp
#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

static void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

static void GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] ( " << error << " ) " << function << " "<< file << ":" << line << std::endl;
        return false;
    }
    return true;
}
```

``` cpp
// window loop
GLClearError();
glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
ASSERT(GLClearError());
```

``` cpp
// using macro
GLCall(glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), position, GL_STATIC_DRAW));
// ...
GLCall(glDrawElements(GL_TRIANGLES, s6, GL_UNSIGNED_INT, nullptr));
```