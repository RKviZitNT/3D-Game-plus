cmake_minimum_required(VERSION 3.17)
project(3DGAME)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)

# Поиск SFML
find_package(SFML 2.6 COMPONENTS graphics audio REQUIRED)

# Добавление исполняемого файла
add_executable(3DGAME main.cpp main.h)

# Связывание с SFML
target_link_libraries(3DGAME sfml-graphics sfml-audio)