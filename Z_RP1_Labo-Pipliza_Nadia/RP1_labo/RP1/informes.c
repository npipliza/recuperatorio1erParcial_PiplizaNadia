#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayContribuyentes.h"
#include "arrayRecaudadores.h"
#include "informes.h"
#include "utn.h"

#define VACIO 0
#define OCUPADO 1
#define BAJA -1

/******************************************************************************************************************************************/
void informeContribuyentes(eContribuyentes listaContribuyentes[], int TAMC, eRecaudadores listaRecaudadores[], int TAMR, int unC)
{
	int i;
	int j;
	int bandera  = 0;
	int bandera2 = 0;
	int inicio   = 0;
	int fin      = TAMC;

	if(unC != 0)
	{
		inicio = unC;
		fin    = unC + 1;
	}

	if(listaContribuyentes != NULL && TAMC > 0)
	{
		printf("\nINFORME CONTRIBUYENTES--------------------------------------------\n");
		for(i = inicio; i < fin; i++)
		{
			if(listaContribuyentes[i].isEmpty == OCUPADO)
			{
				printf("\nCONTRIBUYENTE:\n");
				printf("ID-C \tAPELLIDO \tNOMBRE     \tCUIL\n");
				mostrarUnContribuyente(listaContribuyentes[i]);
				bandera2 = 1;
			}

			for(j = 0; j < TAMR; j++)
			{
				if(listaRecaudadores[j].isEmpty == OCUPADO && listaRecaudadores[j].idContribuyente == listaContribuyentes[i].idContribuyente)
				{
					if(bandera == 0)
					{
						printf("\nIMPUESTOS:\n");
						printf("ID-R \tMES \tTIPO \tIMPORTE \tESTADO\n");
						bandera = 1;
					}
					printf("%2d %10s %10s %10f %10s\n", listaRecaudadores[j].idRecaudacion,
														listaRecaudadores[j].mes,
														listaRecaudadores[j].tipo,
														listaRecaudadores[j].importe,
														listaRecaudadores[j].estado);
				}
			}
			bandera = 0;
			if(bandera2 == 1)
			{
				printf("\n------------------------------------------------------------------\n");
				bandera2 = 0;
			}
		}
	}
	else
	{
		printf("\nNO SE HAN DADO DE ALTA CONTRIBUYENTES\n");
	}

}//fin funcion informeContribuyentes

/******************************************************************************************************************************************/
void informeRecaudaciones(eContribuyentes listaContribuyentes[], int TAMC, eRecaudadores listaRecaudadores[], int TAMR)
{
	int i;
	int j;
	//int bandera = 0;

	if(listaContribuyentes != NULL && TAMC > 0 && listaRecaudadores != NULL && TAMR > 0)
	{
		for(j = 0; j < TAMR; j++)
		{
			for(i = 0; i < TAMC; i++)
			{
			if(listaRecaudadores[j].isEmpty == OCUPADO &&
			   listaRecaudadores[j].idContribuyente == listaContribuyentes[i].idContribuyente &&
			   strcmp(listaRecaudadores[j].estado,"SALDADO") == 0)
				{
					printf("\nINFORME DE RECAUDACIONES------------------------------------------\n");
					printf("TIPO \tID-R \tMES  \tIMPORTE \tESTADO \t\tCONTRIBUYENTE\n");
					printf("%10s %2d %10s %10f %10s %10s %10s %10s\n", listaRecaudadores[j].tipo,
																	   listaRecaudadores[j].idRecaudacion,
																	   listaRecaudadores[j].mes,
																	   listaRecaudadores[j].importe,
																	   listaRecaudadores[j].estado,
																	   listaContribuyentes[i].apellidoC,
																	   listaContribuyentes[i].nombreC,
																	   listaContribuyentes[i].cuilC);
					printf("\n------------------------------------------------------------------\n");
				}
			}
		}
	}
	else
	{
		printf("\nNO SE HAN DADO DE ALTA CONTRIBUYENTES\n");
	}

}//fin funcion informeRecaudaciones

