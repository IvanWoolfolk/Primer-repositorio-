#include <stdio.h>
#include "Define.h"

void main ( void )
{
	uint8 au8CardNumber[ArraySize] = ARRAY_EXAMPLE_VALID;
	uint8 u8Check=0;
	u8Check = u8LuhnCheck(&au8CardNumber[0]);

	if( u8Check == 0)
	{
		printf("\nEl número de tarjeta es valido");
	}
	else
	{
		printf("\nEl número de tarjeta es invalido");
	}
}

uint8 u8LuhnCheck	(uint8 *pu8Data)
{
	uint8 u8NEW_VALUE=0;
	uint16 u16RESULTADO_SUM=0;
	uint8 u8LIST_SIZE=ArraySize;
	
	printf("El número de tarjeta es:");

	while(u8LIST_SIZE != 0)
	{
		u8NEW_VALUE = *pu8Data;
		//printf("%d",pu8Data);//
		printf("%d",*pu8Data);

			if(u8LIST_SIZE % MOD_2 == 0)
			{
				u8NEW_VALUE=(*pu8Data)*MOD_2;

					if(u8NEW_VALUE>=MAX_NUM10)
					{
						u8NEW_VALUE = u8NEW_VALUE-OPERACION_MOD;
					}
					else
					{
						//Nothing to do//
					}
			}

			else 
			{
				//Nothing to do//
			}

		u16RESULTADO_SUM+=u8NEW_VALUE;
		pu8Data++;
		u8LIST_SIZE--;
		u16RESULTADO_SUM = u16RESULTADO_SUM % MAX_NUM10;
	}

	return u16RESULTADO_SUM;
}

