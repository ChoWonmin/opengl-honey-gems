# Create OpenGL window

glfw, glew, glad


## glfw
https://www.glfw.org/

### build
1. cmake
    - glfw > build 생성
    - cmake > Browe Source file에서 glfw 선택
    - cmake > Browse Build 에서 glfw > build 선택
    - cmake > config 에서 visual studio version 선택
    - glfw >build > GLFW.sln이 생성되면 성공
    - glfw >build > GLFW.sln 실행
    - Build Solution
    - glfw > include > glfw를 opengl_include
    - glfw > build > src > Debug > glfw3.lib를 opengl_lib
2. visual studio
    - visuadl studio 버전별로 바이너리 파일도 다운로드할 수 있다.

### project
- visual studio > empty project 생성
- release, x64 변경
- property > VC++ Directories 
    - include directory에 opengl_include 추가
    - library directory에 opengl_lib 추가
- property > configure > Linker > input
    - Additionnal Dependencies
    - ```
        oepngl32.lib
        glfw3.lib
    - oepngl32.lib;glfw3.lib;%(AdditionnalDenpendencies)

## GLAD
https://glad.dav1d.de/

- web service에서 빌드 파일 제공
- version 선택
- profile : core
- glad.zip 다운로드 후 압축 풀기
- include
    - opengl_include로 glad/glad, glad/KHR 이동
- lib
    - glad/glad.c를 프로젝트에 이동
    - source file > new item > existing file