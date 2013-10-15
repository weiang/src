#ifndef _HANDLE_H_
#define _HANDLE_H_

template <class T> 
class handle {
	public:
		handle() : p(0) { }
		handle(T* t) : p(t) { }
		handle(const handle& s) : p(0) { if (s.p) p = s.p -> clone(); }
		~handle() {	delete p; }

		static bool compare_handle(const handle& a, const handle& b)
		{
			return a.p -> name() < b.p -> name();
		}
		operator bool () const; 
		T& operator*() const;
		T* operator->() const;
		handle& operator=(const handle&);
		
	private:
		T* p;
};

#endif
