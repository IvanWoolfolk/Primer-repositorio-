#include <stdio.h>
/*DATA TYPES*/

typedef unsigned char uint8;
typedef unsigned char uint16;

/*Definitions*/
#define VALUE_NULL 0
#define ARRAY_TEST_VALID {1,9,2,3,4,5,6,4,8,9,1,1,8,4,3,6}
#define ARRAY_TEST_INVALID {1,9,2,3,4,5,6,4,8,9,1,1,8,4,5,6}
#define ARRAY_SIZE 16
#define CONDITION_2 2
#define CONDITION_10 10
#define CONDITION_9 9


/*Function Prototypes*/
uint8 u8LuhnCheck(uint8 *pu8Data);

void main(void)
{
    uint8 au8CardNumber[ARRAY_SIZE]=ARRAY_TEST_VALID;
    uint8 u8Check=VALUE_NULL;
    u8Check = u8LuhnCheck(&au8CardNumber[VALUE_NULL]);
    if(u8Check==VALUE_NULL)
    {
        printf("Numero de tarjeta valida");
    }
    else
    {
        printf("Numero de tarjeta NO valida");
    }
}

uint8 u8LuhnCheck(uint8 *pu8Data)
{
    uint8 u8LISTA=ARRAY_SIZE;
    uint16 u16SUMA=VALUE_NULL;
    uint8 u8VALUE=VALUE_NULL;
    while(u8LISTA!=VALUE_NULL)
    {
        u8VALUE=*pu8Data;
        if(*pu8Data%CONDITION_2==VALUE_NULL)
        {
            u8VALUE=(*pu8Data)*CONDITION_2;
            if(u8VALUE>=CONDITION_10)
            {
                u8VALUE=u8VALUE - CONDITION_9;
            }
            else
            {
                /*nothing to do*/
            }
        }
        u16SUMA+=u8VALUE;
        pu8Data++;
        u8LISTA--;
        u16SUMA=u16SUMA%CONDITION_10;
    }
    return u16SUMA;
}
    