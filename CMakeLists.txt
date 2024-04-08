cmake_minimum_required(VERSION 3.28)
project(3DGAME CXX)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "Операционная система: Windows")
    set(SFML_DIR "D:/Projects/Soft/SFML/lib/cmake/SFML")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    message(STATUS "Операционная система: Linux")
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    message(STATUS "Операционная система: macOS")
else()
    message(STATUS "Неизвестная операционная система")
endif()

add_executable(3DGAME
    main.cpp
    src/mazeGen.cpp
    src/mazeGen.h
    src/drawing.cpp
    src/drawing.h
    src/map.cpp
    src/map.h
    src/player.cpp
    src/player.h
    src/rayCasting.cpp
    src/rayCasting.h
    src/config.h
)

find_package(SFML 2.6.1 COMPONENTS graphics audio REQUIRED)

target_link_libraries(3DGAME sfml-graphics sfml-audio)