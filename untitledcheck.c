#include<malloc.h>
#include<stdio.h>
#include<math.h>


int main(int argc, char *argv[])
{
	int *points;
	FILE *pointfile;
	char *filename;
	filename = argv[1];
	pointfile = fopen(filename, "r");
	char line[1024];
	
	points = malloc(sizeof(int));
	
	while(fgets(line, 1024, pointfile) != NULL)
	{
		sscanf(line, "%d", points);
		printf("%d", *points);
		
	}
}
