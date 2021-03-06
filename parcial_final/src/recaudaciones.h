#ifndef RECAUDACIONES_H_
#define RECAUDACIONES_H_
typedef struct
{
	int idContribuyente;
	int mes;
	int tipoRecaudacion;
	float importe;
	int idRecaudacion;
	int idEstadoRecaudacion;
	int estaVacio;
}eRecaudacion;

typedef struct
{
	int idTipoRecaudacion;
	char tipoRecaudacion[15];
	int estaVacio;
}eTipoRecaudacion;

typedef struct
{
	int idEstadoRecaudacion;
	char estadoRecaudacion[15];
	int estaVacio;
}eEstadoRecaudacion;
#include "contribuyentes.h"
/*
 * @Brief inicializarArrayRecaudacion modifica todos los estaVacio de un arrayEstructuras para indicar su disponibilidad.
 * @param recibe por puntero el array de estructuras y su dimension.
 * @return retorna 1 en caso de que haya validado que el puntero se recibio correctamente.
 *         retorna 0 en caso contrario.
 */
int inicializarArrayRecaudacion(eRecaudacion arrayRecibido[],int tamanioArrayRecibido);
/*
 * @Brief buscarLibreRecaudacion busca la disponibilidad que indican los "estaVacio" en array de recaudaciones.
 * @param recibe por puntero el array de estructuras y su dimension.
 * @return retorna distinto de -1 si confirma que el puntero se recibio correctamente y a su vez si encontro lugar disponible.
 *         retorna -1 en cualquiera de los 2 casos contrarios.
 */
int buscarLibreRecaudacion(eRecaudacion arrayRecibido[],int tamanioArrayRecibido);
/*
 * @Brief muestraRecaudacionesContribuyente muestra todas las recaudaciones que tiene cargadas un contribuyente en especifico.
 * @param recibe por puntero los array de estructuras recaudaciones , estadoRecaudaciones y tipoRecaudaciones, ademas de
 * el valor de un id contribuyente el cual verifica antes de ejecutar el muestreo.
 * @return retorna 1 en caso de que haya verificado que los punteros se recibieron correctamente.
 *         retorna 0 en caso contrario.
 */
int muestraRecaudacionesContribuyente(eRecaudacion arrayRecibido[],int tamanioArrayRecibido,eTipoRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eEstadoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,int idContribuyente);
/*
 * @Brief consigueTipoRecaudacion actua como intermediario entre un id de la estructura recaudaciones y un id de misma
 * caracteristica y valor de la estructura tipoRecaudaciones , verificando la igualdad de los mismos devuelve por puntero
 * char la descripcion del tipo.
 * @param recibe por puntero el array tipoRecaudacion y su dimension ,una cadena de caracteres por puntero para devolver
 * la descripcion, ademas de el tipo de recaudacion que va a buscar en valor numerico , este ultimo fue verificado
 * por la funcion muestraRecaudacionesContribuyente.
 * @return no tiene retorno.
 */
void consigueTipoRecaudacion(eTipoRecaudacion arrayRecibido[],int tamanioArrayRecibido,int tipoRecaudacion,char tipo[]);
/*
 * @Brief consigueEstadoRecaudacion actua como intermediario entre un id de la estructura recaudaciones y un id de misma
 * caracteristica y valor de la estructura estadoRecaudaciones , verificando la igualdad de los mismos devuelve por puntero
 * char la descripcion del estado.
 * @param recibe por puntero el array estadoRecaudacion y su dimension ,una cadena de caracteres por puntero para devolver
 * la descripcion, ademas de el estado de recaudacion que va a buscar en valor numerico , este ultimo fue verificado
 * por la funcion muestraRecaudacionesContribuyente.
 * @return no tiene retorno.
 */
void consigueEstadoRecaudacion(eEstadoRecaudacion arrayRecibido[],int tamanioArrayRecibido,int estadoRecaudacion,char tipo[]);
/*
 * @Brief muestraRecaudacionesPorId solicita un id de recaudacion , verifique que este sea existente y luego imprime los
 * datos del contribuyente al que pertenece , muestra un submenu de opciones para confirmar el estado al cual se quiere
 * cambiar la recaudacion y confirmado el mismo modifica el valor del id estado al nuevo seleccionado.
 * @param recibe por puntero el array estadoRecaudacion y su dimension, el array contribuyente y su dimension , este ultimo
 * en vista de comparar los datos del id recaudativo identificado como existente y buscar el contribuyente al cual pertenece
 * con el codigo id que ambas estructuras comparten.
 * @return retorna 1 en caso de que haya verificado que los punteros se recibieron correctamente.
 *         retorna 0 en caso contrario.
 */
int muestraRecaudacionesPorId(eRecaudacion arrayRecibido[],int tamUno,eContribuyente arrayRecibidoDos[],int tamDos);
/*
 * @Brief muestraRecaudacionesSaldadas imprime todas las recaudaciones con estado "saldadas" existentes.
 * @param recibe por puntero el array recaudaciones , su dimension, el de tipo recaudaciones , su dimension ,el de estado
 * recaudaciones, su dimension y el de contribuyentes junto a su dimension. Precisa recibir todos los nombrados para
 * poder obtener el tipo y estado al mostrar las recaudaciones saldadas ,y para acceder a los datos del contribuyente y
 * asi mostrarlo identificandolo mediante el id en comun que comparte con la recaudacion.
 * @return retorna 1 en caso de que haya verificado que los punteros se recibieron correctamente.
 *         retorna 0 en caso contrario.
 */
int muestraRecaudacionesSaldadas(eRecaudacion arrayRecibido[],int tamanioArrayRecibido,eTipoRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eEstadoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eContribuyente arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro);
/*
 * @Brief cargaDatosRecaudacion solicita los datos para cargar en los campos de un array de recaudaciones, ademas
 * modifica el estaVacio una vez tomados los datos para indicar que la estructura esta en uso. Solicita un id del
 * contribuyente al cual asignarle la recaudacion y busca congruencia existente entre estos.
 * @param recibe por puntero el array de estructuras recaudacion y una posicion libre en este la cual fue encontrada
 * por otra funcion, ademas recibe el array de contribuyentes y su dimension para asi asegurar la existencia del
 * contribuyente al cual se le asignara la recaudacion cargada.
 * @return retorna 1 en caso de que haya validado que los punteros se recibieron correctamente y a su vez que haya logrado
 * cargar los datos con exito.
 * 		   retorna 0 en cualquiera de los 2 casos contrarios.
 */
int cargaDatosRecaudacion(eRecaudacion arrayRecibido[],int posicion,eContribuyente arrayRecibidoDos[],int tamanioArrayRecibidoDos);
int muestraRecaudacionesSaldadasMasMil(eRecaudacion arrayRecibido[],int tamanioArrayRecibido,eTipoRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eEstadoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eContribuyente arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro);
int muestraRecaudacionesFebrero(eRecaudacion arrayRecibido[],int tamanioArrayRecibido,eTipoRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eEstadoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eContribuyente arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro);
#endif /* RECAUDACIONES_H_*/
