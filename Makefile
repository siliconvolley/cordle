CC = gcc
SRC = src/main.c
BIN = bin/main.exe

all: compile run

compile: $(SRC)
	mkdir -p $(dir $(BIN))
	$(CC) -o $(BIN) $(SRC)

run: $(BIN)
	@$(BIN)

clean:
	rm -f $(BIN)
