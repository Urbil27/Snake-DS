/*---------------------------------------------------------------------------------
Este código se ha desarrollado basándose en el código de dovoto "Simple sprite demo" 
y en otro ejemplo de Jaeden Ameronen
---------------------------------------------------------------------------------*/


#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estándar de C
#include <stdlib.h>		//librería estándar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos

//librerías desarrolladas por nosotros para el proyecto
	
#include "definiciones.h"
#include "perifericos.h"
#include "rutinasAtencion.h"
#include "fondos.h"
#include "sprites.h"

int ESTADO;
int colorSerpiente = VERDE;
int tiempo;
int ultimaTeclaPulsada;
int x;
int y;
touchPosition pos_pantalla;
int My;
int Mx;
extern int numSprites = 0;
int  numMonedasRecogidas = 0;
void actualizarPosicion(){
	if(ultimaTeclaPulsada == ARRIBA){
		MostrarCabezaArriba(1,x,y);
	}
	if(ultimaTeclaPulsada == ABAJO){
		MostrarCabezaAbajo(1,x,y);
	}
	if(ultimaTeclaPulsada == IZQUIERDA){
		MostrarCabezaIzq(1,x,y);
	}
	if(ultimaTeclaPulsada == DERECHA){
		MostrarCabezaDer(1,x,y);
	}
}

void generarMoneda(){
	My = (rand() % 150)+15;
	Mx = (rand() % 187)+15;
	while(My == y && Mx == x){
		My = (rand() % 187)+8;
		Mx = (rand() % 187)+8;
	}
	//numSprites++;
	//iprintf("\x1b[17;5HX: %d",Mx);
	//iprintf("\x1b[18;5HY: %d",My);
	MostrarMoneda(2,Mx,My);
}

bool chocado(){
	if(y  == 0 || y == 191 || x == 0 || x == 255){
		iprintf("\x1b[15;5HChocado");

		return true;
	}
	iprintf("\x1b[15;5HNoChocado");
	return false;
}
bool MonedaRecogida(){
		if (My ==  y && Mx  ==  x){
			
			return true;
		} 
		return false;
}
void juego()
{	
	//definiciones de variables
	int i=9;
	int tecla=0;

	ESTADO=INICIO;
	
	//Escribe en la fila 22 columna 5 de la pantalla	
	//iprintf("\x1b[22;5HPrueba de escritura");						

	/* Si se quiere visualizar el valor de una variable escribir %d dentro de las comillas y el nombre de la variable fuera de las comillas */
	//iprintf("\x1b[23;5HPrueba de escritura con variable. Valor=%d", i);

	//*******************************EN LA 2.ACTIVIDAD ********************************//
        // LLAMADAS A REALIZAR:
	// Configurar el teclado.
	// Configurar el temporizador.
	// Establecer las rutinas de atención a interrupciones
	// Habilitar las interrupciones del teclado.
	// Habilitar las interrupciones del temporizador.
	// Habilitar interrupciones.
	//******************************************************************************//
	ConfigurarTeclado(0x40F0);
	ConfigurarTemporizador(55050,0xFFF9);//50 ticks

	//ConfigurarTemporizador(39321,0xFFFA);//5 ticks
	EstablecerVectorInt();
	HabilitarIntTeclado();
	HabilitarIntTempo();
	visualizarFondoInicioVerde();
	while(1)
	{	
		
      /*******************************EN LA 1.ACTIVIDAD*****************************************/
		/* Si el estado es ESPERA: codificar aquí la encuesta del teclado, sacar por pantalla la tecla que se ha pulsado, y si se pulsa ta la tecla START cambiar de estado */
		
		

		if(ESTADO == INICIO){
			
			PosTactil();
			
			if(TeclaDetectada()==1){
				tecla = TeclaPulsada();
			}
			if(tecla == START){
				visualizarFondoJuego();
				numMonedasRecogidas = 0;
				x = 127;
				y = 95;
				MostrarCabezaArriba(1,x,y);						
				generarMoneda();
				ESTADO = JUGANDO;
			}
		}
		
		if(ESTADO == JUGANDO){
			
			actualizarPosicion();
			if(numMonedasRecogidas < 15){
				ConfigurarTemporizador(55050,0xFFF9);//50 ticks
			}
			if(numMonedasRecogidas = 15){
				ConfigurarTemporizador(56003,0xFFF9);//55 ticks
			}
			if(numMonedasRecogidas = 30){
				ConfigurarTemporizador(56798,0xFFF9);//60 ticks
			}
			if(MonedaRecogida()){
				numMonedasRecogidas++;
				BorrarMoneda(2,Mx,My);
				generarMoneda();
			}
			if(chocado()){
				visualizarFondoGameOver();
				BorrarMoneda(2,Mx,My);
				BorrarCabezaArriba(1,x,y);
				BorrarCabezaAbajo(1,x,y);
				BorrarCabezaDer(1,x,y);
				BorrarCabezaIzq(1,x,y);
				ESTADO = FINAL;
			}
		}
		if(ESTADO  == FINAL){
			if(TeclaDetectada()==1){
				iprintf("\x1b[10;5HTecla: %d",tecla);

				tecla = TeclaPulsada();
			}
			if(tecla == START){
				ESTADO = JUGANDO;
				visualizarFondoJuego();
				numMonedasRecogidas = 0;
				x = 127;
				y = 95;
				MostrarCabezaArriba(1,60,60);						
				generarMoneda();
			}
			if(tecla ==  SELECT){
				visualizarFondoInicioVerde();
				if(colorSerpiente==VERDE){
					visualizarFondoInicioVerde();
				}
				else if(colorSerpiente==AZUL){
					visualizarFondoInicioAzul();
				}
				ESTADO = INICIO;
			}
		}	
	}
} 	

