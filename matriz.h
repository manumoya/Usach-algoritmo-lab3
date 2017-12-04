/*  ======= FUNCIONES DE MATRIZ  ========== */
int largo_matriz;
//char matriz_grafo[5][5];
char primer_nodo[1];
int **matriz_grafo_din;

int get_largo_matriz(){
  return largo_matriz;
}

void set_valores_matriz(){
  for (int i=0; i<largo_matriz; i++){
    for (int j=0; j<largo_matriz; j++){
      matriz_grafo_din[i][j]=0;
    }   
  }
}

void set_matriz_din(int largo){
  largo_matriz=largo+1;

  if (largo_matriz>26){
    printf( "\nMaximo 26 destinos!!\n" );
    return;
  }

  matriz_grafo_din = (int**)malloc(sizeof(int*)*largo_matriz);

  for (int i=0; i<largo_matriz; i++){
      matriz_grafo_din[i]=(int*)malloc(sizeof(int)*largo_matriz);
  }

  set_valores_matriz();

}

/* generar grafo */
void generar_grafo(char vertices[]) {
  for(int i=0; i<largo_matriz && vertices[i] != '\0'; ++i){
    matriz_grafo_din[0][i+1]=vertices[i];
    matriz_grafo_din[i+1][0]=vertices[i];
  }
}


/* imprimir grafo */
void imprimir_grafo(){
  for (int i=0; i<largo_matriz; i++){
    for (int j=0; j<largo_matriz; j++){
      if (j==0 || i==0){
        printf("%c ", matriz_grafo_din[i][j]);
      }else{
        printf("%i ", matriz_grafo_din[i][j]);
      }  
    }
    printf("\n");   
  }
}

/* retorna posición del nodo*/
int posicion_nodo(char letra[]){
  int posicion=0;
  for (int i=0; i<largo_matriz; i++){
    if ( matriz_grafo_din[0][i] == letra[0]){
      i=largo_matriz+1;
      posicion--;
    }
    posicion++;
  }  
  return posicion;
}

void agregar_adyacencia(char origen[], char destino[], int costo){
  int pos_origen=posicion_nodo(origen);
  int pos_destino=posicion_nodo(destino); 
  int pos_primer_nodo=posicion_nodo(&primer_nodo[0]);
  /* restricción 1: no puede ir al nodo origen  por lo que esta adyacencia no es valida
     restricción 2: no puede ir al mismo nodo
  */
  if (pos_destino != pos_primer_nodo && origen[0]!=destino[0]){
    matriz_grafo_din[pos_origen][pos_destino]=costo;  
  }

}

/* deja en cero el grafo*/
void resetear_grafo(char arreglo[]){
  for (int i=0; i<largo_matriz; i++)
      arreglo[i]='\0';
}

/* procesa grafo */
void procesar_grafo(int largo){
  char arrGrafoOut[26];
  resetear_grafo(arrGrafoOut);
  char arrGrafo[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i=0; i<largo; i++){
      arrGrafoOut[i]=arrGrafo[i];
  }
  generar_grafo(arrGrafoOut);
}
