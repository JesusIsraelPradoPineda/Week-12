  /********************************************************
 * ExOriginal3 -- List. *
 * Not an especially earth-shattering program. *
 * *
 * Author: Israel Prado. *
 * *
 * Purpose: Create a list with the name of the students and theor respective control numbers. *
 * *
 * Usage: *
 * Put the name and the control number and it will save it!  *
 ********************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
  char frase[100000];
  char frase2[200000]; //variables para almacenar cadena
  printf("dame lista de los alumnos (enumeralos) \n");
  fgets(frase, sizeof(frase), stdin);
  sscanf(frase,"%[^\n]s",frase2); //registro lo que me ingresaron
  FILE*fichero;
  fichero = fopen("Lista.txt","wt"); 
  fprintf(fichero, "lista de alumnos\n"); //escribo en el documento los datos recibidos
  fprintf(fichero, "%s\n",frase2);
  fprintf(fichero, "\n"); 
  printf("dame sus numeros de control, enumeralos igual \n"); //registro lo que me ingresaron
  fgets(frase, sizeof(frase), stdin);
  sscanf(frase,"%[^\n]s",frase2);
  fprintf(fichero, "No. de control\n"); //escribo en el documento los datos recibidos
  fprintf(fichero, "%s\n",frase2);
  fprintf(fichero, "\n"); 
    fclose(fichero);
    printf("Proceso completo"); //cierro e indico que el proceso se logro exitosamente
    return 0;
}
