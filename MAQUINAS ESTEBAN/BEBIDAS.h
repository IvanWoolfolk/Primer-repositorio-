/********typedefines**********/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

/******colors_defines********/
#define INIT_DRINKNS_VALUE {250,750,250,1500,700,750,700,1000,700}
#define MEDIA_ONZA 15
#define ONZAyMEDIA 50
#define CUATRO_ONZA 115
#define OCHO_ONZA 250
#define MAX_VODKA 700
#define MAX_MINERAL 1000
#define MAX_COCA 1500
#define MAX_ZUMO 250
#define MAX_RON 750
#define bebidatimes 200
#define ANALYS 9
#define DRINKS_WARNING 1


void delay(int number_of_seconds);
void INTERVALO();

typedef enum
{
	enLIMON = 0,
	enRON,
	enNARANJA,
	enCOCA,
	enWHISKY,
	enGINEBRA,
	enTEQUILA,
	enAGUA,
	enVODKA
}SM_tenStates;

typedef struct
{
	uint8 u8ZUMO_LIMON;                 //200ml
	uint16 u16RON;                      //650ml
	uint8 u8ZUMO_NARANJA;               //250ml
	uint16 u16COCA_COLA;                //1500ml
	uint16 u16WHISKY;                   //700ml
	uint16 u16GINEBRA;                  //750ml
	uint16 u16TEQUILA;                  //700ml
	uint16 u16AGUA_MINERAL;             //1000ml
	uint16 u16VODKA;                    //700ml
}DRINKS_INFO;

DRINKS_INFO DRINKS_ml = INIT_DRINKNS_VALUE;