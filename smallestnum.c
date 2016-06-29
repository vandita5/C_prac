#include<stdio.h>
#include<math.h>
#include<malloc.h>

#define smallerNum(x,y) x>y ? y : x

int main(int argc, char *argv[])
{
	int i, num[50];
	for(i=1;i<argc;i++)
	{
		num[i-1] = atoi(argv[i]);
	}
	int smallest = num[0];
	for(i=0;i<argc-1;i++)
	{
		smallest = smallerNum(smallest,num[i]);
	}
	printf("%d", smallest);
}



