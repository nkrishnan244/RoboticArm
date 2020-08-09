cmake_minimum_required(VERSION 3.5.1)

set(This RoboticArm)

set(CMAKE_VERBOSE_MAKEFILE off)
set(CMAKE_CXX_STANDARD 14)

project(${This})

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(PkgConfig REQUIRED)

set(SOIL2 /home/nikhil/SOIL2/lib/libsoil2.so)

pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} /home/nikhil/SOIL2/include /home/nikhil/RoboticArm/headers)

add_executable(${This} 
    src/main.cpp 
    src/simulation.cpp
    src/model.cpp
    src/shader.cpp
    src/vertex.cpp
    src/cylinder.cpp
    src/mesh.cpp
    src/camera.cpp
)

target_link_libraries(${This} /home/nikhil/SOIL2/lib/libsoil2.so ${OPENGL_LIBRARIES} ${GLFW_STATIC_LIBRARIES} ${GLEW_LIBRARIES})