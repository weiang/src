CC=g++
CFLAGS=-c
OBJ=median.o	\
	grade.o		\
	Student_info.o	\
	main.o

all: $(OBJ) main

median.o: median.cc median.h
	$(CC) $(CFLAGS) median.cc

grade.o: grade.cc grade.h 
	$(CC) $(CFLAGS) grade.cc

Student_info.o: Student_info.cc Student_info.h
	$(CC) $(CFLAGS) Student_info.cc

main.o: main.cc
	$(CC) $(CFLAGS) main.cc

main: $(OBJ)
	$(CC) $(OBJ) -o main

clean:
	rm *.o
