#include <stdio.h>

void trocainteiros(int *x, int *y){
	int c;
	c=*x;
	*x=*y;
	*y=c;
	
}



int main(){
	
	int n1, n2;	
	scanf("%d%d", &n1, &n2);
	
	trocainteiros(&n1, &n2);
	
	printf("%d, %d", n1, n2);
	
	
return 0;
}

