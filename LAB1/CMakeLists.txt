cmake_minimum_required(VERSION 3.10)
project(LAB1)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

# 添加各个可执行文件
add_executable(solution_1 solution_1.cpp)
add_executable(solution_2 solution_2.cpp)
add_executable(solution_3 solution_3.cpp)
add_executable(battle battle.cpp)
add_executable(check_input check_input.cpp)
add_executable(rand_input rand_input.cpp)
