# Setup

1. 빈 프로젝트 생성
2. show all files
3. src 폴더 생성
4. glfw :: 프로젝트 > Dependencies > GLFW
    - lib-vc${version}
    - include
5. All Configurations, x64(vc-2019는 x64)
5. include :: property > C/C++ > General > Additionnal Include Directories
    - $(SolutionDir) : 매크로 기능 제공(현재 솔루션.sln Dir)
    - ```
        $(SolutionDir)Dependencies\GLFW\include
6. lib :: Linker 
    - General Additional > Library Directories
    - ```
        $(SolutionDir)Dependencies\GLFW\lib-vc2019
    - input > Additional Dependencies
    - ``` glfw3.lib


# index

1. setup
2. glew
