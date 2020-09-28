#include <stdio.h>
#include <math.h>
#include <conio.h>
void main ()
{
    int CuantosBits;
    char Cualop;
    printf("\n¿De cuántos bits es tu variable?\n 8 bits \n 16 bits \n 32 bits\n");
    scanf("%d",&CuantosBits);

if (CuantosBits==8||CuantosBits==16||CuantosBits==32)
	{
	   printf("\n¿Qué operación deseas hacer?\n A)AND\n O)OR\n X)XOR");
	   scanf("%c",&Cualop);
		if (Cualop=='A')
		{
		
		}
		else if (Cualop=='O')
		{
			
		}
		else if (Cualop=='X')	
		{

		}
    }


else 
	{printf("\nLa variable debe ser de 8, 16 o 32 bits.");
	}
    
}