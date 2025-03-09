##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for CPOOL_day_01 project
##

SRC = $(shell find . -type f -name "*.c" ! -name "main.c" ! -path "./tests/*")

SRC_TEST = $(shell find . -type f -name "*.c" ! -name "main.c")

INCLUDE_H := $(shell find include -type d)

INCLUDE = $(INCLUDE_H:%=-I%)

OBJ = 	$(SRC:%.c=build/%.o)

OBJ_DEBUG = $(SRC:%.c=build-debug/%.o)

OBJ_TEST = $(SRC_TEST:%.c=build-test/%.o)

COMPILE_FLAGS = -Weverything -Wno-pointer-bool-conversion \
				-Wno-unsafe-buffer-usage

CFLAGS += 	-lm $(COMPILE_FLAGS) $(INCLUDE)

DEBUG_FLAGS = -fsanitize=address -g3 -lm $(COMPILE_FLAGS) $(INCLUDE)

TESTING_FLAGS = -fsanitize=address -g3 --coverage -lgcov \
				-lcriterion -lm $(COMPILE_FLAGS) $(INCLUDE)

LIB_NAME = libcuddle.a

DEBUG_NAME = debug

TESTING_NAME = test

RUN_NAME = cuddle

CC	=	clang

build/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

build-debug/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(DEBUG_FLAGS) -c $< -o $@

build-test/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(TESTING_FLAGS) -c $< -o $@

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	@rm -f $(LIB_NAME)
	@ar rc $(LIB_NAME) $(OBJ)

$(DEBUG_NAME): $(OBJ_DEBUG)
	@rm -f $(LIB_NAME)
	@ar rc $(LIB_NAME) $(OBJ_DEBUG)
	$(CC) src/main.c -o $(DEBUG_NAME) $(LIB_NAME) $(DEBUG_FLAGS)

run: $(OBJ)
	@rm -f $(LIB_NAME)
	@ar rc $(LIB_NAME) $(OBJ)
	$(CC) src/main.c -o $(RUN_NAME) $(LIB_NAME) $(CFLAGS)
	./$(RUN_NAME)

tests_run: $(OBJ_TEST)
	@rm -f $(LIB_NAME)
	@ar rc $(LIB_NAME) $(MY_LIB) $(OBJ_TEST)
	$(CC) -o $(TESTING_NAME) $(LIB_NAME) \
		$(TESTING_FLAGS)
	./$(TESTING_NAME)

show_test: tests_run
	mkdir -p coverage
	gcovr -r . --html --html-details -o coverage/index.html
	firefox coverage/index.html

clean:
	$(shell find . -type f -name "*.o" -delete)

fclean: clean
	rm -rf build
	rm -rf build-debug
	rm -rf build-test
	rm -f $(LIB_NAME)
	rm -f $(DEBUG_NAME)
	rm -f $(TESTING_NAME)
	rm -f coding-style-reports.log
	rm -f $(MY_LIB)
	rm -rf coverage
	$(shell find . -name "*.gcda" -delete)
	$(shell find . -name "*.gcno" -delete)

re: fclean all
