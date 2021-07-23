/********************************************************
 * Ex04 -- reading of data. *
 * Not an especially earth-shattering program. *
 * *
 * Author: Israel Prado. *
 * *
 * Purpose: Read a file and organize it. *
 * *
 * Usage: *
 * Run the program ussign thbe file in the same place*
 ********************************************************/
#include <stdio.h>
#include <string.h>

char *punt = "Datos.txt"; //se abre el archivo a partir del puntero
int main() {
	FILE *arch;            //se detecta el documento
	char ant[100];        

	int place;         

	arch = fopen(punt, "r"); //se lee unicamente el documento
	if (arch == NULL) {
		fprintf(stderr, "Problem opening %s for reading\n", punt); //si detecta error, va a lanzar el mensaje y sale del programa
		return(8);
	}

	place = 0;
	while (fgets(ant, sizeof(ant), arch)) { //se define el ciclo del documento, que se cumplira hasta que se ubique el final del documento
		if (ant[0] == '\n') { //si encuentra un final de linea
			printf("\n");
			place = 0; //separara y continuara el programa
			continue;
		}

		ant[strlen(ant) - 1] = '\0';        
		switch (place) { //encuentra la posicion en que esta ubicada tu linea
			case 1:
			case 2:
			case 5:
			case 6:
				printf("%s\n", ant);      //estos casos los escribira en una misma linea (l1,2,5 y 6)
				break;
			case 0:
			case 4:
				printf("%s ", ant);     //estos casos los escribira en una misma linea (l0 y 4)   
				break;
			case 3:
				printf("%s, ", ant);        //unicaente escribe ubna linea
				break;
			default:
				printf("Error: unknown field\n"); //si esta no esta dentro de los casos mandara a error
		}
		++place; //cambia de posicion

	}
	fclose(arch); //cierra el documento

	return(0);
}
