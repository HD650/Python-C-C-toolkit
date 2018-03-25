/*
example:
int data[100];
int compare1(const void* a, const void* b)
{
	return *((int*)a)-*((int*)b);
}
heap_sort(data,100,compare);
*/

void memswap(void *m1, void *m2, size_t sizen);
//input: content to be sort
//size: item size in the input
//len: len to be sort
//compare: function to compare two item
void sift(char* input, int size, int i, int len,int(*compare)(const void*,const void*));
void heapify(char* input, int size, int len, int(*compare)(const void*,const void*));
void heap_sort(char* input, int size, int len, int(*compare)(const void*,const void*));
