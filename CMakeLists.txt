cmake_minimum_required(VERSION 2.8.0)
project(PlayingCardsCPP)

include_directories(includes)

file(GLOB SOURCE "src/*.cpp")

add_executable(cards ${SOURCE})

