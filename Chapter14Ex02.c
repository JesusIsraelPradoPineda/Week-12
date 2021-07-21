/********************************************************
 * Ex02 -- Intercambio. *
 * Not an especially earth-shattering program. *
 * *
 * Author: Israel Prado. *
 * *
 * Purpose: Realizar copias a otros archivos con los correspondientes espacios. *
 * *
 * Usage: *
 * Mete un texto y este te duplicara los espacios que encuentre  *
 ********************************************************/
#include <stdio.h>                
#include <stdlib.h>               

int main(void)
{             
    char entra[] = "hola.txt";
    char sale[] = "salida.txt"; //declaro los archivos a utilizar
    FILE *entrar;
    FILE *salir; //directorio de cada uno
    int cara;                    // usado para fgetc
    int i;
    int espacios = 2; //declaro las variables a utilizar

    entrar = fopen(entra, "r"); //mando la orden de abrir el documento
    if (entrar == NULL) {
        fprintf(stderr, "No se encontro %s\n", entra); //si este no existe, mandara error 
        exit(8);
    }

    salir = fopen(sale, "w");
    if (salir == NULL) {
        fprintf(stderr, "No se encontro %s\n", sale);//si este no esta bien declarado, mandara error 
        exit(8);
    }

    while (1) {
        cara = fgetc(entrar);
        if (cara == ' ') {    //cada espacio pondra 2 mas... duplicando la cantidad de espacios
            cara = ' ';
            for (i = 0; i <= espacios; i++) {
                fputc(cara, salir);
            }
        }
        if (cara == EOF) //cuando este llegue al final del documento, este se saldra automaticamente
            break;

        fputc(cara, salir);
    }

    fclose(entrar); 
    fclose(salir); //cierro los documentos

    return 0;
}
