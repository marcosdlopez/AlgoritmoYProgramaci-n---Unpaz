#include <stdio.h>
#include <stdlib.h>
#define n 40
 // tipo de datos estructura

/*EJERCICIO  141

Escribir un programa para calcular el importe de una venta en un supermercado.
El usuario debe ingresar por pantalla el nombre del producto,
el precio por unidad y cantidad de unidades vendidas
y el programa sacará por pantalla:
el nombre de los producto vendidos
El cantidad de unidades vendidas
precio del producto
El subtotal de ese producto

El total general de toda la venta.

Permitir como máximo 40 productos distintos en la venta.

Se considera que primero se carga un vector con los 40 productos
 permitidos para la venta y su precio
*/

typedef struct
{
    char nombreprod[40];
    int cantstock;
    int cantvendido;
    float precio;
} registro;

void cargararticulo ( registro producto[], int *fin);
void cargarventas (registro producto[], int fin);
void listar (registro producto[], int fin);



int main()
{
    registro producto[n];
    int fin;

    cargararticulo (producto , &fin);

    printf("\n\n fin %d", fin);
    system("pause");

    cargarventas (producto, fin);
    listar (producto, fin);

    return 0;
}



void cargararticulo ( registro producto[], int *fin)
{
    //solamente cargo datos
        int i=0;
        char sino;
    do
    {
         system("cls");
         printf("\n\n\nCARGA DE DATOS\n\n\n");
         printf("\n Ingrese nombre del producto:   ");
         fflush(stdin);
         gets(producto[i].nombreprod);
         printf("\n\n Ingrese stock: ");
         scanf("%d",&producto[i].cantstock);
         producto[i].cantvendido = 0;
         printf("\n\n Precio: ");
        scanf("%f", &producto[i].precio);

        printf("desea seguir cargando datos (s/n): ");
        fflush(stdin);
        scanf("%c", &sino);
        i++;


    }while ((sino != 'n' && sino != 'N') && i < n);
//aca el video lo explique mal aca va el valor y no la direccion
//la funcion recibe la direccion, la referencia a esa variable perdonnnnnnn
//
    *fin = i;

}

void cargarventas (registro producto[], int fin)
{
    int i;
    system("cls");

    for(i=0; i<fin; i++)
    {
        printf("\nEl articulo %s stock: %d", producto[i].nombreprod, producto[i].cantstock);
        printf("\n Cantidad vendida:");
        scanf("%d", &producto[i].cantvendido);
        if( producto[i].cantvendido < producto[i].cantstock)
            producto[i].cantstock = producto[i].cantstock - producto[i].cantvendido;
        else
        {
            printf("\n\n Supera stock !!!!!!!!!!\n\n");
            producto[i].cantvendido=0;
        }
    }

}

void listar (registro producto[] , int fin)
{
    int i;
    float total=0;
    system("cls");
    printf("\n\n\t\tLISTADO DE LOS ARTICULOS\n\n");

    printf("ARTICULO \t\t STOCK \tVENDIDO\tPRECIO  PRECIO*CANTIDAD");

    for(i=0; i<fin; i++)
    {

        printf("\n%s \t\t  %d", producto[i].nombreprod, producto[i].cantstock);
        printf("\t%d", producto[i].cantvendido);
        printf("\t %f   %f", producto[i].precio, producto[i].precio * producto[i].cantvendido);
        total += producto[i].cantvendido * producto[i].precio;

    }

    printf("\n\n\n TOTAL VENDIDO---->  %f", total);
}
