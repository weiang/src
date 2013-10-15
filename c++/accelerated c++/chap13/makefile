OBJ = student_info.o median.o grade.o test.o analysis.o

a.out: $(OBJ)
	g++ -g $(OBJ)

student_info.o: student_info.cpp student_info.h grade.h median.h 
	g++ -g -c student_info.cpp

median.o: median.h median.cpp
	g++ -g -c median.cpp

grade.o: grade.h median.h grade.cpp
	g++ -g -c grade.cpp

test.o: test.cpp student_info.h
	g++ -g -c test.cpp

analysis.o: analysis.h analysis.cpp
	g++ -g -c analysis.cpp

clean:
	rm $(OBJ)
