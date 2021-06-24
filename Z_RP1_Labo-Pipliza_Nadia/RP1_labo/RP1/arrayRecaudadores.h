//#include "arrayContribuyentes.h"
#ifndef ARRAYRECAUDADORES_H_
#define ARRAYRECAUDADORES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayContribuyentes.h"
//#include "arrayRecaudadores.h"
//#include "informes.h"
#include "utn.h"

#define VACIO 0
#define OCUPADO 1
#define BAJA -1
//#define TAMC 50 //contribuyentes

//eContribuyentes listaContribuyentes;
/********** ESTRUCTURAS ********************************************************************************/
//isEmpty 0 vacio - 1 ocupado
typedef struct
{
	int   idRecaudacion;
    int   idContribuyente;
    char  mes[25];
    char  tipo[25];
    float importe;
    char  estado[25];
    int   isEmpty;
}eRecaudadores;

//void mostrarUnContribuyenteConRecaudaciones(eRecaudadores listaRecaudadores, eContribuyentes listaContribuyentes);

/********** FUNCIONES ABM ******************************************************************************/

void HardcodearRecaudacion(eRecaudadores listaRecaudadores[], int TAMR);
//int modificacionEstadoRecaudacion(eRecaudadores listaRecaudadores[], int TAMR, eContribuyentes listaContribuyentes[], int TAMC);
/***********************************************************************/

void InicializarRecaudacion(eRecaudadores listaRecaudadores[], int TAMR);

/***********************************************************************/

int  obtenerIDdeRecaudadores(void);

/***********************************************************************/

int  obtenerUltimoIDdeRecaudadores(void);

/***********************************************************************/

int obtenerIndexRecaudacionLibre(eRecaudadores listaRecaudadores[], int TAMR);

/***********************************************************************/

int buscarRecaudacionPorID(eRecaudadores listaRecaudadores[], int TAMR, int ID);

/***********************************************************************/

eRecaudadores cargarDatosRecaudacion(void);

/***********************************************************************/

eRecaudadores modificarUnaRecaudacion(eRecaudadores recaudacion);

/***********************************************************************/

int altaRecaudacion(eRecaudadores listaRecaudadores[], int TAMR);

/***********************************************************************/

int bajaRecaudacion(eRecaudadores listaRecaudadores[], int TAMR);

/***********************************************************************/

int modificacionRecaudacion(eRecaudadores listaRecaudadores[], int TAMR);

int buscarContribuyenteBajaRecaudaciones(eRecaudadores listaRecaudadores[], int TAMR, int ID);


/********** FUNCIONES MOSTRAR Y ORDENAR ****************************************************************/

void mostrarUnaRecaudacion(eRecaudadores listaRecaudadores);

/***********************************************************************/

int mostrarTodasLasRecaudaciones(eRecaudadores listaRecaudadores[], int TAMR);

int modificarEstadoRefinanciar(eRecaudadores listaRecaudadores[], int TAMR);
#endif /* ARRAYRECAUDADORES_H_ */
