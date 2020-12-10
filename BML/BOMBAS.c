#include "BOMBAS.h"

SM_configurar enCurrentBomba = enBOMBA_A;
void Bomba (void)
{   
    uint8 u8TIME=1;
    static uint32 u32Time_A;
    static uint32 u32Time_B;
    static uint32 u32Time_C;
        switch(enCurrentBomba)
        {
            case enBOMBA_A:
            printf("Seleccione el tiempo de trabajo (minutos) de cada bomba\n");
            printf("\nBomba de infusión A :   ");
    	    scanf("%d",&u32Time_A);
    	    if(u32Time_A<=TIME_MAX)
    	    {
    	        enCurrentBomba = enBOMBA_B;    
    	    }
    	    else
    	    {
    	        printf("\nERROR: TIME NOT VALID");
    	        enCurrentBomba = enBOMBA_A; 
    	    }
            break;
            
            case enBOMBA_B:
            printf("\nBomba de infusión B :   ");
    	    scanf("%d",&u32Time_B);
    	    if(u32Time_B<=TIME_MAX)
    	    {
    	        enCurrentBomba = enBOMBA_C;    
    	    }
    	    else
    	    {
    	        printf("\nERROR: TIME NOT VALID");
    	        enCurrentBomba = enBOMBA_B; 
    	    }
            break;
            
            case enBOMBA_C:
            printf("\nBomba de infusión C :   ");
    	    scanf("%d",&u32Time_C);
    	    if(u32Time_C<=TIME_MAX)
    	    {
    	        u32Time_A=u32Time_A*seconds;
    	        u32Time_B=u32Time_B*seconds;
    	        u32Time_C=u32Time_C*seconds;
    	        enCurrentBomba = enEJECUCION;
    	    }
    	    else
    	    {
    	        printf("\nERROR: TIME NOT VALID");
    	        enCurrentBomba = enBOMBA_C; 
    	    }
            break;
            
            case enEJECUCION:
            while(u8TIME!=0)
            {
                if(u32Time_A!=0)
                {
                    printf("\nBOMBA A: %d segundos restantes",u32Time_A);
                    u32Time_A--;
                }
                if(u32Time_B!=0)
                {
                    printf("\nBOMBA B: %d segundos restantes",u32Time_B);
                    u32Time_B--;
                }
                if(u32Time_C!=0)
                {
                    printf("\nBOMBA C: %d segundos restantes",u32Time_C);
                    u32Time_C--;
                }
                if(u32Time_A==0 && u32Time_B==0 && u32Time_C==0)
                {
                    u8TIME=0;
                    enCurrentBomba = enBOMBA_A;
                }
                printf("\n");
                break;
            }
        }
}