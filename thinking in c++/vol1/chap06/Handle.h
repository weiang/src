#ifndef HANDLE_H_
#define HANDLE_H_

class Cheshire;

class Handle {
	public:
		Handle(int a = 0);
		~Handle();
		int read();
		void change(int);

	private:
		Cheshire *smile;
};

#endif // HANDLE_H_
