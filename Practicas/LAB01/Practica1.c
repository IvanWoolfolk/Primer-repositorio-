#include "stdio.h"
#include "GENFUN.h"

void main(void)
{
    uint8 au8array[12]="helloworld";
    GENFUN_vCAPSON (&au8array[0], 11);
    printf("%s\n", au8array);
    GENFUN_vCAPSOFF (&au8array[0], 11);
    printf("%s\n", au8array);
}

void GENFUN_vCAPSON (uint8 *pu8Src, uint8 u8SizeOFList)	
{
    while(u8SizeOFList !=0)
    {
        if(pu8Src>ASCII_LOW_THRESHOLD_OFF_ON && *pu8Src<ASCII_HIGH_THRESHOLD_OFF_ON)
        {
            pu8Src -= ASCII_CONVERTION_FACTOR;
        }
        else
        {
            //nothingtodo//
        }
        pu8Src++;
        u8SizeOFList--;
    }
}

void GENFUN_vCAPSOFF (uint8 *pu8Src, uint8 u8SizeOFList)	
{
    while(u8SizeOFList !=0)
    {
        if(pu8Src>ASCII_LOW_THRESHOLD_ON_OFF && *pu8Src<ASCII_HIGH_THRESHOLD_ON_OFF)
        {
            pu8Src += ASCII_CONVERTION_FACTOR;
        }
        else
        {
            //nothingtodo//
        }
        pu8Src++;
        u8SizeOFList--;
    }
}