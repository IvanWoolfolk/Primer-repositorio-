#include <stdio.h>
#include <GENFUN.h>


void main (void)
{
    uint8 au8ArrayToCapsOn[15] = "My name is Ivan"
    printf("Array before Capson: %s\n",au8ArrayToCapsOn);
    GENFUN_vCapson(&au8ArrayToCapsOn[0],15);
    printf("Array after Capson:$s\n",au8ArrayToCapsOn);

}

void GENFUN_vCapson (uint8 *pu8Scr, uint8 u8SizeOfList)
{
    while ( u8SizeOfList != 0 )
    {
        if (*pu8Scr > ASCII_LOW_THRESHOLD_OFF_ON && *pu8Scr < ASCII_HIGH_THRESHOLD_OFF_ON)
        {
            *pu8Scr -= ASCII_CONVERTION_FACTOR;
        }
        else
        {
            /*Nothing to do*/
        }
        pu8Scr++;
        u8SizeOfList--;
    }
}