/*-------------------------------------
definiciones.h
-------------------------------------*/
#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estandar de C
#include <stdlib.h>		//librería estandar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos


#define IME		(*(vuint32*)0x04000208) //Interrupt Master Enable -- Habilitar-deshabilitar todas las interrupciones
#define IE		(*(vuint32*)0x04000210) //Interrupt Enable -- Habilitar-deshabilitar las interrupciones de forma individual
#define IF		(*(vuint32*)0x04000214) //Interrupt Flag -- Registro de solicitud de interrupción

// funciones para el tratamiento general de las interrupciones
#define HabilitarInterrupciones() IME=1 //Habilitar todas las interrupciones
#define DeshabilitarInterrrupciones() IME=0 //Deshabilitar todas las interrupciones

//registros del teclado
#define TECLAS_DAT	(*(vu16*)0x4000130) //registro de datos del teclado
#define TECLAS_CNT	(*(vu16*)0x4000132) //registro de control del teclado

//registros del temporizador Timer0
#define TIMER0_CNT   (*(vuint16*)0x04000102) //registro de control del temporizador
#define TIMER0_DAT    (*(vuint16*)0x04000100) //registro de datos del temporizador



//Acceso a los registros de la pantalla táctil
touchPosition PANT_DAT;

// Nombres asignados a las teclas para facilitar la comprensión de nuestro código
#define VERDE 0
#define AZUL 1
#define A			0 
#define B			1
#define SELECT			2 
#define START			3
#define DERECHA		4 
#define IZQUIERDA		5
#define ARRIBA			6 
#define ABAJO			7
#define R			8 
#define L			9

//Nombres asignados a los estados
#define INICIO 0
#define JUGANDO 1
#define FINAL 2

extern int ESTADO;

