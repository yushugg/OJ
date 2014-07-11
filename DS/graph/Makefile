test : test.cc graph.o
	g++ -g -Wall -o test test.cc graph.o

graph.o : graph.cc graph.h
	g++ -g -Wall -c graph.cc

clean :
	rm -rf test *.o *.exe
