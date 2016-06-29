
#include<stdio.h>
#include<math.h>
#include<malloc.h>

int factorial(int num, double fact)
{
	if(num == 0) 
	{
		printf("0");
		return 0;
	}
	if(num == 1) return fact;
	fact = fact * num;
	factorial(--num, fact);
}

int main(int argc, char *argv[])
{
	int num, i;
	num = atoi(argv[1]);
	double fact = 1;
	fact = factorial(num, fact);
	printf("%f\n",fact) ;
}
