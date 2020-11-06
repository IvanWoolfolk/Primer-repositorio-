#include <stdio.h>
#include <stdlib.h>


/***********************************defines************************************/
void FILA_PRINT();
void COLUMNA_PRINT();
void imprimirSeparadorFilas();
void TABLERO_CUBIERTO();
MINES_POSITION(columna_scan,fila_scan,ARREGLO);

/***********************************defines************************************/
#define COLUMNAS 15
#define FILAS 15
#define VALID_DIFICULTY 3
#define MINAS_BASE 10
#define ASCII_PALO 124
#define ASCII_A 65
#define UNKNOWN_CAGE '#'
#define MINE '@'
#define MAX_RAND 3

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





void main(void)
{
    uint8 u8MINES_NEAR;
    uint8 columna_scan;
    uint8 fila_scan;
    uint8 u8DIFICULTAD=0;
    uint8 ARREGLO[FILAS][COLUMNAS];
    srand (time(NULL));
    printf("Buscaminas");
    printf("\nIngrese la dificultad          1)Facil     2)Normal     3)Dificil\nDIFICULTAD: ");
    scanf("%d",&u8DIFICULTAD);
    if(u8DIFICULTAD<=VALID_DIFICULTY)
    {
        uint8 u8MINES=((MINAS_BASE*u8DIFICULTAD));
        MINESinfo GAME1={u8MINES,u8MINES,0};
        printf("BUSCAMINAS, CANTIDAD DE MINAS %d\n",GAME1.u8TOTAL_MINAS);
        TABLERO_CUBIERTO(ARREGLO);      
        while(GAME1.u8TOTAL_MINAS!=0)   //llenado aleatoria listo
        {
            uint8 fila_aleatoria = 0+(rand()%(FILAS));
            uint8 columna_aleatoria = 0+(rand()%(COLUMNAS));             
            ARREGLO[fila_aleatoria][columna_aleatoria] = MINE;
            GAME1.u8TOTAL_MINAS=GAME1.u8TOTAL_MINAS-1;
        }
        
        COLUMNA_PRINT();
        FILA_PRINT(ARREGLO);
        printf("\nCUANTAS COLUMNAS SE DESEA DESPLAZAR: ");   //A=0 B=1(ejemplo, si quiere seleccionar la columna B que se desplaze 1 unidad)
        scanf("%d",&columna_scan);
        printf("COLUMNA SELECCIONADA: %c",columna_scan+ASCII_A);
        printf("\nCUANTAS FILAS SE DESEA DESPLAZAR: ");
        scanf("%d",&fila_scan);
        printf("FILA SELECCIONADA: %c",fila_scan+ASCII_A);

    }
    else
    {
        printf("\nOpción no valida");
    }

}

void COLUMNA_PRINT()
{
    uint8 FOR_VARIABLE;
    uint8 COLUMNA_VALUE=ASCII_A;
    printf("%c   ",ASCII_PALO);
    for (FOR_VARIABLE = 0; FOR_VARIABLE < COLUMNAS; FOR_VARIABLE++)
    {
        printf("%c %c ",ASCII_PALO,COLUMNA_VALUE+FOR_VARIABLE);
    }
    printf("%c COLUMNAS\n",ASCII_PALO);
    for (FOR_VARIABLE = 0; FOR_VARIABLE <= COLUMNAS; FOR_VARIABLE++)
    {
        printf("----");
    }
    printf("\n");
}

void FILA_PRINT(uint8 ARREGLO[FILAS][COLUMNAS]) 
{
    uint8 FOR_VARIABLE2;
    uint8 FOR_VARIABLE1;
    uint8 FILA_VALUE=ASCII_A;
    for (FOR_VARIABLE1 = 0; FOR_VARIABLE1 < FILAS; FOR_VARIABLE1++)
    {
        
        printf("%c %c %c",ASCII_PALO,FILA_VALUE+FOR_VARIABLE1,ASCII_PALO);
        for(FOR_VARIABLE2=0;FOR_VARIABLE2<COLUMNAS;FOR_VARIABLE2++)
        {
            printf(" %c %c",ARREGLO[FOR_VARIABLE1][FOR_VARIABLE2],ASCII_PALO);               
        }
        printf("\n");                                                                   
        printf("|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n"); 
    }
    printf("\n");
}

void TABLERO_CUBIERTO(uint8 ARREGLO[FILAS][COLUMNAS]) 
{
    uint8 FOR_VARIABLE1;
    int FOR_VARIABLE2;
    for (FOR_VARIABLE1 = 0; FOR_VARIABLE1 < FILAS; FOR_VARIABLE1++)
    {
        for (FOR_VARIABLE2 = 0; FOR_VARIABLE2 < COLUMNAS; FOR_VARIABLE2++) 
        {
            ARREGLO[FOR_VARIABLE1][FOR_VARIABLE2] = UNKNOWN_CAGE;
        }
    }
}

