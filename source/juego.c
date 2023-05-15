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
int colorSerpiente = VERDE;
int cuerpos[][3] = { {0,0,0},
					 {1,8,0},
					 {2,16,0}};
int tiempo;
int x;
int y;
touchPosition pos_pantalla;
int My;
int Mx;
extern int numSprites = 0;
int  numMonedasRecogidas = 0;
void actualizarPosicion(int x, int y){
	
	}
void cargarSpriteFondoInicio(){

}
void cargarFondoAzulInicio(){
	
}
void generarMoneda(){
	int My = (rand() % 187)+8;
	int Mx = (rand() % 187)+8;
	while(My == y && Mx == x){
		My = (rand() % 187)+8;
		Mx = (rand() % 187)+8;
	}
	numSprites++;
	MostrarMoneda(numSprites,Mx,My);
}

bool chocado(){
	if(y  == 0 || y == 191 || x == 0 || x == 255){
		return true;
	}
	return false;
}
bool MonedaRecogida(){
		if (My ==  y && Mx  ==  x){
			BorrarMoneda(numSprites);
			generarMoneda();
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
	iprintf("\x1b[22;5HPrueba de escritura");						

/* Si se quiere visualizar el valor de una variable escribir %d dentro de las comillas y el nombre de la variable fuera de las comillas */
	iprintf("\x1b[23;5HPrueba de escritura con variable. Valor=%d", i);

	//*******************************EN LA 2.ACTIVIDAD ********************************//
        // LLAMADAS A REALIZAR:
	// Configurar el teclado.
	// Configurar el temporizador.
	// Establecer las rutinas de atención a interrupciones
	// Habilitar las interrupciones del teclado.
	// Habilitar las interrupciones del temporizador.
	// Habilitar interrupciones.
	//******************************************************************************//
	ConfigurarTeclado(0x400F);
	ConfigurarTemporizador(55050,0xFFF9);
	EstablecerVectorInt();
	HabilitarIntTeclado();
	HabilitarIntTempo();
-
	while(1)
	{	
		
      /*******************************EN LA 1.ACTIVIDAD*****************************************/
		/* Si el estado es ESPERA: codificar aquí la encuesta del teclado, sacar por pantalla la tecla que se ha pulsado, y si se pulsa ta la tecla START cambiar de estado */
		
		

		if(ESTADO == INICIO){
			visualizarFondoInicioVerde();
			if(PosTactil.py >=90 && PosTactil.py<= 145){ 
				if (PosTactil.px >=0 && PosTactil.px<= 120){//Pulsacion flecha izquierda
					if(colorSerpiente == VERDE){
						visualizarFondoInicioAzul();
						colorSerpiente = AZUL;
					}
					if(colorSerpiente == AZUL){
						visualizarFondoInicioVerde();
						colorSerpiente = VERDE;
					}
				}
				if (PosTactil.px >=130 && PosTactil.px<= 255){//Pulsacion flecha Derecha
					if(colorSerpiente == VERDE){
						visualizarFondoInicioAzul();
						colorSerpiente = AZUL;
					}
					if(colorSerpiente == AZUL){
						visualizarFondoInicioVerde();
						colorSerpiente = VERDE;
					}
				}
				}

				}
			if(TeclaDetectada()==1){
				tecla = TeclaPulsada();
			}
			if(tecla == START){
				ESTADO = JUGANDO;
				numMonedasRecogidas = 0;
				x = 127;
				y = 95;
			}
			/*
			if(tecla != 0){
			}
			*/
		}
		if(ESTADO == JUGANDO){
			MostrarFondoJuego();
			if(numMonedasRecogidas < 15){
				ConfigurarTemporizador(55050,64)//50 ticks
			}
			if(numMonedasRecogidas = 15){
				ConfigurarTemporizador(56003,64)//55 ticks
			}
			if(numMonedasRecogidas = 30){
				ConfigurarTemporizador(56798,64)//60 ticks
			}
			
			MostrarCabezaArriba(numSprites,x,y)
			generarMoneda();
			if(MonedaRecogida()){
				numMonedasRecogidas++;
			}
			if(chocado()){
				mostrarFondoFinal();
				BorrarMoneda(numSprites);
				numSprites--;
				BorrarCabezaArriba(numSprites);
				BorrarCabezaAbajo(numSprites);
				BorrarCabezaDer(numSprites);
				BorrarCabezaIzq(numSprites);
				numSprites--;
				ESTADO = FINAL;
			}
		}
		if(ESTADO  == FINAL){
			if(TeclaDetectada()==1){
				tecla = TeclaPulsada();
			}
			if(tecla == START){
				ESTADO = JUGANDO;
				numMonedasRecogidas = 0;
				x = 127;
				y = 95;
			}
			if(tecla ==  SELECT){
				mostrarFondoInicial();
				if(colorSerpiente==VERDE){
					cargarFondoVerdeInicio();
				}
				else if(colorSerpiente==AZUL){
					cargarFondoAzulInicio();
				}
				ESTADO = INICIO;
			}
		}

	}
}



