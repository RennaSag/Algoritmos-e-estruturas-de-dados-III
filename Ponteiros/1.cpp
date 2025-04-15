#include <stdio.h>

int main(){
	 
	 int a, b, *p;
	 
	 a=20;
	 p=&a;
	 
	 *p=34; //a=34
	 
	 b=25;
	 p=&b;	//p=25
	
	printf("%d\n", a);
	printf("%d", b);
	
	
return 0;
}