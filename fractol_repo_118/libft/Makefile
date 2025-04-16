# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 17:18:38 by apardo-m          #+#    #+#              #
#    Updated: 2023/10/08 18:04:08 by apardo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADERS = libft.h ft_printf.h
FLAGS = -Wall -Wextra -Werror
AR_FLAGS = -rcs
SRCS_LIBFT = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putendl_fd.c \
	ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_striteri.c \
	ft_strmapi.c \
	ft_split.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_putunsignbr.c \
	ft_puthex.c \
	ft_mystrtod.c
SRCS_PRINTF = ft_printf.c \
	ft_printf_func_chars.c \
	ft_printf_func_hex.c \
	ft_printf_func_nbrs.c

SRCS_BONUS = ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

SRCS = $(SRCS_LIBFT) $(SRCS_PRINTF) 
OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJS) 	
	@echo "--> Object files generated!\n"
	ar $(AR_FLAGS) $@ $? 
	@echo "--> Library Completed!"

bonus: .bonus 
	
.bonus: $(OBJS_BONUS)
	@echo "--> BONUS Object files generated!\n"
	ar $(AR_FLAGS) $(NAME) $?
	@echo "-->BONUS  Library Completed!"
	@touch .bonus

%.o: %.c Makefile $(HEADERS)
	cc $(FLAGS) -c $< -o $@
	
clean:
	@echo "--> Remove *.o files."
	rm -rf $(OBJS) $(OBJS_BONUS) .bonus

fclean: clean
	@echo "--> Remove $(NAME) file."
	rm -rf $(NAME)	
	
re: fclean all

.PHONY: all clean fclean re bonus
