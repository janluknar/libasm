# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 12:52:34 by jluknar-          #+#    #+#              #
#    Updated: 2020/07/09 09:47:31 by jluknar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJ =		$(SRC:.s=.o)
FLAGS =		-Wall -Werror -Wextra
ASM_FLAGS =	-f macho64
NAME =		libasm.a
%.o: 		%.s

	nasm $(ASM_FLAGS)	$<

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)
	gcc $(FLAGS) $(NAME) main.c
clean:
	rm -rf $(OBJ)
fclean:
	rm -rf $(OBJ) $(NAME) a.out
re:	fclean $(NAME)

.PHONY:		clean fclean 