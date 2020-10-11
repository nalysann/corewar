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
project(corewar C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -O2 -march=native -pipe")

include_directories(include)
include_directories(libft/include)

add_subdirectory(libft)

add_executable(asm)

target_link_libraries(asm ft)

add_executable(corewar)

target_link_libraries(corewar ft)
