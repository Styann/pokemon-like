cmake_minimum_required(VERSION 3.25.1)

project(pokemon_like)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# include_directories(./objects/Player)

add_executable(pokemon_like
    ./src/game.cpp
    ./src/Player/Player.cpp
    ./src/Settings/Settings.cpp
    ./src/SpriteSheet/SpriteSheet.cpp
)

# target_sources(pokemon_like PUBLIC
#     ./src/game.cpp
#     ./objects/Player/Player.cpp
#     ./objects/Player/Player.hpp
# )

find_package(raylib 3.0 REQUIRED)
target_link_libraries(pokemon_like raylib)
