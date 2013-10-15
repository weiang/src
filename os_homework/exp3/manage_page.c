/*************************************************************************
	> File Name: repg.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年05月08日 星期三 23时55分11秒
    > Describition: 
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fifo(int *, int, int);
void lru(int *, int, int);
void lfr(int *, int, int);
void nur(int *, int, int);

char *string = "********************";

int main(void)
{

	int n;
	int phy_size;
	int *req;
	int i;

	printf("Please enter available physical size: \n");
	scanf("%d", &phy_size);
	printf("Please enter requset number: \n");
	scanf("%d", &n);

	if ((req = malloc(n * sizeof(int))) == NULL) {
		fprintf(stderr, "Malloc error\n");
		return -1;
	}
	for (i = 0; i < n; i ++)
		scanf("%d", &req[i]);
	fifo(req, n, phy_size);
	lru(req, n, phy_size);
	lfr(req, n, phy_size);
	nur(req, n, phy_size);
	return 0;
}

/* Show pages in memory */
void show_page(int *page, int n)
{
	int i;

	for (i = 0; i < n; i ++) {
		if (page[i] < 0)
			printf("# ");
		else 
			printf("%d ", page[i]);
	}
	printf("\n");
}

/* FIFO */
int fifo_ifpagein(int *pg, int rr, int req)
{
	int i;

	for (i = 0; i < rr; i ++)
		if (req == pg[i])
			return 1;
	return 0;
}

void fifo(int *req, int n, int phy_size)
{
	int rear = 0;
	int *page = (int *)malloc(phy_size * sizeof(int));
	int i;
	int flag = 0;	// Indicate if page is full
	int mis = 0;
	int r;

	printf("%sFIFO%s\n", string, string);
	memset(page, -1, sizeof(int) * phy_size);
	for(i = 0; i < n; i ++) {
		if (flag == 0) 
			r = fifo_ifpagein(page, rear, req[i]);
		else 
			r = fifo_ifpagein(page, phy_size, req[i]);
		if (r == 1)	// requested page in memory
			continue;
		mis ++;
		page[rear % phy_size] = req[i];
		++ rear;
		if ((rear %= phy_size) == 0)
			flag = 1;
		show_page(page, phy_size);
	}
	printf("Page Missed: %d\n", mis);
	printf("Miss Rate: %f\n", (float)mis / n);
	return;
}

/* LRU */
struct stack {
	int pg_num;
	struct stack *next, *pre;
};

int lru_ifpagein(struct stack *head, int n, int req)
{
	int i;

	for (i = 0; i < n;i ++)
		if (head[i].pg_num == req)
			return i;
	return -1;
}

void lru(int *req, int n, int phy_size)
{
	struct stack *top, *rear, *pages;
	int cnt, r;
	int i,j, mis = 0;
	struct stack base;

	printf("%sLRU%s\n", string, string);
	base.next = NULL;
	base.pre = NULL;
	base.pg_num = phy_size;
	top = &base;

	pages = (struct stack *)malloc(phy_size * sizeof(struct stack));
	for (i = 0; i < phy_size; i ++) {
		pages[i].next = NULL;
		pages[i].pre = NULL;
		pages[i].pg_num = -1;
	}
	for (i = 0, cnt = 0; i < n; i ++) {
		r = lru_ifpagein(pages, cnt, req[i]);

		/* Page Hit */
		if (r >= 0) {
			if (&pages[r] == top) {
				continue;
//				goto print;
			}
			rear = &pages[r];
			rear -> pre -> next = rear -> next;
			rear -> next -> pre = rear -> pre;

			rear -> next = top -> next;
			rear -> pre = top;
			top -> next = rear;
			top = rear;
			continue;
		}
		
		/* Page Miss */
		else {
			mis ++;
			/* Physical memory is full */
			if (cnt == phy_size) {
				if (phy_size == 1)
					top -> pg_num = req[i];
				else {
					rear = base.next;
					base.next = rear -> next;
					rear -> next -> pre = &base;
					rear -> pg_num = req[i];
					rear -> pre = top;
					rear -> next = top -> next;
					top -> next = rear;
					top = rear;
				}
			}
			else {
				pages[cnt].pre = top;
				pages[cnt].next = top -> next;
				pages[cnt].pg_num = req[i];
				top -> next = &pages[cnt];
				top = &pages[cnt];
				cnt ++;
			}
		}
//print:
		for (j = 0;j < phy_size; j ++)
			if (pages[j].pg_num == -1)
				printf("# ");
			else 
				printf("%d ", pages[j].pg_num);
		printf("\n");
//		for(rear = base.next; rear != top -> next; rear = rear -> next)
//			printf("%d ", rear -> pg_num);
//		printf("\n");
	}
	printf("Page Missed: %d\n", mis);
	printf("Miss Rate: %f\n", (float) mis / n);
}
/* LFR */

