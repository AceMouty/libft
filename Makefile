NAME = libft.a
INC_DIR = include/libft

CC = clang
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

AR = ar
ARFLAGS = rsc 
# r: replace | s: index | c: copy

SRC = $(filter-out $(TEST_SRC),$(wildcard *.c))
OBJ = $(SRC:.c=.o)
TEST_BIN = test_lib
TEST_SRC = main.c check.c

# --- external libs ---
LIB_DIR = lib

# ft_printf: lib repo, branch, where the archive is kept, and the temp clone
FTPRINTF_URL = https://github.com/AceMouty/ft_printf.git
FTPRINTF_REF = main
FTPRINTF_DIR = $(LIB_DIR)/ft_printf
FTPRINTF_LIB = $(FTPRINTF_DIR)/libftprintf.a
FTPRINTF_TMP = $(LIB_DIR)/ft_printf_src

# get_next_line: same setup as ft_printf
GNL_URL = https://github.com/AceMouty/ft_getnextline.git
GNL_REF = main
GNL_BUFFER_SIZE = 42
GNL_DIR = $(LIB_DIR)/ft_getnextline
GNL_LIB = $(GNL_DIR)/libftgetnextline.a
GNL_TMP = $(LIB_DIR)/ft_getnextline_src

# scratch area used when merging the archives
MERGE_DIR = $(LIB_DIR)/merge_objs
# --- end external libs

# default target
all: $(NAME)

# fetch, build, keep the archive + public header, delete the clone
$(FTPRINTF_LIB):
	rm -rf $(FTPRINTF_TMP)
	git clone --depth 1 --branch $(FTPRINTF_REF) $(FTPRINTF_URL) $(FTPRINTF_TMP)
	$(MAKE) -C $(FTPRINTF_TMP)
	mkdir -p $(FTPRINTF_DIR)
	cp $(FTPRINTF_TMP)/libftprintf.a $(FTPRINTF_DIR)/
	cp $(FTPRINTF_TMP)/include/ft_printf.h $(INC_DIR)/
	rm -rf $(FTPRINTF_TMP)

$(GNL_LIB):
	rm -rf $(GNL_TMP)
	git clone --depth 1 --branch $(GNL_REF) $(GNL_URL) $(GNL_TMP)
	$(MAKE) -C $(GNL_TMP) BUFFER_SIZE=$(GNL_BUFFER_SIZE)
	mkdir -p $(GNL_DIR)
	cp $(GNL_TMP)/libftgetnextline.a $(GNL_DIR)/
	cp $(GNL_TMP)/include/get_next_line.h $(INC_DIR)/
	rm -rf $(GNL_TMP)

# unpack both external archives, then pack everything into libft.a
$(NAME): $(OBJ) $(FTPRINTF_LIB) $(GNL_LIB)
	rm -rf $(MERGE_DIR) $(NAME)
	mkdir -p $(MERGE_DIR)
	cd $(MERGE_DIR) && $(AR) x $(CURDIR)/$(FTPRINTF_LIB)
	cd $(MERGE_DIR) && $(AR) x $(CURDIR)/$(GNL_LIB)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(MERGE_DIR)/*.o
	rm -rf $(MERGE_DIR)

# Rule to compile each .c -> .o
%.o: %.c $(INC_DIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

test: CFLAGS += -g -O0
test: fclean $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) ./$(NAME) -o $(TEST_BIN)

# Remove object files
clean:
	rm -f $(OBJ)
	rm -rf $(MERGE_DIR)

# remove object files and library
fclean: clean
	rm -f $(NAME) $(TEST_BIN)

depclean:
	rm -rf $(LIB_DIR)
	rm -rf $(INC_DIR)/ft_printf.h $(INC_DIR)/get_next_line.h

# full rebuild
re: fclean all

# tell make these are not actual files
.PHONY: all clean fclean re test

