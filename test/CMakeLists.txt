set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

find_package(GTest REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)


file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${TEST_NAME} ${SRC_FILES})

target_link_libraries(
    ${TEST_NAME} PUBLIC
    ${LIB_NAME}
    ${GTEST_LIBRARIES} 
    pthread
    Eigen3::Eigen
    SQLite::SQLite3
)

target_include_directories(${TEST_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}"
    "${EIGEN3_INCLUDE_DIR}"
    "${GTEST_INCLUDE_DIRS}"
    ${SQLite3_INCLUDE_DIRS}
)


include(GoogleTest)
gtest_discover_tests(${TEST_NAME})

# get_target_property(TEST_INCLUDE_DIRS ${TEST_NAME} INCLUDE_DIRECTORIES)
# foreach(dir ${TEST_INCLUDE_DIRS} )
#     message(STATUS ${dir})
# endforeach()