test : test.cc heap.o
	g++ -g -Wall -o test test.cc heap.o

heap.o : heap.cc heap.h
	g++ -g -Wall -c heap.cc

clean :
	rm -rf test *.o *.exe
