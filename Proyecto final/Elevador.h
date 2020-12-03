#include "stdio.h"
#include <time.h>
#include <stdlib.h>
/***********************************Func************************************/


/***********************************defines************************************/
#define APAGADO 0
#define MAX_PEOPLE 6
#define END_REQUEST 16

/*******************************typedefines************************************/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef enum
{
	enLobby = 0,
	enPiso1,
	enPiso2,
	enPiso3,
	enPiso4,
	enPiso5,
	enPiso6,
	enPiso7,
	enPiso8,
	enPiso9,
	enPiso10
}SM_States;

