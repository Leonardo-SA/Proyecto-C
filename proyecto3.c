// Leonardo Serrano Arias C17484
// Vincer Solis Hernandez B87702
// David Rodriguez Gutierrez B59281

/*
Funcionamiento del programa:
El programa solicita al usuario ciertos datos para crear una matriz.
El usuario debe ingresar la cantidad de filas y columnas y los números de cada posición.
La función del programa retorna 0 si no hay errores y -1 si hubo algún error.
El programa devuelve las direcciones de memoria de los números que inician cada fila.
El programa presenta verificación de errores.
*/

#include <stdio.h>
#include <stdlib.h>

// Definición de la función
int ingresarPosicionesMatriz(float ***matriz, int *filas, int *columnas, float ***direcciones);

int main() {
    int filas, columnas;
    float **matriz;
    float **direcciones;

    // Llamar a la función para ingresar posiciones
    int resultado = ingresarPosicionesMatriz(&matriz, &filas, &columnas, &direcciones);

    if (resultado == 0) {
        // Imprimir las direcciones de memoria del primer elemento de cada fila
        printf("\nDirecciones de memoria del primer elemento de cada fila:\n");
        for (int i = 0; i < filas; i++) {
            printf("Fila %d -> Primer elemento: %p\n", i + 1, (void *)direcciones[i]);
        }

        // Liberar memoria
        for (int i = 0; i < filas; i++) {
            free(matriz[i]);
        }
        free(matriz);
        free(direcciones);
    } else {
        printf("Hubo un error durante la entrada de datos.\n");
    }

    return 0;
}

int ingresarPosicionesMatriz(float ***matriz, int *filas, int *columnas, float ***direcciones) {
    // Solicitar al usuario las dimensiones de la matriz
    printf("Ingrese el número de filas de la matriz: ");
    if (scanf("%d", filas) != 1 || *filas <= 0) {
        // Error: La entrada no es un número positivo
        return -1;
    }

    printf("Ingrese el número de columnas de la matriz: ");
    if (scanf("%d", columnas) != 1 || *columnas <= 0) {
        // Error: La entrada no es un número positivo
        return -1;
    }

    // Asignar dinámicamente memoria para la matriz y las direcciones
    *matriz = (float **)malloc(*filas * sizeof(float *));
    if (*matriz == NULL) {
        // Error al asignar memoria
        return -1;
    }

    
    *direcciones = (float **)malloc(*filas * sizeof(float *));
    if (*direcciones == NULL) {
        // Error al asignar memoria
        free(*matriz);
        return -1;
    }

    // Llenar la matriz con números ingresados por el usuario y obtener las direcciones
    for (int i = 0; i < *filas; i++) {
        printf("Ingrese los %d números para la fila %d: ", *columnas, i + 1);

        (*matriz)[i] = (float *)malloc(*columnas * sizeof(float));
        if ((*matriz)[i] == NULL) {
            // Error al asignar memoria para la fila
            // Liberar memoria asignada previamente
            for (int j = 0; j < i; j++) {
                free((*matriz)[j]);
            }
            free(*matriz);
            free(*direcciones);
            return -1;
        }

        (*direcciones)[i] = (*matriz)[i];

        for (int j = 0; j < *columnas; j++) {
            if (scanf("%f", &(*matriz)[i][j]) != 1) {
                // Error: La entrada no es un número
                // Liberar memoria asignada previamente
                for (int k = 0; k <= i; k++) {
                    free((*matriz)[k]);
                }
                free(*matriz);
                free(*direcciones);
                return -1;
            }
        }
    }

    return 0; // Éxito
}
