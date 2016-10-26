#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"

#define Amoladora 0
#define Mezcladora 1
#define Taladro 2

   int main()
{
    eTipoEquipo equipos[3];
    eCliente clientes[100];
    eAlquiler alquiler[100];
    int idCliente=10;
    int idAlquiler=20;
    int altaC;
    int altaA;

    inicializarClientes(clientes, 100);

    char seguir='s';
    int opcion;
    int confirma;

    do
    {
        printf("\n                             ::MENU DE OPCIONES::\n\n");
        printf("1. Alta de cliente\n");
        printf("2. Modificar datos del cliente\n");
        printf("3. Baja del cliente\n");
        printf("4. Nuevo alquiler\n");
        printf("5. Fin del alquiler\n");
        printf("6. Informar\n");
        printf("7. Salir\n\n");

        printf("* Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            altaC=altaCliente(clientes, idCliente, 100);
            if (altaC!=-1)
            {
                idCliente++;
            }
            break;
        case 2:
            modificarCliente(clientes, idCliente, 100);
            break;
        case 3:
            bajaCliente(clientes, idCliente, 100);
            break;
        case 4:
            altaA=nuevoAlquiler(alquiler, clientes, equipos, 100, idAlquiler);
            if (altaA!=-1)
            {
                idAlquiler++;
            }
            break;
        case 5:
            finAlquiler(alquiler, 100);
            break;
        case 6:
            informar(clientes, 100);
            break;
        case 7:
            printf("Usted eligio salir. Confirma salir? s/n\n");
            confirma=tolower(getch());
            if (confirma=='s')
            {
                seguir='n';
            }
            else
            {
                break;
            }
            break;
        }system("cls");
    }while(seguir=='s');
return 0;
}
