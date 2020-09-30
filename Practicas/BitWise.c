#include <stdio.h>
int main()
{
    unsigned short u16Variable=0;                                //   32 bits                            16 bits     8 bits
    unsigned char u8Variable=0;                                 //00000000000000000000000000000000°0000000000000000°00000000
    unsigned int bits,operacion,corrimiento,u32Variable=0; 
    
    printf("Introdusca los bits de su variable: ");
    scanf("%d",&bits);
    if(bits==8||bits==16||bits==32)
    {
        while(1)   
        {
            printf("\nSeleccione la operación a realizar  1)AND   2)OR   3)XOR\n");
            scanf("%d",&operacion);
            if(operacion>=1&&operacion<=3)
            {
                printf("Ingrese el corrimiento a realizar: ");  
                scanf("%d",&corrimiento);
                switch(operacion)
                {
                    case 1:                                     
                    if(bits==8)
                    {
                        if(bits==8)
                        {
                        u8Variable &= ~( 1 << corrimiento ); 
                        printf("El resultado es %d",u8Variable);
                        }
                        else if(corrimiento>8)
                        {
                        printf("\nopción no valida");
                        }
                        
                    }
                    else if(bits==16)
                    {
                        if(u16Variable>corrimiento)
                        {
                        u16Variable &= ~( 1 << corrimiento ); 
                        printf("El resultado es %d",u16Variable);
                        }
                        else if(corrimiento>16)
                        {
                        printf("\nopción no valida");    
                        }
                    }
                    else
                    {
                        if(bits==32)
                        {
                        u32Variable &= ~( 1 << corrimiento ); 
                        printf("El resultado es %d",u32Variable);
                        }
                        else if(corrimiento>32)
                        {
                        printf("\nopción no valida");    
                        }
                    }
                    break;
                    
                    case 2:
                    if(bits==8)
                    {
                        if(bits==8)
                        {
                        u8Variable |= ( 1 << corrimiento ); 
                        printf("El resultado es %d",u8Variable);
                        }
                        else if(corrimiento>8)
                        {
                        printf("\nopción no valida");    
                        }
                    }
                    else if(bits==16)
                    {
                        if(bits==16)
                        {
                        u16Variable |= ( 1 << corrimiento ); 
                        printf("El resultado es %d",u16Variable);
                        }
                        else if(corrimiento>16)
                        {
                        printf("\nopción no valida");    
                        }
                    }
                    else
                    {
                        if(bits==32)
                        {
                        u32Variable |= ( 1 << corrimiento ); 
                        printf("El resultado es %d",u32Variable);
                        }
                        else if(corrimiento>32)
                        {
                        printf("\nopción no valida");    
                        }
                    }
                    break;
                    
                    case 3:
                    if(bits==8)
                    {
                        if(bits==8)
                        {
                        u8Variable ^= ( 1 << corrimiento );   
                        printf("El resultado es %d",u8Variable);
                        }
                        else if(corrimiento>8)
                        {
                        printf("\nopción no valida");    
                        }
                        
                    }
                    else if(bits==16)
                    {
                        if(bits==16)
                        {
                        u16Variable ^= ( 1 << corrimiento );  
                        printf("El resultado es %d",u16Variable);
                        }
                        else if(corrimiento>16)
                        {
                        printf("\nopción no valida");    
                        }
                    }
                    else
                    {
                        if(bits==32)
                        {
                        u32Variable ^= ( 1 << corrimiento );  
                        printf("El resultado es %d",u32Variable);
                        }
                        else if(corrimiento>32)
                        {
                        printf("\nopción no valida");    
                        }
                    }
                    break;
                }
            }
            else
            {
                printf("Error:seleccione 1,2 o 3");
            }
        }
    }
    else
    {
        printf("Error: Utilice 8, 16 o 32 bits");    
    }
}