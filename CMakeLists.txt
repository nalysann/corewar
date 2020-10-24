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

add_executable(
        src/corewar/main.c
        src/corewar/init_data.c
        src/corewar/utils.c
        src/corewar/players.c
        src/corewar/parse.c
        src/corewar/int_utils.c
        src/corewar/init_game.c
        src/corewar/carriege.c
        src/corewar/game.c
        src/corewar/op.c
        src/corewar/champ_op.c
        src/corewar/arena.c
        src/corewar/args.c
        src/corewar/champ_ops/ops_array.c
        src/corewar/champ_ops/add.c
        src/corewar/champ_ops/aff.c
        src/corewar/champ_ops/and.c
        src/corewar/champ_ops/fork.c
        src/corewar/champ_ops/ld.c
        src/corewar/champ_ops/ldi.c
        src/corewar/champ_ops/lfork.c
        src/corewar/champ_ops/live.c
        src/corewar/champ_ops/lld.c
        src/corewar/champ_ops/lldi.c
        src/corewar/champ_ops/or.c
        src/corewar/champ_ops/st.c
        src/corewar/champ_ops/sti.c
        src/corewar/champ_ops/sub.c
        src/corewar/champ_ops/xor.c
        src/corewar/champ_ops/zjmp.c


        src/corewar/finish.c)

target_link_libraries(corewar
        "ft"
        )
