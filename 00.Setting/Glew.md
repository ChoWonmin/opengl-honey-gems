# Glew

## download
http://glew.sourceforge.net/basic.html

## setup
- glfwMakeContextCurrent() 이후에 glewInit()
- $(SolutionDir)/Dependencies/GLEW로 glew 옮기기
- $(SolutionDir)/Dependencies/GLEW/include
- linker > input에 glew32s.lib
- c/c++ > Prepoccessor 에 GLEW_STATIC
