#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "blu2021.h"
//LEVANTADORES
int utn_levantaEnteros(int* resultado,char* mensaje,char* mensajeError,int min,int max)
{
	int aux;
	int exito=0;
	int tipoValidado;

	if(resultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&min<=max)
	{
		do{
			printf("%s\n",mensaje);
			fflush(stdin);
			tipoValidado=scanf("%d",&aux);
			if(aux<min||aux>max||tipoValidado==0)
			{
				printf("%s\n",mensajeError);
				exito=0;
			}
			else
			{
				*resultado=aux;
				exito=1;
				break;
			}
		}while(exito==0);
	}
	return exito;
}

int utn_levantaCadenaCaracteres(char cadena[],char* mensaje,char* mensajeError,int largoCadena)
{
	int exito=0;
	int i;
	char auxCadena[largoCadena];

	inicializarCadenaCaracteres(auxCadena,largoCadena);

	if(cadena!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&largoCadena>0)
	{
		while(exito==0)
		{
			printf("%s\n",mensaje);
			fflush(stdin);
			if(fgets(auxCadena,largoCadena,stdin)!=NULL)
			{
				exito=1;
				auxCadena[strcspn(auxCadena,"\n")]=0;
				for(i=0;i<largoCadena;i++)
				{
					if(isdigit(auxCadena[i]))
					{
						exito=0;
						break;
					}
				}
				strcpy(cadena,auxCadena);
			}
			else
			{
				printf("%s\n",mensajeError);
			}
		}
	}
	return exito;
}

int utn_levantaCuil(char cadena[],char* mensaje,char* mensajeError,int largoCadena)
{
	int exito=0;
	int i;
	char auxCadena[largoCadena];
	int contador=largoCadena-1;

	inicializarCadenaCaracteres(auxCadena,largoCadena);

	if(cadena!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&largoCadena>0)
	{
		while(exito==0)
		{
			printf("%s\n",mensaje);
			fflush(stdin);
			if(fgets(auxCadena,largoCadena,stdin)!=NULL)
			{
				exito=1;
				for(i=0;i<largoCadena-1;i++)
				{
					if(isdigit(auxCadena[i]))
					{
						contador--;
					}
				}
				if(contador==0)
				{
					auxCadena[strcspn(auxCadena,"\n")]=0;
					strcpy(cadena,auxCadena);
				}
				else
				{
					exito=0;
					break;
				}
			}
			else
			{
				printf("%s\n",mensajeError);
			}
		}
	}
	return exito;
}
//INICIALIZADORES
int inicializarCadenaCaracteres(char cadenaRecibida[],int largoCadena)
{
	int exito=0;
	int i;
	if(cadenaRecibida!=NULL)
	{
		for(i=0;i<largoCadena;i++)
		{
			cadenaRecibida[i]=' ';
		}
		exito=1;
	}
	return exito;
}
//PAUSA/VUELTA ATRAS EN MENU
void vueltaAtras()
{
	printf("Pulse cualquiera tecla para volver\n");
	fflush(stdin);
	getchar();
}


