/***********************************defines************************************/
void FILA_PRINT();
void COLUMNA_PRINT();
void imprimirSeparadorFilas();
void TABLERO_CUBIERTO();

/***********************************defines************************************/
#define APAGADO 0
#define MOJITO 1
#define GINTONIC 2
#define CAIPIRINHA 3
#define PIÑACOLADA 4
#define ASCII_A 65
#define ASCII_BASE0 48
#define UNKNOWN_CAGE '#'
#define MINE '@'
#define MAX_RAND 3
#define TOTAL_CAGES 255

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
