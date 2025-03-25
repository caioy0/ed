#include <stdio.h>
#include <stdlib.h>

int main(){

	int v[5000000000]; //nao cabe na memoria de alocacao estatica
	
	int *v = (int *) malloc (10*sizeof(int));		
	printf("foi");
	return 0;
}
