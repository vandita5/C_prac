#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Dicttree{
	struct Dicttree *root[26];
	int isEnd;
}dicttree;	




int main (int argc, char *argv[])
{
	FILE *dictfile;
	char *dictfilename;
	dictfilename = argv[1];
	dictfile = fopen(dictfilename,"r");
	char line[1024];
	
	dicttree *head = NULL;
	char tempstr[1024];
	dicttree *prev , *current;
	int position, i, j;
	
	//initialize head
	head = malloc(sizeof(*head));
	for(i=0;i<26;i++)
	{
		head->root[i] = 0;
	}
	head->isEnd = 0;
	
	// insert words into tree
	while(fgets(line, 1024, dictfile)!=NULL)
	{
		sscanf(line,"%s\n", tempstr);
		if(strlen(tempstr) >1)			//only if more than 1 letter
		{
			//put prev to head first
			prev = head;
			
			// now loop for each character in word
			for(i=0;i<strlen(tempstr);i++)
			{
				position = tempstr[i] - 97;
				// initialize a new node in the position of that letter
				if(prev->root[position] == NULL) 
				{
					//initialize by malloc 
					prev->root[position] = malloc(sizeof(*head));
					//put it into current to initialize current's nodes to null
					current  = prev->root[position];
					current->isEnd = 0;
					for(j=0;j<26;j++)
					{
						current->root[j] = NULL;
					}
					
				}
				//now make the prev root just initialized as prev for the next letter
				prev = prev->root[position];
				//if it was the last character then mark isEnd as 1
				if(i==strlen(tempstr)-1)
				{
					prev->isEnd = 1;
				}
			}
		}
	}
	
	int sp[6], depth, isTaken;
	for (i=0;i<7;i++)
	{
		depth = 0;
		sp[depth] = i;
		for(j=0;j<7;j++)
		{
			isTaken = 0;
			for(t=0;t<depth;t++)
			{
				if(sp[t] == j) isTaken = 1;
			
			}
			if(isTaken == 0)
			{
				depth = 1;
				sp[depth] = j;
				for(k=0;k<7;k++)
				{
					isTaken = 0;
					for(t=0;t<depth;t++)
					{
						if(spt[t]  == j) isTaken = 1;
					}
					if(isTaken = 0)
					{
						depth = 2;
						sp[depth] = k;
						for(l=0;l<7;l++)
						{
							combfnc(
						}
					}
				}
			}
			
		}
	}
	
	char word[1024] = "caterpillar";
	prev = head;
	int  isEndPos = 0;
	for(i=0;i<strlen(word);i++)
	{
		if(prev->root[word[i]-97] != NULL)
		{
			//printf("%c \n", word[i]);
			prev = prev->root[word[i]-97];
			if(prev->isEnd == 1)
			{
				isEndPos = i;
				printf("%d \n", isEndPos);
			}
		}
		else
		{
			break;
		}
	}
	
}
