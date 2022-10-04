main: move.o maze.o
	g++ main.cpp

maze.o: maze.cpp maze.h
	g++ -c maze.cpp

move.o: move.cpp maze.h
	g++ -c move.cpp

