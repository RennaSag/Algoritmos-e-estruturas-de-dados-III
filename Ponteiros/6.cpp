#include <stdio.h>

int main(){
	
	int a=3, *pa=&a;
	float b=5, *pb=&b;
	double c=7, *pc=&c;
	
	printf("V1: %d\nV2: %.2f\nV3: %lf\n\n", a,b,c);
	
	*pa*=3;
	*pb+=1.1;
	*pc+=4;
	
	printf("V1: %d\nV2: %.2f\nV3: %lf", a,b,c);
	
	
	
return 0;
}