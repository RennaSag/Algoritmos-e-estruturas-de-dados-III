/*Um polígono é uma figura plana e fechada formada pela união de um
número finito de segmentos de retas.
Desta forma, ele pode ser representado como uma lista de vértices e para
que seja desenhado basta que seja traçada uma reta entre os vértices
adjacentes.
Exemplo:
Vi = (xi, yi)


• Crie um TAD capaz de armazenar polígonos, o TAD deve ser capaz
de excluir e inserir vértices e arestas, assim como, ter os dados
necessários para que o polígono possa ser desenhado.*/


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Vertice;


typedef struct {
    Vertice *vertices; 
    int numVertices;  
    int capacidade;    
} Poligono;


Poligono *criarPoligono(int capacidade) {
    Poligono *poligono = (Poligono *)malloc(sizeof(Poligono));
    poligono->vertices = (Vertice *)malloc(capacidade * sizeof(Vertice));
    poligono->numVertices = 0;
    poligono->capacidade = capacidade;
    return poligono;
}



void inserirVertice(Poligono *poligono, float x, float y) {
    if (poligono->numVertices < poligono->capacidade) {
        poligono->vertices[poligono->numVertices].x = x;
        poligono->vertices[poligono->numVertices].y = y;
        poligono->numVertices++;
    } else {
        printf("Poligono cheio.\n");
    }
}

void excluirVertice(Poligono *poligono, int indice) {
    if (indice >= 0 && indice < poligono->numVertices) {
        for (int i = indice; i < poligono->numVertices - 1; i++) {
            poligono->vertices[i] = poligono->vertices[i + 1];
        }
        poligono->numVertices--;
    } else {
        printf("Indice invalido.\n");
    }
}

void desenharPoligono(Poligono *poligono) {
    printf("Vertices do poligono:\n");
    for (int i = 0; i < poligono->numVertices; i++) {
        printf("(%.2f, %.2f)\n", poligono->vertices[i].x, poligono->vertices[i].y);
    }
}

void destruirPoligono(Poligono *poligono) {
    free(poligono->vertices);
    free(poligono);
}

int main() {
    Poligono *poligono = criarPoligono(10); 
    inserirVertice(poligono, 0.0, 0.0);
    inserirVertice(poligono, 1.0, 0.0);
    inserirVertice(poligono, 1.0, 1.0);
    inserirVertice(poligono, 0.0, 1.0);
    desenharPoligono(poligono);
    excluirVertice(poligono, 2);
    desenharPoligono(poligono);
    destruirPoligono(poligono);
    return 0;
}
