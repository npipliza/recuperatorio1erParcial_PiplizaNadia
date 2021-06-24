#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayRecaudadores.h"
#include "arrayContribuyentes.h"
#include "informes.h"
#include "utn.h"

//ID AUTOINCREMENTAL
int idIncrementalC = 999;
int idContribuyente;
int pedirDatos;
int modificarDatos;

/** INICIALIZAR ESTRUCTURAS ******************************************************************* */
void InicializarContribuyentes(eContribuyentes listaContribuyentes[], int TAMC)
{
	int i;

	for (i = 0; i < TAMC; i++)
	{
		listaContribuyentes[i].isEmpty = VACIO;
	}//fin for
}//fin funcion InicializarBicicleta

/** DATOS HARDCODEADOS DE ESTRUCTURAS */
/************************************************************************************/
void HardcodearContribuyentes(eContribuyentes listaContribuyentes[], int TAMC)
{
	int   i;
	int   idContribuyente[] = {1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009};
	char  nombreC[][25]     = {"Ana","Gonzalo","Pamela","Lucas","Olga","Pedro","Mariana","Alfredo","Julia","Lucas"};
	char  apellidoC[][25]   = {"Perez","Gomez","Lopez","Rivero","Lima","Gomez","Diaz","Ponte","Gimenez","Limay"};
	char  cuilC[][14]       = {"20-42554102-4","27-35421542-7","20-29452951-4","27-06254873-4","27-45123586-4","27-15789658-4","27-08523654-4","27-13852698-4","27-32589652-4","27-29852415-4"};
	int   isEmpty[]         = {OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(i = 0; i < TAMC; i++)
	{
		listaContribuyentes[i].idContribuyente = idContribuyente[i];
		strcpy(listaContribuyentes[i].nombreC,nombreC[i]);
		strcpy(listaContribuyentes[i].apellidoC,apellidoC[i]);
		strcpy(listaContribuyentes[i].cuilC,cuilC[i]);
		listaContribuyentes[i].isEmpty         = isEmpty[i];
	}//fin for
}//fin funcion HardcodearBicicletas

/************************************************************************************/
int obtenerIDdeContribuyente()
{
	return idIncrementalC+=1;
}

/************************************************************************************/
int obtenerUltimoIDdeContribuyente()
{
	return idIncrementalC;
}

/************************************************************************************/
int obtenerIndexContribuyenteLibre(eContribuyentes listaContribuyentes[], int TAMC)
{
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listaContribuyentes != NULL && TAMC > 0)
	{
		for(i = 0; i < TAMC; i++)
		{//PREGUNTO POR EL ESTADO "LIBRE"
			if(listaContribuyentes[i].isEmpty == VACIO)
			{//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
int altaContribuyente(eContribuyentes listaContribuyentes[], int TAMC)
{
	int rtn = 0;
	eContribuyentes auxContribuyente;
	//BUSCO ESPACIO EN ARRAY
	int index = obtenerIndexContribuyenteLibre(listaContribuyentes, TAMC);

	if(index != -1)// == -1 array lleno, != -1 hay lugar.
	{
		auxContribuyente           = cargarDatosContribuyente();
		listaContribuyentes[index] = auxContribuyente;
		rtn                        = index;//case1//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
	}
	else
	{
		rtn = -1;
	}
	return rtn;
}

/************************************************************************************/
int buscarContribuyentesPorID(eContribuyentes listaContribuyentes[], int TAMC, int ID)
{
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listaContribuyentes != NULL && TAMC > 0)
	{
		for(i = 0; i < TAMC; i++)
		{//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (listaContribuyentes[i].idContribuyente == ID && listaContribuyentes[i].isEmpty == OCUPADO)
			{//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
void mostrarUnContribuyente(eContribuyentes contribuyente)
{
		if(contribuyente.isEmpty == OCUPADO)
		{
			printf("%d \t%2s \t%8s \t%2s \n", contribuyente.idContribuyente,
											   contribuyente.apellidoC,
											   contribuyente.nombreC,
											   contribuyente.cuilC);
		}
}//fin funcion mostrarUnContribuyente

/************************************************************************************/
void mostrarUnContribuyenteConSusRecaudaciones(eContribuyentes listaContribuyentes, eRecaudadores listaRecaudadores[], int TAMR)
{
	int bandera = 0;
	int j;
	int idC;

	if(listaContribuyentes.isEmpty == OCUPADO)
	{
		idC = listaContribuyentes.idContribuyente;
		printf("%d \t%2s \t%8s \t%2s \n", listaContribuyentes.idContribuyente,
				listaContribuyentes.apellidoC,
				listaContribuyentes.nombreC,
				listaContribuyentes.cuilC);
		//printf("%d", TAMR);
		for(j = 0; j < TAMR; j++)
		{
			if(listaRecaudadores[j].isEmpty == OCUPADO && listaRecaudadores[j].idContribuyente == idC)
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
	}
}
/************************************************************************************/
int mostrarTodosLosContribuyentes(eContribuyentes listaContribuyentes[], int TAMC)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	printf("\n\t -----> LISTA DE CONTRIBUYENTES <----- \n");
	printf("\n ID \tAPELLIDO \tNOMBRE \tCUIL\n");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listaContribuyentes != NULL && TAMC > 0)
	{
		for(i = 0; i < TAMC; i++)
		{//PREGUNTO POR SU ESTADO "OCUPADO"
			if (listaContribuyentes[i].isEmpty == OCUPADO)
			{//MUESTRO UN SOLO TRABAJO
				mostrarUnContribuyente(listaContribuyentes[i]);
				//CONTADOR DE TRABAJO
				cantidad++;
			}
		}
	}
	//SI CANTIDAD == 0 - NO HUBO TRABAJOS PARA MOSTRAR (ARRAY SIN ALTAS)
	if(cantidad > 0)
	{
		rtn = 1;
	}
	return rtn;
}

/************************************************************************************/
eContribuyentes cargarDatosContribuyente(void)
{
	eContribuyentes auxiliar;

	auxiliar.idContribuyente = obtenerIDdeContribuyente();

	utn_getPalabra(auxiliar.nombreC ,sizeof(auxiliar.nombreC), "\nIngrese nombre: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
	utn_getPalabra(auxiliar.apellidoC ,sizeof(auxiliar.apellidoC), "Ingrese apellido: ", "\nERROR: Ingrese hasta 25 letras.", 20);
	utn_getCuil(auxiliar.cuilC,"Ingrese CUIL: ", "\nERROR: Ingrese CUIL válido. \n",14,10);
	//printf("ingrese cuil:");
	//scanf("%I64d",&auxiliar.cuilC);
    auxiliar.isEmpty = OCUPADO;

	return auxiliar;
}

/************************************************************************************/
eContribuyentes modificarUnContribuyente(eContribuyentes contribuyente)
{
	int mostrarOpciones;

	eContribuyentes auxiliar = contribuyente;

	do//creo bucle del menu
	{
		printf("\nINGRESE OPCIÓN A MODIFICAR: ************************************\n"
			   "1. Nombre.\n"
			   "2. Apellido.\n"
			   "3. CUIL.\n"
			   "0. SALIR\n"
			   "Elija una opción: \n");
		scanf("%d", &mostrarOpciones);

		switch(mostrarOpciones)
		{
			case 1:
				utn_getPalabra(auxiliar.nombreC ,sizeof(auxiliar.nombreC), "\nIngrese nombre: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
			break;

			case 2:
				utn_getPalabra(auxiliar.apellidoC ,sizeof(auxiliar.apellidoC), "Ingrese apellido: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
			break;

			case 3:
				utn_getCuil(auxiliar.cuilC,"Ingrese CUIL: ", "\nERROR: Ingrese CUIL válido. \n",14,10);
			break;
		}
	}while(mostrarOpciones != 0);

	auxiliar.isEmpty = OCUPADO;
	return auxiliar;

}

/************************************************************************************/
int modificacionContribuyente(eContribuyentes listaContribuyentes[], int TAMC)
{
	int rtn = 0;
	int idContribuyente;
	int index;
	int opcion;
	int opcion1;
	int bandera = 0;
	eContribuyentes auxiliar;

	//LISTO TODOS LOS CONTRIBUYENTES
	if(mostrarTodosLosContribuyentes(listaContribuyentes, TAMC) != 0)
	{//BANDERA EN 1 SI HAY CONTRIBUYENTES DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXISTEN CONTRIBUYENTES DADOS DE ALTA.\n");
	}

	//SI HAY CONTRIBUYENTES PARA MODIFICAR
	if(bandera == 1)
	{//PIDO ID A MODIFICAR
		printf("\n***** OPCIÓN MODIFICAR ***** \n");
		do
		{
			opcion = 0;
			printf("INGRESE EL ID.\n");
			scanf("%d", &idContribuyente);

		//OBTENGO INDEX DEL ARRAY DE CONTRIBUYENTES A MODIFICAR
		index = buscarContribuyentesPorID(listaContribuyentes, TAMC, idContribuyente);

			//BUSCO INDEX POR ID EN ARRAY
			if(index == -1)
			{
				printf("NO EXISTE ID.\n");

			printf("¿INGRESAR OTRO ID? \n SI: 1\n NO: 2\n");
			scanf("%d", &opcion);

				if(opcion == 2)
				{
					return rtn;
				}
			}
		}while(opcion == 1);



		if(index != -1)
		{
			//LLAMO A FUNCION QUE MODIFICA TRABAJO
		auxiliar = modificarUnContribuyente(listaContribuyentes[index]);
			printf("¿CONFIRMA LA MODIFICACIÓN DEL CONTRIBUYENTE? \n Confirmar: 1\n Cancelar:  2\n");
			scanf("%d", &opcion1);

			if(opcion1 == 1)
			{
				listaContribuyentes[index] = auxiliar;
				rtn = 1;//1 modificó ok
			}
			if(opcion1 == 2)
			{
				return rtn;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
int bajaContribuyente(eContribuyentes listaContribuyentes[], int TAMC, eRecaudadores listaRecaudadores[], int TAMR)
{
	int rtn = 0;
	int idContribuyente;
	int index;
	int bandera = 0;
	int opcion;
	int opcion1;
	//int j;

	//LISTO TODOS LOS TRABAJOS
	if(mostrarTodosLosContribuyentes(listaContribuyentes, TAMC) != 0)
	{//BANDERA EN 1 SI HAY TRABAJOS DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXISTEN CONTRIBUYENTES DADOS DE ALTA.\n");
	}
	//SI HAY TRABAJOS PARA DAR DE BAJA
	if(bandera == 1)
	{//PIDO ID A DAR DE BAJA
		printf("\n***** OPCIÓN BAJA ***** \n");
		do
		{
			opcion1 = 0;
			printf("ingrese el ID.\n");
			scanf("%d", &idContribuyente);

			//OBTENGO INDEX DEL ARRAY DE TRABAJOS A DAR DE BAJA
			index = buscarContribuyentesPorID(listaContribuyentes, TAMC, idContribuyente);

			//BUSCO INDEX POR ID EN ARRAY
			if(index == -1)
			{
				printf("NO EXISTE ID.\n");
				printf("¿Ingresar otro ID? \n SI: 1\n NO: 2\n");
				scanf("%d", &opcion1);

				if(opcion1 == 2)
				{
					return rtn;
				}
			}
		}while(opcion1 == 1);

		if(index != -1)
		{
			printf("\n ID \tNOMBRE  \tAPELLIDO \tCUIL\n");
			//informeContribuyentes(listaContribuyentes, TAMC, listaRecaudadores, TAMR, index);
			mostrarUnContribuyenteConSusRecaudaciones(listaContribuyentes[index], listaRecaudadores, TAMR);
			/*for(j = 0; j < TAMR; j++)
			{
				if(listaRecaudadores[j].isEmpty == OCUPADO && listaRecaudadores[j].idContribuyente == listaContribuyentes[idContribuyente].idContribuyente)
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
			}*/


			printf("\n¿CONFIRMA LA BAJA DEL CONTRIBUYENTE? \n  Confirmar: 1\n  Cancelar: 2\n");
			scanf("%d", &opcion);

			if(opcion == 1)
			{
				listaContribuyentes[index].isEmpty = BAJA;
				rtn = idContribuyente;//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
			}
			if(opcion == 2)
			{
				return rtn;
			}
		}
	}
	return rtn;
}


