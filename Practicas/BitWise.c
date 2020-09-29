#include <stdio.h>
#include <math.h>
#include <conio.h>
void main ()
{
    int Bits,corrimiento;
    int Cualop;
    int Switch=1;
	unsigned char u8variable8;
	unsigned short u16variable16;
	unsigned long u32variable;
    printf("\n¿De cuántos bits es tu variable?\n 8 bits \n 16 bits \n 32 bits\n");
    scanf("%d",&Bits);

if (Bits==8||Bits==16||Bits==32)
	{
        	do{
	        	printf("\n¿Qué operación deseas hacer?\n 1)AND\n 2)OR\n 3)XOR\n");
	        	scanf("%d",&Cualop);
		        	if (Cualop>=1 && Cualop<=3)
	                 	{
					     printf("Escoja el corrimiento de la operación");
						 scanf("%d",&corrimiento);

	                     switch(Cualop)
						 {
							 case 1:
							 printf("\nIngrese el valor a cambiar");
							 break;

							 case 2:
							 break;

							 case 3:
							 break;
						 }
    	             	}
    
        			else 
            			{printf("\nOpción no válida, vuelva a intentarlo");}
        
        	}while (Switch==1);
	}
else 
	{printf("\nLa variable debe ser de 8, 16 o 32 bits.");
	}
    
}