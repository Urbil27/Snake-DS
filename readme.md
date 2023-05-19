**MEMORIA DEL PROYECTO DE LA NINTENDO DS**

Urbil Melín, Jon Merquelanz y David Murguialday

# Índice {#índice .TOC-Heading}

[1.- INTRODUCCIÓN [3](#introducción)](#introducción)

[2.- DESARROLLO [4](#desarrollo)](#desarrollo)

[2.1.- Problemas surgidos [5](#problemas-surgidos)](#problemas-surgidos)

[2.2.- Herramientas usadas
[6](#herramientas-usadas)](#herramientas-usadas)

[3.- ESTRUCTURA DEL CÓDIGO
[7](#estructura-del-código)](#estructura-del-código)

[4.- CONCLUSIONES [9](#conclusiones)](#conclusiones)

# 1.- INTRODUCCIÓN

El proyecto se planteó para ayudar a los alumnos a entender mejor los
conceptos tratados en clase, el subsistema de entrada y salida. Para
ello, teníamos unos requisitos mínimos como al menos una tecla
sincronizada por encuesta, dos por interrupción, además del uso de la
pantalla táctil y un temporizador.

Nosotros nos hemos decantado por hacer el Snake para la Nintendo DS,
dónde utilizamos las teclas de las crucetas por interrupción para mover
la serpiente por la pantalla, las teclas START y SELECT por encuesta,
también utilizamos la pantalla táctil en el inicio, para seleccionar el
color de la serpiente, y finalmente utilizamos un temporizador, por
interrupción, donde lo utilizamos para controlar la velocidad de
movimiento de la serpiente a lo largo del juego.

# 2.- DESARROLLO

Como bien hemos dicho antes, hemos realizado el juego Snake.

Tal y como se muestra en el autómata entregado anteriormente, el juego
contiene 3 estados distintos. El estado de INICIO, donde se espera a que
el jugador pulse la tecla START para cambiar al estado de JUGANDO.
Además de ello, el jugador pulsando la pantalla podrá elegir de qué
color quiere que sea su serpiente, verde o azul, todo ello a través de
la función posTactil(), definida en perifericos.c

Una vez estemos en el estado de JUGANDO, el jugador deberá manejar la
serpiente utilizando las crucetas e intentar recoger las monedas. Cada
vez que el jugador recoja una moneda, se sumará un punto a su puntuación
y se generará de nuevo una moneda en coordenadas aleatorias. Conforme el
jugador vaya aumentando su puntuación, la velocidad de la serpiente irá
aumentando, para así complicarlo más. Si el jugador se choca con los
bordes de la pantalla, perderá y se cambiará al estado FINAL.

En el estado FINAL, el jugador podrá decidir si vuelve al estado de
INICIO pulsando la tecla SELECT o volver a jugar directamente pulsando
la tecla START.

## 2.1.- Problemas surgidos

A lo largo de un desarrollo de un proyecto suelen surgir diferentes
problemas y errores los cuales plantean retos importantes al equipo que
está trabajando en el proyecto.

Nosotros hemos tenido los siguientes problemas:

-   **Pantalla táctil:**

> Ha sido uno de los mayores problemas que hemos tenido, tanto es así
> que no hemos podido darle una solución por completo.
>
> El problema era el siguiente, nosotros tenemos una pantalla para
> elegir el color de la serpiente la cual se controla mediante la
> pantalla táctil de la Nintendo DS.
>
> Al tocar la pantalla de la Nintendo esto se ejecutaba múltiples veces
> y el color en el que siempre terminaba era en el verde.
>
> Esto era porque teníamos dos ifs uno detrás de otro en el que en el
> primero poníamos la variable del color de la serpiente en azul y en el
> siguiente comprobábamos que, si estaba en azul y la volvíamos a poner
> en verde, sin tener en cuenta de que al salir de un if se entraba en
> el otro, anulando así el cambio que habíamos hecho en el primero.
>
> Ahora hemos solucionado este problema, pero a la hora de mantener
> presionada la pantalla táctil sigue cambiando de manera constante
> entre verde y azul.

-   **Teclado:**

El problema que teníamos con el teclado es que no estábamos habilitando
las interrupciones de teclado correctamente, por lo que las teclas que
funcionan por encuesta funcionaban correctamente, pero las que funcionan
por interrupción no, ya que no estábamos habilitando el bit 12 del IE.

-   **Modificador extern:**

El modificador extern es una de las cosas que al principio no
entendíamos correctamente, ya que creíamos que ese modificador lo
teníamos que usar para acceder a una variable que no estaba en ese mismo
archivo, y es justo al contrario.

El modificador extern ha de utilizarse al declarar una variable que debe
poder accederse desde cualquier fichero del programa.

## 2.2.- Herramientas usadas

Para la realización de un proyecto, consideramos importante la elección
de buenas herramientas que ayuden al equipo a desarrollar las
funcionalidades que hay que desarrollar con eficacia y seguridad, para
ello hemos hecho uso de las siguientes herramientas:

-   **Visual Studio Code**

Es un editor de código multilenguaje y de código abierto desarrollado
por Microsoft el cual nos ha ayudado a programar ya que cuenta con las
siguientes funcionalidades:

-   Cerrado automático de llaves, paréntesis, etc.

-   Navegación fluida por el código

> Al hacer Ctrl + clic sobre una llamada a una función o variable te
> lleva a donde esté siendo declarada esa función o variable.

-   **GitHub**

Es una herramienta muy útil en cualquier proyecto de desarrollo de
software con muchas funcionalidades interesantes para desarrollar en
equipo, pero nosotros lo hemos utilizado simplemente como repositorio de
código a donde ir subiendo el código que vamos generando, para tener una
copia de seguridad y para que el profesorado tenga acceso al todo el
código para así poder solucionarnos las dudas de una manera más eficaz.

-   **Devkit Pro**

> Devkit Pro es el compilador de C que hemos utilizado. Es un compilador
> el cual sirve para compilar código C para diferentes dispositivos que
> hagan uso de chips con arquitectura ARM (En nuestro caso la Nintendo
> DS tiene un procesador ARM9 y un ARM7) por lo que es el que el
> profesorado ha decidido instalar en el entorno que nos han facilitado.

-   **Virtual Box**

Virtual Box es un software hipervisor de máquinas virtuales con el cual
hemos ejecutado el entorno que nos ha facilitado el profesorado con
todas las herramientas necesarias para el desarrollo del juego para la
Nintendo DS.

-   **Entorno facilitado por el profesorado**

El entorno facilitado por el profesorado consistía en una máquina
virtual Ubuntu en la cual estaba preinstalado el software para compilar
el proyecto y ciertos emuladores para hacer más fácil probar el proyecto
en el ordenador sin tener que pasarlo a una Nintendo DS real con el
coste de tiempo que eso supondría.

# 3.- ESTRUCTURA DEL CÓDIGO

La estructura básica que hemos utilizado es la facilitada por el
profesorado.

Esta cuenta con tres directorios principales, estos son los siguientes:

-   **Gfx**

Es el directorio en el que han de almacenarse los fondos utilizados en
el proyecto y sus correspondientes archivos ".grit" para que estos
fondos sean reconocidos por el código.

-   **Include**

En este directorio han sido almacenados los ficheros .h del proyecto,
estos ficheros sirven para declarar variables globales y para indicarle
a C que funciones y variables tienen que poder ser accedidas desde otros
archivos.

Para importar estos archivos en un archivo .c utilizamos la sentencia
#include "archivo.h".

-   **Source**

En este directorio como indica su propio nombre se almacena el código
fuente del proyecto, es en este directorio donde están los ficheros en
los que están escritas todas las operaciones aritméticas y lógicas que
hacen funcionar a nuestro proyecto.

Este directorio cuenta con los siguientes siete archivos principales:

-   ***Fondos.c***

> Es donde definimos las funciones para visualizar los diferentes fondos
> de nuestro proyecto.

-   ***Graficos.c***

> En este archivo es donde inicializamos todo lo necesario para poder
> mostrar cualquier tipo de gráfico por pantalla, es decir tanto sprites
> como fondos.

-   ***Juego.c***

> Es el archivo más importante del proyecto, es donde tenemos
> prácticamente toda la lógica, donde cambiamos los estados, donde
> actualizamos las variables como "numMonedasRecogidas", donde
> configuramos el temporizador, generamos las monedas, visualizamos los
> diferentes fondos, etc.

-   ***Main.c***

> Es el fichero principal del proyecto, desde el cual se inicia todo, su
> función se limita a llamar a tres funciones:

-   *inicializarGraficosSprites()*

> Esta función se encuentra en el fichero Graficos.c y lo que hace es
> iniciar los gráficos, los fondos, guardar los sprites en memoria,
> reservar memoria para cada uno de los sprites, establecer la paleta de
> colores que va a ser usada por los sprites e inicializar la memoria de
> los sprites.

-   *HabilitarInterrupciones()*

> Esta función lo único que hace es poner el IME(Interrupt Master
> Enable) a 1 y con lo cual habilitar las interrupciones.

-   *Juego()*

> Esta función se encarga de ejecutar el juego como tal el cual cuenta
> con un while(1) para estar ejecutándose de manera constante y hacer
> las operaciones pertinentes para que el juego funcione.

-   ***Periféricos.c***

> En este archivo tenemos las funciones que sirven para configurar todos
> los periféricos que hemos usado en el proyecto, tales como el
> temporizador, teclas, pantalla táctil etc.
>
> En la mayoría de estas funciones no contamos con ninguna lógica aparte
> de configurar los diferentes periféricos, pero en la función
> PosTactil() contamos con lógica para cambiar el color de la serpiente
> y para cambiar el fondo que mostramos por pantalla.

-   ***rutinasAtencion.c***

> En este archivo como indica su nombre tenemos las diferentes rutinas
> de atención de los periféricos que funcionan por interrupción en las
> cuales se realizan las operaciones pertinentes que hay que realizar
> cuando un periferico en concreto realice una interrupción.

-   ***sprites.c***

> Es donde tenemos guardados los sprites que utilizamos en el proyecto,
> también es donde definimos la paleta de colores y las diferentes
> funciones para poder mostrar y borrar los sprites en el punto de la
> pantalla donde haga falta mostrarlos.

# 4.- CONCLUSIONES

Mediante este proyecto hemos podido poner en practica los conocimientos
adquiridos gracias a las clases teóricas sobre todo del apartado del
subsistema de entrada y salida.

También hemos dado un primer paso en el aprendizaje de un lenguaje que
desconocíamos casi por completo con el reto que eso ha supuesto.

Hemos tenido que probar mucho, leer mucha información en los apuntes de
egela, buscar información en internet y leer foros como StackOverflow
para solucionar errores que no entendíamos en un primer instante.

Para finalizar esta conclusión tenemos que decir también que nos ha
servido para desarrollar "*Soft Skills*" como el trabajo en equipo que
hemos podido desarrollar con eficacia ya que en un inicio a cada miembro
del equipo se nos daban bien hacer cosas distintas, entonces lo que
hemos hecho es cada uno se centraba en lo que sabia y después se le
explicaba al resto del equipo como lo había hecho y porque,
transfiriendo así el conocimiento entre miembros del grupo y obteniendo
todos un entendimiento mas global del proyecto entero.
