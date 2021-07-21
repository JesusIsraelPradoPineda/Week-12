  
/********************************************************
 * Ex01 -- Ex01. *
 * Not an especially earth-shattering program. *
 * *
 * Author: Israel Prado. *
 * *
 * Purpose: Hacer memorias a partir de documentos. *
 * *
 * Usage: *
 * Ingresa el documento, leera el numero de letras y se guardara el documento en un txt *
 ********************************************************/
#include <stdio.h>
#include <stdlib.h>

const char archivo[] = "input.txt"; //archivo que voy a usar para el trabajo, puede definirse otro
const char archivo2[] = "output.txt";//archivo donde guardare los datos

int main()
{
	int su = 0;//numero de caracteres a mostrar
	FILE *loc; //ingreso del archivo

	int letra; //letra por letra a contar

	loc = fopen(archivo, "r"); //solo abro para leer

	if (loc == NULL) {
		printf("Cannot open %s\n", archivo);
		exit(8); //si no funciona la situacion, este cerrara
	}
	while (1) {
		letra = fgetc(loc); 
		if (letra == EOF)  //este cada vez que identifique el caracter, aumentara la cuenta a un 1
			break;
		++su;
	}

	printf("Number of characters in %s is %d\n", archivo, su); //se imprime en pantalla

	fclose(loc); //se cierra 
  FILE *loc2;
  loc2 = fopen(archivo2, "wr");
  fprintf(loc2,"Number of characters in %s is %d\n", archivo, su); //se imprime en pantalla al crear un archivo
  fclose(loc2);
	return 0; //cierro el programa y guardo los dos documentos
}
