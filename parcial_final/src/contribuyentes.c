#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "blu2021.h"
#include "contribuyentes.h"

int inicializarArrayContribuyente(eContribuyente arrayRecibido[],int tamanioArrayRecibido)
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

int cargaDatosContribuyente(eContribuyente arrayRecibido[],int posicion)
{
	int exito=0;
	char auxNombre[15];
	char auxApellido[15];
	char auxCuil[12];

	inicializarCadenaCaracteres(auxNombre,15);
	inicializarCadenaCaracteres(auxApellido,15);
	inicializarCadenaCaracteres(auxCuil,12);

	if(arrayRecibido!=NULL)
	{
		utn_levantaCadenaCaracteres(auxNombre,"Ingrese nombre contribuyente","Error,Reingrese nombre sin numeros",15);
		utn_levantaCadenaCaracteres(auxApellido,"Ingrese apellido contribuyente","Error,Reingrese lugar sin numeros",15);
		utn_levantaCuil(auxCuil,"Ingrese cuil","ERROR,reingrese cuil",12);
		strcpy(arrayRecibido[posicion].nombre,auxNombre);
		strcpy(arrayRecibido[posicion].apellido,auxApellido);
		strcpy(arrayRecibido[posicion].cuil,auxCuil);
		arrayRecibido[posicion].estaVacio=0;
		exito=1;
	}
	return exito;
}

int buscarLibreContribuyente(eContribuyente arrayRecibido[],int tamanioArrayRecibido)
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

int muestraContribuyentesCargados(eContribuyente arrayRecibido[],int tamanioArrayRecibido,eRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eTipoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eEstadoRecaudacion arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro)
{
	int i;
	int exito=0;
	int sePuedeMostrar=0;

	if(arrayRecibido!=NULL&&arrayRecibidoDos!=NULL&&arrayRecibidoTres!=NULL&&arrayRecibidoCuatro!=NULL)
	{
		exito=1;
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			if(arrayRecibido[i].estaVacio==0)
			{
				printf("--------------DATOS CONTRIBUYENTE----------------\n");
				printf("ID         NOMBRE       APELLIDO        CUIL\n");
				sePuedeMostrar++;
				muestraContribuyenteCargado(arrayRecibido[i]);
				muestraRecaudacionesContribuyente(arrayRecibidoDos,tamanioArrayRecibidoDos,arrayRecibidoTres,tamanioArrayRecibidoTres,arrayRecibidoCuatro,tamanioArrayRecibidoCuatro,arrayRecibido[i].idContribuyente);
			}
		}
		if(sePuedeMostrar==0)
		{
			printf("No hay datos cargados que mostrar\n\n");
			printf("Pulse cualquiera tecla para volver\n");
			fflush(stdin);
			getchar();
		}
		else
		{
			printf("Pulse cualquiera tecla para volver\n");
			fflush(stdin);
			getchar();
		}
	}
	return exito;
}

void muestraContribuyenteCargado(eContribuyente estructuraRecibida)
{
	printf("%-11d%-13s%-16s%s\n",estructuraRecibida.idContribuyente,estructuraRecibida.nombre,estructuraRecibida.apellido,estructuraRecibida.cuil);
}

void menuModificar(eContribuyente arrayRecibido[],int tamanioArrayRecibido)
{
	int idModificar;
	int idExistente=0;
	int campoModificar;
	int i;
	char auxNombre[15];
	char auxApellido[15];
	char auxCuil[12];

	printf("Bienvenido a Menu Modificar\n");
	printf("Ingrese id contribuyente a modificar\n");
	scanf("%d",&idModificar);
	for(i=0;i<tamanioArrayRecibido;i++)
	{
		if(idModificar==arrayRecibido[i].idContribuyente&&arrayRecibido[i].estaVacio==0)
		{
			idExistente=1;
			break;
		}
	}
	if(idExistente)
	{
		printf("?Que campo desea modificar?\n");
		printf("Nombre=1\nApellido=2\nCuil=3\n");
		scanf("%d",&campoModificar);
		while(campoModificar<1||campoModificar>3)
		{
			printf("ERROR,CAMPO INVALIDO ?Que campo desea modificar?\n");
			printf("Nombre=1\nApellido=2\nCuil=3\n");
			scanf("%d",&campoModificar);
		}
		switch(campoModificar)
		{
			case 1:
				utn_levantaCadenaCaracteres(auxNombre,"Reingrese nombre contribuyente","Error,Reingrese nombre sin numeros",15);
				strcpy(arrayRecibido[i].nombre,auxNombre);
			break;
			case 2:
				utn_levantaCadenaCaracteres(auxApellido,"Reingrese apellido contribuyente","Error,Reingrese apellido sin numeros",15);
				strcpy(arrayRecibido[i].apellido,auxApellido);
			break;
			case 3:
				utn_levantaCuil(auxCuil,"Reingrese cuil","ERROR,reingrese cuil",12);
				strcpy(arrayRecibido[i].cuil,auxCuil);
			break;
		}
	}
	else
	{
		printf("ERROR,usted no ha ingresado id valido, verifique y reingrese\n");
		printf("Pulse cualquiera tecla para volver\n");
		fflush(stdin);
		getchar();
	}
}

