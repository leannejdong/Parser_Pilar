cmake_minimum_required(VERSION 3.17)
project(Parser_Pila)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")


add_executable(Parser_Pila main.cpp)
target_link_libraries(Parser_Pila -fsanitize=address)