/*---------------------------------------------------------------------------------
Código desarrollado basado en el ejemplo "Simple sprite demo" de dovoto y en otro de Jaeden Amero.
---------------------------------------------------------------------------------*/

#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

#include "sprites.h"
#include "definiciones.h"

u16* gfxMoneda;
u16* gfxCabezaDer;
u16* gfxCabezaIzq;
u16* gfxCabezaArriba;
u16* gfxCabezaAbajo;
u16* gfxCuerpo;


	
/* Reservar memoria para cada sprite que se quiera mostrar en pantalla */
void memoriaReserva()
{
	/* Por cada sprite que se quiera incluir en la pantalla principal hay que hacer algo equivalente a lo que sigue */
	gfxMoneda= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxCabezaDer= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxCabezaIzq= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxCabezaAbajo= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxCabezaArriba= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxCuerpo= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

	//gfxromboGrande=oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
}

/* A cada uno de los 256 valores que puede tomar un pixel en la PALETA PRINCIPAL
   se le puede asignar un color. El valor 0 es transparente. Los valores sin definir son negros. 
   MODIFICAR SEGÚN LOS COLORES QUE QUERAIS UTILIZAR EN VUESTROS SPRITES */
void EstablecerPaletaPrincipal() {

	SPRITE_PALETTE[1] = RGB15(31,0,0); // los píxeles con valor 1 serán de color rojo.
	SPRITE_PALETTE[2] = RGB15(31,31,0); // los píxeles con valor 2 serán verdes.
	SPRITE_PALETTE[3] = RGB15(31,31,31); // los píxeles con valor 3 serán Blanco.
	SPRITE_PALETTE[4] = RGB15(0,31,0); // los píxeles con valor 4 serán Verde fosforito.
	SPRITE_PALETTE[6] = RGB15(0,0,0); // los píxeles con valor 6 serán negro.
	SPRITE_PALETTE[8] = RGB15(31,0,31); // los píxeles con valor 6 serán negro.
	SPRITE_PALETTE[14] = RGB15(25,0,0); // los píxeles con valor 14 serán Granate.
	SPRITE_PALETTE[15] = RGB15(16,0,16);
	SPRITE_PALETTE[17] = RGB15(31,19,25);
	SPRITE_PALETTE[23] = RGB15(19,31,19); // los píxeles con valor 23 serán verde claro.
	SPRITE_PALETTE[21] = RGB15(0,12,0); // los píxeles con valor 21 serán verde oscuro.
}

/* definición de un sprite de 16x16 píxeles para dibujar un rombo */
/* Por la forma que tienen de trabajar los bancos de memoria, la imagen del sprite se divide en bloques de 8x8 píxeles. Los primeros 64 (8x8) píxeles que indicamos
aparecerán en el cuadrante superior izquierdo de la imagen del sprite, los siguientes 64 en el cuadrante superior derecho, los siguientes en el cuadrante inferior izquierdo y los
últimos en el cuadrante inferior derecho */

