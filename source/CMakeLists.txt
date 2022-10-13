cmake_minimum_required(VERSION 3.12)
include(../pico-sdk/pico_sdk_init.cmake)
project(arcade)
pico_sdk_init()

enable_language(ASM)

#添加编译子目录
add_subdirectory(lib/Config)
add_subdirectory(lib/Infrared)
add_subdirectory(lib/OLED)
add_subdirectory(lib/Icm20948)
add_subdirectory(lib/LCD)
add_subdirectory(lib/Fonts)
add_subdirectory(lib/GUI)
add_subdirectory(flappy)



#添加头文件目录
include_directories(./lib/Config)
include_directories(./lib/GUI)
include_directories(./lib/Icm20948)
include_directories(./lib/LCD)
include_directories(./lib/Infrared)
include_directories(./lib/OLED)
include_directories(./flappy)


# 生成可执行文件
add_executable(arcade 
main.c
)

# enable usb output, disable uart output
pico_enable_stdio_usb(arcade 1)
pico_enable_stdio_uart(arcade 1)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(arcade)

target_link_libraries(arcade LCD OLED Infrared Icm20948 GUI Fonts Config pico_stdlib hardware_spi)