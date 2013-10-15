OBJ = student_info.o median.o grade.o test.o analysis.o handle.o

a.out: $(OBJ)
	g++ -g $(OBJ)

student_info.o: student_info.cpp student_info.h grade.h median.h handle.h
	g++ -g -c student_info.cpp

median.o: median.h median.cpp
	g++ -g -c median.cpp

grade.o: grade.h median.h grade.cpp
	g++ -g -c grade.cpp

test.o: test.cc student_info.h
	g++ -g -c test.cc

analysis.o: analysis.h analysis.cpp
	g++ -g -c analysis.cpp

handle.o: handle.h handle.cpp
	g++ -g -c handle.cpp


clean:
	rm $(OBJ)
