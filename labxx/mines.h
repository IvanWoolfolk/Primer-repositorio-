/***********************************defines************************************/
void FILA_PRINT();
void COLUMNA_PRINT();
void imprimirSeparadorFilas();
void TABLERO_CUBIERTO();

/***********************************defines************************************/
#define COLUMNAS 15
#define FILAS 15
#define VALID_DIFICULTY 3
#define MINAS_BASE 10
#define ASCII_PALO 124
#define ASCII_A 65
#define ASCII_BASE0 48
#define UNKNOWN_CAGE '#'
#define MINE '@'
#define MAX_RAND 3
#define TOTAL_CAGES 255
int MINES_CARRY= 0;
/*******************************typedefines************************************/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct
{
	unsigned int u8TOTAL_MINAS;
	unsigned int u8MINAS_FALTANTES;
	uint8 u8MINAS_DESCUBIERTAS;
}MINESinfo;