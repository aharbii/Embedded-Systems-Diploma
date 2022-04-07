cmake_minimum_required(VERSION 3.23)
project(SUMAPP)
set(SRC_FILES 
    main.c 
    src/calc.c)
message(STATUS "SRC File has ${SRC_FILES}")
message(STATUS "Path is ${CMAKE_SOURCE_DIR}")

if(EXISTS ${CMAKE_SOURCE_DIR}/main.c)
    message(STATUS "main.c file exists")
else() 
    message(FATAL_ERROR "Cannot find main.cpp")
endif()


add_executable(sumapp ${SRC_FILES})

target_include_directories(sumapp PUBLIC include/)