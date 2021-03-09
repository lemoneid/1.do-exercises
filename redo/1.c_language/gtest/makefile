.PHONY: clean
CC = g++
MAINOBJ = main.cpp

all : main.o module/test.o
	${CC} -o ./bin/main main.o module/test.o

main.o: ${MAINOBJ}
	${CC} -I./ -c ${MAINOBJ}

module/test.o: module/test.h module/test.cc
	${CC} -I./ -o module/test.o -c module/test.cc

run: all
	./bin/main

clean:
	rm -rf ./a.out *.o  ./bin/main ./module/test.o ./main.o
