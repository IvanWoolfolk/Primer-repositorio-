#include <stdio.h>
#include <math.h>
#include <conio.h>
void main ()
{
    int Bits,corrimiento;
    int Cualop;
    int Switch=1;
	unsigned long u32variable32;
    printf("\n¿De cuántos bits es tu variable?\n 8 bits \n 16 bits \n 32 bits\n");
    scanf("%d",&Bits);

if (Bits==8||Bits==16||Bits==32)
	{
        	do{
	           printf("\n¿Qué operación deseas hacer?\n 1)AND\n 2)OR\n 3)XOR\n 4)Salir\n");
	        	scanf("%d",&Cualop);
		        	if (Cualop>=1 && Cualop<=4){
							    
						Switch=1;
					    printf("Escoja el corrimiento de la operación\n");
						scanf("%d",&corrimiento);

								if (corrimiento>=0 && corrimiento<=7 && Bits==8 || corrimiento>=0 && corrimiento<=15 && Bits==16 || corrimiento>=0 && corrimiento< 31 && Bits==32)
	                       		{
						 			switch(Cualop)
						 			{
							 			case 1:
							 			//AND 
										u32variable32 &= ~(1 << corrimiento);
										printf("El resultado es %d\n",u32variable32);
										
										break;

							 			case 2:
							 			//OR
                                        u32variable32 |= (1 << corrimiento);
										printf("El resultado es %d\n",u32variable32);
							 			break;

							 			case 3:
							 			//XOR
                                        u32variable32 ^= (1 << corrimiento);
										printf("El resultado es %d\n",u32variable32);
							 			break;
							 			
							 			case 4:
							 			//END
							 			printf("Tenga buen día\n");
							 			Switch=0;
							 			break;
							 		}  
								}
								else 
									{
									printf("El valor es muy grande para el número de bits que ingresó, intentelo de nuevo\n");
									}}
        			else 
            			{
						printf("\nOpción no válida, vuelva a intentarlo\n");
						}
        	}while (Switch==1);
	}
else 
	{printf("\nLa variable debe ser de 8, 16 o 32 bits.\n");
	}
    
}