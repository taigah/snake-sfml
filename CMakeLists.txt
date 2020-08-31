cmake_minimum_required(VERSION 3.12)
project(snake VERSION 1.0.0)

add_link_options(
  -lsfml-system
  -lsfml-window
  -lsfml-graphics
)

add_executable(snake
  src/main.cpp
  src/Player.cpp
  src/Cherry.cpp
)
