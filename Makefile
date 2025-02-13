CC = gcc
SRC = src/main.c
BIN = bin/main.exe

all: compile run

compile: $(SRC)
	$(CC) -o $(BIN) $(SRC)

run: $(BIN) 
	@$(BIN)

clean:
	rm -f $(BIN)