CC=g++ -std=c++11 -g
exe=stairs

$(exe): stairs.o recurse.o
	$(CC) stairs.o recurse.o -o $(exe)

stairs.o: stairs.cpp
	$(CC) -c stairs.cpp

recurse.o: recurse.cpp
	$(CC) -c recurse.cpp

clean:
	rm -f *.o $(exe)
	