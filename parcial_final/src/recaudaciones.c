#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "blu2021.h"
#include "recaudaciones.h"

int inicializarArrayRecaudacion(eRecaudacion arrayRecibido[],int tamanioArrayRecibido)
{
	int exito=0;
	int i;
	if(arrayRecibido!=NULL)
	{
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			arrayRecibido[i].estaVacio=1;
		}
		exito=1;
	}
	return exito;
}

int buscarLibreRecaudacion(eRecaudacion arrayRecibido[],int tamanioArrayRecibido)
{
	int i;
	int auxLibre=-1;

	if(arrayRecibido!=NULL)
	{
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			if(arrayRecibido[i].estaVacio==1)
			{
				auxLibre=i;
				break;
			}
		}
	}
	return auxLibre;
}

int muestraRecaudacionesContribuyente(eRecaudacion arrayRecibido[],int tamanioArrayRecibido,eTipoRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eEstadoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,int idContribuyente)
{
	int exito=0;
	int i;
	int sePuedeMostrar=1;
	char descripcionTipo[15];
	char descripcionEstado[15];

	if(arrayRecibido!=NULL&&arrayRecibidoDos!=NULL&&arrayRecibidoTres!=NULL)
	{
		exito=1;
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			if(idContribuyente==arrayRecibido[i].idContribuyente)
			{
				if(sePuedeMostrar)
				{
						printf("--------------------RECAUDACION DE CONTRIBUYENTE %d-------------------\n",idContribuyente);
						printf("MES    TipoRecaudacion    EstadoRecaudacion   IMPORTE     ID RECAUDACION\n");
						sePuedeMostrar=0;
				}
				consigueTipoRecaudacion(arrayRecibidoDos,tamanioArrayRecibidoDos,arrayRecibido[i].tipoRecaudacion,descripcionTipo);
				consigueEstadoRecaudacion(arrayRecibidoTres,tamanioArrayRecibidoTres,arrayRecibido[i].idEstadoRecaudacion,descripcionEstado);
				printf("%-7d%-19s%-20s%-12.2f%d\n",arrayRecibido[i].mes,descripcionTipo,descripcionEstado,arrayRecibido[i].importe,arrayRecibido[i].idRecaudacion);
			}
		}
	}
	if(sePuedeMostrar)
	{
		printf("Sin recaudaciones que mostrar\n");
	}
	return exito;
}

void consigueTipoRecaudacion(eTipoRecaudacion arrayRecibido[],int tamanioArrayRecibido,int tipoRecaudacion,char tipo[])
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		if(arrayRecibido[i].estaVacio==0&&tipoRecaudacion==arrayRecibido[i].idTipoRecaudacion)
		{
			strncpy(tipo,arrayRecibido[i].tipoRecaudacion,15);
		}
	}
}

void consigueEstadoRecaudacion(eEstadoRecaudacion arrayRecibido[],int tamanioArrayRecibido,int estadoRecaudacion,char tipo[])
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		if(arrayRecibido[i].estaVacio==0&&estadoRecaudacion==arrayRecibido[i].idEstadoRecaudacion)
		{
			strncpy(tipo,arrayRecibido[i].estadoRecaudacion,15);
		}
	}
}

int muestraRecaudacionesPorId(eRecaudacion arrayRecibido[],int tamUno,eContribuyente arrayRecibidoDos[],int tamDos)
{
	int exito=0;
	int i;
	int j;
	int auxIdRec;
	int recExistente=0;
	int opcionCambiaEstado;

	if(arrayRecibido!=NULL&&arrayRecibidoDos!=NULL)
	{
		exito=1;
		printf("Ingrese Id de recaudacion\n");
		fflush(stdin);
		scanf("%d",&auxIdRec);
		for(i=0;i<tamUno;i++)
		{
			if(auxIdRec==arrayRecibido[i].idRecaudacion&&arrayRecibido[i].estaVacio==0)
			{
				recExistente=1;
				break;
			}
		}
		if(recExistente)
		{
			for(j=0;j<tamDos;j++)
			{
				if(arrayRecibido[i].idContribuyente==arrayRecibidoDos[j].idContribuyente)
				{
					printf("--------------DATOS CONTRIBUYENTE----------------\n");
					printf("ID         NOMBRE       APELLIDO        CUIL\n");
					muestraContribuyenteCargado(arrayRecibidoDos[j]);
					break;
				}
			}
			printf("Ingrese 1:Cambiar estado a refinanciar\n"
						"   2:Cambiar estado a saldado\n"
				        "   3:CANCELAR\n");
			fflush(stdin);
			scanf("%d",&opcionCambiaEstado);
			while(opcionCambiaEstado<1||opcionCambiaEstado>3)
			{
					printf("Ingrese 1:Cambiar estado a refinanciar\n"
								"   2:Cambiar estado a saldado\n"
								"   3:CANCELAR\n");
					fflush(stdin);
					scanf("%d",&opcionCambiaEstado);
			}
			switch(opcionCambiaEstado)
			{
					case 1:
						arrayRecibido[i].idEstadoRecaudacion=2;
						printf("Estado de recaudacion en refinanciado\n");
					break;
					case 2:
						arrayRecibido[i].idEstadoRecaudacion=3;
						printf("Estado de recaudacion en saldado\n");
					break;
					case 3:
						printf("Se ha cancelado el cambio de estado\n");
					break;
			}
		}
		else
		{
			 printf("La recaudacion ingresada no existe , verifique por favor\n");
		}
	}
	return exito;
}

