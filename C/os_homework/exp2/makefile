OBJ =  exp2 monitor deadlock

all: $(OBJ)

exp2: exp2.o

monitor: monitor.o -lpthread

deadlock: deadlock.o -lpthread

test:
	./exp2

clean:
	rm *.o

