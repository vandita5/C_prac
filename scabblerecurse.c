#include<stdio.h>
#include<string.h>

int count;

void recurseInHere(int nChars, int sp[nChars], int depth, char word[nChars+1]){
	int i,j,isTaken;
	if (depth == nChars-1) {
		count ++;
		for (i=0;i<nChars;i++){
			printf("%c",word[sp[i]]);
		}
		printf("\n");
		return;
	}
	depth++;
	for (i=0;i<nChars;i++){
		isTaken = 0;
		for (j=0;j<depth;j++){
			if (sp[j] == i) isTaken = 1;
		}
		if (isTaken == 0){
			sp[depth] = i;
			recurseInHere(nChars,sp,depth,word);
		}
	}
}

int main (void){
	int nChars = 7;	
	int sp[nChars], depth=0;
	int i;
	count = 0;
	char word[nChars+1];
	sprintf(word,"%s","ALGHBLP");
	for (i=0;i<nChars;i++){
		sp[0] = i;
		recurseInHere(nChars,sp,depth,word);
	}
	printf("%d\n",count);
}

