#include <stdio.h>

int main(){
	int v[100];
	int a= 23;
	//int *p = 6789;
	int * p = &a;
	printf("a = %d\np= %p\n",a,p);
	
	int **x = &p;
	printf("x = %p\n",x);

	int **k;
	int *j;
	int b = 10;
	k = &j'
	j = &b;
	
	*k = &a;
	
	int *v1;
	int t;
	int v2[t];

	printf("Foi");
	return 0;
	
}

/*
int v[0], i;
for (i=0;i<10;i++){ //problema de acesso a memoria
	v[i] = i;
	printf("posicao %d tem o valor %d/n", i,v[i]);
	}
return -1; //deslocamento de bit


int v[1000000000000000]; // teste de alocacao com varios tamanhos
printf("foi");
return 0;
*/
