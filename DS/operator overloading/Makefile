test : test.o fraction.o ZeroDivisionException.o
	g++ -o test test.o fraction.o ZeroDivisionException.o

test.o : test.cc fraction.h
	g++ -Wall -g -c test.cc

fraction.o : fraction.cc ZeroDivisionException.h
	g++ -Wall -g -c fraction.cc

ZeroDivisionException.o : ZeroDivisionException.cc
	g++ -Wall -g -c ZeroDivisionException.cc

clean:
	rm -rf *.o test *.exe
