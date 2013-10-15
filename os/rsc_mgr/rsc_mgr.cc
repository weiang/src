#include <pthread.h>
#include <iostream>
#include "./rsc_mgr.h"
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void rsc_mgr::request(int i)
{
	pthread_mutex_lock(&mutex);
//	cout << " In thread: " << pthread_self() << "'s Request function!" << endl;	
	if (i > total) {
		cerr << "Request error!" << endl;
		pthread_mutex_unlock(&mutex);
		exit(1);
	}

	if (avail < i) {
		struct blk_que *p = new struct blk_que;
		p -> qst = i;
		pthread_mutex_init(&(p -> thd_blk), NULL);
		p -> next = queue -> next;
		queue -> next = p;
		pthread_mutex_lock(&(p -> thd_blk));	// Block the thread
		cout << "Blocked!" << endl;
	}
	else {
		avail -= i;
	}
	pthread_mutex_unlock(&mutex);
}

void rsc_mgr::release(int i)
{
	pthread_mutex_lock(&mutex);
//	cout << "In thread: " << pthread_self() << "'s Release function!" << endl;
	avail += i;
	sched();
	pthread_mutex_unlock(&mutex);
}

void rsc_mgr::sched()
{
	pthread_mutex_lock(&mutex);
	struct blk_que	*q = queue -> next;
	struct blk_que	*preq = queue;
	while (q != NULL) {
		if (q -> qst <= avail) {
			avail -= q -> qst;
			pthread_mutex_unlock(&(q -> thd_blk));
			pthread_mutex_destroy(&(q -> thd_blk));
			preq -> next = q -> next;
			delete q;
			break;
		}
		else {
			preq = q;
			q = q -> next;
		}
	}
}
