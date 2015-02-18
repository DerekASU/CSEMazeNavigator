  # the compiler: gcc for C program, define as g++ for C++
CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

  # the build target executable:
default: maze

maze: Menu.o Maze.o Node.o
	$(CC) $(CFLAGS) -o maze Maze.o Menu.o Node.o

Menu.o: Menu.cpp Menu.h Node.h
	$(CC) $(CFLAGS) -c Menu.cpp

Maze.o: Maze.cpp Maze.h Menu.h
	$(CC) $(CFLAGS) -c Maze.cpp


Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp

clean:
	$(RM) maze *.o 
