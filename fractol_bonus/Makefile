
NAME = FRACTOL

BONUS = FRACTOL_BONUS

CC = cc 

CFLAGS = -Wall -Wextra -Werror

FILES = MANDATORY/julia.c MANDATORY/mandelbrot.c MANDATORY/evenements.c MANDATORY/les_outils.c MANDATORY/main.c

FILES_BONUS = BONUS/main_bonus.c BONUS/mandelbrot_bonus.c BONUS/julia_bonus.c BONUS/les_outils_bonus.c \
BONUS/evenements_julia_bonus.c BONUS/evenements_mandelbrot_bonus.c BONUS/evenements_tricorn_bonus.c \
BONUS/fonction_couleurs_bonus.c BONUS/tricorn_bonus.c


OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(FILES_BONUS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lm -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

bonus: $(OBJS_BONUS)
		$(CC)  $(CFLAGS) $(OBJS_BONUS) -lm -lmlx -framework OpenGL -framework AppKit -o $(BONUS) 

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

%.o : %.c fractol.h
	$(CC) $(CFLAGS) -Imlx -c  $< -o $@ 

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)


re : fclean all

.PHONY: all clean fclean re