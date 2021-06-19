#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define n 5

//prototipo de funciones

 void  cargar (float matriz[][n]);
 void mostrar (float[][n]);
 float promedio (float matriz[][n]);
 float sumatoria (float matriz[][n]);

int main()
{
    float matriz[n] [n], prome = 0;

   // ejecucion de funciones

    cargar(matriz);
    mostrar (matriz);
    prome = promedio(matriz);

    printf("\n\n\nEl promedio de la contradiagonal es %.2f y la sumatoria de la diagonal es %.2f",prome, sumatoria(matriz));
    return 0;
}

//implementacion de funciones


 void cargar (float matriz[][n])
 {
       int i,j;
       printf("\n Cargar matriz \n\n\n");
       for(i=0; i<n; i++)
        for(j=0; j<n; j++)
       {
           scanf("%f", &matriz[i][j]);
       }
 }

 float promedio (float matriz[][n])
 {
       int i, j;
       printf("\n\nIngreso a realizar el promedio\n\n\n");
       float suma=0;
       for(i=0; i<n; i++)
       {
           for(j=0 ; j<n; j++)
           {
               if( j + i +1 == n)
                suma +=matriz[i][j];

           }
       }
       suma = suma / (float) n;
       return suma;
 }


 float sumatoria (float matriz[][n])
 {
       int i;
       float suma=0;
       printf("\n\n\nCalculo la suma\n\n\n");
       for(i=0; i<n; i++)
       {
           suma += matriz[i][i];
       }

       return suma;
 }

void mostrar (float matriz[][n])
{
    int i,j;

    for(i=0; i<n; i++)
    {
        printf("\n");
        for(j=0; j<n; j++)
        {
            printf("\t %f", matriz[i][j]);
        }
    }

}
