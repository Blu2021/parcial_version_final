#ifndef CONTRIBUYENTES_H_
#define CONTRIBUYENTES_H_
typedef struct
{
	char nombre[15];
	char apellido[15];
	char cuil[12];
	int idContribuyente;
	int estaVacio;
}eContribuyente;
#include "recaudaciones.h"
/*
 * @Brief inicializarArrayContribuyente modifica todos los estaVacio de un arrayEstructuras para indicar su disponibilidad.
 * @param recibe por puntero el array de estructuras y su dimension.
 * @return retorna 1 en caso de que haya validado que el puntero se recibio correctamente.
 *         retorna 0 en caso contrario.
 */
int inicializarArrayContribuyente(eContribuyente arrayRecibido[],int tamanioArrayRecibido);
/*
 * @Brief cargaDatosContribuyente solicita los datos para cargar en los campos de un array de contribuyentes, ademas
 * modifica el estaVacio una vez tomados los datos para indicar que la estructura esta en uso.
 * @param recibe por puntero el array de estructuras y su dimension.
 * @return retorna 1 en caso de que haya validado que el puntero se recibio correctamente.
 *         retorna 0 en caso contrario.
 */
int cargaDatosContribuyente(eContribuyente arrayRecibido[],int posicion);
/*
 * @Brief buscarLibreContribuyente busca la disponibilidad que indican los "estaVacio" en array de contribuyentes.
 * @param recibe por puntero el array de estructuras y su dimension.
 * @return retorna distinto de -1 si confirma que el puntero se recibio correctamente y a su vez si encontro lugar disponible.
 *         retorna -1 en cualquiera de los 2 casos contrarios.
 */
int buscarLibreContribuyente(eContribuyente arrayRecibido[],int tamanioArrayRecibido);
/*
 * @Brief menuModificar permite alterar datos que hayan sido cargados previamente en una estructura de contribuyentes.
 * @param recibe por puntero el array de estructuras y su dimension.
 * @return no tiene retorno.
 */
void menuModificar(eContribuyente arrayRecibido[],int tamanioArrayRecibido);
/*
 * @Brief muestraContribuyenteCargado trabaja en conjunto con su plural , recibe una posicion de la estructura especifica
 * y muestra los datos de esta mediante un printf.
 * @param recibe por parametro actual una estructura especifica de contribuyentes.
 * @return no tiene retorno
 */
void muestraContribuyenteCargado(eContribuyente estructuraRecibida);
/*
 * @Brief muestraContribuyentesCargados muestra todos los contribuyentes cargados junto con sus recaudaciones adjudicadas
 * trabaja en conjunto con muestraContribuyenteCargado.
 * @param recibe por puntero el array de estructuras contribuyente , recaudaciones, tipoRecaudaciones y estadoRecaudaciones,
 * junto a sus respectivas dimensiones.
 * @return retorna 1 en caso de que haya validado que los punteros se recibieron correctamente.
 *         retorna 0 en caso contrario.
 */
int muestraContribuyentesCargados(eContribuyente arrayRecibido[],int tamanioArrayRecibido,eRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eTipoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eEstadoRecaudacion arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro);
/*
 * @Brief bajaDatosContribuyente solicita un id de contribuyente a dar de baja ,verifica que este mismo exista luego pide
 * confirmacion de la baja mediante un submenu diminuto , y en caso afirmativo modifica el estaVacio de la estructura en
 * cuestion , como tambien el de todas las recaudaciones ligadas al id ingresado.
 * @param recibe por puntero el array de estructuras contribuyente , recaudaciones, tipoRecaudaciones y estadoRecaudaciones,
 * junto a sus respectivas dimensiones
 * @return retorna 1 en caso de que haya validado que los punteros se recibieron correctamente.
 *         retorna 0 en caso contrario.
 */
int bajaDatosContribuyente(eContribuyente arrayRecibido[],int tamanioArrayRecibido,eRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eTipoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eEstadoRecaudacion arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro);
int muestraContribuyentesCargadosSegunTipo(eContribuyente arrayRecibido[],int tamanioArrayRecibido,eRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eTipoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eEstadoRecaudacion arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro);
int muestraContribuyentesCargadosSegunEstadoRefinanciar(eContribuyente arrayRecibido[],int tamanioArrayRecibido,eRecaudacion arrayRecibidoDos[],int tamanioArrayRecibidoDos,eTipoRecaudacion arrayRecibidoTres[],int tamanioArrayRecibidoTres,eEstadoRecaudacion arrayRecibidoCuatro[],int tamanioArrayRecibidoCuatro);
void muestraContribuyenteCargadoPorId(eContribuyente arrayRecibido[],int tamUno,int idMostrar);
int muestraContribuyenteMasRecaudaciones(eContribuyente arrayRecibido[],int tamUno,eRecaudacion arrayDos[],int tamDos);

#endif /* CONTRIBUYENTES_H_ */
