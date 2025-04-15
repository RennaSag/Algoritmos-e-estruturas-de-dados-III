#include <stdio.h>

void fun(int *v1, int *v2){
	int c;
	
	c=*v1;
	*v1=*v2;
	*v2=c;
	
	printf("%d, %d", *v1, *v2);
}




int main(){
	int a, b;
	
	scanf("%d%d", &a,&b);
	
	fun(&a, &b);
	
	
	
return 0;
}