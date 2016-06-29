#include<malloc.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

void  printImage(int rows, int cols, int **image)
{
	int i,j;
	for (i=0;i<rows;i++)
	{
		for (j=0;j<cols;j++)
		{
			printf ("%d ", image[i][j]);
		}
		printf("\n");
	}
}


void flipX (int rows, int cols, int image[rows][cols])
{
	int i,j;
	int retimg[rows][cols];
	for(i=0;i<rows;i++)
	{
		for (j=0;j<cols;j++)
		{
				retimg[rows-i-1][j] = image[i][j];
		}
	}
	for(i=0;i<rows;i++)
	{
		for (j=0;j<cols;j++)
		{
			image[i][j] = retimg[i][j];
		}
	}
}

void flipY (int rows, int cols, int image[rows][cols])
{
	int i,j;
	int retimg[rows][cols];
	for(i=0;i<rows;i++)
	{
		for (j=0;j<cols;j++)
		{
				retimg[i][cols-j-1] = image[i][j];
		}
	}
	for(i=0;i<rows;i++)
	{
		for (j=0;j<cols;j++)
		{
			image[i][j] = retimg[i][j];
		}
	}
}

void transpose (int rows, int cols, int image[rows][cols], int returnimage[cols][rows])
{
	int i,j;
	for(i=0;i<rows;i++)
	{
		for (j=0;j<cols;j++)
		{
			returnimage[j][i] = image[i][j];
		}
	}
}

void binarizeImage(int rows, int cols, int image[rows][cols], int **retimg)
{
	int i,j;
	for(i=0;i<rows;i++)
	{
		for (j=0;j<cols;j++)
		{
			if (image[i][j] > 10) 
			{
				retimg[i][j]=1;
			}
			else
			{
				retimg[i][j]=0;
			}
		}
	}
}

void connectingPix(int **img, int rows, int cols, int **retimg)
{
	int i,j,num=1;
	for(i=0;i<rows;i++)
	{
		for (j=0;j<cols;j++)
		{
			retimg[i][j] = 0;
		}
	}
	for(i=0;i<rows;i++)
	{
		for (j=0;j<cols;j++)
		{
			if(img[i][j] == 1)
			{
				if(retimg[i][j] == 0)
				{
					retimg[i][j] = num;
					printf("%d %d\n",i,j);
					num ++;
				}
				if (i<rows-1)
				{
					if(img[i+1][j] == 1)
					{
						retimg[i+1][j] = retimg[i][j];
						printf("%d %d\n",i+1,j);
					}
				}
				if (j<cols-1)
				{
					if(img[i][j+1] == 1)
					{
						retimg[i][j+1] = retimg[i][j];
						printf("%d %d\n",i,j+1);
					}
				}
				
			}
			else
			{
				retimg [i][j] = 0;
			}
		}
	}
	
}

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

void recurseConnect(int **img, int **retimg, int rows, int cols, int label, int x, int y)
{
	if (x < 0 || x >= rows) return;
	if (y <0 || y >= cols) return;
	if (img[x][y] == 0) return;
	if (retimg[x][y] != 0) return;
	int i;
	retimg[x][y] = label;
	for(i=0;i<8;i++)
	{
		recurseConnect(img, retimg, rows, cols, label, x+dx[i], y+dy[i]);
	}
}

void connectingPix2(int **img, int rows, int cols, int **retimg)
{
	int i,j, label = 0;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			retimg[i][j] = 0;
		}
	}
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			if(img[i][j] != 0 && retimg[i][j] == 0)
			{
				recurseConnect(img, retimg, rows, cols, ++label, i, j);
			}
		}
	}
}



void freeMem(int **img,int rows)
{
	int i,j;
 for(i=0;i<rows;i++)
	{
		free(img[i]);
	}
	free(img);
}

int main(int argc, char *argv[])
{
	int i,j;
	FILE *imagefile;
	char *imagefilename;
	imagefilename = argv[1];
	imagefile = fopen(imagefilename, "r");
	char  line[1024];
	int image[3][6];
	int rowNum = 0;
	
	//read image from text file and print it
	while (fgets(line,1024,imagefile) != NULL)
	{
		sscanf(line,"%d %d %d %d %d %d", &image[rowNum][0], &image[rowNum][1], 
			&image[rowNum][2], &image[rowNum][3], &image[rowNum][4], &image[rowNum][5]);
		rowNum ++;
	}
	
	//assigning pointers to give to printImage
	int **dummy;
	dummy = malloc(3*sizeof(*dummy));
	for (i=0;i<3;i++){
		dummy[i] = &image[i];
	}
	
	printImage(3, 6, dummy);
	
	//transpose image
	int returnimage[6][3];
	//transpose(3, 6, image,returnimage);
	/*
	for (i=0;i<6;i++)
	{
		for (j=0;j<3;j++)
		{
			printf ("%d ", returnimage[i][j]);
		}
		printf("\n");
	}
	*/
	//flip around y axis
	//flipY(3,6,image);
	/*for (i=0;i<3;i++)
	{
		for (j=0;j<6;j++)
		{
			printf ("%d ", image[i][j]);
		}
		printf("\n");
	}
	*/
	//flip around x axis
	//flipX(3,6,image);
	/*for (i=0;i<3;i++)
	{
		for (j=0;j<6;j++)
		{
			printf ("%d ", image[i][j]);
		}
		printf("\n");
	}
	*/
	
	//create an image using heap memory
	int **image2;
	image2 = malloc(3*sizeof(*image2));
	for (i=0;i<3;i++)
	{
		image2[i] = malloc(6*sizeof(*image2[i]));
		
	}
		
	//binarize image created in heap
	binarizeImage(3, 6, image, image2);
	printImage(3,6,image2);
	
	
	//create an array containing numbers of connected regions
	int **connectImage;
	connectImage = malloc(3*sizeof(*connectImage));
	for (i=0;i<3;i++)
	{
		connectImage[i] = malloc(6*sizeof(*connectImage[i]));
		
	}
	
	//calling connectingPix function to check for connected pixels
	connectingPix2(image2, 3, 6, connectImage);
	printImage(3,6,connectImage);
	
	freeMem(image2, 3);
	freeMem(connectImage, 3);
	free(dummy);
	return 0;
}
