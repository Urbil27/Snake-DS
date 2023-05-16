extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;
extern u16* gfxMoneda;
extern u16* gfxCabezaDer;
extern u16* gfxCabezaIzq;
extern u16* gfxCabezaArriba;
extern u16* gfxCabezaAbajo;
extern u16* gfxCuerpo;
extern void memoriaReserva();

/* Para cada uno de los 256 valores que puede tomar un Pixel le da un color en la pantalla principal. El valor 0 es transparente y los valores sin definir negros */
extern void EstablecerPaletaPrincipal();


/* Para cada uno de los 256 valores que puede tomar un Pixel le da un color en la pantalla secundaria. El valor 0 es transparente y los valores sin definir negros */
extern void EstablecerPaletaSecundaria();


/* Carga en memoria los Sprites dibujados.*/
extern void GuardarSpritesMemoria();


/* Esta función dibuja un rombo en la posición de pantalla x-y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126. */
extern void MostrarMoneda(int indice, int x, int y);
extern void MostrarCuerpo(int indice, int x, int y);
extern void MostrarCabezaArriba(int indice, int x, int y);
extern void MostrarCabezaAbajo(int indice, int x, int y);
extern void MostrarCabezaDer(int indice, int x, int y);
extern void MostrarCabezaIzq(int indice, int x, int y);

/*Esta función borra de la pantalla el rombo con el índice que se le indique como parámetro */
extern void BorrarMoneda(int indice, int x, int y);
extern void BorrarCuerpo(int indice, int x, int y);
extern void BorrarCabezaArriba(int indice, int x, int y);
extern void BorrarCabezaAbajo(int indice, int x, int y);
extern void BorrarCabezaDer(int indice, int x, int y);
extern void BorrarCabezaIzq(int indice, int x, int y);


