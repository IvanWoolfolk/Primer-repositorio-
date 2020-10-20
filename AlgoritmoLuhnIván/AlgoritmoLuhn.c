#include <stdio.h>
#include "Define.h"

uint8 u8LuhnCheck (uint8 *pu8Data );

void main ( void )
{
	uint8 au8CardNumber[ArraySize] = {5,8,8,8,1,4,1,9,0,8,8,8,8,8,8,5};
	uint8 u8Check=0;

	u8Check = u8LuhnCheck(&au8CardNumber[0]);

	if( u8Check == 0)
	{
		printf("Si");
	}
	else
	{
		printf("El número de tarjeta no es válido");
	}
}

uint8 u8LuhnCheck (uint8 *pu8Data)
{
	uint8 u8NEW_VALUE=0;
	uint16 u16RESULTADO_SUM=0;
	uint8 u8LIST_SIZE=ArraySize;

	while(u8NEW_VALUE != 0)
	{
		u8NEW_VALUE=*pu8Data;

			if(*pu8Data % MOD == 0)
			{
				u8NEW_VALUE=(*pu8Data)*MOD;

					if(u8NEW_VALUE>MAX_MOD)
					{
						u8NEW_VALUE = u8NEW_VALUE+(u8NEW_VALUE % MOD);
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
			u16RESULTADO_SUM = u16RESULTADO_SUM % MOD_VALIDEZ;
	}

	return u16RESULTADO_SUM;
}

