# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/11 14:31:26 by nalysann          #+#    #+#              #
#    Updated: 2020/10/11 14:31:31 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.17)
project(corewar)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Wall -Wextra -Werror -O2 -march=native -pipe)

include_directories(include
        libft/include)

link_directories(asm
        libft)

add_executable(asm
        src/asm/op.c)

target_link_libraries(asm
        "ft"
        )

link_directories(corewar
        libft)

add_executable(corewar
        src/corewar/main.c src/corewar/init_data.c)

target_link_libraries(corewar
        "ft"
        )
