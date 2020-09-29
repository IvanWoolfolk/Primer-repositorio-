#include <stdio.h>
#include <math.h>
#include <conio.h>
void main ()
{
    int Bits,corrimiento,ValueToChange;
    int Cualop;
    int Switch=1;
	unsigned char u8variable8;
	unsigned short u16variable16;
	unsigned long u32variable32;
    printf("\n¿De cuántos bits es tu variable?\n 8 bits \n 16 bits \n 32 bits\n");
    scanf("%d",&Bits);

if (Bits==8||Bits==16||Bits==32)
	{
        do{
            if (Bits==8)
			    ValueToChange=u8variable8;
			else if(Bits==16)
			    ValueToChange=u16variable16;
			else
			    ValueToChange=u32variable32;
				
	        	printf("\n¿Qué operación deseas hacer?\n 1)AND\n 2)OR\n 3)XOR: ");
	        	scanf("%d",&Cualop);
		        	if (Cualop>=1 && Cualop<=3)
	                 	{
					     printf("\nEscoja el corrimiento de la operación: ");
						 scanf("%d",&corrimiento);
						 printf("\nIngrese el numero a cambiar: ");
						 scanf("%d",&ValueToChange);

	                     switch(Cualop)
						 {
							 case 1:
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