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
/*Function Prototypes*/
void GENFUN_vCAPSON (uint8 *pu8Src, uint8 u8SizeOfList);
void GENFUN_vCAPSOFF (uint8 *pu8Src, uint8 u8SizeOfList);
uint8 GENFUN_u8GetOccurence (uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList);
void GENFUN_u8MemSet (uint8 *pu8Src, uint8 u8Char2Set, uint8 u8SizeOfList);