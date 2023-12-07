//Vincer Solis Hernadez B87702, Leonardo Serrano Arias C17484, David Rodriguez Gutierrez B59281
//Este programa toma una matriz dada por el usuario de un tamano dado por el usuario
//y determina el camino mas corto entre x y y ciudad definida por el usuario usando 
//recursion, en donde se buscan todos los caminos posibles y se determina el mas corto
//y este luego se imprime junto al recorrido que tiene se tiene que hacer.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CaminoMasCorto(int cant_ciudades,int matriz[cant_ciudades][cant_ciudades],  int inicio, int fin, int caminoActual[cant_ciudades], int distancia_actual, int *mejorCamino, int *distancia_mascorta) {
    // si se completo el camino
    if (inicio == fin) {
        // se determina la distancia mas corta comparando la distancia vieja con la actual, por eso la 
        // distancia_mascorta tiene que ser definida en el main como un valor mas grande que las distancias
        // de la matriz
        if (distancia_actual < *distancia_mascorta) {
            // se guarda la distacia actual si comple con el if
            *distancia_mascorta= distancia_actual;
            //printf("%d", distancia_actual]);
            // se recorre con un for, array del mejor camino, con el actual, si se cumple el if,
            // para poder imprimirlo
            for (int i = 0; i < cant_ciudades; i++) {
                mejorCamino[i] = caminoActual[i];
                //printf("%d", mejorCamino[i]);
            }
        }
        return;
    }
    // caso base de la recursion
    // se recorren las columnas de la matriz, en donde se muestre que esten conectados al punto de inicio
    // El for sirve para ver todos los posibles caminos entre las ciudades que esten conectadas a la de inicio
    for (int i = 0; i < cant_ciudades; i++) {
        // se comienza en la fila de inicio de la ciudad de la cual se parte, 
        // si esta distancia es mayor a 0 y camino actual en el cual 
        // el if determina si hay una conexion entre las ciudades a la de inicio con matriz[inicio][i] > 0,
        // ademas verifica que la columna actual no se haya revisado ya con caminoActual
        if (matriz[inicio][i] > 0 && !caminoActual[i]) {
            // determina la ciudad como parte del camino actual 
            caminoActual[i] = 1;
            // vuelve a llamar a la funcion para seguir con el camino que se eligio, usando i como parametro para la ciudad de inicio
            // se determina la nueva distancia y se le ingresa a la llamada recursiva, ademas de pasarle otros parametros
            int distancia;
            distancia  = distancia_actual + matriz[inicio][i];
            //printf("%d", distancia);
            CaminoMasCorto(cant_ciudades, matriz, i, fin, caminoActual, distancia, mejorCamino, distancia_mascorta);
            caminoActual[i] = 0;  // actualiza el camino actual para buscar mas caminos posibles
        }
    }
}



int main() {    
    // se crean variables que se van a usar para los for y la matriz
    int cant_ciudades,i,j,dis;
    int distancia;
    // variable para indicar valor de la distancia mas corta
    int grande = 100;
    // se ingresan la cantidad de ciudades que se quiere 
    printf("Ingrese la cantidad de ciudades que quiere tomar en cuenta: ");
    //fflush(stdout);
    scanf("%d", &cant_ciudades);
    // se crea la matriz y un array para las distacias y ciudades
    char arr [6][10];
    int matriz[cant_ciudades][cant_ciudades];
    // string de las ciudades de destino y fin
    char ciudad_inicio[10];
    char ciudad_final[10];
    // for para ingresar la totalidad de las ciudades     
    for(i=0;i<cant_ciudades;i++){
        printf("Ingrese las ciudades:");
        //fflush(stdout);
        scanf("%s", arr[i]);
        //printf("%s",arr[i]);
    }
    // for para recorrer las ciudades de forma matriz simetrica, donde solo se ingresen
    // ciertos datos y que no sea repetido
    for (i = 0; i < cant_ciudades; i++) {
        for (j = i; j < cant_ciudades; j++) {
            if (i!=j){
                //if(
                // mientras no se este en la misma ciudad se rellena con 0 la distancia, 
                // se ingresa -1 si no hay caminos y se guardan de forma simetrica los valores
                printf("Ingrese -1, si no hay camino entre las ciudades");
                printf("Ingrese las distancias entre la ciudad %s, y ciudad %s:", arr[i], arr[j]);
                scanf("%d", &distancia);

            
                matriz[i][j] = distancia;
                matriz[j][i] = distancia;
                //printf('%d',i);
                //printf(matriz);
            } 

            else{

                matriz[i][j] = 0;
            }
        }    
                
            //printf("%d\n", matriz[i][j]);
    }

    /*int matriz[6][6] = {
        {0, -1, -1, 5, -1, -1},
        {-1, 0, 4, 6, 1, 4},
        {-1, 4, 0, 2, 2, 10},
        {5, 6, 2, 0, 1, -1},
        {-1, 1, 2, 1, 0, -1},
        {-1, 4, 10, -1, -1, 0}
    };*/

    // se determinan los numeros del array de ciudades
    int numinicio, numfinal;
    printf("Ingrese la ciudad de inicio:");
    //fflush(stdout);
    scanf("%s", ciudad_inicio);
    //printf("%s", ciudad_inicio);
    // el for compara cada string del array arr con la ciudad de inicio
    // si da 0 se guarda el valor de la ciudad el cual es i
    for(i=0;i<cant_ciudades;i++){  
        if (strcmp(arr[i], ciudad_inicio) == 0) {
            numinicio=i;
            //printf("%d",numinicio);
        }
    }
    //printf("%d", i);
    printf("Ingrese la ciudad de llegada:");
    //fflush(stdout);
    scanf("%s", ciudad_final);
    // el for compara cada string del array arr con la ciudad de inicio
    // si da 0 se guarda el valor de la ciudad el cual es i
    for(i=0;i<cant_ciudades;i++){  
        if (strcmp(arr[i], ciudad_final) == 0) {
            numfinal=i;
            //printf("%d",numfinal);
        }
    }
      
    // se definen los array del tamano de la matriz
    // el caminoActual, el mejorcamino y 
    // la distancia mas corta la cual se tiene que 
    // definir como un numero grande para que se pueda
    // implimentar un if en la funcion recursiva
    int caminoActual[cant_ciudades];
    int mejorCamino[cant_ciudades];
    int distancia_mascorta = grande;
    // se determina el caminoActual, desde la ciudad inicial como 1
    // ya que se parte como un camino correcto ya que es la ciudad de inicio
    caminoActual[numinicio] = 1;
    // se define la distancia actual en 0
    int distancia_actual=0;
    // se llama a la funcion dando los parametros del numero de tamano, la matriz, los numeros de las ciudades de inicio y fin, el
    // caminoActual, el mejor camino y la distancia mas corta en forma de direccion, y la distancia actual
    CaminoMasCorto(cant_ciudades, matriz, numinicio, numfinal, caminoActual, distancia_actual, mejorCamino, &distancia_mascorta);
        
    // se imprime el camino mas corto, todo el recorrido,
    printf("El camino más corto desde %s hasta %s es: ", ciudad_inicio, ciudad_final);
    // se usa un ciclo for para recorrer el mejor camino, donde se imprime la posiciones del arr[i] de las 
    // ciudades
    for (i = 0; i < cant_ciudades; i++) {
        if (mejorCamino[i]) {
            //printf("%d ", i);
            printf("%s->", arr[i]);
        }
    }
    // Por Ultimo se imprime la distancia mas corta
    printf("\nLa distancia mas corta es: %d\n", distancia_mascorta);

return 0;
}



