#include <stdio.h>
#include <math.h>
#include <conio.h>
void main ()
{
    int CuantosBits;
    int Cualop;
    int Switch=1;
    printf("\n¿De cuántos bits es tu variable?\n 8 bits \n 16 bits \n 32 bits\n");
    scanf("%d",&CuantosBits);

if (CuantosBits==8||CuantosBits==16||CuantosBits==32)
	{
        do{
	        printf("\n¿Qué operación deseas hacer?\n 1)AND\n 2)OR\n 3)XOR\n");
	        scanf("%d",&Cualop);
		        if (Cualop>=1 && Cualop<=3)
	                 {
	    
    	             }
    
        else 
            {
            printf("\nOpción no válida, vuelva a intentarlo");
            }
        
        }while (Switch==1);
	}
else 
	{printf("\nLa variable debe ser de 8, 16 o 32 bits.");
	}
    
}