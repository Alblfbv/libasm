# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 10:53:45 by allefebv          #+#    #+#              #
#    Updated: 2021/02/04 12:52:37 by allefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a
TESTER		=	libasm_tester

ASM			=	nasm -f elf64
AR			=	ar -rcs
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRCS_DIR	=	srcs/
SRCS_FILES	=	ft_strlen.s	\
				ft_strcpy.s	\
				ft_strcmp.s	\
				ft_write.s	\
				ft_read.s	\
				ft_strdup.s
SRCS		=	$(addprefix $(SRCS_DIR),$(SRCS_FILES))

OBJS_DIR	=	objs/
$(shell mkdir -p $(OBJS_DIR))
OBJS		=	$(SRCS:$(SRCS_DIR)%.s=$(OBJS_DIR)%.o)


all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)
				echo "made libasm"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.s Makefile
				$(ASM) $< -o $@

test:			$(NAME) main.c
				$(CC) $(CFLAGS) main.c $(NAME) -o $(TESTER) libasm.h

clean:			
				rm -rf $(OBJS_DIR)
				echo "cleaned libasm"

fclean:			clean
				rm -f $(NAME)
				rm -f $(TESTER)
				echo "fcleaned libasm"
	
re:				fclean
				$(MAKE) all

.SILENT:		$(OBJS) $(NAME) all clean fclean re
