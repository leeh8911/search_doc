cmake_minimum_required(VERSION 3.11.3)

project(SEARCH_DOC)

message("${CMAKE_CURRENT_BINARY_DIR}")

set(LIB_NAME ${PROJECT_NAME}_LIB)
set(EXEC_NAME ${PROJECT_NAME}_EXE)
set(TEST_NAME ${PROJECT_NAME}_TEST)

set(CMAKE_MODULE_PATH 
    ${CMAKE_MODULE_PATH} 
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Set the C++ standard we will use
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(OPTION_BUILD_DOCS "Build documentation." OFF)
option(OPTION_TEST_ALL "Execute all test" OFF)

if (OPTION_TEST_ALL)
add_compile_definitions(TEST_ALL)
endif(OPTION_TEST_ALL)

find_program(CLANGTIDY clang-tidy)
if(CLANGTIDY)
message(STATUS "activate clang-tidy")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY "${CLANGTIDY};-extra-arg=-Wno-unknown-warning-option;-fix")
else()
message(SEND_ERROR "clang-tidy requested but executable not found")
endif()

message(STATUS ${OPTION_BUILD_DOCS})
message(STATUS OPTION_BUILD_DOCS)

find_package(Python3 REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(SQLite3 REQUIRED)

if(OPTION_BUILD_DOCS)
message(STATUS "Build only documentation")
add_subdirectory(docs)
else()
message(STATUS "Build source and test files")
add_subdirectory(src)
add_subdirectory(test)
add_dependencies(${TEST_NAME} ${LIB_NAME})
endif()