/******************************************************************************************************************************************/
void informeContribuyenteMasEstadosR(eContribuyentes listaContribuyentes[], int TAMC, eRecaudadores listaRecaudadores[], int TAMR)
{//a) Contribuyentes con más recaudaciones en estado “refinanciar”.
	/*int i;
	int j;
	int maximoCurso;
	eRecaudadores contador;
	eRecaudadores auxiliar[TAMR];
	int i;
	int j;
	for(i=0; i<TAMR;i++)
	{
		auxiliar[i].idRecaudacion = listaRecaudadores[i].idRecaudacion;
		auxiliar[i].contador = 0;
	}

	for(i=0; i<TAMR;i++)
	{
		for(j=0; jtAlumnos;j++)
		{
			if(auxiliar[i].idRecaudacion == listaRecaudadores[j].idRecaudacion)
			{
				auxiliar[i].contador++;
			}
		}
	}

	//seguia otro for pero no pude saacar foro perdon meli del futuro
	// ya lo consegui xd te amo amiga
	/*
	for(i=0;i<tCursos;i++)
	{
		printf("%d - %d\n", auxiliar[i].id, auxiliar[i].contador);
	}*/

/*	for(i=0;i<TAMR;i++)
	{
		if(i==0 || auxiliar[i].contador > maximoCurso)
		{
			maximoCurso = auxiliar[i].contador;
		}
	}

	//printf("maximo_ %d", maximoCurso);

	for(i=0;i<TAMR;i++)
	{
		if(auxiliar[i].contador == maximoCurso)
		{
			for(j=0;j<TAMR;j++)
			{
				if(auxiliar[i].idRecaudacion == listaRecaudadores[j].idRecaudacion)
				{
					printf("%s\n", listaRecaudadores[j].estado);

				}
			}
		}
	}*/

	/*if(listaContribuyentes != NULL && TAMC > 0 && listaRecaudadores != NULL && TAMR > 0)
	{
		for(j = 0; j < TAMR; j++)
		{
			for(i = 0; i < TAMC; i++)
			{
			if(listaRecaudadores[j].isEmpty == OCUPADO &&
			   listaRecaudadores[j].idContribuyente == listaContribuyentes[i].idContribuyente &&
			   strcmp(listaRecaudadores[j].estado,"REFINANCIAR") == 0)
				{
					printf("\nINFORME CONTRIBUYENTE CON MAS ESTADOS REFINANCIAR-----------------\n");
					printf("TIPO \tID-R \tMES  \tIMPORTE \tESTADO \t\tCONTRIBUYENTE\n");
					printf("%10s %2d %10s %10f %10s %10s %10s %10s\n", listaRecaudadores[j].tipo,
																	   listaRecaudadores[j].idRecaudacion,
																	   listaRecaudadores[j].mes,
																	   listaRecaudadores[j].importe,
																	   listaRecaudadores[j].estado,
																	   listaContribuyentes[i].apellidoC,
																	   listaContribuyentes[i].nombreC,
																	   listaContribuyentes[i].cuilC);
					printf("\n------------------------------------------------------------------\n");
				}
			}
		}
	}
	else
	{
		printf("\nNO SE HAN DADO DE ALTA CONTRIBUYENTES\n");
	}*/

}//fin funcion informeContribuyenteMasEstadosR

/******************************************************************************************************************************************/
void informeRecaudacionesMayoresAMil(eContribuyentes listaContribuyentes[], int TAMC, eRecaudadores listaRecaudadores[], int TAMR)
{//b) Cantidad de recaudaciones saldadas de importe mayor a 1000: Se imprimira la cantidad de recaudaciones en estado “saldado” con ese importe o mayor.
	int i;
	int j;
	//int bandera = 0;
	printf("\nINFORME CONTRIBUYENTE CON IMPUESTOS SALDADOS MAYORES A $1000-----------\n");
	printf("TIPO \tID-R \tMES  \tIMPORTE \tESTADO \t\tCONTRIBUYENTE\n");
	if(listaContribuyentes != NULL && TAMC > 0 && listaRecaudadores != NULL && TAMR > 0)
	{
		for(j = 0; j < TAMR; j++)
		{
			for(i = 0; i < TAMC; i++)
			{
			if(listaRecaudadores[j].isEmpty == OCUPADO &&
			   listaRecaudadores[j].idContribuyente == listaContribuyentes[i].idContribuyente &&
			   strcmp(listaRecaudadores[j].estado,"SALDADO") == 0 && listaRecaudadores[j].importe > 1000)
				{
					//printf("\nINFORME CONTRIBUYENTE CON MAS ESTADOS REFINANCIAR-----------------\n");
					//printf("TIPO \tID-R \tMES  \tIMPORTE \tESTADO \t\tCONTRIBUYENTE\n");
					printf("%10s %2d %10s %10f %10s %10s %10s %10s\n", listaRecaudadores[j].tipo,
																	   listaRecaudadores[j].idRecaudacion,
																	   listaRecaudadores[j].mes,
																	   listaRecaudadores[j].importe,
																	   listaRecaudadores[j].estado,
																	   listaContribuyentes[i].apellidoC,
																	   listaContribuyentes[i].nombreC,
																	   listaContribuyentes[i].cuilC);
					printf("\n------------------------------------------------------------------\n");
				}
			}
		}
	}
	else
	{
		printf("\nNO SE HAN DADO DE ALTA CONTRIBUYENTES\n");
	}

}//fin funcion informeRecaudacionesMayoresAMil


