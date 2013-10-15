#include "./rsc_mgr.h"
#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;

#define N_THD	2	
#define N_RSC	10
#define NUM		100
#define SLEEP	10
#define MAX_NUM	(NUM / 10)

void *cons(void *);

vector<rsc_mgr> resource;
rsc_mgr		r;
pthread_t	pid[N_THD];

int main()
{
	for (int i = 0; i < N_RSC; i ++) {
		r.init(NUM, NUM);
		resource.push_back(r);
	}
	for (int i = 0; i < N_THD; i ++) {
		cout << i << endl;
		pthread_create(&(pid[i]), NULL, cons, NULL);
		srand(i);
	}
	for (int i = 0; i < N_THD; i ++) {
		if (pthread_join(pid[i], NULL) != 0) 
			cout << "Wait error!" << endl;
		cout << "Return from thread: " << pid[i] << endl;
	}
	exit(0);
}

void *cons(void *p)
{
	printf("In thread!!!\n");
	int rsc_kind = rand() % N_RSC;
	int rsc_cnt = rand() % MAX_NUM;
	int sleep_time = rand() % SLEEP;

	cout << rsc_kind << ", " << rsc_cnt << endl;
	usleep(sleep_time);
	resource[rsc_kind].request(rsc_cnt);
	cout << "After request!!!" << endl;
	sleep_time = rand() % SLEEP;
	usleep(sleep_time);
	resource[rsc_kind].release(rsc_cnt);
	cout << "After release!!!" << endl;
	pthread_exit(NULL);
}

