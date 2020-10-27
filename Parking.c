#include "stdio.h"
#include "stdlib.h"
#include "parking.h"

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct
{
	uint8 u8MaxSlots;
	uint8 u8AvailableSlots;
	uint8 u8NotAvailableSlots;
	uint32 u32MoneyEarn;
}tstParkingInfo;

typedef enum
{
	enSector0 = 0,
	enSector1,
	enSector2,
	enSector3,
	enSector4,
	enMaxSectors
}tenParkingSectors;

#define MaxInputAction      5
#define SECTOR0_SLOTS		5
#define SECTOR1_SLOTS		10
#define SECTOR2_SLOTS		25
#define SECTOR3_SLOTS		7
#define SECTOR4_SLOTS		12

#define INIT_PARKING_SLOTS		\
{								\
	{SECTOR0_SLOTS,SECTOR0_SLOTS,0,0},					\
	{SECTOR1_SLOTS,SECTOR1_SLOTS,0,0},					\
	{SECTOR2_SLOTS,SECTOR2_SLOTS,0,0},					\
	{SECTOR3_SLOTS,SECTOR3_SLOTS,0,0},					\
	{SECTOR4_SLOTS,SECTOR4_SLOTS,0,0},					\
}


void ShowAvailableSlots ( tenParkingSectors enCurrentSector );
void ShowNotAvailableSlots ( tenParkingSectors enCurrentSector );
void ShowEarnedMoney ( tenParkingSectors enCurrentSector );
uint8 u8AddCarToSector( tenParkingSectors enCurrentSector );
uint8 u8RemoveCarFromSector( tenParkingSectors enCurrentSector );
void u8ImportPaymentOfSlot( tenParkingSectors enCurrentSector );


/********************************************************************Main***********************************************************************************/

tstParkingInfo askMyParks[enMaxSectors] = INIT_PARKING_SLOTS;						/*Struct to Use*/

void main ( void )
{
    uint8 Referencia=0;
	uint8 u8InputAction = 0;
	tenParkingSectors enSector; 
	uint8 u8ConfirmationFromAction = 0;
	while(1)
	{
	    Referencia=0;
		fflush(stdin);                                                            //limpieza del buffer de entrada
		printf("Press 1 to -> Read Available Slots\n");
		printf("Press 2 to -> Read Unavailable Slots\n");
		printf("Press 3 to -> Read Earned Money($10 por carro)\n");
		printf("Press 4 to -> Enter a Car to a Section\n");
		printf("Press 5 to -> Remove a Car from a Section\n");
		printf("Press 6 to -> Print ticket\n");
		printf("Enter selection: ");
		scanf("%d", &u8InputAction);
		printf("Action Selected %d\n", u8InputAction );
		printf("Enter Sector from 0 to 4: ");
		scanf("%d", &enSector);
		printf("Sector Selected %d\n", enSector );
		    if( enSector < enMaxSectors )
		    {
			    if( u8InputAction == 1 )
			    {
			        ShowAvailableSlots(enSector);    
			    }
			    else if( u8InputAction == 2 )
			    {
			        ShowNotAvailableSlots(enSector);    
			    }
			    else if( u8InputAction == 3 )
			    {
			        ShowEarnedMoney(enSector);    
			    }
			    else if( u8InputAction == 4 )
			    {
			        Referencia=u8AddCarToSector(enSector);
			        if(Referencia==1)
			        {
			            askMyParks[enSector].u8AvailableSlots--;  
			            askMyParks[enSector].u8NotAvailableSlots++; 
			            askMyParks[enSector].u32MoneyEarn+=10; 
			        }
			        else
			        {
			            /*nothing to do*/
			        }
			    }
			    else if ( u8InputAction == 5 )
			    {
			        Referencia=u8RemoveCarFromSector(enSector);
			        if(Referencia==1)
			        {
			            askMyParks[enSector].u8AvailableSlots++;  
			            askMyParks[enSector].u8NotAvailableSlots--;
			        }
			        else
			        {
			            /*nothing to do*/
			        }
			    }
			    else if ( u8InputAction == 6 )
			    {
			        u8ImportPaymentOfSlot(enSector);
			    }
                			        
			 
		        printf("\n\n");
		    }
		    else
	    	{
			/*Not a valid sector*/
		    }
        }
}

/*F1*/
void ShowAvailableSlots (tenParkingSectors enCurrentSector)
{
    if(askMyParks[enCurrentSector].u8AvailableSlots!=0)
    {
        printf("En el sector %d se encontraron %d espacios disponibles",enCurrentSector,askMyParks[enCurrentSector].u8AvailableSlots);    
    }
    else
    {
        printf("\nLo sentimos,el sector esta lleno");
    }
}

/*F2*/
void ShowNotAvailableSlots ( tenParkingSectors enCurrentSector )
{
    printf("En el sector %d estan ocupados %d espacios ",enCurrentSector,askMyParks[enCurrentSector].u8NotAvailableSlots);    
}

/*F3*/
void ShowEarnedMoney ( tenParkingSectors enCurrentSector )
{
    printf("Ingresos obtenidos en el sector %d: $%d",enCurrentSector,askMyParks[enCurrentSector].u32MoneyEarn);
}
/*F4*/
uint8 u8AddCarToSector( tenParkingSectors enCurrentSector )
{
    uint8 Acarreo=0;
    if(askMyParks[enCurrentSector].u8NotAvailableSlots!=askMyParks[enCurrentSector].u8MaxSlots)
    {
        Acarreo=1; 
        printf("\nSu carro a sido agregado correctamente al sector %d",enCurrentSector);
    }
    else
    {
        printf("\nLo sentimos, este sector esta lleno");
    }
    return Acarreo;
}
/*F5*/
uint8 u8RemoveCarFromSector( tenParkingSectors enCurrentSector )
{
    uint8 Acarreo=0;
    if(askMyParks[enCurrentSector].u8NotAvailableSlots!=0)
    {
        Acarreo=1; 
        printf("\nCarro retirado del sector %d correctamente",enCurrentSector);
    }
    else
    {
        printf("\nError: No se puede remover en la seccion %d porque no hay carros", enCurrentSector);
    }
    return Acarreo;
}
/*F6*/
void u8ImportPaymentOfSlot( tenParkingSectors enCurrentSector )
{
    if(askMyParks[enCurrentSector].u8NotAvailableSlots!=0)
    {
        printf("\n%cTicket Su carro en el sector %d se le cobro una tarifa de $10. Gracias por su preferencia",enCurrentSector,askMyParks[enCurrentSector].u8AvailableSlots);
    }
    else
    {
        printf("Ticket error. No cars available");
    }
}
