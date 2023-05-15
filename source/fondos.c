
#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

/* Si queremos visualizar distintos fondos, aquí se debe incluir el fichero de cabecera (fichero .h) de cada fondo. Estos ficheros de cabecera se generan automáticamente durante la compilación. */
#include "FondoGameOver.h"
#include "FondoInicioAzul.h"
#include "FondoInicioVerde.h"
#include "FondoJuego.h"
#include "fondos.h"
#include "graficos.h"


/* Se elige el canal de DMA que se utilizará para copiar las imágenes en memoria.*/

static const int DMA_CHANNEL = 3;

/* Para cada fondo que se quiera visualizar hay que escribir un procedimiento como el siguiente */

void visualizarFondoInicioVerde() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     FondoInicioVerdeBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     FondoInicioVerdeBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarFondoInicioAzul() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     FondoInicioAzulBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     FondoInicioAzulBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}
void visualizarFondoGameOver() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     FondoGameOverBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     FondoGameOverBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}
void visualizarFondoJuego() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     FondoJuegoBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     FondoJuegoBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}