#include<stdio.h>
#include<math.h>
#include<malloc.h>


int main(int argc, char *argv[])
{
	int num, i;
	num = atoi(argv[1]);
	if(num == 0) 
	{
		printf("0");
		return 0;
	}
	double fact = 1;
	for(i=1;i<=num;i++)
	{
		fact = fact * i;
	}
	printf("%e\n",fact) ;
}
