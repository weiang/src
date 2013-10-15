OBJ = url.o test.o 

test: url.o test.o url.h
	g++ -o test -g test.o url.o

test.o: test.cpp url.h
	g++ -g -c test.cpp

url.o: url.h url.cpp
	g++ -g -c url.cpp

clean:
	rm $(OBJ)

