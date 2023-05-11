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

int tiempo;
touchPosition pos_pantalla;
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

	void actualizarPosicion(int x, int y){
	
	}
	boolean MonedaRecogida(){
		
	}


	while(1)
	{	
		
      /*******************************EN LA 1.ACTIVIDAD*****************************************/
		/* Si el estado es ESPERA: codificar aquí la encuesta del teclado, sacar por pantalla la tecla que se ha pulsado, y si se pulsa ta la tecla START cambiar de estado */
		
		

		if(ESTADO == INICIO){
			MostrarFondoInicio();
			if(PosTactil.py >=32 && PosTactil.py<= 64){ 
				if (PosTactil.px >=31 && PosTactil.px<= 95){//Pulsacion flecha izquierda
					ColorAnterior();
				}
				if (PosTactil.px >=158 && PosTactil.px<= 222){//Pulsacion flecha Derecha
					SiguienteColor();
				}

				}
			if(TeclaDetectada()==1){
				tecla = TeclaPulsada();
			}
			if(tecla == START){
				ESTADO = JUGANDO;
				MostrarFondoJuego();
				int puntos = 0;
				ConfigurarTemporizador(55050,)//55 ticks: 56003 60 ticks: 56798
			}
			/*
			if(tecla != 0){
			}
			*/
		}

	}
}



