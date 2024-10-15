CC = g++ -g
exe = prog

$(exe): catalog.o run_catalog.o
		$(CC) catalog.o run_catalog.o -o $(exe)

catalog.o: catalog.cpp
		$(CC) -c catalog.cpp
run_catalog.o: run_catalog.cpp
		$(CC) -c run_catalog.cpp

clean:
		rm -f *.o $(exe)

leak_check: catalog.o run_catalog.o
		$(CC) catalog.o run_catalog.o -o $(exe)
		valgrind --leak-check=full ./$(exe)