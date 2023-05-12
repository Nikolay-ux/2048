all:./main.cpp
	g++ -c ./main.cpp
	g++ main.o -o app

run:
	./app