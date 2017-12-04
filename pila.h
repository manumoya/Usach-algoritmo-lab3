
typedef struct _nodo {
    char nombre[20];
    int costo;
    struct _nodo *siguiente;
}Nodo;

typedef struct _pila{
  Nodo *inicio;
  Nodo *final;  
}Pila;

/* inicaliza pila*/
void inicializa(Pila *pila){
  pila->inicio = NULL;
  pila->final = NULL; 
}

/* pila push */
void push(Pila *pila, char nombre[20], int costo) {
	/* Crear un nodo nuevo */
  Nodo *nuevo;
  nuevo = (Nodo*)malloc(sizeof(Nodo));

  strcpy(nuevo->nombre,nombre);
  nuevo->costo=costo;
  nuevo->siguiente = NULL;

  /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */

  if(pila->inicio==NULL){
    pila->final= nuevo;
  }

  /* Si la cola no estaba vacía, añadimos el nuevo como 1ro */
  if(pila->inicio != NULL){
    nuevo->siguiente = pila->inicio;
  }  
 
  /* Ahora, el último elemento de la cola es el nuevo nodo */
  pila->inicio= nuevo;
}

/* Pila pop */
void pop(Pila *pila) {
  Nodo *nodo_pop;
  if (pila->inicio==NULL){
    return;
  }  
  nodo_pop = pila->inicio;
  pila->inicio = nodo_pop->siguiente;
  
  free(nodo_pop);
}

/* Imprimir pila */
void print_pila(Pila *pila){
  Nodo *auxiliar;
  auxiliar = pila->inicio;
  
  if (auxiliar==NULL){
    printf( "\nLa lista está vacía!!\n" );
  }else{
    printf("\nMostrando pila completa:\n");
  } 
  int costo_total=0; 
  while (auxiliar!=NULL) {
    costo_total=costo_total + auxiliar->costo;
    printf("nombre: %s", auxiliar->nombre);
    printf(" costo: %d", auxiliar->costo);
    printf("\n");
    auxiliar = auxiliar->siguiente;
  }
  printf("costo total: %d\n", costo_total);
}

/* Vr si existe nodo par ver si tiene ciclo*/
int existe_ciclo(Pila *pila, char nodo[]){
  Nodo *auxiliar;
  auxiliar = pila->inicio;
  //printf("\nMostrando pila completa:\n");
  if (auxiliar==NULL) printf( "\nLa lista está vacía!!\n" );
  int validacion=0;
  int cont_pila=0;
  while (auxiliar!=NULL && validacion==0) {
    if (auxiliar->nombre[0]==nodo[0]){
      validacion=1;

    }
    auxiliar = auxiliar->siguiente;
    cont_pila++;
  }
  return (validacion);
}