u8 moneda[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	8	,	8	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	8	,	15	,	15	,	0	,	0	,	0	,	0	,	0	,	8	,	15	,	15	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	8	,	15	,	15	,	17	,	0	,	0	,	0	,	0	,	8	,	15	,	15	,	17	,	 //	0	0	0	0	0	0	8	8	8	8	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	8	15	15	15	15	8	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	8	,	8	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	8	15	15	15	15	8	0	0	0	0	0
15	,	15	,	8	,	0	,	0	,	0	,	0	,	0	,	15	,	15	,	8	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	8	15	15	17	17	15	15	8	0	0	0	0
17	,	15	,	15	,	8	,	0	,	0	,	0	,	0	,	15	,	15	,	15	,	8	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	8	15	15	17	15	15	15	8	0	0	0	0
0	,	0	,	0	,	0	,	8	,	15	,	15	,	17	,	0	,	0	,	0	,	0	,	8	,	15	,	15	,	17	,	 //	0	0	0	0	8	15	15	17	15	15	15	8	0	0	0	0
0	,	0	,	0	,	0	,	0	,	8	,	15	,	15	,	0	,	0	,	0	,	0	,	0	,	8	,	15	,	15	,	 //	0	0	0	0	8	15	15	17	17	15	15	8	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	8	,	8	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	8	15	15	15	15	8	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	8	15	15	15	15	8	0	0	0	0	0
15	,	15	,	15	,	8	,	0	,	0	,	0	,	0	,	17	,	15	,	15	,	8	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	8	8	8	8	0	0	0	0	0	0
15	,	15	,	8	,	0	,	0	,	0	,	0	,	0	,	15	,	15	,	8	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
8	,	8	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0

};
u8 cabezaDer[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	2	,	2	,	// 	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	// 	0	0	0	0	0	0	2	2	2	2	0	0	0	0	0	0
0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	0	0	0	2	2	2	2	2	2	2	2	0	0	0	0
0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	0	0	2	2	2	2	2	2	2	2	2	2	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	2	,	2	,	0	,	0	,	0	,	0	,	0	,	0	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
2	,	2	,	2	,	2	,	0	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
0	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
0	,	0	,	0	,	0	,	0	,	0	,	2	,	2	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	// 	0	0	0	2	2	2	2	2	2	2	2	2	2	0	0	0
2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	// 	0	0	0	0	2	2	2	2	2	2	2	2	0	0	0	0
2	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	0	,	// 	0	0	0	0	0	0	2	2	2	2	0	0	0	0	0	0
2	,	2	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	// 	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
};
u8 cabezaIzq[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	2	,	2	,	// 	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	// 	0	0	0	0	0	0	2	2	2	2	0	0	0	0	0	0
0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	0	0	0	2	2	2	2	2	2	2	2	0	0	0	0
0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	0	0	2	2	2	2	2	2	2	2	2	2	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	2	,	2	,	0	,	0	,	0	,	0	,	0	,	0	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
2	,	2	,	2	,	2	,	0	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
0	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
0	,	0	,	0	,	0	,	0	,	0	,	2	,	2	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	// 	0	0	0	2	2	2	2	2	2	2	2	2	2	0	0	0
2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	// 	0	0	0	0	2	2	2	2	2	2	2	2	0	0	0	0
2	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	0	,	// 	0	0	0	0	0	0	2	2	2	2	0	0	0	0	0	0
2	,	2	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	// 	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
};
u8 cabezaArriba[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	2	,	2	,	// 	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	// 	0	0	0	0	0	0	2	2	2	2	0	0	0	0	0	0
0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	0	0	0	2	2	2	2	2	2	2	2	0	0	0	0
0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	0	0	2	2	2	2	2	2	2	2	2	2	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	2	,	2	,	0	,	0	,	0	,	0	,	0	,	0	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
2	,	2	,	2	,	2	,	0	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
0	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
0	,	0	,	0	,	0	,	0	,	0	,	2	,	2	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	// 	0	0	0	2	2	2	2	2	2	2	2	2	2	0	0	0
2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	// 	0	0	0	0	2	2	2	2	2	2	2	2	0	0	0	0
2	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	0	,	// 	0	0	0	0	0	0	2	2	2	2	0	0	0	0	0	0
2	,	2	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	// 	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
};
u8 cabezaAbajo[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	21	,	21	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	21	,	4	,	4	,	0	,	0	,	0	,	0	,	21	,	4	,	4	,	4	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	21	,	4	,	23	,	23	,	0	,	0	,	0	,	0	,	21	,	4	,	1	,	23	,	 //	0	0	0	0	0	0	21	21	21	21	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	21	4	4	4	4	21	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	21	,	21	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	21	4	4	4	4	4	4	21	0	0	0	0
4	,	4	,	21	,	0	,	0	,	0	,	0	,	0	,	4	,	4	,	4	,	21	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	21	4	23	23	23	23	4	21	0	0	0	0
23	,	23	,	4	,	21	,	0	,	0	,	0	,	0	,	23	,	1	,	4	,	21	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	21	4	1	23	23	1	4	21	0	0	0	0
0	,	0	,	0	,	0	,	21	,	4	,	4	,	4	,	0	,	0	,	0	,	0	,	21	,	4	,	4	,	4	,	 //	0	0	0	0	21	4	4	4	4	4	4	21	0	0	0	0
0	,	0	,	0	,	0	,	0	,	21	,	4	,	1	,	0	,	0	,	0	,	0	,	0	,	0	,	21	,	1	,	 //	0	0	0	0	21	4	4	4	4	4	4	21	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	21	4	1	1	4	21	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	21	1	1	21	0	0	0	0	0	0
4	,	4	,	4	,	21	,	0	,	0	,	0	,	0	,	4	,	4	,	4	,	21	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	1	1	0	0	0	0	0	0	0
1	,	4	,	21	,	0	,	0	,	0	,	0	,	0	,	1	,	21	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
1	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0

};
u8 cuerpo[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	2	,	2	,	// 	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	// 	0	0	0	0	0	0	2	2	2	2	0	0	0	0	0	0
0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	0	0	0	2	2	2	2	2	2	2	2	0	0	0	0
0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	0	0	2	2	2	2	2	2	2	2	2	2	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	2	,	2	,	0	,	0	,	0	,	0	,	0	,	0	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
2	,	2	,	2	,	2	,	0	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	// 	0	2	2	2	2	2	2	2	2	2	2	2	2	2	2	0
0	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
0	,	0	,	0	,	0	,	0	,	0	,	2	,	2	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	// 	0	0	2	2	2	2	2	2	2	2	2	2	2	2	0	0
2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	// 	0	0	0	2	2	2	2	2	2	2	2	2	2	0	0	0
2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	2	,	2	,	2	,	2	,	2	,	2	,	0	,	0	,	// 	0	0	0	0	2	2	2	2	2	2	2	2	0	0	0	0
2	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	0	,	0	,	0	,	0	,	// 	0	0	0	0	0	0	2	2	2	2	0	0	0	0	0	0
2	,	2	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	// 	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
};

