#include <stdio.h>

int main(){
	int a;
	float x= 5.75;
	a = (int)x; // casting.
	printf("a = %d\n",a);
	x = a;
	printf("x= %.2f\n",x); // %.2f format

	int m = 17, n = 3;
	int p = m/n;
	printf("Valeur p: %d\n",p);

	float y = (float)m/ (float)n; //antes de mandar na RAM para CPU tem uma 					conversao
	printf("valeur y: %.2f\n",y);

	float decimal = y - (int)y;
	printf("decimal = %.3f\n", decimal);

	return 0;
}
