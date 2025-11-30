NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror -I.
SRC = $(filter-out $(TEST_SRC),$(wildcard *.c))
OBJ = $(SRC:.c=.o)
TEST_BIN = test_lib
TEST_SRC = main.c check.c

# default target
all: $(NAME)

# build static lib from object files
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule to compile each .c -> .o
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

test: CFLAGS += -g -O0
test: fclean $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) ./$(NAME) -o $(TEST_BIN)

# Remove object files
clean:
	rm -f $(OBJ)

# remove object files and library
fclean: clean
	rm -f $(NAME)

# full rebuild
re: fclean all

# tell make these are not actual files
.PHONY: all clean fclean re test

