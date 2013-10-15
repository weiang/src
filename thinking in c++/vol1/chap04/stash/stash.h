#ifndef STASH_H_
#define STASH_H_

struct stash {
	int size;	// Size of each element
	int quantity;	// Number of storage space
	int next;	// Next empty element's index

	/* Dynamically allocated array of bytes */
	unsigned char *storage;

	/* Mumber functions */
	void init(int);
	void cleanup();
	int add(const void *);
	void *fetch(int);
	int count();
	void inflate(int);
};

#endif // STASH_H_

