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

dev.o : include/dev.h
	$(CC) $(CPPFLAGS) -c dev.cpp -o dev.o

pessoa.o : include/pessoa.h
	$(CC) $(CPPFLAGS) -c pessoa.cpp -o pessoa.o

productOwner.o : include/productOwner.h
	$(CC) $(CPPFLAGS) -c productOwner.cpp -o productOwner.o

scrumMaster.o : include/scrumMaster.h
	$(CC) $(CPPFLAGS) -c scrumMaster.cpp -o scrumMaster.o

sprint.o : include/sprint.h
	$(CC) $(CPPFLAGS) -c sprint.cpp -o sprint.o

tarefa.o : include/tarefa.h
	$(CC) $(CPPFLAGS) -c tarefa.cpp -o tarefa.o

tester.o : include/tester.h
	$(CC) $(CPPFLAGS) -c tester.cpp -o tester.o

run:
	./$(PROG)

clean:
	rm -r -f core $(PROG) $(OBJS)
