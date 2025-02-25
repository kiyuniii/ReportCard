CC = gcc
CFLAGS = -Wall -Wextra -Iinc

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

SRCS = main.c 					\
       $(SRC_DIR)/database.c 	\
       $(SRC_DIR)/linked_list.c \
       $(SRC_DIR)/student.c		\
	   $(SRC_DIR)/table.c

OBJS = $(OBJ_DIR)/main.o 		\
       $(OBJ_DIR)/database.o 	\
       $(OBJ_DIR)/linked_list.o \
	   $(OBJ_DIR)/student.o \
       $(OBJ_DIR)/table.o

TARGET = reportCard.out

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/main.o: main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
