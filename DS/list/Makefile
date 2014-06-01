test : test.o list.o
	g++ test.o list.o -o test

test.o : test.cc list.h
	g++ -Wall -g -c test.cc

list.o : list.cc list.h node.h
	g++ -Wall -g -c list.cc

node.o : node.cc node.h
	g++ -Wall -g -c node.cc

clean:
	rm -rf test *.o *.exe
