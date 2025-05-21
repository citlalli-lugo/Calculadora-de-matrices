#include <stdio.h>

void imprimeMatriz(float array[2][2]);
float Determinante(float matriz[2][2]);
void Adjunta(float matriz[2][2], float adjunta[2][2]);
int Inversa(float matriz[2][2], float inversa[2][2]);

int main() {
    float matriz[2][2];
    float inversa[2][2];
    
    printf("Dame valores\n");//pedimos valores
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%f", &matriz[i][j]);//almacenamos valores en la matríz
        }
    }
    
    printf("\nMatriz ingresada:\n");
    imprimeMatriz(matriz);//imprimimos la matriz original
    
    if (Inversa(matriz, inversa)) {//condición para saber si la matriz tiene inversa
        printf("\nMatriz inversa:\n");
        imprimeMatriz(inversa);
    } else {
        printf("\nLa matriz no tiene inversa (determinante = 0).\n");
    }

    return 0;
}

float Determinante(float matriz[2][2]) {//función para calcular el determinante
    float det = (matriz[0][0] * matriz[1][1]) - (matriz[1][0] * matriz[0][1]);
    return det;//me regresa el resultado del determinante
}

void Adjunta(float matriz[2][2], float adjunta[2][2]) {
    adjunta[0][0] = matriz[1][1];
    adjunta[0][1] = -matriz[0][1];
    adjunta[1][0] = -matriz[1][0];
    adjunta[1][1] = matriz[0][0];
}

int Inversa(float matriz[2][2], float inversa[2][2]) {
    float det = Determinante(matriz);
    
    if (det == 0) {//comprobación de inversibilidad 
        return 0; //si la matriz no tiene inversa
    }
    
    float adjunta[2][2];//calcula la matriz adjunta
    Adjunta(matriz, adjunta);
    
    for (int i = 0; i < 2; i++) {//divide cada elemento de la matriz adjunta por el determinante para obtener la matriz inversa
        for (int j = 0; j < 2; j++) {
            inversa[i][j] = adjunta[i][j] / det;
        }
    }
    
    return 1;//para saber que el cálculo fue exitoso
}

void imprimeMatriz(float array[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f\t", array[i][j]);
        }
        printf("\n");
    }
}
