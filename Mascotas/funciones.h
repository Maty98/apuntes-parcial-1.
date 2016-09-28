typedef struct
{
    int id;
    char nombre[25];
    int tipo;
    float peso;
    int comio;
    int estado;
}eMascota;

typedef struct
{
    int idTipo;
    char descripcion[10];
}eTipoMascota;

int menu();
void mostrarMascota(eMascota);
void mostrarMascotas(eMascota[], int);
void inicializarMascotas(eMascota[], int);
int buscarMascota(eMascota[], int, int);
void altaMascota (eMascota[], int, eTipoMascota[]);
void bajaMascota(eMascota[], int);
void modificarMascota(eMascota[], int, eTipoMascota[]);
void alimentarMascota (eMascota[], eTipoMascota[], int);
int buscarLibre(eMascota[], int);
int menuTipo(eTipoMascota[], int);
void inicializarTipos(eTipoMascota [], int);
void mostrarTipos(eTipoMascota[], int);
void ordenarMascotas(eTipoMascota[], eMascota[], int);
void menorPeso(eMascota[], int, int);
