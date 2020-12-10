#include "stdio.h"
#include <time.h>
#include <stdlib.h>
/***********************************Func************************************/


/***********************************defines************************************/
#define MAX_PEOPLE 4
#define END_REQUEST 5
#define NO_REQUEST_1 16
#define NO_REQUEST_2 17
#define NO_REQUEST_3 18
#define NO_REQUEST_4 19

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

