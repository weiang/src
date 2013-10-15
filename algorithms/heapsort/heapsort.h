#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

#include <vector>

void build_max_heap(std::vector<int> &, int);
void max_heapify(std::vector<int> &, int, int);
void heap_sort(std::vector<int> &);
int heap_maximum(const std::vector<int> &);
void insert(std::vector<int> &, int);
int extract(std::vector<int> &);
void increase_key(std::vector<int> &, int, int);
void print(const std::vector<int>&);
void build_max_heap_with_insert(std::vector<int> &, int);

#endif // HEAP_SORT_H_
