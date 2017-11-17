#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "matriz.h"
#include "file.h"
#include "pila.h"


void resetear_rutas(int arrRutas[]){
  int largo_rutas = get_largo_matriz();
  for (int i=0; i<largo_rutas; i++)
      arrRutas[i]=0;
}
void imprimir_rutas(int arrRutas[]){
  int largo_rutas = get_largo_matriz();
  for (int i=0; i<largo_rutas; i++){
    printf("ady %d ", arrRutas[i]);
    printf("\n"); 
  }
}



void goloso_rutas(int posNodoIni, Pila *pila){

  int largo_rutas = get_largo_matriz();
  int *nuevas_rutas;
  nuevas_rutas = (int*)malloc(sizeof(int*)*largo_matriz);

  /* guarda todas las adyacencias del nodo*/
  resetear_rutas(nuevas_rutas);
  int cont_ruta=0;
  int menor_valor=0;
  int menor_posNodo=0;
  for (int i=1; i<largo_matriz; i++){
    int valor = matriz_grafo_din[posNodoIni][i];

    if (valor != 0){
      char nom_nodo = matriz_grafo_din[0][i];
      int tiene_ciclo = existe_ciclo(pila, &nom_nodo);

      /*
      printf("Nodo %c \n",  nom_nodo); 
      printf("Valor: %i \n", valor); 
      printf("menor valor: %i \n", menor_valor); 
      printf("tiene ciclo: %i \n\n", tiene_ciclo); 
      */

      if (tiene_ciclo == 0){
        if (menor_valor == 0 || menor_valor > valor){

      
          menor_valor=valor;
          menor_posNodo=i;
          cont_ruta++;
        }
      }
      
    }
  }



  


  if (cont_ruta==0){ // no tien adyacencia

    printf("\nCalcular ruta y costo \n"); 
    print_pila(pila);

    //int valor_ruta_guardada = lee_resultado();
    //print_pila(pila, valor_ruta_guardada);
    //pop(pila);
    
  }else{

    char nombre_nodo = matriz_grafo_din[0][menor_posNodo];

    /*
    printf("\nSeguir \n"); 
    printf("Pos Menor Nodo: %i \n", menor_posNodo); 
    printf("Valor Menor Nodo: %i \n", menor_valor); 
    printf("Nodo Menor %c \n",  nombre_nodo); 
    */

     

     push(pila, &nombre_nodo, menor_valor);
     goloso_rutas(menor_posNodo, pila);

    /*
    for (int i=0; i<largo_matriz; i++){
      if (nuevas_rutas[i]!=0){


        char nombre_nodo = matriz_grafo_din[nuevas_rutas[i]][0];
        int costo_nodo =matriz_grafo_din[posNodoIni][nuevas_rutas[i]];


        if (&nombre_nodo != pila->inicio->nombre){
          
          push(pila, &nombre_nodo, costo_nodo);
          goloso_rutas(nuevas_rutas[i], pila);
        
        }
      }
    }*/
    //pop(pila);
  }

}


int main() {

  Pila *pila;
  if ((pila = (Pila *) malloc (sizeof (Pila))) == NULL) 
    return -1;
  inicializa(pila);

  abrir_archivo();
  leer_archivo();
  cerrar_archivo();

  limpiar_archivo_resultado();  

  push(pila, &primer_nodo[0], 0);
  goloso_rutas( posicion_nodo( &primer_nodo[0] ), pila);

  //mostrar_mejor_ruta();

  /*
  int calculo = (int) strtol("155533333", (char **)NULL, 10);
  printf("calculo %i\n", calculo);
  */

}