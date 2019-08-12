CC = g++
SRC = src/Othello.cpp src/Engine.cpp
INCLUDE = include/

run: othello
	./othello

othello: 
	$(CC) -o $@ $(SRC) -I $(INCLUDE)

