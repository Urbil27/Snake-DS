/*-------------------------------------
rutinasAtencion.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"

int seg3;
int ultimaTeclaPulsada = ARRIBA;
extern int x;
extern int y;
void RutAtencionTeclado ()
{
/*if (ESTADO == CERRADA)
{	
	if (TeclaPulsada()==A)
	{
		ESTADO=ABIERTA;
		visualizarPuertaAbierta();
		seg3=0;
		MostrarRombo(1, 5, 5);
		MostrarRomboGrande(2, 100, 100);
	}
}*/
	int tecla;
	tecla = TeclaPulsada();
	if( ESTADO == JUGANDO){
		if(ultimaTeclaPulsada == ARRIBA || ultimaTeclaPulsada == ABAJO){
			if(tecla == IZQUIERDA){
				BorrarCabezaAbajo(1,x,y);
				BorrarCabezaArriba(1,x,y);
				BorrarCabezaDer(1,x,y);
				MostrarCabezaIzq(1,x,y);
				ultimaTeclaPulsada = tecla;
				iprintf("\x1b[20;5HTecla: %d",tecla);
			}
			if(tecla == DERECHA){
				BorrarCabezaAbajo(1,x,y);
				BorrarCabezaArriba(1,x,y);
				BorrarCabezaIzq(1,x,y);
				MostrarCabezaDer(1,x,y);
				ultimaTeclaPulsada = tecla;
				iprintf("\x1b[20;5HTecla: %d",tecla);
			}
		}
		if(ultimaTeclaPulsada == IZQUIERDA || ultimaTeclaPulsada == DERECHA){
			if(tecla == ARRIBA){
				BorrarCabezaAbajo(1,x,y);
				BorrarCabezaDer(1,x,y);
				BorrarCabezaIzq(1,x,y);
				MostrarCabezaArriba(1,x,y);
				ultimaTeclaPulsada = tecla;
				iprintf("\x1b[20;5HTecla: %d",tecla);
			}
			if(tecla == ABAJO){
				BorrarCabezaArriba(1,x,y);
				BorrarCabezaDer(1,x,y);
				BorrarCabezaIzq(1,x,y);
				MostrarCabezaAbajo(1,x,y);
				ultimaTeclaPulsada = tecla;
				iprintf("\x1b[20;5HTecla: %d",tecla);
			}
		}
		
	
	}
}

void RutAtencionTempo()
{
if(ESTADO == JUGANDO){
	if(ultimaTeclaPulsada == ARRIBA){
		y = y - 1;

	}
	if(ultimaTeclaPulsada == ABAJO){
		y = y + 1;
	}
	if(ultimaTeclaPulsada == DERECHA){
		x = x + 1;
	}
	if(ultimaTeclaPulsada == IZQUIERDA){
		x = x - 1;
	}
	//iprintf("\x1b[19;5HX: %d",x);
	//iprintf("\x1b[20;5HY: %d",y);
	actualizarPosicion(x,y);
}
	
}

void EstablecerVectorInt()
{
irqSet(IRQ_KEYS,RutAtencionTeclado);
irqSet(IRQ_TIMER0,RutAtencionTempo);
	
}

