cmake_minimum_required(VERSION 3.15)
project(disasm)

add_compile_options(-Wall -Wextra -Werror -g -O2 -march=native -pipe)
set(CMAKE_C_STANDARD 99)

include_directories(
        includes
        libft
)

link_directories(disasm
        libft)

add_executable(
        src/main.c
        src/utils.c
        src/disasm.c
        )

target_link_libraries(disasm
        "ft"
        )