int bajaDatosContribuyente(eContribuyente arrayRecibido[],int tamanioArrayRecibido,eRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eTipoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eEstadoRecaudacion arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro)
{
	int exito=0;
	int opcionBaja;
	int contribuyenteBaja;
	int contribuyenteExistente=0;
	int i;

	if(arrayRecibido!=NULL&&arrayRecibidoDos!=NULL&&arrayRecibidoTres!=NULL&&arrayRecibidoCuatro!=NULL)
	{
		exito=1;
		printf("Ingrese idContribuyente a dar de baja\n");
		fflush(stdin);
		scanf("%d",&contribuyenteBaja);
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			if(contribuyenteBaja==arrayRecibido[i].idContribuyente&&arrayRecibido[i].estaVacio==0)
			{
				contribuyenteExistente=1;
				break;
			}
		}

		if(contribuyenteExistente)
		{
				printf("Usted dara de baja el id %d con las siguientes recaudaciones\n",contribuyenteBaja);
				muestraRecaudacionesContribuyente(arrayRecibidoDos,tamanioArrayRecibidoDos,arrayRecibidoTres,tamanioArrayRecibidoTres,arrayRecibidoCuatro,tamanioArrayRecibidoCuatro,contribuyenteBaja);
				printf("Presiones 1 para confirmar , 2 para cancelar\n");
				scanf("%d",&opcionBaja);
				while(opcionBaja!=1&&opcionBaja!=2)
				{
					printf("ERROR,ingrese opcion valida\n");
					fflush(stdin);
					scanf("%d",&opcionBaja);
				}
				if(opcionBaja==1)
				{
					arrayRecibido[i].estaVacio=1;
					for(i=0;i<tamanioArrayRecibidoDos;i++)
					{
							if(contribuyenteBaja==arrayRecibidoDos[i].idContribuyente)
							{
									arrayRecibidoDos[i].estaVacio=1;
							}
					}
					printf("Los datos se han dado de baja exitosamente\n");
					printf("Pulse cualquiera tecla para volver\n");
					fflush(stdin);
					getchar();
				}
		}
		else
		{
				printf("No hay datos cargados cuales dar de baja ? el id es invalido, verifique\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
		}
	}
	return exito;
}


int muestraContribuyentesCargadosSegunTipo(eContribuyente arrayRecibido[],int tamanioArrayRecibido,eRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eTipoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eEstadoRecaudacion arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro)
{
	int i;
	int exito=0;
	int sePuedeMostrar=0;
	int auxTipoRecaudacion;
	int idContribuyenteMostrar;
	int j;

	if(arrayRecibido!=NULL&&arrayRecibidoDos!=NULL&&arrayRecibidoTres!=NULL&&arrayRecibidoCuatro!=NULL)
	{
		exito=1;
		printf("Ingrese tipo recaudacion 1-ARBA\n"
			   " para contribuyenyes     2-IIBB\n"
			   "     a mostrar           3-GANANCIAS\n");
		fflush(stdin);
		scanf("%d",&auxTipoRecaudacion);
		while(auxTipoRecaudacion<1||auxTipoRecaudacion>3)
		{
			printf("ERROR,opcion inexistente\n");
			printf("Ingrese tipo recaudacion 1-ARBA\n"
				   " para contribuyentes     2-IIBB\n"
				   "     a mostrar           3-GANANCIAS\n");
			fflush(stdin);
			scanf("%d",&auxTipoRecaudacion);
		}
		for(i=0;i<tamanioArrayRecibidoDos;i++)
		{
			if(arrayRecibidoDos[i].estaVacio==0&&auxTipoRecaudacion==arrayRecibidoDos[i].tipoRecaudacion)
			{
				printf("--------------DATOS CONTRIBUYENTE----------------\n");
				printf("ID         NOMBRE       APELLIDO        CUIL\n");
				sePuedeMostrar++;
				idContribuyenteMostrar=arrayRecibidoDos[i].idContribuyente;
				for(j=0;j<tamanioArrayRecibido;j++)
				{
					if(arrayRecibido[j].idContribuyente==idContribuyenteMostrar)
					{
						break;
					}
				}
				muestraContribuyenteCargado(arrayRecibido[j]);
			}
		}

		if(sePuedeMostrar==0)
		{
			printf("No hay datos cargados que mostrar\n\n");
		}
	}
	return exito;
}

