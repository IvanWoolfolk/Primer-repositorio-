/*DATA TYPES*/

typedef unsigned char uint8;
typedef unsigned char uint16;


/*DEFINES*/

#define ArraySize 16 
#define ARRAY_EXAMPLE_VALID {4,1,6,8,8,1,8,8,4,4,4,4,7,1,1,5} 
#define ARRAY_EXAMPLE_INVALID {5,8,8,8,1,4,1,9,0,8,8,8,8,8,8,5} 
#define MOD_2 2 
#define OPERACION_MOD 9
#define MAX_NUM10 10

/*Function Prototypes*/ 
uint8 u8LuhnCheck(uint8 *pu8Data); 

