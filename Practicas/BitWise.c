#include <stdio.h>
int main()
{
    unsigned short u16Variable;
    unsigned char operacion,u8Variable;
    unsigned int bits, corrimiento,u32Variable;
    
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
                        printf("\nIngrese su variable: ");
                        scanf("%d",&u8Variable);
                        u8Variable &= ~( 1 << corrimiento ); 
                        printf("El resultado es %d",u8Variable);
                        
                    }
                    else if(bits==16)
                    {
                        printf("\nIngrese su variable: ");
                        scanf("%d",&u16Variable);
                        u16Variable &= ~( 1 << corrimiento ); 
                        printf("El resultado es %d",u16Variable);
                    }
                    else
                    {
                        printf("\nIngrese su variable: ");
                        scanf("%d",&u32Variable);
                        u32Variable &= ~( 1 << corrimiento ); 
                        printf("El resultado es %d",u32Variable);
                    }
                    break;
                    
                    case 2:
                    if(bits==8)
                    {
                        printf("\nIngrese su variable: ");
                        scanf("%d",&u8Variable);
                        u8Variable |= ( 1 << corrimiento ); 
                        printf("El resultado es %d",u8Variable);
                        
                    }
                    else if(bits==16)
                    {
                        printf("\nIngrese su variable: ");
                        scanf("%d",&u16Variable);
                        u16Variable |= ( 1 << corrimiento ); 
                        printf("El resultado es %d",u16Variable);
                    }
                    else
                    {
                        printf("\nIngrese su variable: ");
                        scanf("%d",&u32Variable);
                        u32Variable |= ( 1 << corrimiento ); 
                        printf("El resultado es %d",u32Variable);
                    }
                    break;
                    
                    case 3:
                    if(bits==8)
                    {
                        printf("\nIngrese su variable: ");
                        scanf("%d",&u8Variable);
                        u8Variable ^= ( 1 << corrimiento );   
                        printf("El resultado es %d",u8Variable);
                        
                    }
                    else if(bits==16)
                    {
                        printf("\nIngrese su variable: ");
                        scanf("%d",&u16Variable);
                        u16Variable ^= ( 1 << corrimiento );  
                        printf("El resultado es %d",u16Variable);
                    }
                    else
                    {
                        printf("\nIngrese su variable: ");
                        scanf("%d",&u32Variable);
                        u32Variable ^= ( 1 << corrimiento );  
                        printf("El resultado es %d",u32Variable);
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