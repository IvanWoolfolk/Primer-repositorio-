#include "stdio.h"
#include "Structs.h"

/* Descripcion 

->Crear un programa que simule un estacionamiento con 5 diferentes secciones 0, 1, 2, 3 o 4. Cada seccion tendra un cupo maximo de carros que sera definido por Defines diferentes. 
->Se tiene que usar un arreglo de estructuras para manejar los estacionamientos, la estructura es la de abajo.
->El programa correra en un ciclo infinito y habra funciones aleatorias que metan y saquen carros de las diferentes secciones.
->El programa debe tener una logica que atienda las peticiones siguientes con funciones:
	*Obtener el numero de espacios disponibles de una seccion (F1)
	*Obtener el numero de espacios no disponibles de una seccion (F2)
	*Obtener ganancias de sección(F3)
	*Registrar vehiculo ingresado(F4)
	*Remover vehiculo(F5)
	*Registrar pago de vehiculo ingresado(F6)
*/

/* Fucniones */
/*
->(F1) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de espacios disponibles de esa seccion
->(F2) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de espacios no disponibles de esa seccion
->(F3) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de dinero acumulada en esa sección
->(F4) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento y permita ingresar un vehiculo a esa seccion
->(F5) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento y permita retirar un vehiculo de la cuenta de la seccion
->(F6) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento y registre el pago por haber ingresado el vehiculo
*/

tstParkingInfo astMyParks[enMaxSectors] = INIT_PARKING_SLOTS;						/*Struct to Use*/

void main ( void )
{
	uint8 u8InputAction = 0;
	tenParkingSectors enSector; 
	uint8 u8ConfirmationFromAction = 0;
	while(1)
	{
		//fflush(stdin);
		printf("Press 1 to -> Read Available Slots\n");
		printf("Press 2 to -> Read Unavailable Slots\n");
		printf("Press 3 to -> Read Earned Money\n");
		printf("Press 4 to -> Enter a Car to a Section\n");
		printf("Press 5 to -> Remove a Car from a Section\n");
		printf("Press 6 to -> Registrar pago\n");
		printf("Enter selection: ");
		scanf("%d", &u8InputAction);
		printf("Action Selected %d\n", u8InputAction );

		printf("Enter Sector from 0 to 4: ");
		scanf("%d", &enSector);
		printf("Sector Selected %d\n", enSector );

		if( enSector < enMaxSectors )
		{
			if( u8InputAction == ACCION_1 )
			{
				ShowAvailableSlots ( enSector );
			}
			else if( u8InputAction == ACCION_2 )
			{
				ShowNotAvailableSlots (enSector );
			}
			else if( u8InputAction == ACCION_3 )
			{
				ShowEarnedMoney ( enSector );
			}
			else if( u8InputAction == ACCION_4 )
			{
				u8AddCarToSector( enSector );
			}
			else if ( u8InputAction == ACCION_5 )
			{
				u8RemoveCarFromSector( enSector );
			}
			else if ( u8InputAction == ACCION_6 )
			{
				u8ImportPaymentOfSlot( enSector );
			}
			else 
			{
				printf("La acción registrada %d no es valida",u8InputAction);
			}
			printf("\n\n");
		}
		else
		{
			printf("El sector no es válido\n");
		}

	}
}

/*F1*/
void ShowAvailableSlots ( tenParkingSectors enCurrentSector )
{
	if(enCurrentSector==0)
	{
		if(astMyParks[enCurrentSector].u8AvailableSlots!=0)
			printf("En el sector %d, se encuentran %d espacios disponibles\n", enCurrentSector, astMyParks[enCurrentSector].u8AvailableSlots);
		else {printf("No hay espacios disponibles en el sector %d \n",enCurrentSector );}
	}
	else  if(enCurrentSector==1)
	{	if(astMyParks[enCurrentSector].u8AvailableSlots!=0)
			printf("En el sector %d, se encuentran %d espacios disponibles\n", enCurrentSector, astMyParks[enCurrentSector].u8AvailableSlots);
		else {printf("No hay espacios disponibles en el sector %d \n",enCurrentSector );}
	}	
	else  if(enCurrentSector==2)
	{	
		if(astMyParks[enCurrentSector].u8AvailableSlots!=0)
			printf("En el sector %d, se encuentran %d espacios disponibles\n", enCurrentSector, astMyParks[enCurrentSector].u8AvailableSlots);
		else {printf("No hay espacios disponibles en el sector %d \n",enCurrentSector );}
	}	
	else  if(enCurrentSector==3)
	{	
		if(astMyParks[enCurrentSector].u8AvailableSlots!=0)
			printf("En el sector %d, se encuentran %d espacios disponibles\n", enCurrentSector, astMyParks[enCurrentSector].u8AvailableSlots);
		else {printf("No hay espacios disponibles en el sector %d \n",enCurrentSector );}
	}	
	else  if(enCurrentSector==4)
	{	
		if(astMyParks[enCurrentSector].u8AvailableSlots!=0)
			printf("En el sector %d, se encuentran %d espacios disponibles\n", enCurrentSector, astMyParks[enCurrentSector].u8AvailableSlots);
		else {printf("No hay espacios disponibles en el sector %d \n",enCurrentSector );}
	}	
	else printf("No seleccionó ningún sector valido\n");
}

