test : test.cc disjoint_set.o
	g++ -g -Wall -o test test.cc disjoint_set.o

disjoint_set.o : disjoint_set.cc disjoint_set.h
	g++ -g -Wall -c disjoint_set.cc

clean :
	rm -rf test *.o *.exe
