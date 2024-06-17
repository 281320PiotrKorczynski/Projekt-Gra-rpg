cmake_minimum_required(VERSION 3.15)
project(MySFMLProject)

set(CMAKE_CXX_STANDARD 17)
set( SFML_STATIC_LIBRARIES TRUE )

# Dodaj ścieżkę do SFML
set(SFML_DIR "C:/Users/piotr/OneDrive/Pulpit/projekt/SFML-2.5.1//lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(MySFMLProject empty_classes.cpp)

target_link_libraries(MySFMLProject sfml-system sfml-window sfml-graphics sfml-network sfml-audio)