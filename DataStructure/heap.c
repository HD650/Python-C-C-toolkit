#include "heap.h"

//将一个元素放在她在堆中正确的位置
void sift(int* input, int i, int len,int(*compare)(const void*,const void*))
{
	int half=len/2;
	while(i<half)
	{
		int l=i*2;
		int r=l+1;
		int max=0;

		if(r<len&&(compare(input+r,input+l)>=0))
			max=r;
		else
			max=l;

		if(compare(input+i,input+max)>=0)
			return;
		
		SWAP(input[i],input[max]);
		i=max;
	}
}

//将一个数组变成堆，注意，堆只保证儿子比父亲大，并不保证什么排序顺序
void heapify(int* input, int len, int(*compare)(const void*,const void*))
{
	int i=len/2;
	while(i>=0)
	{
		sift(input,i,len,compare);
		i--;
	}
	return;
}

//heapsort使用堆的特性来将一个数组排序，通过不断读取堆顶，就能将数组排序
void heap_sort(int* input, int len, int(*compare)(const void*,const void*))
{
	heapify(input,len,compare);
	int i=len-1;
	while(i>=1)
	{
		SWAP(input[0],input[i]);

		i--;
		sift(input,0,i,compare);
	}
	return;
}