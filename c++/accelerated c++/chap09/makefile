OBJ = median.o grade.o student_info.o test.o 
HEADER	= median.h grade.h student_info.h 

a.out: $(OBJ) $(HEADER)
	g++ -g $(OBJ)

median.o: median.cpp median.h
	g++ -c median.cpp

grade.o: grade.cpp grade.h median.h
	g++ -c grade.cpp

student_info.o: student_info.h student_info.cc
	g++ -c student_info.cc 

test.o:	test.cc
	g++ -c test.cc

clean:
	rm $(OBJ)
