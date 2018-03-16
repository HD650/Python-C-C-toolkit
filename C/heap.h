/*
example:
int data[100];
int compare1(const void* a, const void* b)
{
	return *((int*)a)-*((int*)b);
}
heap_sort(data,100,compare);
*/


#define SWAP(a, b) {typeof(a) temp=a;a=b;b=temp;}
void sift(int* input, int i, int len,int(*compare)(const void*,const void*));
void heapify(int* input, int len, int(*compare)(const void*,const void*));
void heap_sort(int* input, int len, int(*compare)(const void*,const void*));
