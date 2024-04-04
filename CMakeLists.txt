cmake_minimum_required(VERSION 3.17)
project(3D-Game-plus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# Указываем путь к SFML
set(SFML_DIR "D:/Projects/Soft/SFML/lib/cmake/SFML")

# Поиск SFML
find_package(SFML 2.6.1 COMPONENTS system window graphics audio REQUIRED)

# Установка конфигурации сборки в режим выпуска
set(CMAKE_BUILD_TYPE Release)

# Добавляем исходные файлы вашего проекта
add_executable(3D-Game-plus main.cpp main.h)

# Связываем ваш проект с SFML
target_link_libraries(3D-Game-plus PRIVATE sfml-audio sfml-network sfml-graphics sfml-window sfml-system)

# Добавляем пути к заголовочным файлам SFML
target_include_directories(3D-Game-plus PRIVATE ${SFML_INCLUDE_DIR})