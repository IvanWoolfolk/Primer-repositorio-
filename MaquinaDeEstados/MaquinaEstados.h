/***********************************defines************************************/
void FILA_PRINT();
void COLUMNA_PRINT();
void imprimirSeparadorFilas();
void TABLERO_CUBIERTO();

/***********************************defines************************************/
#define APAGADO 0
#define TRAGO1 1
#define TRAGO2 2
#define TRAGO3 3
#define TRAGO4 4
#define TRAGO5 5
#define TRAGO6 6
#define TRAGO7 7
#define TRAGO8 8
#define TRAGO9 9

/*******************************typedefines************************************/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef enum
{
	idle = 0,
	enTequila,
	enTripleseco,
	enLimon,
	enRon,
	enGinebra,
	enWhisky,
	enTonica,
	enAguagas,
	enRonb,
	enVodka,
	enCafe,
	enVermut,
	enPina,
	enHielo,
	enCoco
}SM_NineStates;
