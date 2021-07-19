/********************************************************
 * ExOriginal1 -- Grades. *
 * Not an especially earth-shattering program. *
 * *
 * Author: Israel Prado. *
 * *
 * Purpose: Create an file with the score of n students. *
 * *
 * Usage: *
 * put the numbers of students and then put they respectives scores  *
#include <stdio.h>
#include <stdlib.h>

int main() {
    float num[4],media; //se registran las variables a usar
    int i,n=0; //variables de contador
    FILE*fichero;
    fichero = fopen("calificaciones.txt","wt"); //abro el documento a trabajar y lo creo, en modo de escritura
    printf("cuantos alumnos vamos a registrar?\n");
    scanf("%d",&n); //pido cuantos alumnos se van a registrar en la plataforma
    for (int k=1;k<=n;k++){ //se realizara la operacion n veces
    for(i=0; i<4; i++){ //registro calificacion de 4 unidades
        printf("Ingresa las calificaciones del alumno %d de la unidad %d:  ",k,i+1);
        scanf("%f", &num[i]);
    }
    media = (num[0]+num[1]+num[2]+num[3])/4; //saco el promedio
    fprintf(fichero, "Alumno %d\n",k); //escribo en el documento los datos recibidos
    fprintf(fichero, "Primera Calificacion: %0.1f\n",num[0]);
    fprintf(fichero, "Segunda Calificacion: %0.1f\n",num[1]);
    fprintf(fichero, "Tercera Calificacion: %0.1f\n",num[2]);
    fprintf(fichero, "Cuarta Calificacion: %0.1f\n",num[3]);
    fprintf(fichero, "Calificacion Final: %0.1f\n",media);
    fprintf(fichero, "\n");
    }
    fclose(fichero);
    printf("Proceso completo"); //una vez que me sali de n, cierro el documento, lo salvo y finalizo el programa
    
    return 0;
}
