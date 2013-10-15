/*************************************************************************
	> File Name: global_operator_new.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Fri, Aug 02, 2013 12:58:24 AM
    > Describition: 
 ************************************************************************/

#include <cstdio>
#include <cstdlib>

void *operator new(size_t sz)
{
	printf("operator new: %d bytes\n", sz);
	void *m = malloc(sz);
	if (!m)
		puts("out of memory");
	return m;
}

void operator delete(void *p)
{
	printf("operator delete\n");
	free(p);
}

class S {
	public:
		S() { puts("S::S()"); }
		~S() { puts("~S::S()"); }
		
	private:
		int i[100];
};

int main()
{
	puts("creating & destorying an int");
	int *p = new int(47);
	delete p;

	puts("creating & destorying an S");
	S *s = new S;
	delete s;

	puts("creating & destorying S[3]");
	S *sa = new S[3];
	delete[] sa;
	
	return 0;
}


