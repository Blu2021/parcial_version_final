//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "blu2021.h"
#include "contribuyentes.h"

#define CONTRIBUYENTE 3
#define RECAUDACION 3

int main(void)
{
	setbuf(stdout,NULL);

	eContribuyente contribuyente[CONTRIBUYENTE];
	eRecaudacion recaudacion[RECAUDACION];
	eTipoRecaudacion tipoRecaudacion[3]={{1,"ARBA",0},{2,"IIBB",0},{3,"GANANCIAS",0}};
	eEstadoRecaudacion estadoRecaudacion[3]={{1,"ADEUDADA",0},{2,"REFINANCIADA",0},{3,"SALDADA",0}};
	int resultadoOpcionMenu;
	int idContribuyente=1000;
	int idRecaudacion=100;
	int posLibre;

	inicializarArrayContribuyente(contribuyente,CONTRIBUYENTE);
	inicializarArrayRecaudacion(recaudacion,RECAUDACION);
	do
	{
		printf("Bienvenido al Menu Contribuyentes\n"
					"1: ALTA CONTRIBUYENTE\n"
					"2: MODIFICAR CONTRIBUYENTE\n"
					"3: BAJA DE CONTRIBUYENTE\n"
					"4: CARGAR RECAUDACION\n"
					"5: REFINANCIAR/SALDAR RECAUDACION\n"
					"6: IMPRIMIR CONTRIBUYENTES\n"
					"7: IMPRIMIR RECAUDACIONES SALDADAS\n"
				    "8: IMPRIMIR RECAUDACIONES SALDADAS +1000\n"
					"9: IMPRIMIR CONTRIBUYENTES SEGUN TIPO R\n"
				    "10:IMPRIMIR RECAUDACIONES FEBRERO\n"
				    "11:IMPRIMIR CONTRIBUYENTES CON REC A REFINANCIAR\n"
				    "12:SALIR\n");
		if(utn_levantaEnteros(&resultadoOpcionMenu,"Ingrese opcion Menu","ERROR,opcion invalida",1,12))
		{
			switch(resultadoOpcionMenu)
			{
				case 1:
					posLibre=buscarLibreContribuyente(contribuyente,CONTRIBUYENTE);
					if(posLibre!=-1)
					{
						if(cargaDatosContribuyente(contribuyente,posLibre))
						{
							contribuyente[posLibre].idContribuyente=idContribuyente;
							printf("Contribuyente dado de alta con exito bajo id %d\n",idContribuyente);
							idContribuyente++;
							vueltaAtras();
						}
						else
						{
							printf("Algo fallo en la carga de datos\n");
							vueltaAtras();
						}
					}
					else
					{
						printf("No hay lugar disponible, elimine al menos uno\n");
						vueltaAtras();
					}
				break;
				case 2:
					menuModificar(contribuyente,CONTRIBUYENTE);
				break;
				case 3:
					bajaDatosContribuyente(contribuyente,CONTRIBUYENTE,recaudacion,RECAUDACION,tipoRecaudacion,3,estadoRecaudacion,3);
				break;
				case 4:
					posLibre=buscarLibreRecaudacion(recaudacion,RECAUDACION);
					if(posLibre!=-1)
					{
						if(cargaDatosRecaudacion(recaudacion,posLibre,contribuyente,CONTRIBUYENTE))
						{
							recaudacion[posLibre].idRecaudacion=idRecaudacion;
							printf("Recaudacion dada de alta con exito bajo id %d\n",idRecaudacion);
							idRecaudacion++;
							vueltaAtras();
						}
						else
						{
							printf("Algo fallo en la carga de datos ó no existe el id contribuyente\n");
							vueltaAtras();
						}
					}
					else
					{
						printf("No hay lugar disponible, elimine al menos uno\n");
						vueltaAtras();
					}
				break;
				case 5:
					muestraRecaudacionesPorId(recaudacion,RECAUDACION,contribuyente,CONTRIBUYENTE);
					vueltaAtras();
				break;
				case 6:
					muestraContribuyentesCargados(contribuyente,CONTRIBUYENTE,recaudacion,RECAUDACION,tipoRecaudacion,3,estadoRecaudacion,3);
				break;
				case 7:
					muestraRecaudacionesSaldadas(recaudacion,RECAUDACION,tipoRecaudacion,3,estadoRecaudacion,3,contribuyente,CONTRIBUYENTE);
					vueltaAtras();
				break;
				case 8:
					muestraRecaudacionesSaldadasMasMil(recaudacion,RECAUDACION,tipoRecaudacion,3,estadoRecaudacion,3,contribuyente,CONTRIBUYENTE);
					vueltaAtras();
				break;
				case 9:
					muestraContribuyentesCargadosSegunTipo(contribuyente,CONTRIBUYENTE,recaudacion,RECAUDACION,tipoRecaudacion,3,estadoRecaudacion,3);
					vueltaAtras();
				break;
				case 10:
					muestraRecaudacionesFebrero(recaudacion,RECAUDACION,tipoRecaudacion,3,estadoRecaudacion,3,contribuyente,CONTRIBUYENTE);
					vueltaAtras();
				break;
				case 11:
					muestraContribuyentesCargadosSegunEstadoRefinanciar(contribuyente,CONTRIBUYENTE,recaudacion,RECAUDACION,tipoRecaudacion,3,estadoRecaudacion,3);
					vueltaAtras();
				break;
				case 12:
					printf("Menu esta finalizando...");
				break;
			}
		}
		else
		{
			printf("Usted debe ingresar opcion del 1 al 9 , intente de nuevo\n");
		}
	}while(resultadoOpcionMenu!=12);

	return EXIT_SUCCESS;
}


