cmake_minimum_required(VERSION 3.18)

# include pico-related cmake functions
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# define project (project name is accessed as ${PROJECT_NAME})
project(script C CXX ASM)

# initialize pico-related cmake structure
pico_sdk_init()

# add executable named as PROJECT_NAME, compiled from script.cpp
add_executable(${PROJECT_NAME} 
    script.cpp
)

# link pico-related libraries (available from pico_sdk_init() ?)
target_link_libraries(${PROJECT_NAME}
    pico_stdlib 
    hardware_gpio 
    hardware_pwm
)

# setup 'make' so that uf2 files are also created
pico_add_extra_outputs(${PROJECT_NAME})