/*F2*/
void ShowNotAvailableSlots ( tenParkingSectors enCurrentSector )
{
	if(enCurrentSector==0)
	{
		if(astMyParks[enCurrentSector].u8NotAvailableSlots!=0)
			printf("En el sector %d, se encuentran %d espacios no disponibles\n", enCurrentSector, astMyParks[enCurrentSector].u8NotAvailableSlots);
		else {printf("Todos los espacios están disponibles en el sector %d \n",enCurrentSector );}
	}
	else  if(enCurrentSector==1)
	{	if(astMyParks[enCurrentSector].u8NotAvailableSlots!=0)
			printf("En el sector %d, se encuentran %d espacios no disponibles\n", enCurrentSector, astMyParks[enCurrentSector].u8NotAvailableSlots);
		else {printf("Todos los espacios están disponibles en el sector %d \n",enCurrentSector );}
	}	
	else  if(enCurrentSector==2)
	{	
		if(astMyParks[enCurrentSector].u8NotAvailableSlots!=0)
			printf("En el sector %d, se encuentran %d espacios no disponibles\n", enCurrentSector, astMyParks[enCurrentSector].u8NotAvailableSlots);
		else {printf("Todos los espacios están disponibles en el sector %d \n",enCurrentSector );}
	}	
	else  if(enCurrentSector==3)
	{	
		if(astMyParks[enCurrentSector].u8NotAvailableSlots!=0)
			printf("En el sector %d, se encuentran %d espacios no disponibles\n", enCurrentSector, astMyParks[enCurrentSector].u8NotAvailableSlots);
		else {printf("Todos los espacios están disponibles en el sector %d \n",enCurrentSector );}
	}	
	else  if(enCurrentSector==4)
	{	
		if(astMyParks[enCurrentSector].u8NotAvailableSlots!=0)
			printf("En el sector %d, se encuentran %d espacios no disponibles\n", enCurrentSector, astMyParks[enCurrentSector].u8NotAvailableSlots);
		else {printf("Todos los espacios están disponibles en el sector %d \n",enCurrentSector );}
	}	
	else printf("No seleccionó ningún sector valido\n");
}

