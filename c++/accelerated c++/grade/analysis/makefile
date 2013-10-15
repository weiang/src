CXX = g++

a.out: analysis.o test.o analysis.h grade.o median.o extract.h
	$(CXX) -g analysis.o test.o grade.o median.o

analysis.o: analysis.cpp analysis.h grade.cpp grade.h
	$(CXX) -c -g analysis.cpp

grade.o: grade.h grade.cpp
	$(CXX) -c -g grade.cpp

median.o: median.h median.cpp
	$(CXX) -c -g median.cpp 

test.o: test.cpp analysis.h
	$(CXX) -c -g test.cpp

clean: 
	rm *.o
