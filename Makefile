all: main

main: main.cpp
	g++ -O3 -march=native -o main main.cpp
