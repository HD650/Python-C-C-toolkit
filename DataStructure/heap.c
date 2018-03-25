#include "heap.h"

//交换两个无类型的内存内容
void memswap(void *m1, void *m2, size_t sizen)
{
	unsigned char *a=(unsigned char*)m1,*b=(unsigned char*)m2;
	while (sizen--)
	{
		*b^=*a^=*b^=*a;
		a+=sizeof(unsigned char);
		b+=sizeof(unsigned char);
	}
}

//将一个元素放在她在堆中正确的位置
void sift(char* input, int size, int i, int len,int(*compare)(const void*,const void*))
{
	int half=len/2;
	while(i<half)
	{
		int l=i*2+1;
		int r=l+1;
		int max=0;

		if(r<len&&(compare(input+r*size,input+l*size)>=0))
			max=r;
		else
			max=l;

		if(compare(input+i*size,input+max*size)>=0)
			return;
		
		memswap(input+i*size,input+max*size,size);
		i=max;
	}
}

//将一个数组变成堆，注意，堆只保证儿子比父亲大，并不保证什么排序顺序
void heapify(char* input, int size, int len, int(*compare)(const void*,const void*))
{
	int i=len/2-1;
	while(i>=0)
	{
		sift(input,size,i,len,compare);
		i--;
	}
	return;
}

//heapsort使用堆的特性来将一个数组排序，通过不断读取堆顶，就能将数组排序
void heap_sort(char* input, int size, int len, int(*compare)(const void*,const void*))
{
	heapify(input,size,len,compare);
	int i=len-1;
	while(i>=1)
	{
		memswap(input,input+i*size,size);

		i--;
		sift(input,size,0,i+1,compare);
	}
	return;
}