int muestraRecaudacionesSaldadas(eRecaudacion arrayRecibido[],int tamanioArrayRecibido,eTipoRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eEstadoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eContribuyente arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro)
{
	int exito=0;
	int sePuedeMostrar=0;
	int i;
	int j;
	char descripcionTipo[15];
	char descripcionEstado[15];

	if(arrayRecibido!=NULL&&arrayRecibidoDos!=NULL&&arrayRecibidoTres!=NULL)
	{
		for(i=0;i<tamanioArrayRecibido;i++)
		{
				if(arrayRecibido[i].estaVacio==0&&arrayRecibido[i].idEstadoRecaudacion==3)
				{
						printf("-------------------------RECAUDACIONES SALDADAS-------------------------\n");
						printf("MES    TipoRecaudacion    EstadoRecaudacion   IMPORTE     ID RECAUDACION\n");
						sePuedeMostrar++;
						consigueTipoRecaudacion(arrayRecibidoDos,tamanioArrayRecibidoDos,arrayRecibido[i].tipoRecaudacion,descripcionTipo);
						consigueEstadoRecaudacion(arrayRecibidoTres,tamanioArrayRecibidoTres,arrayRecibido[i].idEstadoRecaudacion,descripcionEstado);
						printf("%-7d%-19s%-20s%-12.2f%d\n",arrayRecibido[i].mes,descripcionTipo,descripcionEstado,arrayRecibido[i].importe,arrayRecibido[i].idRecaudacion);
						for(j=0;j<tamanioArrayRecibidoCuatro;j++)
						{
								if(arrayRecibido[i].idContribuyente==arrayRecibidoCuatro[j].idContribuyente)
								{
										printf("Pertenecientes al contribuyente       NOMBRE         CUIL\n");
										printf("                                      %-15s%s\n",arrayRecibidoCuatro[j].nombre,arrayRecibidoCuatro[j].cuil);
										break;
								}
						}
				}
	  }

		if(sePuedeMostrar==0)
		{
			 printf("No existen recaudaciones saldadas que mostrar\n");
		}
		exito=1;
	}

	return exito;
}

int cargaDatosRecaudacion(eRecaudacion arrayRecibido[],int posicion,eContribuyente arrayRecibidoDos[],int tamanioArrayRecibidoDos)
{
	int exito=0;
	int i;
	int auxIdContribuyente;
	int auxMes;
	int auxTipoRecaudacion;
	float auxImporte;
	int idExistente=0;
	int importeCorrecto=0;

	if(arrayRecibido!=NULL&&arrayRecibidoDos!=NULL)
	{
		printf("Ingrese id de contribuyente\n");
		fflush(stdin);
		scanf("%d",&auxIdContribuyente);
		for(i=0;i<tamanioArrayRecibidoDos;i++)
		{
			if(auxIdContribuyente==arrayRecibidoDos[i].idContribuyente&&arrayRecibidoDos[i].estaVacio!=1)
			{
				idExistente=1;
				break;
			}
		}
		if(idExistente)
		{
			arrayRecibido[posicion].idContribuyente=auxIdContribuyente;
			utn_levantaEnteros(&auxMes,"Ingrese mes del 1 al 12","ERROR,reingrese mes",1,12);
			arrayRecibido[posicion].mes=auxMes;
			printf("Ingrese tipo recaudacion 1-ARBA\n"
				   "                         2-IIBB\n"
				   "                         3-GANANCIAS\n");
			fflush(stdin);
			scanf("%d",&auxTipoRecaudacion);
			while(auxTipoRecaudacion<1||auxTipoRecaudacion>3)
			{
				printf("Ingrese tipo recaudacion 1-ARBA\n"
					   "                         2-IIBB\n"
					   "                         3-GANANCIAS\n");
				fflush(stdin);
				scanf("%d",&auxTipoRecaudacion);
			}
			arrayRecibido[posicion].tipoRecaudacion=auxTipoRecaudacion;
			printf("Ingrese importe por favor\n");
			fflush(stdin);
			importeCorrecto=scanf("%f",&auxImporte);
			while(!importeCorrecto)
			{
				printf("ERROR!,Ingrese importe por favor\n");
				fflush(stdin);
				importeCorrecto=scanf("%f",&auxImporte);
			}
			arrayRecibido[posicion].importe=auxImporte;
			arrayRecibido[posicion].idEstadoRecaudacion=1;
			arrayRecibido[posicion].estaVacio=0;
			exito=1;
		}
	}
	return exito;
}

