cmake_minimum_required(VERSION 3.19)
project(MV C)

set(CMAKE_C_STANDARD 99)

add_executable(MV
        main.c
        Code/Menu/menu.c
        Code/team.c
        Factory/Tools/tools.c
        Factory/DateTime/datetime.c
        )