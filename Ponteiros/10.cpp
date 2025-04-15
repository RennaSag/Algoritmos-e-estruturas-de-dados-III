#include <stdio.h>

int main() {
    float x, y, *p, **pd;

    scanf("%f %f", &x, &y);

    p = &x;    
    pd = &p;
    **pd *= 4;
    
    p = &y;
    **pd *= 4;

    printf("x = %f, y = %f\n", x, y);

    return 0;
}
