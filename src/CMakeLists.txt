cmake_minimum_required(VERSION 3.24)
project(course_project_pdsd)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_GENERATOR "Ninja")
message("generator is set to ${CMAKE_GENERATOR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(.)

add_executable(course_project_pdsd
        main.cpp
        ContList.cpp
        ContList.h
        ForwardList.cpp
        ForwardList.h
        List.cpp
        List.h
        Node.cpp
        Node.h
        Set.cpp
        Set.h
        UnorderedMap.cpp
        UnorderedMap.h
        )
