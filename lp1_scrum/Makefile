PROG = SCRUM
CC = g++
CPPFLAGS = -Wall -ansi -pedantic -g -O0 -std=c++11 -Iinclude
OBJS = main.o backlog.o dev.o pessoa.o productOwner.o scrumMaster.o sprint.o tarefa.o tester.o

all:
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

main.o:
	$(CC) $(CPPFLAGS) -c main.cpp -o main.o

backlog.o : include/backlog.h
	$(CC) $(CPPFLAGS) -c backlog.cpp -o backlog.o

clean:
	rm -r -f core $(PROG) $(OBJS)
