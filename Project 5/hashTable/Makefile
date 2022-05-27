main: hashDriver.cpp LinearProbing.o HashTable.o Chaining.o Cuckoo.o
	g++ -o main hashDriver.cpp LinearProbing.o Chaining.o HashTable.o Cuckoo.o

Chaining.o: Chaining.cpp Chaining.h HashTable.o
	g++ -c Chaining.cpp HashTable.o

LinearProbing.o: LinearProbing.cpp LinearProbing.h HashTable.o
	g++ -c LinearProbing.cpp HashTable.o

HashTable.o: HashTable.cpp HashTable.h
	g++ -c HashTable.cpp

Cuckoo.o: Cuckoo.cpp Cuckoo.h
	g++ -c Cuckoo.cpp

Valgrind:
	valgrind --tool=memcheck --log-file=valgrindoutput.txt ./main

ValLeak:
	valgrind --tool=memcheck --log-file=valgrindoutput.txt --leak-check=full ./main

clean:
	rm -f *.o *.h.gch a.out main