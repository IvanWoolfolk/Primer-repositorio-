#include <stdio.h>
#include <stdlib.h>
#include "BEBIDAS.h"
#include <time.h> 
int main()
{
        uint8 START=0;
        uint8 SELECTION=ANALYS;
        uint8 breakenCurrent=0;
        uint16 u16BEBIDA_PREP;
        uint8 ALMACEN;
        SM_tenStates enCurrentState = enLIMON;
        srand(time(0));
         while(1)
        {
                switch(SELECTION)
                {
                    case 1:
                    {
                    printf("\nZUMO DE LIMON:     %d ml",DRINKS_ml.u8ZUMO_LIMON);
                    printf("\nZUMO DE NARANJA:   %d ml",DRINKS_ml.u8ZUMO_NARANJA);
                    printf("\nRON:               %d ml",DRINKS_ml.u16RON);
                    printf("\nCOCA COLA:         %d ml",DRINKS_ml.u16COCA_COLA);
                    printf("\nWHISKY:            %d ml",DRINKS_ml.u16WHISKY);
                    printf("\nGINEBRA:           %d ml",DRINKS_ml.u16GINEBRA);
                    printf("\nTEQUILA:           %d ml",DRINKS_ml.u16TEQUILA);
                    printf("\nAGUA MINERAL:      %d ml",DRINKS_ml.u16AGUA_MINERAL);
                    printf("\nVODKA:             %d ml",DRINKS_ml.u16VODKA);
                    printf("\n");
                    printf("Desea llenar el almacen? SI=0/NO=otro:   ");
                    scanf("%d",&ALMACEN);
                    if(ALMACEN==0)
                    {
                        DRINKS_ml.u8ZUMO_LIMON=MAX_ZUMO;
                        DRINKS_ml.u8ZUMO_NARANJA=MAX_ZUMO;
                        DRINKS_ml.u16RON=MAX_RON;
                        DRINKS_ml.u16COCA_COLA=MAX_MINERAL;
                        DRINKS_ml.u16WHISKY=MAX_VODKA;
                        DRINKS_ml.u16GINEBRA=MAX_RON;
                        DRINKS_ml.u16TEQUILA=MAX_VODKA;
                        DRINKS_ml.u16AGUA_MINERAL=MAX_MINERAL;
                        DRINKS_ml.u16VODKA=MAX_VODKA;
                    }
                    else
                    {
                        /*nothing to do*/
                    }
                    SELECTION=ANALYS;
                    }
                    break;
                    
                    case 2:
                    {
                    printf("\nGINTONIC:   250mlAGUA MINERAL   50mlGINEBRA ");
                    if(DRINKS_ml.u16AGUA_MINERAL>=OCHO_ONZA&&DRINKS_ml.u16GINEBRA>=ONZAyMEDIA)
                    {
                        INTERVALO();
                        DRINKS_ml.u16AGUA_MINERAL-=OCHO_ONZA;
                        DRINKS_ml.u16GINEBRA-=ONZAyMEDIA;
                        SELECTION=ANALYS;
                    }
                    else
                    {
                        printf("ERROR: NO CONTAMOS CON LOS INGREDIENTE NECESARIOS, MÁS INFORMACION EN DRINKS INFO\n");
                        SELECTION=DRINKS_WARNING;
                    }
                    }
                    break;
                    
                    case 3:
                    {
                    printf("\nLong Island Ice Tea:  15mlVODKA  15mlGINEBRA  15mlRON  15mlWHISKY 15mlTEQUILA 15mlZUMO de LIMON 115mlCOCA-COLA ");
                    if(DRINKS_ml.u8ZUMO_LIMON>=MEDIA_ONZA&&DRINKS_ml.u16COCA_COLA>=CUATRO_ONZA&&DRINKS_ml.u16GINEBRA>=MEDIA_ONZA&&DRINKS_ml.u16VODKA>=MEDIA_ONZA&&DRINKS_ml.u16RON>=MEDIA_ONZA&&DRINKS_ml.u16WHISKY>=MEDIA_ONZA&&DRINKS_ml.u16TEQUILA>=MEDIA_ONZA)
                    {
                        INTERVALO();
                        DRINKS_ml.u16COCA_COLA-=CUATRO_ONZA;
                        DRINKS_ml.u16GINEBRA-=MEDIA_ONZA;
                        DRINKS_ml.u16VODKA-=MEDIA_ONZA;
                        DRINKS_ml.u16RON-=MEDIA_ONZA;
                        DRINKS_ml.u16WHISKY-=MEDIA_ONZA;
                        DRINKS_ml.u16TEQUILA-=MEDIA_ONZA;
                        DRINKS_ml.u8ZUMO_LIMON-=MEDIA_ONZA;
                        SELECTION=ANALYS;
                    }
                    else
                    {
                        printf("ERROR: NO CONTAMOS CON LOS INGREDIENTE NECESARIOS, MÁS INFORMACION EN DRINKS INFO\n");
                        SELECTION=DRINKS_WARNING;
                    }
                    }
                    break;
                    
                    case 4:
                    {
                    printf("\nCUBA LIBRE:   250mlCOCA-COLA   50mlRON 15mlZUMO de LIMON ");
                    if(DRINKS_ml.u16COCA_COLA>=CUATRO_ONZA&&DRINKS_ml.u16RON>=ONZAyMEDIA&&DRINKS_ml.u8ZUMO_LIMON>=MEDIA_ONZA)
                    {
                        INTERVALO();
                        DRINKS_ml.u16COCA_COLA-=CUATRO_ONZA;
                        DRINKS_ml.u16RON-=ONZAyMEDIA;
                        DRINKS_ml.u8ZUMO_LIMON-=MEDIA_ONZA;
                        SELECTION=ANALYS;
                    }
                    else
                    {
                        printf("ERROR: NO CONTAMOS CON LOS INGREDIENTE NECESARIOS, MÁS INFORMACION EN DRINKS INFO\n");
                        SELECTION=DRINKS_WARNING;
                    };
                    }
                    break;
                    
                    case 5:
                    {
                    printf("\nTequila Sunrise:   115mlZumo de naanja   50mlTequila ");
                    if(DRINKS_ml.u8ZUMO_NARANJA>=CUATRO_ONZA&&DRINKS_ml.u16TEQUILA>=ONZAyMEDIA)
                    {
                        INTERVALO();
                        DRINKS_ml.u8ZUMO_NARANJA-=CUATRO_ONZA;
                        DRINKS_ml.u16TEQUILA-=ONZAyMEDIA;
                        SELECTION=ANALYS;
                    }
                    else
                    {
                        printf("ERROR: NO CONTAMOS CON LOS INGREDIENTE NECESARIOS, MÁS INFORMACION EN DRINKS INFO\n");
                        SELECTION=DRINKS_WARNING;
                    }
                    }
                    break;
                    
                    case 6:
                    {
                    printf("\nShot de Vodka:  50mlVodka ");
                    if(DRINKS_ml.u16VODKA>=ONZAyMEDIA)
                    {
                        INTERVALO();
                        DRINKS_ml.u16VODKA-=ONZAyMEDIA;
                        SELECTION=ANALYS;
                    }
                    else
                    {
                        printf("ERROR: NO CONTAMOS CON LOS INGREDIENTE NECESARIOS, MÁS INFORMACION EN DRINKS INFO\n");
                        SELECTION=DRINKS_WARNING;
                    }
                    }
                    break;
                    
                    case 7:
                    {
                    printf("\nCaballito:  50mlTequila ");
                    if(DRINKS_ml.u16TEQUILA>=ONZAyMEDIA)
                    {
                        INTERVALO();
                        DRINKS_ml.u16TEQUILA-=ONZAyMEDIA;
                        SELECTION=ANALYS;
                    }
                    else
                    {
                        printf("ERROR: NO CONTAMOS CON LOS INGREDIENTE NECESARIOS, MÁS INFORMACION EN DRINKS INFO\n");
                        SELECTION=DRINKS_WARNING;
                    }
                    }
                    break;
                    
                    case 8:
                    {
                    printf("\nIngrese la cantidad en ml que desee");
                    while(breakenCurrent==0)
                    {
                        switch(enCurrentState)
                        {
                            case enLIMON:
                            printf("\nZumo de limon: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u8ZUMO_LIMON>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u8ZUMO_LIMON-=u16BEBIDA_PREP;
                                enCurrentState=enRON;
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                                enCurrentState=enLIMON;
                            }
                            break;
                            
                            case enRON:
                            printf("\nRON: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u16RON>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u16RON-=u16BEBIDA_PREP;
                                enCurrentState=enNARANJA;
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                                enCurrentState=enRON;
                            }
                            break;
                            
                            case enNARANJA:
                            printf("\nNARANJA: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u8ZUMO_NARANJA>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u8ZUMO_NARANJA-=u16BEBIDA_PREP;
                                enCurrentState=enCOCA;
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                                enCurrentState=enNARANJA;
                            }
                            break;
                            
                            case enCOCA:
                            printf("\nCOCA COLA: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u16COCA_COLA>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u16COCA_COLA-=u16BEBIDA_PREP;
                                enCurrentState=enWHISKY;
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                                enCurrentState=enCOCA;
                            }
                            break;
                            
                            case enWHISKY:
                            printf("\nWHISKY: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u16WHISKY>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u16WHISKY-=u16BEBIDA_PREP;
                                enCurrentState=enGINEBRA;
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                                enCurrentState=enWHISKY;
                            }
                            break;
                            
                            case enGINEBRA:
                            printf("\nGINEBRA: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u16GINEBRA>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u16GINEBRA-=u16BEBIDA_PREP;
                                enCurrentState=enTEQUILA;
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                                enCurrentState=enGINEBRA;
                            }
                            break;
                            
                            case enTEQUILA:
                            printf("\nTEQUILA: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u16TEQUILA>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u16TEQUILA-=u16BEBIDA_PREP;
                                enCurrentState=enVODKA;
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                                enCurrentState=enTEQUILA;
                            }
                            break;
                            
                            case enVODKA:
                            printf("\nVODKA: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u16VODKA>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u16VODKA-=u16BEBIDA_PREP;
                                breakenCurrent=1;
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                                enCurrentState=enVODKA;
                            }
                            SELECTION=ANALYS;
                            break;
                        }
                    }
                    INTERVALO();
                    }
                    
                    case 9:
                    {
                    printf("\nSeleccione la opcion deseada\n2)GINTONIC\n3)Long Island Ice Tea\n4)CUBA LIBRE\n5)Tequila sunrise\n6)SHOT DE VODKA\n7)Caballito\n8)Perzonalizada\n");
                    scanf("%d",&SELECTION);    
                    }
                    break;
                }
        }

    return 0;
}


void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
}

void INTERVALO()
{
    int i,j;
    printf("\nSu bebida esta siendo preparada\n");
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
        printf(".");
        }
        printf("\n");
    }
    printf("\nBebida preparada\n");
}