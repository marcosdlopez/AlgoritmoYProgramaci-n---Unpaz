/*Ejercicio ejemplo
Se tiene el siguiente struct:

typedef struct {
    int codigo;
    char descripcion[41];
    float precio;
} tproducto;
Elaborar un programa que permita:

Crear un archivo binario llamado "productos.dat"
1 - Carga de registros de tipo tproducto.
2 - Listado completo de productos.
3 - Consulta de un producto por su código.
4 - Modificación del precio de un producto.
5 - Consulta con busqueda binaria
OBSERVACION: La carga máxima de productos es 100
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define n 100

typedef struct {
    int codigo;
    char descripcion[41];
    float precio;
} tproducto;

int menu();
int cargaarchivo(tproducto Producto[]); // carga el archivo al vector estructura


int cargar();
int listado(tproducto Producto[], int fin);
int consulta(tproducto Producto[], int fin);
void modificacion(tproducto Producto[], int fin);

int ordenarcodigo(tproducto Producto[], int fin);
int busquedabinaria(tproducto Producto[], int fin, int codigobuscado);
int consultabinaria (tproducto Producto[], int fin);
int bajaarchivo(tproducto Producto[],int fin);


int main()
{
    int opcion,error, fin;
    tproducto Producto[n];
    do {
        opcion = menu();
        switch (opcion)
        {
            case 1:
                    error = cargar();
                    if (error == -1)
                    {
                        printf("\n\n ERROR de apertura\n\n\n");
                        getche();
                    }
                    if (error != -1)
                        fin = cargaarchivo(Producto);

                    break;
            case 2:
                   fin = cargaarchivo(Producto);
                   listado(Producto, fin);
                   break;
            case 3:
                   fin = cargaarchivo(Producto);
                   consulta(Producto, fin);
                   break;
            case 4:
                   fin = cargaarchivo(Producto);
                   modificacion(Producto,fin);  //error toma tambien el valor de i
                   break;
            case 5:
                   fin = cargaarchivo(Producto);
                   ordenarcodigo(Producto,fin);
                   consultabinaria(Producto,fin);  //error toma tambien el valor de i
                   break;
            case 6:
                   fin = cargaarchivo(Producto);
                   ordenarcodigo(Producto,fin);
                   fin = bajaarchivo(Producto, fin);
                   listado(Producto, fin);
                   break;


        }
    } while (opcion!=9);
    return 0;
}

int menu()
{
    int opcion;
    system("cls");  //limpia la pantalla
    printf("1 - Carga de registros de tipo tproducto\n");
    printf("2 - Listado completo de productos.\n");
    printf("3 - Consulta de un producto por su codigo.\n");
    printf("4 - Modificacion del precio de un producto. \n");
    printf("5 - Consulta binaria \n");
    printf("6 - Baja de un codigo \n");
    printf("9 - Finalizar\n\n");
    printf("Ingrese su opcion:");
    scanf("%i",&opcion);
    return opcion;

}


int cargar()
{
    //Voy cargando y grabanco
    FILE *arch;
    arch=fopen("productos.dat","ab");
    if (arch==NULL)
        return -1;

    char sino;
    tproducto producto;  //VARIABLE DE TIPO tproducto

    do
    {
        printf("Ingrese el codigo del producto:");
        scanf("%d",&producto.codigo);
        fflush(stdin);
        printf("Ingrese el nombre del producto:");
        fflush(stdin);
        gets(producto.descripcion);
        printf("Ingrese precio:");
        scanf("%f",&producto.precio);
        fwrite(&producto, sizeof(tproducto), 1, arch);
        printf("\n\n Quiere seguir cargando (s/n): ");
        fflush(stdin);
        scanf("%c", &sino);
    }while (sino != 'n');
    fclose(arch);
   return 0;
}

int listado(tproducto Producto[], int fin)
{
    int i;

    for(i=0 ; i<fin ; i++)
    {
        printf("%d %s %0.2f\n", Producto[i].codigo, Producto[i].descripcion, Producto[i].precio);

    }
    system("pause");

    return 0;
}

int consulta(tproducto Producto[], int fin)
{
    int cod,i;
    int existe=0;

    printf("Ingrese el codigo de producto a consultar:");
    scanf("%d", &cod);


    for(i=0 ; i<fin ; i++)
    {
        if (cod==Producto[i].codigo)
        {
           printf("%d %s %0.2f\n", Producto[i].codigo, Producto[i].descripcion, Producto[i].precio);
           existe=1;  //bandera para saberr que encontre el codigo
           i= fin+1;
        }

    }
    if (existe==0)
        printf("No existe un producto con dicho codigo\n");

    return 0;
}

int cargaarchivo(tproducto Producto[])
{
    FILE *arch;
    arch=fopen("productos.dat","rb");
    if (arch==NULL)
        return -1;
    tproducto producto;
    int i=0;

    fread(&producto, sizeof(tproducto), 1, arch);
    while(!feof(arch))
    {
        Producto[i] = producto;
        i++;
        if (i >= n)  i=0;
        fread(&producto, sizeof(tproducto), 1, arch);
    }
    printf("%d", i);
    system("pause");
    fclose(arch);
   return i;
}

void modificacion(tproducto Producto[], int fin)
{
    int cod, i, existe = 0;

    printf("Ingrese el codigo de producto a modificar:");
    scanf("%d", &cod);
    for(i=0; i<fin; i++)
    {
        if (cod==Producto[i].codigo)
        {
           printf("%d %s %0.2f\n", Producto[i].codigo, Producto[i].descripcion, Producto[i].precio);
           printf("Ingrese nuevo precio:");
           scanf("%f",&Producto[i].precio);

           printf("Se modifico el precio para dicho producto.\n");
           i= fin +1;  //para salir del for
           existe=1;    //bandera para indicar que existe el producto
        }
    }
    if (existe==0)
        printf("No existe un producto con dicho codigo\n");

}


int ordenarcodigo(tproducto Producto[], int fin)
{
    tproducto producto;
    int i,j;
    printf("\n\n\nORDENANDO");
    getche();
    for(i=0; i<fin-1; i++)
        for(j=0; j<fin-1-i; j++)
    {
        if( Producto[j].codigo > Producto[j+1].codigo)
        {
            producto = Producto[j];
            Producto[j] =Producto [j+1];
            Producto [j+1] = producto;
        }
    }
}

int busquedabinaria(tproducto Producto[], int fin, int codigobuscado)
{
    int i;
    int alto=fin-1, bajo=0, central;

    if (Producto[alto].codigo == codigobuscado)
       return alto;
    if (Producto[bajo].codigo == codigobuscado)
       return bajo;

    while(alto >= bajo)
    {
        central = (alto + bajo) / 2;
        if (Producto[central].codigo == codigobuscado)
            return central;
        if (Producto[central].codigo > codigobuscado)
        {
            alto = central -1;
        }
        else
        {
            bajo = central + 1;
        }
    }
}

int consultabinaria (tproducto Producto[], int fin)
{
    int cod,i;
    printf("Ingrese el codigo de producto a modificar:");
    scanf("%d", &cod);
    i = busquedabinaria (Producto, fin,cod);
    printf("%d %s %0.2f\n", Producto[i].codigo, Producto[i].descripcion, Producto[i].precio);
    system("pause");
    return 0;


}
int bajaarchivo(tproducto Producto[],int fin)
{
    int cod,i, j;
    char sino;
    printf("Ingrese el codigo de producto a modificar:");
    scanf("%d", &cod);
    i = busquedabinaria (Producto, fin,cod);
    printf("%d %s %0.2f\n", Producto[i].codigo, Producto[i].descripcion, Producto[i].precio);
    printf("\n\n\n Quiere dar de baja ese codigo ???? ");
    fflush (stdin);
    scanf("%c", &sino);
    if (sino == 's')
    {
            for(j=i ; j<fin-1 ; j++)
            {
                    // correr el vector estructura un lugar pisando el dato a borrar
                    Producto[j] = Producto[j+1];

            }
            fin--;


    }
    return fin;
}
