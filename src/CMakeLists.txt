file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(${LIB_NAME} STATIC
    ${SRC_FILES})

add_executable(${EXEC_NAME} ${SRC_FILES})

find_package(Python3 REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

target_link_libraries(
    ${LIB_NAME} PUBLIC
    pthread
    Eigen3::Eigen
)

target_include_directories(${LIB_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}
    "${EIGEN3_INCLUDE_DIR}"
)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(${LIB_NAME} PRIVATE -Werror -Wall -Wextra -Wuninitialized -pedantic)
endif()
if ( MSVC )
    target_compile_options(${LIB_NAME} PRIVATE /W4)
endif()