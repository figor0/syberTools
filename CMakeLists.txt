cmake_minimum_required(VERSION 3.5)

project(syberTools LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
include_directories(include)

set(SOURCES
)
set(HEADERS
)
add_executable(${PROJECT_NAME} "main.cpp" ${SOURCES} ${HEADERS})
