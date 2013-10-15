/*
 * Mem.h
 */
 
#ifndef MEM_H_
#define MEM_H_

typedef unsigned char byte;

class Mem {
	public:
		Mem(int sz = 0);
		~Mem();
		int msize();
		byte *pointer(int minsize = 0);
		bool moved(int);

	private:
		byte *mem;
		int size;
		void ensureMinsize(int);
};

#endif // MEM_H_

