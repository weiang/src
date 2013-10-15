#ifndef _RSC_MGR_
#define _RSC_MGR_

#include <pthread.h>

struct blk_que {
	pthread_mutex_t	thd_blk;	// Block the thread
	int	qst;					// The blocked thread's request for the resource
	struct blk_que *next;
};

class rsc_mgr {
	public:
		rsc_mgr() { }
		rsc_mgr(int val) : avail(val), total(val) { pthread_mutex_init(&mutex, NULL); queue = NULL; }
		~rsc_mgr() { pthread_mutex_destroy(&mutex); }
		void init(int val, int to) 
		{
			avail = val;
			total = to;
			queue = NULL;
			pthread_mutex_init(&mutex, NULL);
		}
		void release(int cnt);
		void request(int cnt);


	private:
		int total;	// Total resources 
		int avail;	// Resources available
		struct blk_que	*queue;	// Blocked threads' queue
		pthread_mutex_t	mutex;	// Lock the cricial section of the class data elements
		void sched();
};

#endif
