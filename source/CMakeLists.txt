cmake_minimum_required(VERSION 3.17)

set( CMAKE_CXX_COMPILER "arm-none-eabi-g++" )
set( CMAKE_C_COMPILER "arm-none-eabi-gcc" )
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include(../pico-sdk/pico_sdk_init.cmake)

project(arcadeHall C CXX ASM)

pico_sdk_init()

enable_language(CXX)
enable_language(ASM)

add_executable(arcade 
main.cpp
screen/Screen.cpp
util/Random.cpp
image/Draw.cpp
image/StartScreen.cpp
)


#添加编译子目录
add_subdirectory(lib/Config)
add_subdirectory(lib/Infrared)
add_subdirectory(lib/OLED)
add_subdirectory(lib/Icm20948)
add_subdirectory(lib/LCD)
add_subdirectory(lib/Fonts)
add_subdirectory(lib/GUI)
add_subdirectory(flappy)
add_subdirectory(spaceinvader)



#添加头文件目录
include_directories(./lib/Config)
include_directories(./lib/GUI)
include_directories(./lib/Icm20948)
include_directories(./lib/LCD)
include_directories(./lib/Infrared)
include_directories(./lib/OLED)
include_directories(./flappy)
include_directories(./spaceinvader)
include_directories(./screen)
include_directories(./util)


# enable usb output, disable uart output
pico_enable_stdio_usb(arcade 1)
pico_enable_stdio_uart(arcade 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(arcade)

target_include_directories(arcade
    PRIVATE 
    /workspaces/arcade/source/flappy
    /workspaces/arcade/source/spaceinvader       
    /workspaces/arcade/source/image       
)


target_link_libraries(arcade LCD OLED Infrared Icm20948 GUI Fonts Config pico_stdlib hardware_spi)