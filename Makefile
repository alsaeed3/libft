# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 14:48:47 by alsaeed           #+#    #+#              #
#    Updated: 2023/06/15 02:09:07 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a

SRCS =			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
				ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c \
				ft_strdup.c ft_atoi.c ft_substr.c ft_strjoin.c ft_strtrim.c \
				ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 
OBJS = 			$(SRCS:.c=.o)

SRC_LIST =  	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c 
OBJ_LIST = 		$(SRC_LIST:.c=.o)

SRC_PRINTF =	ft_putchar.c ft_putstr.c ft_putnbr.c print_hex.c \
				print_pointer.c print_undec.c ft_printf.c ft_atoi.c
OBJ_PRINTF =	$(SRC_PRINTF:.c=.o)

SRC_GNL =		ft_strlen.c ft_strlen_nl.c ft_strjoin.c ret_line.c \
				update_stash.c get_next_line.c
OBJ_GNL =		$(SRC_GNL:.c=.o)

CC = 			cc
CFLAGS =		-Wall -Wextra -Werror
RM = 			rm -f
ARFLAGS = 		ar -rcs

all: 			$(NAME)

$(NAME): 		$(OBJS) $(OBJ_LIST) $(OBJ_PRINTF) $(OBJ_GNL)
				@$(ARFLAGS) $(NAME) $(OBJS) $(OBJ_LIST) $(OBJ_PRINTF) $(OBJ_GNL)

mand:			$(OBJS)
				@$(ARFLAGS) $(NAME) $(OBJS)

list: 			$(OBJ_LIST)
				@$(ARFLAGS) $(NAME) $(OBJ_LIST)

printf: 		$(OBJ_PRINTF)
				@$(ARFLAGS) $(NAME) $(OBJ_PRINTF)

gnl: 			$(OBJ_GNL)
				@$(ARFLAGS) $(NAME) $(OBJ_GNL)

clean:
				@$(RM) $(OBJS) $(OBJ_LIST) $(OBJ_PRINTF) $(OBJ_GNL)

fclean: 		clean
				@$(RM) $(NAME)

re: 			fclean all

.PHONY:			all mand list printf gnl clean fclean re