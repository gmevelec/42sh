# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jboulet <jboulet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 14:08:52 by jboulet           #+#    #+#              #
#    Updated: 2014/03/24 15:47:08 by gmevelec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

HEAD = sh42.h display.h err42.h parser.h exec.h status.h builtins.h
#HEAD := $(addprefix headers/, $(HEAD))

# srcs/err42/
SRCS_ERRS = err42.c
SRCS_ERRS := $(addprefix srcs/err42/, $(SRCS_ERRS))

# srcs/parser/
SRCS_PARS = cmd.c \
			param_split.c \
			instr_split.c \
			instr_split_2.c \
			parser.c \
			pipe_split.c
SRCS_PARS := $(addprefix srcs/parser/, $(SRCS_PARS))

# srcs/exec/
SRCS_EXEC = cmd.c \
			exec.c \
			exec_2.c \
			fd.c \
			file.c \
			free.c \
			paths.c \
			pipe.c
SRCS_EXEC := $(addprefix srcs/exec/, $(SRCS_EXEC))

# srcs/display/
SRCS_DISP = display.c \
			arrow_system.c \
			arrow_system_long.c \
			big_screen_system.c \
			deletion_system.c \
			errors.c \
			history_system.c \
			infos_line_system.c \
			is_key_0.c \
			is_key_1.c \
			is_key_2.c \
			is_key_3.c \
			key_manager.c \
			line_system.c \
			micro_functions_0.c \
			move_termcaps.c \
			move_termcaps_long.c \
			return_system.c \
			signals.c \
			special_keys_system.c \
			termcaps_functions.c
SRCS_DISP := $(addprefix srcs/display/, $(SRCS_DISP))

# srcs/status
SRCS_STAT = status.c
SRCS_STAT := $(addprefix srcs/status/, $(SRCS_STAT))

# srcs/builtins
SRCS_BUIL = ft_cd.c \
			ft_cd_2.c \
			ft_duck.c \
			ft_echo.c \
			ft_exit.c \
			ft_env.c \
			ft_setenv.c \
			ft_unsetenv.c \
			ft_is_builtin.c
SRCS_BUIL := $(addprefix srcs/builtins/, $(SRCS_BUIL))

# srcs/
SRCS_MAIN = main.c
SRCS_MAIN := $(addprefix srcs/, $(SRCS_MAIN))

SRCS = $(SRCS_MAIN) $(SRCS_DISP) $(SRCS_EXEC) $(SRCS_PARS) $(SRCS_ERRS) \
		$(SRCS_STAT) $(SRCS_BUIL)

OBJS = $(SRCS:.c=.o)

LIB_FOLD = srcs/libft/
TERM_FOLD = /usr/lib

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_FOLD)
	gcc $(FLAGS) -o $(NAME) $(OBJS) -L$(LIB_FOLD) -lft -L$(TERM_FOLD) -ltermcap

%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $<

clean:
	rm -rf $(OBJS)
	make clean -C $(LIB_FOLD)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB_FOLD)

re: fclean all

.PHONY: all clean fclean re
