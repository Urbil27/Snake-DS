/*-------------------------------------
rutinasAtencion.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"
#include "juego.h"

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
	if( ESTADO == JUGANDO && colorSerpiente==VERDE){
		if(ultimaTeclaPulsada == ARRIBA || ultimaTeclaPulsada == ABAJO){
			if(tecla == IZQUIERDA){
				BorrarCabezaAbajo(1,x,y);
				BorrarCabezaArriba(1,x,y);
				BorrarCabezaDer(1,x,y);
				MostrarCabezaIzq(1,x,y);
				ultimaTeclaPulsada = tecla;
			}
			if(tecla == DERECHA){
				BorrarCabezaAbajo(1,x,y);
				BorrarCabezaArriba(1,x,y);
				BorrarCabezaIzq(1,x,y);
				MostrarCabezaDer(1,x,y);
				ultimaTeclaPulsada = tecla;
			}
		}
		if(ultimaTeclaPulsada == IZQUIERDA || ultimaTeclaPulsada == DERECHA){
			if(tecla == ARRIBA){
				BorrarCabezaAbajo(1,x,y);
				BorrarCabezaDer(1,x,y);
				BorrarCabezaIzq(1,x,y);
				MostrarCabezaArriba(1,x,y);
				ultimaTeclaPulsada = tecla;
			}
			if(tecla == ABAJO){
				BorrarCabezaArriba(1,x,y);
				BorrarCabezaDer(1,x,y);
				BorrarCabezaIzq(1,x,y);
				MostrarCabezaAbajo(1,x,y);
				ultimaTeclaPulsada = tecla;
			}
		}
		
	
	}
	else if( ESTADO == JUGANDO && colorSerpiente==AZUL){
		if(ultimaTeclaPulsada == ARRIBA || ultimaTeclaPulsada == ABAJO){
			if(tecla == IZQUIERDA){
				BorrarCabezaAbajoAzul(1,x,y);
				BorrarCabezaArribaAzul(1,x,y);
				BorrarCabezaDerAzul(1,x,y);
				MostrarCabezaIzqAzul(1,x,y);
				ultimaTeclaPulsada = tecla;
			}
			if(tecla == DERECHA){
				BorrarCabezaAbajoAzul(1,x,y);
				BorrarCabezaArribaAzul(1,x,y);
				BorrarCabezaIzqAzul(1,x,y);
				MostrarCabezaDerAzul(1,x,y);
				ultimaTeclaPulsada = tecla;
			}
		}
		if(ultimaTeclaPulsada == IZQUIERDA || ultimaTeclaPulsada == DERECHA){
			if(tecla == ARRIBA){
				BorrarCabezaAbajoAzul(1,x,y);
				BorrarCabezaDerAzul(1,x,y);
				BorrarCabezaIzqAzul(1,x,y);
				MostrarCabezaArribaAzul(1,x,y);
				ultimaTeclaPulsada = tecla;
			}
			if(tecla == ABAJO){
				BorrarCabezaArribaAzul(1,x,y);
				BorrarCabezaDerAzul(1,x,y);
				BorrarCabezaIzqAzul(1,x,y);
				MostrarCabezaAbajoAzul(1,x,y);
				ultimaTeclaPulsada = tecla;
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
	
	actualizarPosicion(x,y);
}
	
}

void EstablecerVectorInt()
{
irqSet(IRQ_KEYS,RutAtencionTeclado);
irqSet(IRQ_TIMER0,RutAtencionTempo);
	
}

