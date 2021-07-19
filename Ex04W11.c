/********************************************************
 * ExOriginal4 -- reading of list. *
 * Not an especially earth-shattering program. *
 * *
 * Author: Israel Prado. *
 * *
 * Purpose: Read the txt with the list. *
 * *
 * Usage: *
 * run the program*
 ********************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *one; //lectura del archivo en esa direccion de memoria

   if ((one = fopen("Lista.txt","r")) == NULL){
       printf("Error! opening file");

       
       exit(1); //si algo malo se encontro a la hora de abrir el programa, se cierra el programa
   }
  char chain[100];
  while (feof(one)==0){ //cuando el valor sera diferente de un espacion en blanco
  fscanf(one, "%s\n",chain); //registrara la variable
  printf("%s ",chain);  //y la imprimira, pasando a la siguiente parte
  }
  fclose(one);
  printf("\n");
  printf("Reading sucesfully"); //una vez acabado, se cierra el programa
   return 0;
}
