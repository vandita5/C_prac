#include<malloc.h>
#include<stdio.h>
#include<math.h>

static int cmpfnc(const int *a, const int *b)
{
	return *a>*b ? -1 : 1;
}

int main (void)
{
	int unsorted[10]={100, 56, 29, -23, 54, 37, 99, 9, 67, 12};
	qsort(unsorted, 10, sizeof(int), cmpfnc);
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d\n",unsorted[i]);
	}
}
