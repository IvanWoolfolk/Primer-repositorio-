#include "stdlib.h"
#include "stdio.h"
#include "time.h" 
#include "GENFUN.h"

void main(void)
{
    uint8 i;
    uint8 u8VALOR;
    uint8 u8Target=TARGET_VALUE;
    uint8 u8Char2Set=CHAR2SET_VALUE;
    uint8 au8array[ARRAY_SIZE]="helloworld";
    uint8 au8array2[ARRAY_SIZE]="jjchangejjj";
    uint8 au8arraynum[ARRAY_SIZE]=ARRAY_NUM_VALUE;
    uint8 au8arraynum2[ARRAY_SIZE]=ARRAY_NUM_VALUE;
    uint32 au32arraynum[MAX_VALUE];
    uint32 au32arraynum2[MAX_VALUE];
    uint8 AVERAGE;


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
    printf("El caracter con el que se cambiara es: e");
    GENFUN_u8MemSet (&au8array[0], u8Char2Set,VALUE_ARRAY);
    printf("\nLa nueva cadena es %s",au8array);
    

    //funcion 5
    printf("\n\nFuncion 5 *Average*\n");
    printf("Promedio de la siguiente cadena={ ");
    for(i=0;i<ARRAY_SIZE;i++)
    {
        printf("%d ",au8arraynum[i]);
    }
    printf("}");
    AVERAGE=GENFUN_u8GetAverage (&au8arraynum[0],ARRAY_SIZE);
    printf("\nAverage=%d\n\n",AVERAGE);
    

    //funcion 6 
    printf("Funcion 6 *MemSet*\n");
    printf("Cadena 1: %s\n",au8array);
    printf("Cadena 2: %s\n",au8array2);                      
    GENFUN_u8MemCopy (&au8array[0], &au8array2[0], ARRAY_SIZE );
    printf("La nueva cadena 1 es: %s",au8array);
    printf("\nLa nueva cadena 2 es: %s",au8array2);  
    

    //funcion7
    printf("\n\nFuncion 7 *SortlList*\n");
    printf("Cadena desordenada={ ");
    for(i=0;i<ARRAY_SIZE;i++)
    {
        printf("%d ",au8arraynum[i]);
    }
    printf("}");
    GENFUN_vSortList (&au8arraynum[0],&au8arraynum[0],ARRAY_SIZE);
    printf("\nCadena ordenada={ ");
    for(i=0;i<ARRAY_SIZE;i++)
    {
        printf("%d ",au8arraynum[i]);
    }
    printf("}");+

    
    //funcion 8
    printf("\n\n    Funcion 8 SoftSignal \n");
    GENFUN_vSoftSignal (&au32arraynum[0], &au32arraynum2[0]);   


    //funcion 9
    printf("\n\n Funcion 9 FilterSignal \n");
    GENFUN_vFilterSignal(&au32arraynum[0],&au32arraynum2[0],MinRand);
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
    uint8 u8Elements=0;
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
        u8SizeOfList--;
    }

}

uint8 GENFUN_u8GetAverage (uint8 *pu8Src, uint8 u8SizeOfList)
{
    uint32 SUMA=0;
    uint8 RESULTADO;
    uint8 j;
    for(j=0;j<ARRAY_SIZE;j++)
    {
       SUMA+=*pu8Src;
       pu8Src++;
    }
    RESULTADO=SUMA/ARRAY_SIZE;
    return RESULTADO;
}

void GENFUN_u8MemCopy (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList)       
{
uint8 RESPALDO;
     while(u8SizeOfList!=0)
     {
        RESPALDO=*pu8Src;
        *pu8Src=*pu8Dest; 
        *pu8Dest=RESPALDO;
        
        u8SizeOfList--;
        pu8Src++;
        pu8Dest++;
     }
}

void GENFUN_vSortList (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList)
{
    uint8 MEMORY;
    uint8 j;
    uint8 k;
    uint8 au8arraynum3[ARRAY_SIZE]=ARRAY_NUM_VALUE;
    for(j=0;j<=ARRAY_SIZE;j++)
    {
        for(k=j+1;k<=ARRAY_SIZE-1;k++)
        {
            if(au8arraynum3[j]>au8arraynum3[k])
            {
                MEMORY=au8arraynum3[j];
                au8arraynum3[j]=au8arraynum3[k];
                au8arraynum3[k]=MEMORY;
           }  
       }
   } 
   for (j=0;j<ARRAY_SIZE;j++)
   {
       *pu8Src=au8arraynum3[j];
       pu8Src++;
   }
}


void GENFUN_vSoftSignal (uint32 *pu32Src, uint32 *pu32Dest) 
{
    uint8 cambio = MAX_VALUE;
    uint8 cambio2 = MAX_VALUE2;
    uint8 promedio=0,n=0,s=0;
    printf("El arreglo fue almacenado como:\n");

        while(cambio!= 0)
        {
            *pu32Src = rand() % 10;

            printf("%c %d %c",CARACTER,*pu32Src,CARACTER);

            cambio--;
            pu32Src++;
        }

    pu32Src=pu32Src-MAX_VALUE;
    


    printf("\n La nueva cadena es: \n");
        
        while(cambio2 != 0)
        {
            n = *pu32Src;
            pu32Src++;
            s=(n+*pu32Src);
            promedio=(s/2);
            *pu32Dest=promedio;

            printf("%c %d %c",CARACTER,*pu32Dest,CARACTER);

            cambio2--;
            pu32Dest++;
        }
}
void GENFUN_vFilterSignal (uint32 *pu32Src, uint32 *pu32Dest, uint32 u32MinRand)
{
    uint8 cambio = MAX_VALUE;
    uint8 cambio2 = MAX_VALUE;
    uint8 aux=0;

        ////Rango es de 20 a 40/// 

    printf("El arreglo va a ser llenado por números aleartorios del 20 al 40 \n");
    u32MinRand--;
        while(cambio!= 0)
        {
            *pu32Src = (1) + (rand() % MaxChain);
            *pu32Dest=aux;
            if(*pu32Src<=MinRand)
            {
             *pu32Src=MinRand;     
            }
            else if(*pu32Src>=MaxRand)
            {
            *pu32Src=MaxRand;
            }

            printf("%c %d %c",CARACTER,*pu32Src,CARACTER);

            cambio--;
            pu32Src++;
            
        }
        
}