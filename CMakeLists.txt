cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(factorial)

add_library(${PROJECT_NAME} STATIC src/fact.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>")

include(CMakePackageConfigHelpers)

configure_package_config_file(
    "Config.cmake.in"
    "${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "lib/cmake/${PROJECT_NAME}"
)

install(TARGETS factorial RUNTIME DESTINATION bin)
install(FILES "${PROJECT_NAME}Config.cmake" DESTINATION "lib/cmake/${PROJECT_NAME}")