cmake_minimum_required(VERSION 3.28)
project(raycaster C)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find GLUT
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

set(CMAKE_C_STANDARD 11)

add_executable(raycaster main.c globals.h
        player/player.h
        player/player.c)

# Link against OpenGL, GLUT, GLU, and the math library
target_link_libraries(raycaster PRIVATE OpenGL::GL GLUT::GLUT GLU m)
