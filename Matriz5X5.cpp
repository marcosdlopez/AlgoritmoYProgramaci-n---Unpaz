#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()

{
    int matriz [N][N], fila, col;

    for (fila=0; fila<N; fila++)

       for (col=0; col<N; col++)
        {
       printf("\t Ingrese el numero correspondiente para la matriz [%i][%i]: \n", fila, col);
       scanf("%i", &matriz[fila][col]);
        }

    for (fila=0; fila<N; fila++)

       for (col=0; col< N; col++)
       {
           if (col == 2)

            printf("numero %i esta ingresado fila 2 \n", matriz[fila][col]);

            if (col == 4)

                printf("numero %i esta ingresado fila 2 \n", matriz[fila][col]);
       }


    return 0;
}
