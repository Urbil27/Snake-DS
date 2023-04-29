/*-------------------------------------
rutinasAtencion.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"

int ESTADO;
int seg3;
int ultimaTeclaPulsada;
int x;
int y;
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
				mostrarCabezaIzq(indice,x,y)
				ultimaTeclaPulsada = tecla;
			}
			if(tecla == DERECHA){
				mostrarCabezaDcha(indice,x,y)
				ultimaTeclaPulsada = tecla;
			}
		}
		if(ultimaTeclaPulsada == IZQUIERDA || ultimaTeclaPulsada == DERECHA){
			if(tecla == ARRIBA){
				mostrarCabezaArriba(indice,x,y);
				ultimaTeclaPulsada = tecla;
			}
			if(tecla == ABAJO){
				mostrarCabezaAbajo(indice,x,y);
				ultimaTeclaPulsada = tecla;
			}
		}
		
	
	}
}

void RutAtencionTempo()
{
if(ESTADO == JUGANDO){
	if(ultimaTeclaPulsada == ARRIBA){

	}
	if(ultimaTeclaPulsada == ABAJO){
		
	}
	if(ultimaTeclaPulsada == DERECHA){
		
	}
	if(ultimaTeclaPulsada == IZQUIERDA){
		
	}
}
	
}

void EstablecerVectorInt()
{
irqSet(IRQ_KEYS,RutAtencionTeclado);
irqSet(IRQ_TIMER0,RutAtencionTempo);
	
}
