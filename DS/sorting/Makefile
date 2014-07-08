test : sorting.o test.cc
	g++ -g -Wall -o test test.cc sorting.o

sorting.o : sorting.cc sorting.h
	g++ -g -Wall -c sorting.cc

clean :
	rm -rf test *.o *.exe
