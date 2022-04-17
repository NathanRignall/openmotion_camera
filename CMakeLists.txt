# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

project(camera)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Add sub ubdirectory
add_subdirectory(openmotion_led_hat_control)

# Add executable. Default name is the project name, version 0.1
add_executable(camera main.cpp)

# Find any packages needed
find_package (Threads REQUIRED)

# Add the custom lib
target_link_libraries(camera
    openmotion_led_hat_control
    ${CMAKE_THREAD_LIBS_INIT}
)

add_compile_options(-pthread)