# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niragne <niragne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 15:27:42 by niragne           #+#    #+#              #
#    Updated: 2020/01/27 18:15:02 by niragne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Hello-World.gb

SRCS = hello-world.asm
OBJS = $(SRCS:%.asm=%.o)

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJS))

AS = ~/.brew/bin/rgbasm
LINKER = ~/.brew/bin/rgblink
ASFLAGS = 


$(NAME): $(OBJ)
	$(LINKER) -o $(NAME) $(OBJ)	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.asm
	$(AS) -o $@ $(CFLAGS) -i $(INC_DIR)/ $<

