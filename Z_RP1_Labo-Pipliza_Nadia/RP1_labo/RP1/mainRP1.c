/* ============================================================================================================
    Parcial1 Labo.: Recuperatorio p1
    Division      : 1ro B
    Alumna        : Pipliza Nadia
   ============================================================================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayContribuyentes.h"
#include "arrayRecaudadores.h"
#include "informes.h"
#include "utn.h"

#define TAMC 50 //contribuyentes
#define TAMR 50 //recaudadores
int main()
{
    eContribuyentes listaContribuyentes[TAMC];
    eRecaudadores   listaRecaudadores[TAMR];

	int mostrarOpciones;
	int idC;
	int opcionesRecaudar;
	int indexUltimoC;
	int indexUltimoR;
	//int criterioDeOrdenamiento;

    setbuf(stdout, NULL);

    InicializarContribuyentes(listaContribuyentes,TAMC);
    InicializarRecaudacion(listaRecaudadores,TAMR);
    HardcodearContribuyentes(listaContribuyentes,TAMC);
    HardcodearRecaudacion(listaRecaudadores,TAMR);

    printf("INICIO... \n");
	do//creo bucle del menu
	{
		mostrarOpciones = PedirEntero("\nINGRESE UNA OPCIÓN: ***********************************************\n"
									  "1.  ALTA Contribuyente.\n"
									  "2.  BAJA Contribuyente.\n"
									  "3.  MODIFICAR Contribuyente.\n"
									  "4.  MENÚ RECAUDACIÓN.\n"
								      "5.  INFORME Contribuyentes.\n"
								      "6.  INFORME Recaudaciones.\n"
									  "7.  INFORME Contribuyente con más estados REFINANCIAR.\n"
									  "8.  INFORME Recaudaciones mayores a $1000.\n"
									  "9.  INFORME Contribuyente por TIPO de impuesto.\n"
								      "10. INFORME Contribuyente con impuestos SALDADOS en Febrero.\n"
									  "0. SALIR\n"
									  "Elija una opción: ","\nError. Ingrese número de opción: ");

		switch(mostrarOpciones)
		{
			//ALTA CONTRIBUYENTE
			case 1:
				indexUltimoC = altaContribuyente(listaContribuyentes, TAMC);
				if(indexUltimoC != -1)
				{
					printf("\n * CONTRIBUYENTE DADO DE ALTA EXITOSAMENTE\n");
					printf("\n ID \tNOMBRE  \tAPELLIDO \tCUIL\n");
					mostrarUnContribuyente(listaContribuyentes[indexUltimoC]);
				}
				else
				{
					printf("\n * ERROR. SIN ESPACIO PARA ALMACENAR MAS CONTRIBUYENTES\n");
				}
				system("pause");
			break;

			//BAJA CONTRIBUYENTE
			case 2:
				idC = bajaContribuyente(listaContribuyentes, TAMC, listaRecaudadores, TAMR);
				if(idC != 0)
				{
					buscarContribuyenteBajaRecaudaciones(listaRecaudadores, TAMC, idC);
					printf("\n * BAJA DE CONTRIBUYENTE EXITOSA\n");
					//mostrarTodosLosContribuyentes(listaContribuyentes, TAMC);
				}
				else
				{
					printf("\n * BAJA DE CONTRIBUYENTE CANCELADA\n");
				}
				system("pause");
			break;

			//MODIFICACION CONTRIBUYENTE
			case 3:
				if(modificacionContribuyente(listaContribuyentes, TAMC) == 1)
				{
					printf("\n * MODIFICACION DE CONTRIBUYENTE EXITOSA\n");
					mostrarTodosLosContribuyentes(listaContribuyentes, TAMC);
				}
				else
				{
					printf("\n * MODIFICACION DE CONTRIBUYENTE CANCELADA\n");
				}
				system("pause");
			break;

			//MENU ABM RECAUDACIONES
			case 4:
				printf("\nINICIO ABM RECAUDACIÓN... \n");
				do//creo bucle del menu
				{
					opcionesRecaudar = PedirEntero("\nINGRESE UNA OPCIÓN: ***********************************************\n"
												   "1. ALTA Recaudación.\n"
												   "2. BAJA Recaudación.\n"
												   "3. MODIFICAR Recaudación.\n"
							                       "4. ESTADO Recaudación.\n"
												   "0. SALIR\n"
												   "Elija una opción: ","\nError. Ingrese número de opción: ");
					switch(opcionesRecaudar)
					{	//ALTA RECAUDACIÓN
						case 1:
							indexUltimoR = altaRecaudacion(listaRecaudadores, TAMR);
							if(indexUltimoR != -1)
							{
								printf("\n * RECAUDACIÓN DADA DE ALTA EXITOSAMENTE\n");
								printf("\nID R \tID C \tMES  \tTIPO   \tIMPORTE\n");
								mostrarUnaRecaudacion(listaRecaudadores[indexUltimoR]);
							}
							else
							{
								printf("\n * ERROR. SIN ESPACIO PARA ALMACENAR MAS RECAUDACIONES\n");
							}
							system("pause");
						break;

						//BAJA RECAUDACIÓN
						case 2:
							if(bajaRecaudacion(listaRecaudadores, TAMR) == 1)
							{
								printf("\n * BAJA DE RECAUDACIÓN EXITOSA\n");
								mostrarUnaRecaudacion(listaRecaudadores[indexUltimoR]);
								//mostrarTodasLasRecaudaciones(listaRecaudadores, TAMR);
							}
							else
							{
								printf("\n * BAJA DE RECAUDACIÓN CANCELADA\n");
							}
							system("pause");
						break;

						//MODIFICACION RECAUDACIÓN
						case 3:
							if(modificacionRecaudacion(listaRecaudadores, TAMR) == 1)
							{
								printf("\n * MODIFICACION DE RECAUDACIÓN EXITOSA\n");
								mostrarUnaRecaudacion(listaRecaudadores[indexUltimoR]);
							}
							else
							{
								printf("\n * MODIFICACION DE RECAUDACIÓN CANCELADA\n");
							}
							system("pause");
						break;

						//ESTADOS RECAUDACIÓN
						case 4:
							if(modificacionEstadoRecaudacion(listaRecaudadores, TAMR, listaContribuyentes, TAMC) == 1)
							{
								printf("\n * MODIFICACION DE ESTADO EXITOSA\n");
								printf("\nID R \tID C \tMES  \tTIPO   \tIMPORTE   \tESTADO\n");
								mostrarUnaRecaudacion(listaRecaudadores[indexUltimoR]);
							}
							else
							{
								printf("\n * MODIFICACION DE ESTADO CANCELADA\n");
							}
							system("pause");
						break;
					}//fin switch opcionesRecaudar
				}while(opcionesRecaudar != 0);
				printf("\n...ABM RECAUDACIÓN FINALIZADO.\n");
				system("pause");
			break;

			//INFORMES CONTRIBUYENTES
			case 5:
				informeContribuyentes(listaContribuyentes, TAMC, listaRecaudadores, TAMR, 0);
				system("pause");
			break;

			//INFORMES RECAUDACIONES
			case 6:
				informeRecaudaciones(listaContribuyentes, TAMC, listaRecaudadores, TAMR);
				system("pause");
			break;

			//INFORMES CONTRIBUYENTE CON MAS ESTADOS REFINANCIAR
			case 7:
				informeContribuyenteMasEstadosR(listaContribuyentes, TAMC, listaRecaudadores, TAMR);
				system("pause");
			break;

			//INFORMES RECAUDACIONES MAYORES A MIL
			case 8:
				informeRecaudacionesMayoresAMil(listaContribuyentes, TAMC, listaRecaudadores, TAMR);
				system("pause");
			break;

			//INFORMES CONTRIBUYENTES POR TIPO DE RECAUDACION (ARBA, IIBB, GANANCIAS)
			case 9:
				informeContribuyentePorTipoDeRecaudacion(listaContribuyentes, TAMC, listaRecaudadores, TAMR);
				system("pause");
			break;

			//INFORME NOMBRE Y CUIL DE CONTRIBUYENTES CON ESTADOS SALDADO EN FEBRERO
			case 10:
				informeContribuyentesEstadosSaldadoFebrero(listaContribuyentes, TAMC, listaRecaudadores, TAMR);
				system("pause");
			break;
		}//fin switch mostrarOpciones
	}while(mostrarOpciones != 0);

	printf("\n...PROGRAMA FINALIZADO.");

	return EXIT_SUCCESS;
}//fin funcion main
