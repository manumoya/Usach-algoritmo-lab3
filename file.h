FILE *itinerario;
FILE *arch_resultado;
FILE *arch_resultado_lectura;
char nombre_archivo[] = "itinerario.txt";
char archivo_resultado[] = "resultado.txt";


void abrir_archivo(){
	if ( (itinerario = fopen(nombre_archivo, "r") ) == NULL){
    	printf("No se ha podido abrir el archivo %s.\n", nombre_archivo);
  	}else{
  		//printf("Archivo abierto %s.\n", nombre_archivo);
  	}
}

void cerrar_archivo(){
	if (fclose(itinerario)!=0) {
      printf("No se ha podido cerrar el fichero %s.\n", nombre_archivo);
   
    }else{
    	fclose(itinerario);
  		//printf("Archivo cerrado %s.\n", nombre_archivo);
  	}
}

void abrir_archivo_resultado(){
	if ( (arch_resultado = fopen(archivo_resultado, "wt") ) == NULL){
    	printf("No se ha podido abrir el archivo %s.\n", archivo_resultado);
  	}else{
  		//printf("Archivo abierto %s.\n", archivo_resultado);
  	}
}

void cerrar_archivo_resultado(){
	if (fclose(arch_resultado)!=0) {
      printf("No se ha podido cerrar el fichero %s.\n", archivo_resultado);
   
    }else{
    	fclose(arch_resultado);
  		//printf("Archivo cerrado %s.\n", archivo_resultado);
  	}
}

void abrir_archivo_resultado_lectura(){
	if ( (arch_resultado_lectura = fopen(archivo_resultado, "r") ) == NULL){
    	printf("No se ha podido abrir el archivo %s.\n", archivo_resultado);
  	}else{
  		//printf("Archivo abierto %s.\n", archivo_resultado);
  	}
}

void cerrar_archivo_resultado_lectura(){
	if (fclose(arch_resultado_lectura)!=0) {
      printf("No se ha podido cerrar el fichero %s.\n", archivo_resultado);
   
    }else{
    	fclose(arch_resultado_lectura);
  		//printf("Archivo cerrado %s.\n", archivo_resultado);
  	}
}

void limpiar_archivo_resultado(){
	if ( (arch_resultado = fopen(archivo_resultado, "w") ) == NULL){
	}else{
   		fclose(arch_resultado);
   	}
}


int len_linea(char cadena[]){
    int j=0;
    while (cadena[j] != '\0'){
    	j++;
    } 
    return j;
}

char get_val_prim_linea(char linea[], char ini_or_nronodo){
	// D: Decena
	if ( ini_or_nronodo=='D'){
		//printf( "largo line : %d \n", len_linea(linea) );
		if (len_linea(linea)==4){
			return ('0');
		}else{
			return (linea[0]);
		}
	}
	// U: unidad
    if ( ini_or_nronodo=='U'){
		if (len_linea(linea)==4){
			return (linea[0]);
		}else{
			return (linea[1]);
		}
	}

	// N: Nodo
    if (ini_or_nronodo=='N'){
    	//printf( "NOD : \n");
    	if (len_linea(linea)==4){
			return (linea[2]);
		}else{
			return (linea[3]);
		}
    }
    
    return(0);
}

char get_val_otras_linea(char linea[], char tipo_valor){
	// O: origen
	if ( tipo_valor=='O'){
    	//printf( "Orig : \n");
        return (linea[0]);
    }
    // D: Detino
    if (tipo_valor=='D'){
        //printf( "Dest : \n");
    	return (linea[2]);
    }

    return(0);
}

int get_val_costo(char linea[]){
	char valor[20]="";
    for (int i=4; i<=strlen(linea); i++){
    	strcat(valor, &linea[i]);
    }

    int valor_final =atoi(valor);
 	return ( valor_final );
}

int convertir_numero(char decena[], char unidad[]){
	int unid= (int) unidad[0] -48;
	//int unid= (int) strtol(&unidad[0], (char **)NULL, 10);

	if (decena[0]=='0'){
		return unid;
	}else{
		int dece =(int) decena[0] -48;
		//int dece =(int) strtol(&decena[0], (char **)NULL, 10);
		return (dece*10+unid);
	}
	return(0);
}

void carga_matriz(int nro_linea, char linea[]){
	if (nro_linea==1){
		char dece[1], unid[1];
		dece[0] = get_val_prim_linea(linea, 'D');
		unid[0] = get_val_prim_linea(linea, 'U');
		int nroNodos = convertir_numero(dece, unid);

		primer_nodo[0] = get_val_prim_linea(linea, 'N');

		set_matriz_din(nroNodos+1);
		procesar_grafo(nroNodos+1); 
	}else{
		int costo = get_val_costo (linea);

		char origen[1], destino[1];
		origen[0]  = get_val_otras_linea(linea, 'O');
		destino[0] = get_val_otras_linea(linea, 'D');

		agregar_adyacencia(origen, destino, costo);
	}

}

void leer_archivo(){
	char linea[100];
	int nro_linea=1;

	while (!feof(itinerario)){
		fgets(linea,sizeof(linea),itinerario);
		carga_matriz(nro_linea, linea);

		nro_linea++;
	}
	imprimir_grafo();
	printf("\n");
}

void guarda_ruta_mejor(char info[], int valor){

	char linea2[10]="";
    strcat(linea2, &info[0]);
   	strcat(linea2, "-");
   	
   	char num_to_char[3];
	sprintf(num_to_char, "%i", valor);
	
    strcat(linea2, num_to_char);
    strcat(linea2, "\n");
    

    fputs(linea2, arch_resultado);

}


