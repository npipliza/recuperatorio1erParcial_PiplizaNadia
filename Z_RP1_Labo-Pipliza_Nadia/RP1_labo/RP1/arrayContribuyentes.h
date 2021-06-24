#ifndef ARRAYCONTRIBUYENTES_H_
#define ARRAYCONTRIBUYENTES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayRecaudadores.h"
#include "informes.h"
#include "utn.h"
//#define T 10
#define VACIO 0
#define OCUPADO 1
#define BAJA -1
/********** ESTRUCTURAS ********************************************************************************/
//isEmpty 0 vacio - 1 ocupado
typedef struct
{
    int   idContribuyente;
    char  nombreC[25];
    char  apellidoC[25];
    char  cuilC[14];
    int   isEmpty;
}eContribuyentes;

/********** FUNCIONES ABM ******************************************************************************/

void HardcodearContribuyentes(eContribuyentes listaContribuyentes[], int TAMC);

/***************************************************************************************/

void InicializarContribuyentes(eContribuyentes listaContribuyentes[], int TAMC);

/***************************************************************************************/

int obtenerIDdeBicicleta();

/***************************************************************************************/

int obtenerUltimoIDdeBicicleta();

/***************************************************************************************/

int obtenerIndexContribuyenteLibre(eContribuyentes listaContribuyentes[], int TAMC);

/***************************************************************************************/

int buscarContribuyentesPorID(eContribuyentes listaContribuyentes[], int TAMC, int ID);

/***************************************************************************************/

eContribuyentes cargarDatosContribuyente(void);

/***************************************************************************************/

eContribuyentes modificarUnContribuyente(eContribuyentes contribuyente);

/***************************************************************************************/

int altaContribuyente(eContribuyentes listaContribuyentes[], int TAMC);

/***************************************************************************************/

//int bajaContribuyente(eContribuyentes listaContribuyentes[], int TAMC);

/***************************************************************************************/

int modificacionContribuyente(eContribuyentes listaContribuyentes[], int TAMC);

//void mostrarUnContribuyenteConRecaudaciones(eContribuyentes listaContribuyentes, eRecaudadores listaRecaudadores, int TAMR);
/********** FUNCIONES MOSTRAR Y ORDENAR ****************************************************************/

void mostrarUnContribuyente(eContribuyentes contribuyente);

/***************************************************************************************/

int mostrarTodosLosContribuyentes(eContribuyentes listaContribuyentes[], int TAMC);

//void informeTotalPreciosServicios(eTrabajo listaContribuyentes[], int TAM, eServicio listaRecaudadores[], int TAMs);
/********** SORT ***************************************************************************************/
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
//int ordenaEmpleadosPorApellido(eTrabajo listaContribuyentes[], int TAM, int criterio);

#endif /* ARRAYCONTRIBUYENTES_H_ */
