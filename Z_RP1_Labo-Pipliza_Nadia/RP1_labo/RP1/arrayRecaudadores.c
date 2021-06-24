#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayContribuyentes.h"
#include "arrayRecaudadores.h"

//#include "informes.h"
#include "utn.h"

//ID AUTOINCREMENTAL
int idIncremental = 99;
#define TAMR1 50 //recaudadores
//int pedirDatos;
//int modificarDatos;

/** INICIALIZAR ESTRUCTURAS */
/************************************************************************************/
void InicializarRecaudacion(eRecaudadores listaRecaudadores[], int TAMR)
{
	int i;

	for (i = 0; i < TAMR; i++)
	{
		listaRecaudadores[i].isEmpty = VACIO;
	}//fin for
}//fin funcion InicializarRecaudacion

/** DATOS HARDCODEADOS DE ESTRUCTURAS */
/************************************************************************************/
void HardcodearRecaudacion(eRecaudadores listaRecaudadores[], int TAMR)
{
	int   i;
	int   idRecaudacion[]   = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
	int   idContribuyente[] = {1000, 1000, 1002, 1000,1004, 1005, 1006, 1007, 1008, 1009};
	char  mes[][25]         = {"Enero","Febrero","Marzo","Abril","Enero","Febrero","Marzo","Abril","Febrero","Abril"};
	char  tipo[][25]        = {"ARBA","IIBB","ARBA","GANANCIAS","IIBB","ARBA","GANANCIAS","IIBB","ARBA","GANANCIAS"};
	int   importe[]         = {1500, 45000, 2000, 4300,1500, 45000, 2000, 4300,1500, 45000};
	char  estado[][25]      = {"PENDIENTE","SALDADO","PENDIENTE","SALDADO","PENDIENTE","PENDIENTE","SALDADO","REFINANCIAR","PENDIENTE","SALDADO"};
	int   isEmpty[]         = {OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(i = 0; i < TAMR; i++)
	{
		listaRecaudadores[i].idRecaudacion   = idRecaudacion[i];
		listaRecaudadores[i].idContribuyente = idContribuyente[i];
		strcpy(listaRecaudadores[i].mes,mes[i]);
		strcpy(listaRecaudadores[i].tipo,tipo[i]);
		listaRecaudadores[i].importe = importe[i];
		strcpy(listaRecaudadores[i].estado,estado[i]);
		listaRecaudadores[i].isEmpty = isEmpty[i];
	}//fin for
}//fin funcion HardcodearRecaudacion

/************************************************************************************/
int obtenerIDdeRecaudadores()
{
	return idIncremental+=1;
}

/************************************************************************************/
int obtenerUltimoIDdeRecaudadores()
{
	return idIncremental;
}

/************************************************************************************/
void mostrarUnaRecaudacion(eRecaudadores listaRecaudadores)
{
	if(listaRecaudadores.isEmpty == OCUPADO)
	{
		printf("%2d %10d %10s %10s %10.2f %10s\n", listaRecaudadores.idRecaudacion,
											  	  listaRecaudadores.idContribuyente,
												  listaRecaudadores.mes,
												  listaRecaudadores.tipo,
												  listaRecaudadores.importe,
												  listaRecaudadores.estado);
	}
}

/************************************************************************************/
void mostrarUnContribuyenteConRecaudaciones(eRecaudadores listaRecaudadores, eContribuyentes listaContribuyentes)
{
	//eContribuyentes listaContribuyentes;

	if(listaRecaudadores.isEmpty == OCUPADO)
	{
		printf("%2d %10s %10s %2d %10s %10s %10.2f %10s\n", listaRecaudadores.idContribuyente,
															listaContribuyentes.apellidoC,
															listaContribuyentes.nombreC,
															listaRecaudadores.idRecaudacion,
															listaRecaudadores.mes,
															listaRecaudadores.tipo,
															listaRecaudadores.importe,
															listaRecaudadores.estado);
	}
}

/************************************************************************************/
int mostrarTodasLasRecaudaciones(eRecaudadores listaRecaudadores[], int TAMR)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	printf("\t -----> LISTA DE RECAUDACIONES <----- \n");
	printf("\nID R \tID C \tMES  \tTIPO   \tIMPORTE \t ESTADO\n");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listaRecaudadores != NULL && TAMR > 0)
	{
		for(i = 0; i < TAMR; i++)
		{//PREGUNTO POR SU ESTADO "OCUPADO"
			if (listaRecaudadores[i].isEmpty == OCUPADO)
			{//MUESTRO UN SOLO SERVICIO
				//HardcodearServicios(listaRecaudadores, TAMR);
				mostrarUnaRecaudacion(listaRecaudadores[i]);
				//CONTADOR DE SERVICIO
				cantidad++;
			}
		}
	}
	//SI CANTIDAD == 0 - NO HUBO SERVICIOS PARA MOSTRAR (ARRAY SIN ALTAS)
	if(cantidad > 0)
	{
		rtn = 1;
	}
	return rtn;
}

