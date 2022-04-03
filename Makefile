##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make things
##

SRC = include/glad/glad.c \
	  src/main.cpp \
	  src/main_loop.cpp \
	  src/misc/input.cpp \
	  src/shader.cpp \
	  src/vertex.cpp \
	  src/misc/stb_image.cpp \
	  src/texture/texture_loader.cpp \
	  src/matrices/transform.cpp

OBJ = $(SRC:.c=.o)

INCLUDE = -I./include/

CPPFLAGS = -Wall -Wextra

LIB = -L/usr/local/include/

FLAGS = $(INCLUDE) -lGLEW -lglfw -lGLU -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl

NAME = minecraft_hub

all: NAME

NAME: $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LIB) $(FLAGS) $(CFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
