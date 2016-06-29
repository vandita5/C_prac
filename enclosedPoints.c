#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<malloc.h>

#define smaller(x,y) x>y ? y : x
#define larger(x,y) x<y ? y : x


void main(int argc, char *argv[])
{
	double points[5][2] = {{1,2},{2,-3},{4,0},{3,3},{1,2}};
	double pixel[2];
	pixel[0] = atof(argv[1]);
	pixel[1] = atof(argv[2]);
	double x, y, x1, y1, x2, y2, smallx, smally, largex, largey, m, c;
	double intercept[4][2];
	int nintercepts = 0;
	int i, j;
	x = pixel[0];
	y = pixel[1];
	
	//calculating intercepts
	for(i=0;i<4;i++)
	{
		
		x1 = points[i][0];
		x2 = points[i+1][0];
		y1 = points[i][1];
		y2 = points[i+1][1];
		smallx = smaller(x1,x2);
		smally = smaller(y1,y2);
		largex = larger(x1,x2);
		largey = larger(y1,y2);
				
		//check if parallel to x axis
		if (fabs(y1-y2) < 1E-5)
		{
			if(x<largex && x>smallx)
			{
				intercept[nintercepts][0] = x;
				intercept[nintercepts][1] = y1;
				nintercepts ++;
			}
			continue;
		}
		
		//check if parallel to y axis
		if (fabs(x1-x2) < 1E-5)
		{
			if(y<largey && y>smally)
			{
				intercept[nintercepts][0] = x1;
				intercept[nintercepts][1] = y;
				nintercepts ++;
			}
			continue;
		}
		
		//not parallel to any axis
		m = (y1-y2)/(x1-x2);
		c = y1 - m*x1;
		double xa, xb, ya, yb;
		xa = x;
		ya = m*x+c;
		xb = (y-c)/m;
		yb = y;
		if(ya<largey && ya>smally && xa<largex && xa>smallx)
			{
				intercept[nintercepts][0] = xa;
				intercept[nintercepts][1] = ya;
				nintercepts ++;
			}
		if(yb<largey && yb>smally && xb<largex && xb>smallx)
			{
				intercept[nintercepts][0] = xb;
				intercept[nintercepts][1] = yb;
				nintercepts ++;
			}
	}
	
	//checking if point is inside
	float temp1 = 1, temp2 = 1;
	if (nintercepts == 4)
		{
			for(i=0;i<nintercepts;i++)
			{
				printf(" x and y of intercept are %f %f \n", intercept[i][0], intercept[i][1]);
				if (fabs(intercept[i][0]-x)<1E-5)
				{
					temp1 *= (y-intercept[i][1]);
				}
				if (fabs(intercept[i][1]-y)<1E-5)
				{
					temp2 *= (x-intercept[i][0]);
				}
			}
			if (temp1<0 && temp2<0)
			{
				printf("point is inside\n");
			}
			else
			{
				printf("point is outside\n");
			}
		}
		else
			{
				printf("point is outside\n");
			}	
	
}
