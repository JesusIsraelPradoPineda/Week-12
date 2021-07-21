/********************************************************
 * Ex03 -- Classification. *
 * Not an especially earth-shattering program. *
 * *
 * Author: Israel Prado. *
 * *
 * Purpose: make classifications of numbers into 2 files given 1. *
 * *
 * Usage: *
 * put in a TXT the numbers and the porgram will separate in two files. *
 ********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char archivo[] = "datos.txt"; //genero una variable para guardar el nombre del archivo

int main()
{
	int  number;         
	FILE *one;     
	FILE *three; 
	FILE *non;    //genero las ubicaciones de memoria de los archivos
	char *line = NULL;   
	size_t  len = 0;   //longitud actual de la línea  
	one = fopen(archivo,"r");
	three = fopen("divisible.txt", "w");
	non = fopen("others.txt", "w"); //mando a abrir los documentos
	if (one == NULL) {
		printf("No se pudo encontrar el documento -%s- \n",archivo); //si este no se encuentra, mando a error
		exit(8);
	}
	while (getline(&line, &len, one) != -1){ //este se cumplira cuando no llegue al final del texto
		sscanf(line, "%d", &number); //escanea linea por linea
		if ((number % 3) == 0)
			fprintf(three, "%d\n", number);
		else
			fprintf(non, "%d\n", number); //si se cumple la condicion, lo metera en un documento, de lo contrario, se ira al otro el numero
	}
	free(line);
	fclose(one);
	fclose(three);
	fclose(non);
  printf("Exito en la operacion \n");  //cierro los documentos y salgo
	return 0;
}
