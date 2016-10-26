typedef struct
{
    int id;
    int dni;
    char nombre[20];
    char apellido[20];
    int estado;
}eCliente;

typedef struct
{
    int idTipo;
    char descripcion[10];
}eTipoEquipo;

typedef struct
{
    int id;
    int cliente;
    int estado;
    int equipo;
    int tiempoEsti;
    int tiempoReal;
}eAlquiler;

/** \brief Inicializa los clientes con estado en 0
 *
 * \param Array de clientes
 * \param Tama�o del array
 *
 */
void inicializarClientes (eCliente[], int);

/** \brief Busca el primer espacio libre en el array de clientes
 *
 * \param Array de clientes
 * \param Tama�o del array
 * \return El indice del primer espacio libre
 *
 */
int buscarLibre (eCliente[], int);

/** \brief Da de alta un cliente
 *
 * \param Array de clientes
 * \param Id del cliente
 * \param Tama�o del array
 * \return El cliente
 *
 */
int altaCliente (eCliente[], int, int);

/** \brief Modifica algunos datos seleccionados del cliente
 *
 * \param Array de clientes
 * \param Id del cliente
 * \param Tama�o del array
 *
 */
void modificarCliente (eCliente[], int, int);

/** \brief Muestra los clientes habilitados en sistema
 *
 * \param Array de clientes
 * \param Tama�o del array
 *
 */
void mostrarClientes (eCliente[], int);

/** \brief Realiza la baja l�gica de un cliente en sistema. (estado=2)
 *
 * \param Array de clientes
 * \param ID del cliente
 * \param Tama�o del array
 *
 */
void bajaCliente (eCliente[], int, int);

/** \brief Muestra los tipos de equipos
 *
 * \param Array de tipos
 * \param Tama�o del array
 *
 */
void mostrarTipos(eTipoEquipo[], int);

/** \brief Habilita en sistema un nuevo alquiler
 *
 * \param Array de alquileres
 * \param Array de clientes
 * \param Array de tipos de equipos
 * \param Tama�o del array
 * \param ID del alquiler
 * \return El indice del alquiler
 *
 */
int nuevoAlquiler (eAlquiler[], eCliente[], eTipoEquipo[], int, int);

/** \brief Realiza el fin de un alquiler
 *
 * \param Array de alquileres
 * \param Tama�o del array
 *
 */
void finAlquiler (eAlquiler[], int);

/** \brief Busca un alquiler por su ID
 *
 * \param Array de alquileres
 * \param Tama�o del array
 * \param ID del alquiler
 * \return El indice del alquiler
 *
 */
int buscarAlquiler (eAlquiler[], int, int);

/** \brief Informa segun varios criterios
 *
 * \param Array de clientes
 * \param Tama�o del array
 *
 */
void informar (eCliente[], int);