/******************************************************************************************************************************************/
void informeContribuyentePorTipoDeRecaudacion(eContribuyentes listaContribuyentes[], int TAMC, eRecaudadores listaRecaudadores[], int TAMR)
{//c) Informar todos los datos de los contribuyentes de un tipo de recaudación ingresada por el usuario (ARBA, IIBB, GANANCIAS)
	int i;
	int j;
	int mostrarOpciones;
	//int bandera = 0;
	printf("\nINFORME CONTRIBUYENTES POR TIPO DE RECAUDACIÓN-----------------\n");
	printf("TIPO \tID-R \tMES  \tIMPORTE \tESTADO \t\tCONTRIBUYENTE\n");
	if(listaContribuyentes != NULL && TAMC > 0 && listaRecaudadores != NULL && TAMR > 0)
	{
		for(j = 0; j < TAMR; j++)
		{
			do//creo bucle del menu
			{
			mostrarOpciones = PedirEntero("\nINGRESE IMPUESTO A MOSTRAR: \n"
										  "1. ARBA.\n"
										  "2. IIBB.\n"
										  "3. GANANCIAS.\n"
										  "0. SALIR.\n"
										  "Elija una opción: ","\nError. Ingrese número de opción: ");

				switch(mostrarOpciones)
				{
					case 1:
						strncpy(listaRecaudadores[j].tipo,"ARBA",50);
					break;

					case 2:
						strncpy(listaRecaudadores[j].tipo,"IIBB",50);
					break;

					case 3:
						strncpy(listaRecaudadores[j].tipo,"GANANCIAS",50);
					break;
				}
			}while(mostrarOpciones !=0 && mostrarOpciones !=1 && mostrarOpciones !=2 && mostrarOpciones !=3);


			for(i = 0; i < TAMC; i++)
			{
			if(listaRecaudadores[j].isEmpty == OCUPADO && listaRecaudadores[j].idContribuyente == listaContribuyentes[i].idContribuyente)
				{

					//printf("\nINFORME CONTRIBUYENTE CON MAS ESTADOS REFINANCIAR-----------------\n");
					//printf("TIPO \tID-R \tMES  \tIMPORTE \tESTADO \t\tCONTRIBUYENTE\n");
					printf("%10s %2d %10s %10f %10s %10s %10s %10s\n", listaRecaudadores[j].tipo,
																	   listaRecaudadores[j].idRecaudacion,
																	   listaRecaudadores[j].mes,
																	   listaRecaudadores[j].importe,
																	   listaRecaudadores[j].estado,
																	   listaContribuyentes[i].apellidoC,
																	   listaContribuyentes[i].nombreC,
																	   listaContribuyentes[i].cuilC);
					printf("\n------------------------------------------------------------------\n");
				}
			}
		}
	}
	else
	{
		printf("\nNO SE HAN DADO DE ALTA CONTRIBUYENTES\n");
	}

}//fin funcion informeContribuyentePorTipoDeRecaudacion

/******************************************************************************************************************************************/
void informeContribuyentesEstadosSaldadoFebrero(eContribuyentes listaContribuyentes[], int TAMC, eRecaudadores listaRecaudadores[], int TAMR)
{//d)Nombre y c.u.i.l. de los Contribuyentes que pagaron impuestos en el mes de FEBRERO
	int i;
	int j;
	//int mostrarOpciones;
	//int bandera = 0;
	printf("\nINFORME CONTRIBUYENTE CON IMPUESTOS PAGOS EN FEBRERO-----------------\n");
	printf("TIPO \tID-R \tMES  \tIMPORTE \tESTADO \t\tCONTRIBUYENTE\n");
	if(listaContribuyentes != NULL && TAMC > 0 && listaRecaudadores != NULL && TAMR > 0)
	{
		for(j = 0; j < TAMR; j++)
		{
			for(i = 0; i < TAMC; i++)
			{
			if(listaRecaudadores[j].isEmpty == OCUPADO &&
			   listaRecaudadores[j].idContribuyente == listaContribuyentes[i].idContribuyente &&
			   strcmp(listaRecaudadores[j].mes,"Febrero") == 0)
				{
					//printf("\nINFORME CONTRIBUYENTE CON MAS ESTADOS REFINANCIAR-----------------\n");
					//printf("TIPO \tID-R \tMES  \tIMPORTE \tESTADO \t\tCONTRIBUYENTE\n");
					printf("%10s %10s %10s %10s\n", listaRecaudadores[j].mes,
																	   listaContribuyentes[i].apellidoC,
																	   listaContribuyentes[i].nombreC,
																	   listaContribuyentes[i].cuilC);
					printf("\n------------------------------------------------------------------\n");
				}
			}
		}
	}
	else
	{
		printf("\nNO SE HAN DADO DE ALTA CONTRIBUYENTES\n");
	}

}//fin funcion informeContribuyentesEstadosSaldadoFebrero
