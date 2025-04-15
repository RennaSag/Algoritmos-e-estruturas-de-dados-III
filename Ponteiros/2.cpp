#include <stdio.h>


int main () {

    int a, *p;

    scanf ("%d", &a);

    p = &a; 
    
    *p*=2;
    
    printf("%d", a);

	
     

    return 0;
}