#include "stdio.h"
#include "time.h"

typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned long  uint32;

#define TIME_MAX 25


typedef enum
{
	enBOMBA_A = 0,
	enBOMBA_B,
	enBOMBA_C,
	enEJECUCION
}SM_configurar;