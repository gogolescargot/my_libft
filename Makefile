# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 15:27:49 by ggalon            #+#    #+#              #
#    Updated: 2023/12/06 20:56:57 by ggalon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DIRECTORIES ==================================================================

SRCS_DIR_LIBFT	=	src/

OBJS_DIR_LIBFT	=	obj/

INCL_DIR_LIBFT	=	inc/

# FILES ========================================================================

NAME_LIBFT		= 	libft.a

FILE_C_LIBFT	=	ft_isalnum ft_isprint ft_memcmp ft_putchar_fd ft_split \
					ft_strlcat ft_strncmp ft_substr ft_atoi ft_isalpha \
					ft_itoa ft_memcpy ft_putendl_fd ft_strchr ft_strlcpy \
					ft_strnstr ft_tolower ft_bzero ft_isascii ft_arrayclear \
					ft_memmove ft_putnbr_fd ft_strdup ft_strlen ft_strrchr \
					ft_toupper ft_calloc ft_isdigit ft_memchr ft_memset \
					ft_putstr_fd ft_strjoin ft_strmapi ft_strtrim ft_striteri \
					ft_printf ft_printf_utils \
					get_next_line get_next_line_utils

FILE_H_LIBFT	=	libft ft_printf get_next_line

SRCS_LIBFT		=	$(addsuffix .c, $(addprefix $(SRCS_DIR_LIBFT), $(FILE_C_LIBFT)))

OBJS_LIBFT		=	$(addsuffix .o, $(addprefix $(OBJS_DIR_LIBFT), $(FILE_C_LIBFT)))

INCL_LIBFT		=	$(addsuffix .h, $(addprefix $(INCL_DIR_LIBFT), $(FILE_H_LIBFT)))

# COMMANDS =====================================================================

CC			=	cc

CC_FLAGS	=	-Wall -Wextra -Werror

AR			=	ar

AR_FLAGS	=	-rc

# RULES ========================================================================

all:
	@ echo "\n${BIBlue}Compilation of Libft source files...${NC}"
	@ mkdir -p $(OBJS_DIR_LIBFT)
	@ $(MAKE) --no-print-directory $(NAME_LIBFT)
	@ echo "\n${BIGreen}Libft Ready !${NC}"

$(NAME_LIBFT): $(OBJS_LIBFT)
	@ echo "\n${BICyan}Creating the library...${NC}"
	$(AR) $(AR_FLAGS) $@ $^

$(OBJS_DIR_LIBFT)%.o: $(SRCS_DIR_LIBFT)%.c $(INCL_LIBFT) Makefile
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@ echo "\n${BIRed}Libft binary deletion...${NC}"
	rm -rf $(OBJS_DIR_LIBFT)

fclean:
	@ echo "\n${BIRed}Libft deletion...${NC}"
	rm -rf $(OBJS_DIR_LIBFT)
	rm -f $(NAME_LIBFT)

re: fclean all

.PHONY: all clean fclean re

# COLORS =======================================================================

# Reset
NC=\033[0m

# Regular Colors
Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

# Bold
BBlack=\033[1;30m
BRed=\033[1;31m
BGreen=\033[1;32m
BYellow=\033[1;33m
BBlue=\033[1;34m
BPurple=\033[1;35m
BCyan=\033[1;36m
BWhite=\033[1;37m

# Underline
UBlack=\033[4;30m
URed=\033[4;31m
UGreen=\033[4;32m
UYellow=\033[4;33m
UBlue=\033[4;34m
UPurple=\033[4;35m
UCyan=\033[4;36m
UWhite=\033[4;37m

# Background
On_Black=\033[40m
On_Red=\033[41m
On_Green=\033[42m
On_Yellow=\033[43m
On_Blue=\033[44m
On_Purple=\033[45m
On_Cyan=\033[46m
On_White=\033[47m

# High Intensity
IBlack=\033[0;90m
IRed=\033[0;91m
IGreen=\033[0;92m
IYellow=\033[0;93m
IBlue=\033[0;94m
IPurple=\033[0;95m
ICyan=\033[0;96m
IWhite=\033[0;97m

# Bold High Intensity
BIBlack=\033[1;90m
BIRed=\033[1;91m
BIGreen=\033[1;92m
BIYellow=\033[1;93m
BIBlue=\033[1;94m
BIPurple=\033[1;95m
BICyan=\033[1;96m
BIWhite=\033[1;97m

# High Intensity backgrounds
On_IBlack=\033[0;100m
On_IRed=\033[0;101m
On_IGreen=\033[0;102m
On_IYellow=\033[0;103m
On_IBlue=\033[0;104m
On_IPurple=\033[0;105m
On_ICyan=\033[0;106m
On_IWhite=\033[0;107m
