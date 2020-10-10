/*DATA TYPES*/

typedef unsigned char uint8;
typedef unsigned char uint16;
typedef unsigned char uint32;

/*Definitions*/
#define ASCII_HIGH_THRESHOLD_OFF_ON 123
#define ASCII_LOW_THRESHOLD_OFF_ON 96
#define ASCII_CONVERTION_FACTOR 32
#define ASCII_LOW_THRESHOLD_OFF_OFF 64
#define ASCII_HIGH_THRESHOLD_OFF_OFF 91
#define TARGET_VALUE 111                   //111ASCI='o'
#define VALUE_ARRAY 11
#define ARRAY_SIZE 12
#define CHAR2SET_VALUE 101
#define ARRAY_NUM_VALUE {4,5,0,7,2,8,8,7,8,9,1,1}
#define ARRAY_NUM_VALUE0 {0,0,0,0,0,0,0,0,0,0,0,0}
#define MAX_VALUE 255
#define MAX_VALUE2 254
#define MinRand 20
#define MaxRand 40
#define MaxChain 50
#define CARACTER 124



/*Function Prototypes*/
void GENFUN_vCAPSON (uint8 *pu8Src, uint8 u8SizeOfList);
void GENFUN_vCAPSOFF (uint8 *pu8Src, uint8 u8SizeOfList);
uint8 GENFUN_u8GetOccurence (uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList);
void GENFUN_u8MemSet (uint8 *pu8Src, uint8 u8Char2Set, uint8 u8SizeOfList);
uint8 GENFUN_u8GetAverage (uint8 *pu8Src, uint8 u8SizeOfList);
void GENFUN_u8MemCopy (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList);
void GENFUN_vSortList (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList);
void GENFUN_vSoftSignal (uint8 *pu8Src, uint8 *pu8Dest);
void GENFUN_vFilterSignal (uint32 *pu32Src, uint32 *pu32Dest, uint32 u32MinRand) ;