int muestraRecaudacionesFebrero(eRecaudacion arrayRecibido[],int tamanioArrayRecibido,eTipoRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eEstadoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eContribuyente arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro)
{
	int exito=0;
	int sePuedeMostrar=0;
	int i;
	int j;
	char descripcionTipo[15];
	char descripcionEstado[15];

	if(arrayRecibido!=NULL&&arrayRecibidoDos!=NULL&&arrayRecibidoTres!=NULL)
	{
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			if(arrayRecibido[i].estaVacio==0&&arrayRecibido[i].mes==2)
			{
				printf("-------------------------RECAUDACIONES FEBRERO-------------------------\n");
				printf("MES    TipoRecaudacion    EstadoRecaudacion   IMPORTE     ID RECAUDACION\n");
				sePuedeMostrar++;
				consigueTipoRecaudacion(arrayRecibidoDos,tamanioArrayRecibidoDos,arrayRecibido[i].tipoRecaudacion,descripcionTipo);
				consigueEstadoRecaudacion(arrayRecibidoTres,tamanioArrayRecibidoTres,arrayRecibido[i].idEstadoRecaudacion,descripcionEstado);
				printf("%-7d%-19s%-20s%-12.2f%d\n",arrayRecibido[i].mes,descripcionTipo,descripcionEstado,arrayRecibido[i].importe,arrayRecibido[i].idRecaudacion);
				for(j=0;j<tamanioArrayRecibidoCuatro;j++)
				{
					if(arrayRecibido[i].idContribuyente==arrayRecibidoCuatro[j].idContribuyente)
					{
						printf("Pertenecientes al contribuyente       NOMBRE         CUIL\n");
						printf("                                      %-15s%s\n",arrayRecibidoCuatro[j].nombre,arrayRecibidoCuatro[j].cuil);
						break;
					}
				}
			}
	    }

		if(sePuedeMostrar==0)
		{
			 printf("No existen recaudaciones en febrero que mostrar\n");
		}
		exito=1;
	}

	return exito;
}

int muestraRecaudacionesSaldadasMasMil(eRecaudacion arrayRecibido[],int tamanioArrayRecibido,eTipoRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eEstadoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eContribuyente arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro)
{
	int exito=0;
	int sePuedeMostrar=0;
	int i;
	int j;
	char descripcionTipo[15];
	char descripcionEstado[15];

	if(arrayRecibido!=NULL&&arrayRecibidoDos!=NULL&&arrayRecibidoTres!=NULL)
	{
		for(i=0;i<tamanioArrayRecibido;i++)
		{
				if(arrayRecibido[i].estaVacio==0&&arrayRecibido[i].idEstadoRecaudacion==3&&arrayRecibido[i].importe>999)
				{
						printf("-------------------------RECAUDACIONES SALDADAS +1000-------------------------\n");
						printf("MES    TipoRecaudacion    EstadoRecaudacion   IMPORTE     ID RECAUDACION\n");
						sePuedeMostrar++;
						consigueTipoRecaudacion(arrayRecibidoDos,tamanioArrayRecibidoDos,arrayRecibido[i].tipoRecaudacion,descripcionTipo);
						consigueEstadoRecaudacion(arrayRecibidoTres,tamanioArrayRecibidoTres,arrayRecibido[i].idEstadoRecaudacion,descripcionEstado);
						printf("%-7d%-19s%-20s%-12.2f%d\n",arrayRecibido[i].mes,descripcionTipo,descripcionEstado,arrayRecibido[i].importe,arrayRecibido[i].idRecaudacion);
						for(j=0;j<tamanioArrayRecibidoCuatro;j++)
						{
								if(arrayRecibido[i].idContribuyente==arrayRecibidoCuatro[j].idContribuyente)
								{
										printf("Pertenecientes al contribuyente       NOMBRE         CUIL\n");
										printf("                                      %-15s%s\n",arrayRecibidoCuatro[j].nombre,arrayRecibidoCuatro[j].cuil);
										break;
								}
						}
				}
	  }

		if(sePuedeMostrar==0)
		{
			 printf("No existen recaudaciones saldadas que mostrar\n");
		}
		exito=1;
	}

	return exito;
}
