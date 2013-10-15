OBJ = grade.o median.o main.o extract.o

a.out: $(OBJ)
	g++ -g $(OBJ)
grade.o: grade.h grade.cpp median.o student_info.h
	g++ -c grade.cpp
median.o: median.h median.cpp
	g++ -c median.cpp 
extract.o: extract.cpp extract.h grade.h student_info.h
	g++ -c extract.cpp
main.o: main.cpp grade.h student_info.h
	g++ -c main.cpp

clean:
	rm $(OBJ)
