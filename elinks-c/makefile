CC=gcc
EXE=elinks-search
OUT_DIR=dist
MAIN_PATH=src/main.c
CFLAGS=-Wall -Wextra -Werror -O3 $(MAIN_PATH) -o $(OUT_DIR)/$(EXE)

all:
	$(CC) $(CFLAGS) $(MAIN)
debug:
	$(CC) -g $(CFLAGS) $(MAIN)
