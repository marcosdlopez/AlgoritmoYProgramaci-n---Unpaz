#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int main()
{   FILE *aorigen;
    FILE *destino;

    char archivoOrigen[20], archivoDestino[20], nombre[20];

    printf("\n Ingrese el nombre del archivo Origen: ");
    fflush(stdin);
    gets(archivoOrigen); //scanf("%s",archivoOrigen);

    printf("\n Ingrese el nombre del archivo destino: ");
    fflush(stdin);
    gets(archivoDestino);

    aorigen=fopen(archivoOrigen,"r");
    if (aorigen == NULL)
        {
          printf("Error de apertura del archivo %s", archivoOrigen);
          return -1;
        }

    destino=fopen(archivoDestino,"w");  //por que es de creacion va w
    if (destino == NULL)
        {
           printf("Error de creacion de archivo %s",archivoDestino);
           return -1;
        }
    //leo mi archivo Origen y guardo en mi archivo destino
   while ((aorigen) == 0)
   {
       fscanf(aorigen,  "%s", nombre); //fgets(nombre, aorigen);
       fprintf(destino, " %s", nombre);

   }

   fclose(aorigen);
   fclose(destino);
   system("pause");
   return 0;
}