/* Carga en memoria cada uno de los sprites que hemos dibujado */

void GuardarSpritesMemoria(){ 
	
int i;
	//sprite de 16*16
	for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxMoneda[i] = moneda[i*2] | (moneda[(i*2)+1]<<8);				
	}
		for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxCuerpo[i] = cuerpo[i*2] | (cuerpo[(i*2)+1]<<8);				
	}
		for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxCabezaDer[i] = cabezaDer[i*2] | (cabezaDer[(i*2)+1]<<8);				
	}
		for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxCabezaIzq[i] = cabezaIzq[i*2] | (cabezaIzq[(i*2)+1]<<8);				
	}
		for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxCabezaAbajo[i] = cabezaAbajo[i*2] | (cabezaAbajo[(i*2)+1]<<8);				
	}
		for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxCabezaArriba[i] = cabezaArriba[i*2] | (cabezaArriba[(i*2)+1]<<8);				
	}
	
	//sprite de 32x32
	/*for(i = 0; i < 32 * 32 / 2; i++) 
	{	
		gfxromboGrande[i] = romboGrande[i*2] | (romboGrande[(i*2)+1]<<8);				
	}
	*/
}

/* Esta función dibuja un rombo en la posición x-y de pantalla. A cada rombo que se quiera mostrar en pantalla se le debe asignar un índice distinto, un valor entre 0 y 126 */

extern void MostrarMoneda(int indice, int x, int y)
{ 
 		
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxMoneda,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función borra de la pantalla el Rombo con el índice indicado */
void BorrarMoneda(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxMoneda,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}
void MostrarCuerpo(int indice, int x, int y)
{ 
 		
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxCuerpo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función borra de la pantalla el Rombo con el índice indicado */
void BorrarCuerpo(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxCuerpo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}
void MostrarCabezaArriba(int indice, int x, int y)
{ 
 		
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxCabezaArriba,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función borra de la pantalla el Rombo con el índice indicado */
void BorrarCabezaArriba(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxCabezaArriba,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}
void MostrarCabezaAbajo(int indice, int x, int y)
{ 
 		
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxCabezaAbajo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función borra de la pantalla el Rombo con el índice indicado */
void BorrarCabezaAbajo(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxCabezaAbajo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}
void MostrarCabezaIzq(int indice, int x, int y)
{ 
 		
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxCabezaIzq,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función borra de la pantalla el Rombo con el índice indicado */
void BorrarCabezaIzq(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxCabezaIzq,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}
void MostrarCabezaDer(int indice, int x, int y)
{ 
 		
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxCabezaDer,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función borra de la pantalla el Rombo con el índice indicado */
void BorrarCabezaDer(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxCabezaDer,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}