/*F3*/
void ShowEarnedMoney ( tenParkingSectors enCurrentSector )
{
	if(enCurrentSector==0)
	{
		if(astMyParks[enCurrentSector].u32MoneyEarn!=0)
			printf("En el sector %d, se ecuentran %d pesos", enCurrentSector, astMyParks[enCurrentSector].u32MoneyEarn);
		else{printf("En el sector %d, no se tiene dinero ingresado",enCurrentSector);}
	}
	else  if(enCurrentSector==1)
	{
		if(astMyParks[enCurrentSector].u32MoneyEarn!=0)
			printf("En el sector %d, se ecuentran %d pesos", enCurrentSector, astMyParks[enCurrentSector].u32MoneyEarn);
		else{printf("En el sector %d, no se tiene dinero ingresado",enCurrentSector);}
	}
	else if(enCurrentSector==2)
	{
		if(astMyParks[enCurrentSector].u32MoneyEarn!=0)
			printf("En el sector %d, se ecuentran %d pesos", enCurrentSector, astMyParks[enCurrentSector].u32MoneyEarn);
		else{printf("En el sector %d, no se tiene dinero ingresado"),enCurrentSector;}		
	}
	else  if(enCurrentSector==3)
	{
		if(astMyParks[enCurrentSector].u32MoneyEarn!=0)
			printf("En el sector %d, se ecuentran %d pesos", enCurrentSector, astMyParks[enCurrentSector].u32MoneyEarn);
		else{printf("En el sector %d, no se tiene dinero ingresado",enCurrentSector);}
	}
	else  if(enCurrentSector==4)
	{	
		if(astMyParks[enCurrentSector].u32MoneyEarn!=0)
			printf("En el sector %d, se ecuentran %d pesos", enCurrentSector, astMyParks[enCurrentSector].u32MoneyEarn);
		else{printf("En el sector %d, no se tiene dinero ingresado",enCurrentSector);}
	}	
	else printf("No seleccionó ningún sector valido\n");

}
/*F4*/
uint8 u8AddCarToSector( tenParkingSectors enCurrentSector )
{
	if(enCurrentSector==0)
	{
		printf("Su coche estará en el sector %d",enCurrentSector);
		astMyParks[enCurrentSector].u8AvailableSlots -= 1;
		astMyParks[enCurrentSector].u8NotAvailableSlots += 1;
	}
	else  if(enCurrentSector==1)
	{
		printf("Su coche estará en el sector %d",enCurrentSector);
		astMyParks[enCurrentSector].u8AvailableSlots -= 1;
		astMyParks[enCurrentSector].u8NotAvailableSlots += 1;
	}
	else if(enCurrentSector==2)
	{
		printf("Su coche estará en el sector %d",enCurrentSector);
		astMyParks[enCurrentSector].u8AvailableSlots -= 1;
		astMyParks[enCurrentSector].u8NotAvailableSlots += 1;
	}
	else  if(enCurrentSector==3)
	{
		printf("Su coche estará en el sector %d",enCurrentSector);
		astMyParks[enCurrentSector].u8AvailableSlots -= 1;
		astMyParks[enCurrentSector].u8NotAvailableSlots += 1;
	}
	else  if(enCurrentSector==4)
	{
		printf("Su coche estará en el sector %d",enCurrentSector);
		astMyParks[enCurrentSector].u8AvailableSlots -= 1;
		astMyParks[enCurrentSector].u8NotAvailableSlots += 1;
	}	
	else printf("\nNo seleccionó ningún sector válido\n");
return astMyParks[enCurrentSector].u8AvailableSlots,astMyParks[enCurrentSector].u8NotAvailableSlots;
}
/*F5*/
uint8 u8RemoveCarFromSector( tenParkingSectors enCurrentSector )
{
	if(enCurrentSector==0)
	{
		printf("Su coche se retiró del sector %d",enCurrentSector);
		astMyParks[enCurrentSector].u8AvailableSlots += 1;
		astMyParks[enCurrentSector].u8NotAvailableSlots -= 1;
	}
	else  if(enCurrentSector==1)
	{
		printf("Su coche se retiró del sector %d",enCurrentSector);
		astMyParks[enCurrentSector].u8AvailableSlots += 1;
		astMyParks[enCurrentSector].u8NotAvailableSlots -= 1;
	}
	else if(enCurrentSector==2)
	{
		printf("Su coche se retiró del sector %d",enCurrentSector);
		astMyParks[enCurrentSector].u8AvailableSlots += 1;
		astMyParks[enCurrentSector].u8NotAvailableSlots -= 1;
	}
	else  if(enCurrentSector==3)
	{
		printf("Su coche se retiró del sector %d",enCurrentSector);
		astMyParks[enCurrentSector].u8AvailableSlots += 1;
		astMyParks[enCurrentSector].u8NotAvailableSlots -= 1;
	}
	else  if(enCurrentSector==4)
	{
		printf("Su coche se retiró del sector %d",enCurrentSector);
		astMyParks[enCurrentSector].u8AvailableSlots += 1;
		astMyParks[enCurrentSector].u8NotAvailableSlots -= 1;
	}	
	else printf("\nNo seleccionó ningún sector válido\n");

return astMyParks[enCurrentSector].u8AvailableSlots,astMyParks[enCurrentSector].u8NotAvailableSlots;
}
/*F6*/
uint8 u8ImportPaymentOfSlot( tenParkingSectors enCurrentSector )
{
	if(enCurrentSector==0 && astMyParks[enCurrentSector].u8NotAvailableSlots>0)
	{
		printf("El costo del estacionamiento son 16 pesos fijos");
		astMyParks[enCurrentSector].u32MoneyEarn += PAGO_16;
		printf("\nVuelva pronto");
	}
	else  if(enCurrentSector==1 && astMyParks[enCurrentSector].u8NotAvailableSlots>0)
	{
		printf("El costo del estacionamiento son 16 pesos fijos");
		astMyParks[enCurrentSector].u32MoneyEarn += PAGO_16;
		printf("\nVuelva pronto");
	}
	else if(enCurrentSector==2 && astMyParks[enCurrentSector].u8NotAvailableSlots>0)
	{
		printf("El costo del estacionamiento son 16 pesos fijos");
		astMyParks[enCurrentSector].u32MoneyEarn += PAGO_16;
		printf("\nVuelva pronto");
	}
	else  if(enCurrentSector==3 && astMyParks[enCurrentSector].u8NotAvailableSlots>0)
	{
		printf("El costo del estacionamiento son 16 pesos fijos");
		astMyParks[enCurrentSector].u32MoneyEarn += PAGO_16;
		printf("\nVuelva pronto");
	}
	else  if(enCurrentSector==4 && astMyParks[enCurrentSector].u8NotAvailableSlots>0)
	{
		printf("El costo del estacionamiento son 16 pesos fijos");
		astMyParks[enCurrentSector].u32MoneyEarn += PAGO_16;
		printf("\nVuelva pronto");
	}	
	else printf("No seleccionó ningún sector válido\n");

return astMyParks[enCurrentSector].u32MoneyEarn;
}