int lfr_ifpagein(int *pg, int req, int n)
{	
	int i;

	for (i = 0; i < n; i ++)
		if (pg[i] == req)
			return i;
	return -1;
}
int find_min(int *a, int n)
{
	int i, min;

	min = 0;
	for (i = 0; i < n; i ++)
		if (a[i] < a[min])
			min = i;
	return min;
}
void lfr(int *req, int n, int phy_size)
{
	int i, j, r;
	int *freq = (int *)malloc(sizeof(int) * phy_size);
	int *page = (int *)malloc(sizeof(int) * phy_size);
	int rear = 0;
	int mis = 0;

	printf("%sLFR%s\n", string, string);

	for (j = 0; j < phy_size; j ++) {
		freq[j] = 0;
		page[j] = -1;
	}

	for (i = 0; i < n; i ++) {
		if (rear != phy_size) {
			// Page Miss
			if ((r = lfr_ifpagein(page, req[i], rear)) < 0) {
				mis ++;
				freq[rear] = 1;
				page[rear] = req[i];
				rear ++;
			}
			// Page Hit
			else {
				freq[r] ++;
				continue;
			}
		}
		else {
			// Page Miss
			if ((r = lfr_ifpagein(page, req[i], phy_size)) < 0) {
				r = find_min(freq, phy_size);
				page[r] = req[i];
				freq[r] = 1;
			}

			else {
				freq[r] ++;
				continue;
			}
		}
		for (j = 0; j < phy_size; j ++) 
			if (page[j] == -1)
				printf("# ");
			else
				printf("%d ", page[j]);
		printf("\n");
	}

	printf("Page Missed: %d\n", mis);
	printf("Miss Rate: %f\n", (float) mis / n);

	free(freq);
	free(page);
}

/* NUR */

int nur_ifpagein(int *pg, int n, int req)
{
	int i;

	for (i = 0; i < n; i ++)
		if (pg[i] == req)
			return i;
	return -1;
}

int find_place(int *fg, int n)
{
	int i, result = 0;

	for (i = 0; i < n; i ++)
		if (!fg[i]) 
			fg[i] = 0;
		else 
			result = i;
	return result;
}

void nur(int *req, int n, int ps)
{

	int *page = (int *)malloc(sizeof(int) * ps);
	int *fg = (int *)malloc(sizeof(int) * ps);
	int flag = 0, i, j, r, k;
	int mis = 0;
	int rear = 0;

	printf("%sNUR%s\n", string, string);

	for (i = 0; i < ps; i ++) {
		page[i] = -1;
		fg[i] = 0;
	}
	for (i = 0; i < n; i ++) {
		if (flag == 0) {
			if ((r = nur_ifpagein(page, rear, req[i])) < 0) {
				page[rear] = req[i];
				fg[rear ++] = 1;
				mis ++;
			}
			else {
				fg[r] = 1;
				continue;
			}
			if (rear == ps)
				flag = 1;
		}
		else { 
			r = nur_ifpagein(page, ps, req[i]);
			if (r >= 0) {
				fg[r] = 1;
				continue;
			}
			else {
				mis ++;
				r = find_place(fg, ps);
				page[r] = req[i];
			}
		}
		for (k = 0; k < ps; k ++)
			if (page[k] == -1)
				printf("# ");
			else 
				printf("%d ", page[k]);
		printf("\n");
	}
	free(page);
	free(fg);
	printf("Page Missed: %d\n", mis);
	printf("Miss Rate: %f\n", (float) mis / n);
}

