#include <stdio.h>
#include <stdlib.h>

void numerossorteados(int *nlot){
	printf("--Numeros sorteados na loteria--\n");

	for(int i=0; i<6; i++){
		printf("Digite o %d valor: ", i+1);
		scanf("%d", &nlot[i]);
	}
	system("cls");	
}


void numerosjogados(int *njog){
	printf("--Numeros jogados--\n");
	
	for(int j=0; j<6; j++){
		printf("Digite o %d valor: ", j+1);
		scanf("%d", &njog[j]);
	}
	system("cls");
}


int *comparador(int nlot[6], int njog[6], int *qtdacertados){
	*qtdacertados=0;
	
	for(int x=0; x<6; x++){
		for(int y=0; y<6; y++){	
			if(nlot[x]==njog[y]){
				(*qtdacertados)++;
				break;
			}
		}		
	}
	
	int *vetorcorretos=(int *)malloc(*qtdacertados * sizeof(int));
	
	int index = 0;
    for (int x = 0; x < 6; x++) {
        for (int y = 0; y < 6; y++) {
            if (nlot[x] == njog[y]) {
                vetorcorretos[index++] = nlot[x];
                break;
            }
        }
    }
    return vetorcorretos;
}


void exibircorrecao(int  *vetorcorretos, int *nlot, int qtdacertados){
	
	printf("Numeros sorteados:\n");
	for(int h=0; h<6; h++){
		printf("%d, ", nlot[h]);
	}
	
	printf("\nNumeros que voce acertou:\n");
	for(int t=0; t<qtdacertados; t++){
		printf("%d, ", vetorcorretos[t]);
	}
	
	
}


int main() {
   
   	int nlot[6], njog[6], qtdacertos;

   	numerossorteados(nlot);
   	numerosjogados(njog);
   
	int *vetorcorretos = comparador(nlot, njog, &qtdacertos);
   
   
	exibircorrecao(vetorcorretos, nlot, qtdacertos);

	free(vetorcorretos);
   
return 0;
}
