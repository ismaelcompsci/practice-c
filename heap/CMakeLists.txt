cmake_minimum_required(VERSION 3.10)
project(Heap)

set(SOURCE_FILES main.c)
add_executable(heap ${SOURCE_FILES})

# Specify the path to the directory containing log.c and log.h
set(LOG_DIR ../log)

# Add the log library to your project
add_library(log STATIC ${LOG_DIR}/log.c)

# Include the log library's directory for header files
target_include_directories(log PUBLIC ${LOG_DIR})

# Link the log library with your heap executable
target_link_libraries(heap PRIVATE log)