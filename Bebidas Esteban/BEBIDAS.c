
#include <stdio.h>
#include <stdlib.h>
#include "BEBIDASLIB.h"
int main()
{
        uint8 START=0;
        uint8 SELECTION=0;
        uint8 breakenCurrent=0;
        uint16 u16BEBIDA_PREP;
        uint8 ALMACEN;
        SM_tenStates enCurrentState = enLIMON;
        srand(time(0));
        printf("Para iniciar presione 1:");
        scanf(" %d",&START);
         while(1)
        {
            if(START==1)
            {
                printf("\nSeleccione la opcion deseada\n1)Información de las bebidad\n2)GINTONIC\n3)Long Island Ice Tea\n4)CUBA LIBRE\n5)Tequila sunrise\n6)SHOT DE VODKA\n7)Caballito\n8)Perzonalizada\n");//estado 8 ciclo dentro de los ciclos
                scanf("%d",&SELECTION);
                switch(SELECTION)
                {
                    case 1:
                    {
                    printf("\nZUMO DE LIMON:     "COLOR_RED"%d ml"COLOR_RESET,DRINKS_ml.u8ZUMO_LIMON);
                    printf("\nZUMO DE NARANJA:   "COLOR_RED"%d ml"COLOR_RESET,DRINKS_ml.u8ZUMO_NARANJA);
                    printf("\nRON:               "COLOR_RED"%d ml"COLOR_RESET,DRINKS_ml.u16RON);
                    printf("\nCOCA COLA:         "COLOR_RED"%d ml"COLOR_RESET,DRINKS_ml.u16COCA_COLA);
                    printf("\nWHISKY:            "COLOR_RED"%d ml"COLOR_RESET,DRINKS_ml.u16WHISKY);
                    printf("\nGINEBRA:           "COLOR_RED"%d ml"COLOR_RESET,DRINKS_ml.u16GINEBRA);
                    printf("\nTEQUILA:           "COLOR_RED"%d ml"COLOR_RESET,DRINKS_ml.u16TEQUILA);
                    printf("\nAGUA MINERAL:      "COLOR_RED"%d ml"COLOR_RESET,DRINKS_ml.u16AGUA_MINERAL);
                    printf("\nVODKA:             "COLOR_RED"%d ml"COLOR_RESET,DRINKS_ml.u16VODKA);
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
                    }
                    break;
                    
                    case 2:
                    {
                    printf(COLOR_BLUE"\nGINTONIC:   250mlAGUA MINERAL   50mlGINEBRA "COLOR_RESET);
                    if(DRINKS_ml.u16AGUA_MINERAL>=OCHO_ONZA&&DRINKS_ml.u16GINEBRA>=ONZAyMEDIA)
                    {
                        INTERVALO();
                        DRINKS_ml.u16AGUA_MINERAL-=OCHO_ONZA;
                        DRINKS_ml.u16GINEBRA-=ONZAyMEDIA;
                    }
                    else
                    {
                        printf(COLOR_RED"ERROR: NO CONTAMOS CON LOS INGREDIENTE NECESARIOS, MÁS INFORMACION EN DRINKS INFO\n"COLOR_RESET);
                    }
                    }
                    break;
                    
                    case 3:
                    {
                    printf(COLOR_BLUE"\nLong Island Ice Tea:  15mlVODKA  15mlGINEBRA  15mlRON  15mlWHISKY 15mlTEQUILA 15mlZUMO de LIMON 115mlCOCA-COLA "COLOR_RESET);
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
                    }
                    else
                    {
                        printf(COLOR_RED"ERROR: NO CONTAMOS CON LOS INGREDIENTE NECESARIOS, MÁS INFORMACION EN DRINKS INFO\n"COLOR_RESET);
                    }
                    }
                    break;
                    
                    case 4:
                    {
                    printf(COLOR_BLUE"\nCUBA LIBRE:   250mlCOCA-COLA   50mlRON 15mlZUMO de LIMON "COLOR_RESET);
                    if(DRINKS_ml.u16COCA_COLA>=CUATRO_ONZA&&DRINKS_ml.u16RON>=ONZAyMEDIA&&DRINKS_ml.u8ZUMO_LIMON>=MEDIA_ONZA)
                    {
                        INTERVALO();
                        DRINKS_ml.u16COCA_COLA-=CUATRO_ONZA;
                        DRINKS_ml.u16RON-=ONZAyMEDIA;
                        DRINKS_ml.u8ZUMO_LIMON-=MEDIA_ONZA;
                    }
                    else
                    {
                        printf(COLOR_RED"ERROR: NO CONTAMOS CON LOS INGREDIENTE NECESARIOS, MÁS INFORMACION EN DRINKS INFO\n"COLOR_RESET);
                    }
                    }
                    break;
                    
                    case 5:
                    {
                    printf(COLOR_BLUE"\nTequila Sunrise:   115mlZumo de naanja   50mlTequila "COLOR_RESET);
                    if(DRINKS_ml.u8ZUMO_NARANJA>=CUATRO_ONZA&&DRINKS_ml.u16TEQUILA>=ONZAyMEDIA)
                    {
                        INTERVALO();
                        DRINKS_ml.u8ZUMO_NARANJA-=CUATRO_ONZA;
                        DRINKS_ml.u16TEQUILA-=ONZAyMEDIA;
                    }
                    else
                    {
                        printf(COLOR_RED"ERROR: NO CONTAMOS CON LOS INGREDIENTE NECESARIOS, MÁS INFORMACION EN DRINKS INFO\n"COLOR_RESET);
                    }
                    }
                    break;
                    
                    case 6:
                    {
                    printf(COLOR_BLUE"\nShot de Vodka:  50mlVodka "COLOR_RESET);
                    if(DRINKS_ml.u16VODKA>=ONZAyMEDIA)
                    {
                        INTERVALO();
                        DRINKS_ml.u16VODKA-=ONZAyMEDIA;
                    }
                    else
                    {
                        printf(COLOR_RED"ERROR: NO CONTAMOS CON LOS INGREDIENTE NECESARIOS, MÁS INFORMACION EN DRINKS INFO\n"COLOR_RESET);
                    }
                    }
                    break;
                    
                    case 7:
                    {
                    printf(COLOR_BLUE"\nCaballito:  50mlTequila "COLOR_RESET);
                    if(DRINKS_ml.u16TEQUILA>=ONZAyMEDIA)
                    {
                        INTERVALO();
                        DRINKS_ml.u16TEQUILA-=ONZAyMEDIA;
                    }
                    else
                    {
                        printf(COLOR_RED"ERROR: NO CONTAMOS CON LOS INGREDIENTE NECESARIOS, MÁS INFORMACION EN DRINKS INFO\n"COLOR_RESET);
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
                                printf("\nDesea continuar? SI=0/NO=Otro   :");
                                scanf("%d",&breakenCurrent);
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                            }
                            enCurrentState=enRON;
                            break;
                            
                            case enRON:
                            printf("\nRON: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u16RON>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u16RON-=u16BEBIDA_PREP;
                                printf("\nDesea continuar? SI=0/NO=Otro   :");
                                scanf("%d",&breakenCurrent);
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                            }
                            enCurrentState=enNARANJA;
                            break;
                            
                            case enNARANJA:
                            printf("\nNARANJA: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u8ZUMO_NARANJA>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u8ZUMO_NARANJA-=u16BEBIDA_PREP;
                                printf("\nDesea continuar? SI=0/NO=Otro   :");
                                scanf("%d",&breakenCurrent);
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                            }
                            enCurrentState=enCOCA;
                            break;
                            
                            case enCOCA:
                            printf("\nCOCA COLA: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u16COCA_COLA>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u16COCA_COLA-=u16BEBIDA_PREP;
                                printf("\nDesea continuar? SI=0/NO=Otro   :");
                                scanf("%d",&breakenCurrent);
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                            }
                            enCurrentState=enWHISKY;
                            break;
                            
                            case enWHISKY:
                            printf("\nWHISKY: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u16WHISKY>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u16WHISKY-=u16BEBIDA_PREP;
                                printf("\nDesea continuar? SI=0/NO=Otro   :");
                                scanf("%d",&breakenCurrent);
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                            }
                            enCurrentState=enGINEBRA;
                            break;
                            
                            case enGINEBRA:
                            printf("\nGINEBRA: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u16GINEBRA>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u16GINEBRA-=u16BEBIDA_PREP;
                                printf("\nDesea continuar? SI=0/NO=Otro   :");
                                scanf("%d",&breakenCurrent);
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                            }
                            enCurrentState=enTEQUILA;
                            break;
                            
                            case enTEQUILA:
                            printf("\nTEQUILA: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u16TEQUILA>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u16TEQUILA-=u16BEBIDA_PREP;
                                printf("\nDesea continuar? SI=0/NO=Otro   :");
                                scanf("%d",&breakenCurrent);
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                            }
                            enCurrentState=enVODKA;
                            break;
                            
                            case enVODKA:
                            printf("\nVODKA: ");
                            scanf("%d",&u16BEBIDA_PREP);
                            if(DRINKS_ml.u16VODKA>=u16BEBIDA_PREP)
                            {
                                DRINKS_ml.u16VODKA-=u16BEBIDA_PREP;
                                printf("\nDesea continuar? SI=0/NO=Otro   :");
                                scanf("%d",&breakenCurrent);
                            }
                            else
                            {
                                printf("\nERROR: INSUFCIENTE, MÁS INFORMACIÓN DRINKS INFO");
                            }
                            enCurrentState=enLIMON;
                            break;
                        }
                    }
                    INTERVALO();
                    }
                }
            }
            else
            {
                break;
                //nothing to do
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
    printf("\nSu bebida esta siendo preparada...");
    delay(200);
    printf("\n...");
    delay(200);
    printf("\n...");
    delay(200);
    printf("\n...");
    delay(200);
    printf("\nBebida lista\n");
    delay(200);
}