#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

void mostrarMascota(eMascota unaMascota)
{
    char tipos[][7]={"Perro", "Gato", "Reptil", "Pez", "Ave"};
    char comio[10];
    if(unaMascota.comio)
    {
        strcpy(comio, "Comio");
    }
    else
    {
        strcpy(comio, "No comio");
    }

    printf("\nID: %d\n", unaMascota.id);
    printf("Nombre: %s\n", unaMascota.nombre);
    printf("Tipo: %s\n", tipos[unaMascota.tipo]);
    printf("Peso: %5.2f\n", unaMascota.peso);
    printf("%s\n", comio);
}

void mostrarMascotas(eMascota mascotas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(mascotas[i].estado==1)
        {
            mostrarMascota(mascotas[i]);
        }
    }
    printf("\n\n");
}

int menu()
{
    int opcion;
    system("cls");
    printf("\n                           :: MENU DE OPCIONES ::\n\n");
    printf("1. Alta mascota\n");
    printf("2. Modificar mascota\n");
    printf("3. Baja mascota\n");
    printf("4. Listar mascota\n");
    printf("5. Alimentar mascota\n");
    printf("6. Ordenar mascotas\n");
    printf("7. Mascota de menor peso\n");
    printf("8. Salir\n");
    printf("\n* Indique opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

void inicializarMascotas(eMascota mascotas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
       mascotas[i].estado = 0;
    }
}

int buscarLibre (eMascota mascotas[], int tam)
{
    int indice=-1;
    int i;
    for (i=0;i<tam;i++)
    {
        if(mascotas[i].estado ==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarMascota(eMascota mascotas[], int tam, int id)
{
    int indice=-1;
    int i;

    for (i=0;i<tam;i++)
    {
        if(mascotas[i].id == id)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void altaMascota (eMascota mascotas[], int tam, eTipoMascota tipos[])
{
    int esta;
    int indice;
    int id;
    indice=buscarLibre(mascotas, tam);

    if (indice==-1)
    {
        printf("\nNo hay lugar.\n\n");
    }
    else
        {
            printf("Ingrese ID de mascota: ");
            fflush(stdin);
            scanf("%d", &id);

            esta=buscarMascota(mascotas, tam, id);
            if (esta!=-1)
            {
                printf("La mascota de ID %d ya se encuentra en sistema.\n", id);
            }
            else
            {
                mascotas[indice].id=id;
                printf("Ingrese el nombre de la mascota: ");
                fflush(stdin);
                gets(mascotas[indice].nombre);
                mascotas[indice].tipo=menuTipo(tipos, tam);
                printf("\nIngrese peso: ");
                fflush(stdin);
                scanf("%f", &mascotas[indice].peso);
                mascotas[indice].comio=0;
                mascotas[indice].estado=1;
                printf("\nMascota cargada con exito!!\n");
            }
        }
}

int menuTipo(eTipoMascota tipos[], int tam)
{
    int tipo;
    mostrarTipos(tipos, tam);
    scanf("%d", &tipo);
    return tipo;
}

void mostrarTipos(eTipoMascota tipos[], int tam)
{
    printf("\n         :: TIPOS ::\n");
    printf("0. Perro\n");
    printf("1. Gato\n");
    printf("2. Reptil\n");
    printf("3. Pez\n");
    printf("4. Ave\n");
}

void bajaMascota(eMascota mascotas[], int tam)
{
    int confirma;
    int indice;
    int id;

    printf("Ingrese ID de la mascota a borrar: ");
    fflush(stdin);
    scanf("%d", &id);

    indice=buscarMascota(mascotas, tam, id);
    if (indice==-1)
    {
        printf("La mascota de ID %d no esta cargada en sistema.\n", id);
        system("pause");
    }
    else
        {
            printf("\n :: DATOS DE LA MASCOTA :: \n");
            mostrarMascota(mascotas[indice]);

            printf("\nUsted va a borrar a la mascota de ID %d, esta seguro del cambio?\n", mascotas[indice].id);
            confirma=tolower(getch());
            if (confirma=='s')
            {
                mascotas[indice].estado=2;
            }
            else
            {
                printf("\nSe ha cancelado la baja.\n");
            }
        }
    system("pause");
}

void modificarMascota(eMascota mascotas[], int tam, eTipoMascota tipos[])
{
    int confirma;
    int indice;
    int id;
    int opcion;
    char auxCad[25];
    float aux;

    printf("Ingrese ID de la mascota a modificar: ");
    fflush(stdin);
    scanf("%d", &id);

    indice=buscarMascota(mascotas, tam, id);
    if (indice==-1)
    {
        printf("La mascota de ID %d no esta cargada en sistema.\n", id);
        system("pause");
    }
    else
        {
            printf("\n                                      :: DATOS DE LA MASCOTA ::\n");
            mostrarMascota(mascotas[indice]);
            printf("\n1. Editar nombre\n");
            printf("2. Editar tipo\n");
            printf("3. Editar peso\n");
            printf("* Elija una opcion: ");
            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese el nuevo nombre: ");
                fflush(stdin);
                gets(auxCad);
                printf("\nUsted va a modificar el nombre de la mascota, esta seguro de este cambio? s/n\n");
                confirma=tolower(getch());
                        if (confirma=='s')
                        {
                            strcpy(mascotas[indice].nombre, auxCad);
                            printf("Modificacion de nombre exitosa.\n");
                            system("pause");
                        }
                        else
                        {
                            printf("\nSe ha cancelado la modificacion del nombre.\n");
                            system("pause");
                        }
                break;
            case 2:
                mascotas[indice].tipo=menuTipo(tipos, tam);
                break;
            case 3:
                printf("Ingrese el nuevo peso de la mascota: ");
                scanf("%f", &aux);
                printf("\nUsted va a modificar el peso de la mascota, esta seguro de este cambio? s/n\n");
                confirma=tolower(getch());
                        if (confirma=='s')
                        {
                            aux=mascotas[indice].peso;
                            printf("Modificacion de peso exitosa.\n");
                            system("pause");
                        }
                        else
                        {
                            printf("Se ha cancelado la modificacion del peso.\n");
                            system("pause");
                        }
                break;
            }
        }
}

void alimentarMascota (eMascota mascotas[], eTipoMascota tipos[], int tam)
{
    int i;
    int id;

    id=menuTipo(tipos, tam);
    for(i=0;i<tam;i++)
    {
        if(mascotas[i].tipo==id)
        {
            mascotas[i].comio=1;
            printf("Las mascotas de este tipo fueron alimentadas con exito.\n");
            system("pause");
            break;
        }
        else
        {
            printf("No hay mascotas de este tipo.\n");
            system("pause");
            break;
        }
    }
}

void inicializarTipos(eTipoMascota tipo[], int tam)
{
        tipo[0].idTipo = 0;
        strcpy(tipo[0].descripcion, "Perro");

        tipo[1].idTipo = 1;
        strcpy(tipo[1].descripcion, "Gato");

        tipo[2].idTipo = 2;
        strcpy(tipo[2].descripcion, "Reptil");

        tipo[3].idTipo = 3;
        strcpy(tipo[3].descripcion, "Pez");

        tipo[4].idTipo = 4;
        strcpy(tipo[4].descripcion, "Roedor");
}

void ordenarMascotas (eTipoMascota tipos[], eMascota mascotas[], int tam)
{
    int i;
    int j;
    eTipoMascota auxTipo;
    eMascota auxMascota;
    for (i=0;i<tam-1;i++)
    {
        for (j=i+1;j<tam;j++)
        {
            if (mascotas[i].estado == 1 || strcmp(mascotas[i].nombre, mascotas[j].nombre)>0)//alfabetico
            {
                auxMascota=mascotas[i];
                mascotas[i]=mascotas[j];
                mascotas[j]=auxMascota;
            }

            if (mascotas[i].estado == 1 || tipos[i].idTipo < tipos[j].idTipo) //tipo
            {
                auxTipo=tipos[i];
                tipos[i]=tipos[j];
                tipos[j]=auxTipo;
            }
        }
    }
}

void menorPeso (eMascota mascotas[], int tam, int tipo)
{
    int i;
    int flag=0;
    float menor=0;

    for (i=0;i<tam;i++)
    {
        if (mascotas[i].estado==1 && mascotas[i].tipo==tipo)
        {
            if (mascotas[i].peso < menor || flag==0)
            {
                menor=mascotas[i].peso;
                flag=1;
            }
        }
    }
}
