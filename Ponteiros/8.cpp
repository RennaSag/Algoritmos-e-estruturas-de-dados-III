#include <stdio.h>

int troca(int *n1, int *n2, int *n3){
	int maior, meio, menor;
	
	if (*n1 == *n2 && *n2 == *n3) {
        return 1;
    }
	
	
	
	if(*n1>*n2){
		if(*n1>*n3){
			maior=*n1;
			if(*n2>*n3){
				meio=*n2;
				menor=*n3;
			}
			else{
				meio=*n3;
				menor=*n2;
			}
		}
		else{
			maior=*n3;
			meio=*n1;
			menor=*n2;
			
		}
		
		if(*n2>*n3){
			maior=*n2;
			if(*n1>*n3){
				meio=*n1;
				menor=*n3;
			}
			else{
				meio=*n3;
				menor=*n1;
			}
			
		}
		else{
			maior=*n3;
			meio=*n2;
			menor=*n1;
			
		}
	}
	
	
	if(*n3>*n1){
		if(*n3>*n2){
			maior=*n3;		
			if(*n1>*n2){
				meio=*n1;
				menor=*n2;
			}
			else{
				meio=*n2;
				menor=*n1;
			}			
		}
		else{
			maior=*n2;
			meio=*n3;
			menor=*n1;
		}
	}	

	*n1 = menor;
    *n2 = meio;
    *n3 = maior;

    return 0;

		
}

int main(){
	
	int a, b, c;
	
	scanf("%d%d%d", &a,&b,&c);
	
	int resultado = troca(&a, &b, &c);

    if (resultado == 1) {
        printf("Os três valores são iguais.\n");
    } else {
        printf("Valores ordenados: %d %d %d\n", a, b, c);
    }
	
	
return 0;
}