cmake_minimum_required(VERSION 3.25)
project(CardWar)

set(CMAKE_CXX_STANDARD 17)

add_executable(CardWar sources/card.cpp sources/game.cpp sources/player.cpp Test.cpp StudentTest1.cpp Demo.cpp)
