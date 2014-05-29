test : test.cc fraction.o
	g++ -Wall -g test.cc fraction.o -o test

fraction.o : fraction.cc
	g++ -Wall -g -c fraction.cc -o fraction.o

clean:
	rm -rf *.o test *.exe
