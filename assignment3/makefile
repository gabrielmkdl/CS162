CC = g++ -g 
EXE = prog

$(EXE): airport.o flight.o manager.o main.o
	$(CC) airport.o flight.o manager.o main.o -o $(EXE)

airport.o: airport.cpp
	$(CC) -c airport.cpp

flight.o: flight.cpp
	$(CC) -c flight.cpp 

manager.o:  manager.cpp
	$(CC) -c manager.cpp 

main.o: main.cpp
	$(CC) -c main.cpp 

clean: 
	rm -f *.o $(EXE)

leak_check: airport.o flight.o manager.o main.o
	$(CC) airport.o flight.o manager.o main.o -o $(EXE)
	valgrind --leak-check=full ./$(EXE)