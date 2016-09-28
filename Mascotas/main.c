#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

#define perro 0
#define gato 1
#define reptil 2
#define pez 3
#define ave 4

int main()
{
    eTipoMascota tipos[5];
    eMascota bichos[5];
    char seguir='s';
    int confirma;

    inicializarMascotas(bichos, 5);
    inicializarTipos(tipos, 5);

    do
    {
    switch(menu())
        {
         case 1:
            altaMascota(bichos, 5, tipos);
            system("pause");
            break;
         case 2:
            modificarMascota(bichos, 5, tipos);
            break;
         case 3:
            bajaMascota(bichos, 5);
            break;
         case 4:
            system("cls");
            mostrarMascotas(bichos, 5);
            system("pause");
            break;
         case 5:
            alimentarMascota(bichos, tipos, 5);
            break;
         case 6:
            ordenarMascotas(tipos, bichos, 5);
            mostrarMascotas(bichos, 5);
            system("pause");
            break;
         case 7:
            menorPeso(bichos, 5, 5);
            mostrarMascotas(bichos, 5);
            system("pause");
            break;
         case 8:
             printf("Usted eligio salir. Esta seguro que desea salir?\n");
             confirma=tolower(getche());
             if (confirma=='s')
             {
                 seguir='n';
                 break;
             }
            break;
    }system("cls");
}while(seguir =='s');
return 0;
}
