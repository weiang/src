CC=gcc

OBJ=	main.o \
		lex.o \
		improved.o \
		plain.o

all: plain.elf improved.elf

plain.elf: plain.o lex.o main.o 
	$(CC) plain.o main.o lex.o -o plain.elf

improved.elf: improved.o lex.o main.o
	$(CC) improved.o main.o lex.o -o improved.elf

clean:
	rm *.o *.elf
