#include "stdio.h"
#include "GENFUN.h"
#include <stdlib.h>
#include <time.h> 

//***********************Practica*********************************************//
void main(void)
{
    uint8 u8VALOR;
    uint8 u8Target=TARGET_VALUE;
    uint8 u8Char2Set;
    uint8 au8array[ARRAY_SIZE]="helloworld";
    
    //funcion 1
    printf("Funcion 1 *CapsOn* \n");
    printf("Original : %s\n",au8array);
    printf("After CapsOn: ");
    GENFUN_vCAPSON (&au8array[0], VALUE_ARRAY);
    printf("%s\n\n", au8array);
    
    //funcion 2
    printf("Funcion 2 *CapsOFF* \n");
    printf("Original : %s\n",au8array);
    printf("After CapsOFF: ");
    GENFUN_vCAPSOFF (&au8array[0], VALUE_ARRAY);
    printf("%s\n\n", au8array);
    
    //funcion 3
    printf("Funcion 3 *GetOccurence*\n");
    printf("Cadena a buscar : %s\n",au8array);
    printf("Letra a buscar : %c \n",u8Target);
    u8VALOR=GENFUN_u8GetOccurence (&au8array[0],u8Target,VALUE_ARRAY);
    printf("La letra se encontro %d veces\n\n", u8VALOR);
    
    //funcion 4
    printf("Funcion 4 *MemSet*\n");
    printf("Cadena a utilizar: %s\n",au8array);
    printf("Ingrese el caracter a utilizar: ");
    scanf("%c",&u8Char2Set);
    GENFUN_u8MemSet (&au8array[0], u8Char2Set,VALUE_ARRAY);
    printf("\nLa nueva cadena es %s",au8array);
    
    
}
                            
void GENFUN_vCAPSON (uint8 *pu8Src, uint8 u8SizeOFList)
{
    while(u8SizeOFList !=0)
    {               //96                             //123
        if(*pu8Src>ASCII_LOW_THRESHOLD_OFF_ON && *pu8Src<ASCII_HIGH_THRESHOLD_OFF_ON)
        {
            *pu8Src -= ASCII_CONVERTION_FACTOR;
        }
        else
        {
            /*nothing*/
        }
        pu8Src++;
        u8SizeOFList--;
    }
}

void GENFUN_vCAPSOFF (uint8 *pu8Src, uint8 u8SizeOFList)
{
    while(u8SizeOFList !=0)
    {              //96                                //123
        if(*pu8Src>ASCII_LOW_THRESHOLD_OFF_OFF && *pu8Src<ASCII_HIGH_THRESHOLD_OFF_OFF)
        {
            *pu8Src += ASCII_CONVERTION_FACTOR;
        }
        else
        {
            /*nothing*/
        }
        pu8Src++;
        u8SizeOFList--;
    }
}

uint8 GENFUN_u8GetOccurence (uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList )
{
    int u8Elements=0;
    while(u8SizeOfList!=0)
    {
        if(*pu8Src==u8Target)
        {
             u8Elements++;
        }
        else
        {
            //nothing to do
        }
    u8SizeOfList--;
    pu8Src++;
    }
    return u8Elements;
}

void GENFUN_u8MemSet (uint8 *pu8Src, uint8 u8Char2Set, uint8 u8SizeOfList)
{
    while(u8SizeOfList!=0)
    {
        *pu8Src=u8Char2Set; 
        pu8Src++;
        u8SizeOFList--;
    }

}