/************************************************************************************/
eRecaudadores cargarDatosRecaudacion(void)
{
	int mostrarOpciones;
	eRecaudadores auxiliar;

	auxiliar.idRecaudacion = obtenerIDdeRecaudadores();
	printf("ingrese el ID.\n");
	scanf("%d", &auxiliar.idContribuyente);
	utn_getPalabra(auxiliar.mes ,sizeof(auxiliar.mes), "\nIngrese mes: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
	//utn_getPalabra(auxiliar.tipo ,sizeof(auxiliar.tipo), "Ingrese tipo: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
	do//creo bucle del menu
		{
			mostrarOpciones = PedirEntero("\nINGRESE UNA OPCIÓN: \n"
										  "1. ARBA.\n"
										  "2. IIBB.\n"
										  "3. GANANCIAS.\n"
										  "Elija una opción: ","\nError. Ingrese número de opción: ");

			switch(mostrarOpciones)
			{
				case 1:
					strncpy(auxiliar.tipo,"ARBA",50);
				break;

				case 2:
					strncpy(auxiliar.tipo,"IIBB",50);
				break;

				case 3:
					strncpy(auxiliar.tipo,"GANANCIAS",50);
				break;
			}
		}while(mostrarOpciones !=1 && mostrarOpciones !=2 && mostrarOpciones !=3);

	utn_getNumeroFlotante(&auxiliar.importe,"Ingrese importe: ","\nERROR: Ingrese importe válido.\n",1,999999,10);
	strncpy(auxiliar.estado,"PENDIENTE",50);
	auxiliar.isEmpty = OCUPADO;

	return auxiliar;
}

/************************************************************************************/
int obtenerIndexRecaudacionLibre(eRecaudadores listaRecaudadores[], int TAMR)
{
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listaRecaudadores != NULL && TAMR > 0)
	{
		for(i = 0; i < TAMR; i++)
		{//PREGUNTO POR EL ESTADO "LIBRE"
			if(listaRecaudadores[i].isEmpty == VACIO)
			{//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
int altaRecaudacion(eRecaudadores listaRecaudadores[], int TAMR)
{
	int rtn = 0;

	eRecaudadores auxRecaudacion;
	//BUSCO ESPACIO EN ARRAY
	int index = obtenerIndexRecaudacionLibre(listaRecaudadores, TAMR);

	if(index != -1)// == -1 array lleno, != -1 hay lugar.
	{
		auxRecaudacion           = cargarDatosRecaudacion();
		listaRecaudadores[index] = auxRecaudacion;
		rtn                      = index;//case1//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
	}
	else
	{
		rtn = -1;
	}
	return rtn;
}

/************************************************************************************/
eRecaudadores modificarUnaRecaudacion(eRecaudadores recaudacion)
{
	int mostrarOpciones;

	eRecaudadores auxiliar = recaudacion;

	do//creo bucle del menu
	{
		printf("\nINGRESE OPCIÓN A MODIFICAR: ************************************\n"
			   "1. Mes.\n"
			   "2. Tipo.\n"
			   "3. Importe.\n"
			   "0. SALIR\n"
			   "Elija una opción: \n");
		scanf("%d", &mostrarOpciones);

		switch(mostrarOpciones)
		{
			case 1:
				utn_getPalabra(auxiliar.mes ,sizeof(auxiliar.mes), "\nIngrese mes: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
			break;

			case 2:
				utn_getPalabra(auxiliar.tipo ,sizeof(auxiliar.tipo), "\nIngrese tipo: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
			break;

			case 3:
				utn_getNumeroFlotante(&auxiliar.importe,"Ingrese importe: ","\nERROR: Ingrese importe válido.\n",1,999999,10);
			break;
		}
	}while(mostrarOpciones != 0);

	auxiliar.isEmpty = OCUPADO;
	return auxiliar;

}


/************************************************************************************/
eRecaudadores modificarUnEstadoDeRecaudacion(eRecaudadores recaudacion)
{
	int mostrarOpciones;

	eRecaudadores auxiliar = recaudacion;

	do//creo bucle del menu
	{
		printf("\nINGRESE ESTADO A MODIFICAR: ************************************\n"
			   "1. REFINANCIAR.\n"
			   "2. SALDADO.\n"
			   "0. SALIR\n"
			   "Elija una opción: \n");
		scanf("%d", &mostrarOpciones);

		switch(mostrarOpciones)
		{
			case 1:
				strncpy(auxiliar.estado,"REFINANCIAR",50);
			break;

			case 2:
				strncpy(auxiliar.estado,"SALDADO",50);
			break;
		}
	}while(mostrarOpciones != 0);

	auxiliar.isEmpty = OCUPADO;
	return auxiliar;

}

/************************************************************************************/
int modificacionEstadoRecaudacion(eRecaudadores listaRecaudadores[], int TAMR, eContribuyentes listaContribuyentes[], int TAMC)
{
	int rtn = 0;
	int idRecaudacion;
	int index;
	int opcion;
	int opcion1;
	int bandera = 0;
	eRecaudadores auxiliar;
	//eContribuyentes auxContribuyente;

	//LISTO TODAS LAS RECAUDACIONES
	if(mostrarTodasLasRecaudaciones(listaRecaudadores, TAMR) != 0)
	{//BANDERA EN 1 SI HAY RECAUDACIONES DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXISTEN RECAUDACIONES DADAS DE ALTA.\n");
	}

	//SI HAY RECAUDACIONES PARA MODIFICAR
	if(bandera == 1)
	{//PIDO ID A MODIFICAR
		printf("\n\t***** OPCIÓN MODIFICAR ESTADO ***** \n");
		do
		{
			opcion = 0;
			printf("INGRESE EL ID.\n");
			scanf("%d", &idRecaudacion);

			//OBTENGO INDEX DEL ARRAY DE RECAUDACIONES A MODIFICAR
			index = buscarRecaudacionPorID(listaRecaudadores, TAMR, idRecaudacion);

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
			printf("\nATENCIÓN: Se va a modificar el estado del siguiente contribuyente:\n");
			printf("\nID-C \tAPELLIDO \tNOMBRE \tID-R \tMES  \tTIPO   \tIMPORTE \t ESTADO\n");
			mostrarUnContribuyenteConRecaudaciones(listaRecaudadores[index], listaContribuyentes[index]);
		}while(opcion == 1);


		if(index != -1)
		{
			//LLAMO A FUNCION QUE MODIFICA ESTADOS
			auxiliar = modificarUnEstadoDeRecaudacion(listaRecaudadores[index]);
			printf("\n¿CONFIRMA LA MODIFICACIÓN DEL ESTADO? \n Confirmar: 1\n Cancelar:  2\n");
			scanf("%d", &opcion1);

			if(opcion1 == 1)
			{
				listaRecaudadores[index] = auxiliar;
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
int buscarRecaudacionPorID(eRecaudadores listaRecaudadores[], int TAMR, int ID)
{
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listaRecaudadores != NULL && TAMR > 0)
	{
		for(i = 0; i < TAMR; i++)
		{//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (listaRecaudadores[i].idRecaudacion == ID && listaRecaudadores[i].isEmpty == OCUPADO)
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
int buscarContribuyenteBajaRecaudaciones(eRecaudadores listaRecaudadores[], int TAMR, int ID)
{
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO

	if(listaRecaudadores != NULL && TAMR > 0)
	{
		for(i = 0; i < TAMR; i++)
		{//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			//printf("%d \n",listaRecaudadores[i].idContribuyente);
			if (listaRecaudadores[i].idContribuyente == ID)
			{//SI ENCONTRE EL ID

				listaRecaudadores[i].isEmpty = BAJA;
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
int modificacionRecaudacion(eRecaudadores listaRecaudadores[], int TAMR)
{
	int rtn = 0;
	int idRecaudacion;
	int index;
	int opcion;
	int opcion1;
	int bandera = 0;
	eRecaudadores auxiliar;

	//LISTO TODAS LAS RECAUDACIONES
	if(mostrarTodasLasRecaudaciones(listaRecaudadores, TAMR) != 0)
	{//BANDERA EN 1 SI HAY RECAUDACIONES DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXISTEN RECAUDACIONES DADAS DE ALTA.\n");
	}

	//SI HAY RECAUDACIONES PARA MODIFICAR
	if(bandera == 1)
	{//PIDO ID A MODIFICAR
		printf("\n***** OPCIÓN MODIFICAR ***** \n");
		do
		{
			opcion = 0;
			printf("INGRESE EL ID.\n");
			scanf("%d", &idRecaudacion);

		//OBTENGO INDEX DEL ARRAY DE RECAUDACIONES A MODIFICAR
		index = buscarRecaudacionPorID(listaRecaudadores, TAMR, idRecaudacion);

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
			//LLAMO A FUNCION QUE MODIFICA RECAUDACIONES
			auxiliar = modificarUnaRecaudacion(listaRecaudadores[index]);
			printf("¿CONFIRMA LA MODIFICACIÓN DE LA RECAUDACION? \n Confirmar: 1\n Cancelar:  2\n");
			scanf("%d", &opcion1);

			if(opcion1 == 1)
			{
				listaRecaudadores[index] = auxiliar;
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
int bajaRecaudacion(eRecaudadores listaRecaudadores[], int TAMR)
{
	int rtn = 0;
	int idRecaudacion;
	int index;
	int bandera = 0;
	int opcion;
	int opcion1;

	//LISTO TODOS LOS SERVICIOS
	if(mostrarTodasLasRecaudaciones(listaRecaudadores, TAMR) != 0)
	{//BANDERA EN 1 SI HAY SERVICIOS DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXITEN RECAUDACIONES DADAS DE ALTA.\n");
	}
	//SI HAY SERVICIOS PARA DAR DE BAJA
	if(bandera == 1)
	{//PIDO ID A DAR DE BAJA
		printf("\n***** OPCIÓN BAJA ***** \n");
		do
		{
			opcion1 = 0;
			printf("ingrese el ID.\n");
			scanf("%d", &idRecaudacion);

			//OBTENGO INDEX DEL ARRAY DE SERVICIOS A DAR DE BAJA
			index = buscarRecaudacionPorID(listaRecaudadores, TAMR, idRecaudacion);

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
			printf("\nID R \tID C \tMES  \tTIPO   \tIMPORTE   \tESTADO\n");
			mostrarUnaRecaudacion(listaRecaudadores[index]);

			printf("\n¿CONFIRMA LA BAJA DE LA RECAUDACIÓN? \n  Confirmar: 1\n  Cancelar: 2\n");
			scanf("%d", &opcion);

			if(opcion == 1)
			{
				listaRecaudadores[index].isEmpty = BAJA;
				rtn = 1;//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
			}
			if(opcion == 2)
			{
				return rtn;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
int modificarEstadoRefinanciar(eRecaudadores listaRecaudadores[], int TAMR)
{
	int rtn = 0;
	int idRecaudacion;
	int index;
	int opcion;
	int opcion1;
	int bandera = 0;
	eRecaudadores auxiliar;

	//LISTO TODAS LAS RECAUDACIONES
	if(mostrarTodasLasRecaudaciones(listaRecaudadores, TAMR) != 0)
	{//BANDERA EN 1 SI HAY RECAUDACIONES DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXISTEN RECAUDACIONES DADAS DE ALTA.\n");
	}

	//SI HAY RECAUDACIONES PARA MODIFICAR
	if(bandera == 1)
	{//PIDO ID A MODIFICAR
		printf("\n***** OPCIÓN MODIFICAR ESTADO ***** \n");
		do
		{
			opcion = 0;
			printf("Ingrese ID de la recaudación:");
			scanf("%d", &idRecaudacion);
			//OBTENGO INDEX DEL ARRAY DE RECAUDACIONES A MODIFICAR
			index = buscarRecaudacionPorID(listaRecaudadores, TAMR, idRecaudacion);

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
			//LLAMO A FUNCION QUE MODIFICA RECAUDACIONES
			auxiliar = modificarUnEstadoDeRecaudacion(listaRecaudadores[index]);
			printf("¿CONFIRMA LA MODIFICACIÓN DEL ESTADO DE LA RECAUDACION? \n Confirmar: 1\n Cancelar:  2\n");
			scanf("%d", &opcion1);

			if(opcion1 == 1)
			{
				listaRecaudadores[index] = auxiliar;
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

