all:./main.cpp
	g++ -c ./main.cpp ./game.cpp
	g++ main.o game.o -o app

run:
	./app