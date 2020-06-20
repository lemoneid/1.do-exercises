.PHONY: clean
all: main.o haizei/test.o
	g++ main.o haizei/test.o -o ./bin/haizei
main.o: main.cpp
	g++ -c -I./ main.cpp
haizei/test.o: haizei/test.cc haizei/test.h 
	g++ -c -I./ -o haizei/test.o haizei/test.cc 
clean:
	rm -rf ./bin/haizei main.o haizei/test.o
