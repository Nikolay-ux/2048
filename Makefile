all:./main.cpp
	g++ -c ./main.cpp ./game.cpp
	g++ main.o game.o -o app -lsfml-graphics -lsfml-window -lsfml-system

run:
	./app