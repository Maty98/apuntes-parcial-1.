#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"

void inicializarClientes (eCliente clientes[], int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        clientes[i].estado=0;
    }
}

void inicializarTipos(eTipoEquipo tipo[], int tam)
{
        tipo[0].idTipo = 0;
        strcpy(tipo[0].descripcion, "Amoladora");

        tipo[1].idTipo = 1;
        strcpy(tipo[1].descripcion, "Mezcladora");

        tipo[2].idTipo = 2;
        strcpy(tipo[2].descripcion, "Taladro");
}

int buscarLibre (eCliente clientes[], int tam)
{
    int indice=-1;
    int i;
    for (i=0;i<tam;i++)
    {
        if(clientes[i].estado == 0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarCliente (eCliente clientes[], int tam, int id)
{
    int indice=-1;
    int i;
    for (i=0;i<tam;i++)
    {
        if (clientes[i].id == id)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int altaCliente (eCliente clientes[], int id, int tam)
{
    int indice;
    char auxCad[40];
    indice=buscarLibre(clientes, tam);

    if (indice==-1)
    {
        printf("No hay mas espacio de carga de clientes. Verifique.\n");
    }
    else
    {
        clientes[indice].id=id;
        printf("\nID: %d\n", clientes[indice].id);

        printf("Ingrese el DNI: ");
        fflush(stdin);
        scanf("%d", &clientes[indice].dni);
        while (clientes[indice].dni < 0)
        {
            printf("El DNI debe ser positivo. Reingrese: ");
            fflush(stdin);
            scanf("%d", &clientes[indice].dni);
        }

        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(auxCad);
        while (strlen(auxCad)>20)
        {
            printf("Nombre demasiado largo. Reingrese: ");
            fflush(stdin);
            gets(auxCad);
        }
        strcpy(clientes[indice].nombre, auxCad);

        printf("Ingrese el apellido: ");
        fflush(stdin);
        gets(auxCad);
        while (strlen(auxCad)>20)
        {
            printf("Apellido demasiado largo. Reingrese: ");
            fflush(stdin);
            gets(auxCad);
        }
        strcpy(clientes[indice].apellido, auxCad);

        clientes[indice].estado=1;
        printf("Cliente cargado exitosamente.\n");
    }
    system("pause");
    return indice;
}

void mostrarClientes (eCliente clientes[], int tam)
{
    int i;

    printf("\n                  ::Clientes habilitados::\n\n");
    for (i=0;i<tam;i++)
    {
        if (clientes[i].estado == 1)
        {
            printf("\nID: %d\n", clientes[i].id);
            printf("DNI: %d\n", clientes[i].dni);
            printf("Nombre: %s\n", clientes[i].nombre);
            printf("Apellido: %s\n", clientes[i].apellido);
        }
    }
}

void modificarCliente (eCliente clientes[], int id, int tam)
{
    int indice;
    int opcion;
    char auxCad[40];

    mostrarClientes(clientes, tam);

    printf("\nIngrese el ID del cliente a modificar: ");
    fflush(stdin);
    scanf("%d", &id);

    indice=buscarCliente(clientes, tam, id);
    if (indice==-1)
    {
        printf("El cliente no esta en el sistema. Verifique el ID.\n");
        system("pause");
    }
    else
    {
        printf("\n                            ::MENU DE MODIFICACION::\n\n");

        printf("1. Nombre\n");
        printf("2. Apellido\n\n");

        printf("Escoja una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
            gets(auxCad);
            while (strlen(auxCad)>20)
            {
            printf("Nombre demasiado largo. Reingrese: ");
            fflush(stdin);
            gets(auxCad);
            }
            strcpy(clientes[indice].nombre, auxCad);
            printf("Nombre modificado con exito.\n");
            system("pause");
            break;
        case 2:
            printf("Ingrese el nuevo apellido: ");
            fflush(stdin);
            gets(auxCad);
            while (strlen(auxCad)>20)
            {
            printf("Apellido demasiado largo. Reingrese: ");
            fflush(stdin);
            gets(auxCad);
            }
            strcpy(clientes[indice].apellido, auxCad);
            printf("Apellido modificado con exito.\n");
            system("pause");
            break;
        }
    }
}

void bajaCliente (eCliente clientes[], int id, int tam)
{
    int indice;
    int confirma;

    mostrarClientes(clientes, tam);

    printf("\nIngrese ID del cliente que desea dar de baja: ");
    scanf("%d", &id);

    indice=buscarCliente(clientes, tam, id);

    if (indice == -1)
    {
        printf("Este cliente no puede ser dado de baja porque no existe en el sistema.\n");
        system("pause");
    }
    else
    {
        printf("Usted va a dar de baja a este cliente. Esta seguro de la baja? s/n\n");
        confirma=tolower(getch());

        if (confirma == 's')
        {
            clientes[indice].estado=2;
            printf("Cliente dado de baja exitosamente.\n");
            system("pause");
        }
        else
        {
            printf("La baja ha sido cancelada.\n");
            system("pause");
        }
    }
}

int buscarLibreAlquiler (eAlquiler alquileres[], int tam)
{
    int indice=-1;
    int i;
    for (i=0;i<tam;i++)
    {
        if(alquileres[i].estado == 0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int menuTipo(eTipoEquipo tipos[], int tam)
{
    int tipo;
    mostrarTipos(tipos, tam);
    printf("Elija un tipo: ");
    fflush(stdin);
    scanf("%d", &tipo);

    return tipo;
}

void mostrarTipos(eTipoEquipo tipos[], int tam)
{
    printf("\n         :: TIPOS DE EQUIPO ::\n\n");

    printf("0. Amoladora\n");
    printf("1. Mezcladora\n");
    printf("2. Taladro\n\n");
}

int nuevoAlquiler (eAlquiler alquileres[], eCliente clientes[], eTipoEquipo equipos[], int tam, int id)
{
    int indice;
    int aux;
    indice=buscarLibreAlquiler(alquileres, tam);
    if (indice==-1)
    {
        printf("\nNo hay mas espacio para cargar alquileres.\n");
    }
    else
    {
        alquileres[indice].id=id;
        printf("\nID de alquiler: %d\n", alquileres[indice].id);
        mostrarClientes(clientes, tam);
        printf("\nID del cliente: ");
        fflush(stdin);
        scanf("%d", &alquileres[indice].cliente);
        alquileres[indice].equipo=menuTipo(equipos, tam);
        alquileres[indice].estado=1;
        printf("\nElija un tiempo estimado: ");
        fflush(stdin);
        scanf("%d", &aux);
        while (aux < 0)
        {
            printf("El tiempo no puede ser negativo. Reingrese: ");
            fflush(stdin);
            scanf("%d", &aux);
        }
        alquileres[indice].tiempoEsti=aux;
        printf("\n\nAlquiler ingresado en sistema exitosamente. Volvera al menu principal.\n");
        system("pause");
    }
    return indice;
}

void mostrarAlquileres (eAlquiler alquileres[], int tam)
{
    char tipos[][15]={"Amoladora", "Mezcladora", "Taladro"};
    int i;

    printf("\n                             ::ALQUILERES EN CURSO::\n");

    for (i=0;i<tam;i++)
    {
        if (alquileres[i].estado==1)
        {
            if (alquileres[i].id >= 20 && alquileres[i].id <= 100)
            {
            printf("\n\nID del alquiler: %d\n", alquileres[i].id);
            printf("ID del cliente: %d\n", alquileres[i].cliente);
            printf("Tipo: %s\n", tipos[alquileres[i].equipo]);
            printf("Tiempo estimado: %d\n", alquileres[i].tiempoEsti);
            }
        }
    }
}

int buscarAlquiler (eAlquiler alquileres[], int tam, int id)
{
    int indice=-1;
    int i;
    for (i=0;i<tam;i++)
    {
        if (alquileres[i].id == id)
    {
        indice=i;
    }
    }
    return indice;
}

void finAlquiler (eAlquiler alquileres[], int tam)
{
    int indice;
    int id;
    int confirma;

    mostrarAlquileres(alquileres, tam);

    printf("\nIngrese el ID del alquiler a finalizar: ");
    fflush(stdin);
    scanf("%d", &id);

    indice=buscarAlquiler(alquileres, tam, id);
    if (indice==-1)
    {
        printf("El alquiler no fue encontrado. Verifique el ID.\n");
        system("pause");
    }
    else
    {
        printf("Esta seguro que desea dar de baja este alquiler? s/n\n");
        confirma=tolower(getch());
        if (confirma == 's')
        {
            alquileres[indice].estado=2;
            printf("Ingrese el tiempo real de este alquiler: ");
            fflush(stdin);
            scanf("%d", &alquileres[indice].tiempoReal);
            printf("Alquiler finalizado.\n");
            system("pause");
        }
        else
        {
            printf("Baja del alquiler cancelada.\n");
            system("pause");
        }
    }
}
int buscarAlquiler(eAlquiler,int,int);
int mayorAlquiler(eAlquiler alquileres,eAlquiler tipos, int tipo)
{
    int mayorAlq;
    int cont0;
    int cont1;
    int cont2;
    int indi;
    int tam;
    int id;
    int i;
    indi=buscarAlquiler(alquileres, tam, id);
    for (i=0;i<tam;i++)
    {
        if (alquileres[i].id==id)
        {
        indice=i;
          if(tipo==0)
    {
        cont0=cont0+1;
    }
    if(tipo==1)
    {
        cont1=cont1+1;
    }
    if(tipo==2)
    {
        cont2=cont2+1;
    }
    int mayorAlq;
    if(cont0>cont1 && cont0>cont2)
    {
        mayorAlq=cont0;
    }
     if(cont1>cont0 && cont1>cont2)
    {
        mayorAlq=cont1;
    }
     if(cont2>cont0 && cont2>cont1)
    {
        mayorAlq=cont2;
    }
        if(mayorAlq==cont0)
    {
        printf("el equipo mas alquilado fue la amoladora, y se alquilo %d veces\n",cont0);
    }
    if(mayorAlq==cont1)
    {
        printf("el equipo mas alquilado fue la mezcladora, y se alquilo %d veces\n",cont1);
    }
    if(mayorAlq==cont2)
    {
        printf("el equipo mas alquilado fue el taladro, y se alquilo %d veces\n",cont2);
    }

        }
    }

}
void informar (eCliente clientes[],int tam)
{
    int opcion;
    printf("\n                             ::INFORMAR::\n\n");
    printf("1. Asociado con mas alquileres\n");
    printf("2. Los equipos mas alquilados\n");
    printf("3. Tiempo promedio real de alquiler\n");

    printf("\n* Elija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
            break;
        case 2:
            mayorAlquiler;
            break;
        case 3:
            break;
    }
}



