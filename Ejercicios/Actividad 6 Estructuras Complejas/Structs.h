
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

#define SECTOR0_SLOTS		5
#define SECTOR1_SLOTS		10
#define SECTOR2_SLOTS		25
#define SECTOR3_SLOTS		7
#define SECTOR4_SLOTS		12
#define PAGO_16 			16
#define ACCION_1 			1
#define ACCION_2 			2
#define ACCION_3 			3
#define ACCION_4 			4
#define ACCION_5 			5
#define ACCION_6 			6

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
uint8 u8ImportPaymentOfSlot( tenParkingSectors enCurrentSector );
