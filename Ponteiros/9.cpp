#include <stdio.h>


int main(){
	
	int a, b, *p1=&a, *p2=&b;
	double *pd;
	
    scanf("%d %d", &a, &b);

    pd = (double *)&a;

    
    *pd *= 2;
    pd = (double *)&b;
    *pd *= 2;

    printf("a = %d, b = %d\n", *p1, *p2);
	
return 0;
}