int muestraContribuyentesCargadosSegunEstadoRefinanciar(eContribuyente arrayRecibido[],int tamanioArrayRecibido,eRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eTipoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eEstadoRecaudacion arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro)
{
	int i;
	int exito=0;
	int sePuedeMostrar=0;
	int idContribuyenteMostrar;
	int j;

	if(arrayRecibido!=NULL&&arrayRecibidoDos!=NULL&&arrayRecibidoTres!=NULL&&arrayRecibidoCuatro!=NULL)
	{
		for(i=0;i<tamanioArrayRecibidoDos;i++)
		{
			if(arrayRecibidoDos[i].estaVacio==0&&arrayRecibidoDos[i].idEstadoRecaudacion==2)
			{
				printf("--------------DATOS CONTRIBUYENTE----------------\n");
				printf("ID         NOMBRE       APELLIDO        CUIL\n");
				sePuedeMostrar++;
				idContribuyenteMostrar=arrayRecibidoDos[i].idContribuyente;
				for(j=0;j<tamanioArrayRecibido;j++)
				{
					if(arrayRecibido[j].idContribuyente==idContribuyenteMostrar)
					{
						break;
					}
				}
				muestraContribuyenteCargado(arrayRecibido[j]);
				muestraRecaudacionesContribuyente(arrayRecibidoDos,tamanioArrayRecibidoDos,arrayRecibidoTres,tamanioArrayRecibidoTres,arrayRecibidoCuatro,tamanioArrayRecibidoCuatro,idContribuyenteMostrar);
			}
		}

		if(sePuedeMostrar==0)
		{
			printf("No hay datos cargados que mostrar\n\n");
		}
	}
	return exito;
}

int muestraContribuyenteMasRecaudaciones(eContribuyente arrayRecibido[],int tamUno,eRecaudacion arrayDos[],int tamDos)
{
	int exito=0;
	int i;
	int j;
	int contadorRecaudaciones;
	int banderaRecaudacion;
	int banderaMayor=1;
	int contadorMasRecaudaciones=0;
	int idContribuyenteMasRecaudaciones;

	for(i=0;i<tamUno;i++)
	{
		if(arrayRecibido[i].estaVacio==0)
		{
			contadorRecaudaciones=0;
			for(j=0;j<tamDos;j++)
			{
				if(arrayRecibido[i].idContribuyente==arrayDos[j].idContribuyente&&arrayDos[j].idEstadoRecaudacion==2)
				{
					contadorRecaudaciones++;
					banderaRecaudacion=1;
				}
			}
			if(banderaRecaudacion)
			{
				banderaRecaudacion=0;
				if(banderaMayor||contadorRecaudaciones>contadorMasRecaudaciones)
				{
					idContribuyenteMasRecaudaciones=arrayRecibido[i].idContribuyente;
					contadorMasRecaudaciones=contadorRecaudaciones;
					banderaMayor=0;
				}
		    }
	   }
	}
	if(contadorMasRecaudaciones)
	{
		printf("CONTRIBUYENTE CON MAS RECAUDACIONES A REFINANCIAR\n");
		printf("--------------DATOS CONTRIBUYENTE----------------\n");
		printf("ID         NOMBRE       APELLIDO        CUIL\n");
		muestraContribuyenteCargadoPorId(arrayRecibido,tamUno,idContribuyenteMasRecaudaciones);
	}
	else
	{
		printf("No hay contribuyente con recaudaciones a refinanciar cargado\n");
	}
	return exito;
}
void muestraContribuyenteCargadoPorId(eContribuyente arrayRecibido[],int tamUno,int idMostrar)
{
	int i;
	for(i=0;i<tamUno;i++)
	{
		if(arrayRecibido[i].idContribuyente==idMostrar)
		{
			printf("%-11d%-13s%-16s%s\n",arrayRecibido[i].idContribuyente,arrayRecibido[i].nombre,arrayRecibido[i].apellido,arrayRecibido[i].cuil);
		}
	}
}
