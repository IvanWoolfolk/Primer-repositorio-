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
    
    //funcion 9
    printf("\n\n        Funcion FilterSignal \n");
    GENFUN_vFilterSignal(&au32arraynum[0],&au32arraynum2[0],MaxVal,MinVal);
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

void GENFUN_vFilterSignal (uint32 *pu32Src, uint32 *pu32Dest, uint32 u32MaxVal, uint32 u32MinVal) 
{
    uint8 indice = END_SOFT;
    uint8 indice2 = END_SOFT;
    uint8 o=0;
    printf("Se mostrara los valores almacenados aleatoriamente en el primer areglo con el limite menor de %d y el limite mayor de %d\n",u32MinVal,u32MaxVal);
    u32MaxVal--;
    while(indice!= 0)
    {
        *pu32Src = (u32MinVal) + (rand() % u32MaxVal);
        *pu32Dest=o;
        printf("  %d   ",*pu32Src);
        indice--;
        pu32Src++;
        pu32Dest++;
    }
    pu32Src=pu32Src-255;
    pu32Dest=pu32Dest-1;

    printf("\n Se guardaran los resultados en otra cadena distinta : \n");
    
    while(indice2 != 0)
    {
        o = *pu32Src;
        *pu32Dest=o;
        pu32Src++;
        pu32Dest++;
        printf("  %d   ",*pu32Dest );
        indice2--;
    }

}