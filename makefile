# main: move.o maze.o maze.h
# 	g++ main.cpp -o main

# maze.o: maze.cpp maze.h
# 	g++ -c maze.cpp

# move.o: move.cpp maze.h
# 	g++ -c move.cpp

# 等价于：g++ move.cpp maze.cpp maze.h main.cpp -o main
main:move.cpp maze.cpp maze.h main.cpp
	g++ main.cpp -o main