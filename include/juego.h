/*---------------------------------------------------------------------------------
juego.h
---------------------------------------------------------------------------------*/
extern int My;
extern int Mx;
extern int colorSerpiente;
void juego();
void actualizarPosicion(int x, int y);
void cargarSpriteFondoInicio();
void cargarFondoAzulInicio();
void generarMoneda();
bool chocado();
bool MonedaRecogida();
