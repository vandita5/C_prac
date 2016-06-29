#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<malloc.h>

struct point
{
	double x;
	double y;
};

struct point center;

int cmpfnc(const void *a, const void *b)
{
	struct point *ia = (struct point *)a;
	struct point *ib = (struct point *)b;
	
	double crosspdt;
	crosspdt = (ia->x - center.x)*(ib->y - center.y) - (ia->y - center.y)*(ib->y - center.y);
	return crosspdt > 0 ? 1 : -1;
}

int main(int argc, char *argv[])
{
	int numpoints = 6;
	FILE *pointfile;
	char *filename;
	filename = argv[1];
	pointfile = fopen(filename, "r");
	char line[1024];
	
	struct point *mypoints;
	mypoints = malloc(numpoints * sizeof(*mypoints));
	
	int i=0;
	center.x = 0;
	center.y = 0;
	
	while(fgets(line, 1024, pointfile) != NULL)
	{
		sscanf(line, "%lf %lf", &mypoints[i].x, &mypoints[i].y);
		printf("%f %f", mypoints[i].x, mypoints[i].y);
		center.x += mypoints[i].x;
		center.y += mypoints[i].y;
		i++;
		
	}
	if(i != numpoints) 
	{
		printf("check file"); 
		return 0;
	}
	center.x /= numpoints;
	center.y /= numpoints;
	
	qsort(mypoints, numpoints, sizeof(*mypoints), cmpfnc);
	for (i= 0;i<numpoints;i++)
	{
		printf("%f %f \n",mypoints[i].x, mypoints[i].y);
	}
}

