#include <stdio.h>																/*PM -> El nombre de tu archivo no debe tener espacios ni caracteres especiales, como el acento*/
//#include <math.h>																/*PM -> No son necesarias*/
//#include <conio.h>																/*PM -> No son necesarias*/
void main ()																	/*PM -> Define tipo void como argumento al main*/
{
    int Bits,corrimiento;														/*PM -> Notacion Hungara 32..., define el tipo unsigned/signed*/
    int Cualop;																	/*PM -> Notacion Hungara 32..., define el tipo unsigned/signed*/
    int Switch=1;																/*PM -> Notacion Hungara 32..., define el tipo unsigned/signed*/
	unsigned long u32variable32;
    printf("\n¿De cuántos bits es tu variable?\n 8 bits \n 16 bits \n 32 bits\n");
    scanf("%d",&Bits);

if (Bits==8||Bits==16||Bits==32)
	{																			/*PM-> Cuida la indentacion, tienes codigo no alineado*/
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
										printf("El resultado es %d\n",u32variable32);		/*PM -> Las operaciones se estan realizando mal*/
										
										break;

							 			case 2:
							 			//OR
                                        u32variable32 |= (1 << corrimiento);
										printf("El resultado es %d\n",u32variable32);		/*PM -> Las operaciones se estan realizando mal*/
							 			break;

							 			case 3:
							 			//XOR
                                        u32variable32 ^= (1 << corrimiento);
										printf("El resultado es %d\n",u32variable32);		/*PM -> Las operaciones se estan realizando mal*/
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