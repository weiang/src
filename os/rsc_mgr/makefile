all: a.out

a.out: rsc_mgr.o test.o
	g++ -g rsc_mgr.o test.o -lpthread

rsc_mgr.o: rsc_mgr.cc rsc_mgr.h

test.o: test.cc rsc_mgr.h

clean:
	rm *.o
