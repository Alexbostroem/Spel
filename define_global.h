// SYSTICK
#define STK_CTRL ((volatile unsigned int *)(0xE000E010))	// Status och styrregister
#define STK_LOAD ((volatile unsigned int *)(0xE000E014))	// Räknarintervall
#define STK_VAL ((volatile unsigned int *)(0xE000E018))		// Räknarvärde

// PORTAR
#define GPIO_D_BASE 0x40020C00
#define GPIO_D_MODER ((volatile unsigned int *)(GPIO_D_BASE))	
#define GPIO_D_ODR_LOW ((volatile unsigned char *) GPIO_D_BASE + 0x14)	
#define GPIO_D_ODR_HIGH ((volatile unsigned char *) GPIO_D_BASE + 0x15)
#define GPIO_D_ODR ((volatile unsigned short *) GPIO_D_BASE + 0x14)
#define GPIO_D_IDR_LOW ((volatile unsigned char *) GPIO_D_BASE + 0x10)
#define GPIO_D_IDR_HIGH ((volatile unsigned char *) GPIO_D_BASE + 0x11)
#define GPIO_D_OTYPER ((volatile unsigned short *) GPIO_D_BASE + 0x4)
#define GPIO_D_OSPEEDER ((volatile unsigned int *) GPIO_D_BASE + 0x8)
#define GPIO_D_PUPDR ((volatile unsigned int *) GPIO_D_BASE + 0xC)

#define GPIO_E_BASE 0x40021000
#define GPIO_E_MODER ((volatile unsigned int *)(GPIO_E_BASE))	
#define GPIO_E_ODR_LOW ((volatile unsigned char *) GPIO_E_BASE + 0x14)
#define GPIO_E_ODR_HIGH ((volatile unsigned char *) GPIO_E_BASE + 0x15)
#define GPIO_E_ODR ((volatile unsigned short *) GPIO_E_BASE + 0x14)
#define GPIO_E_IDR_LOW ((volatile unsigned char *) GPIO_E_BASE + 0x10)
#define GPIO_E_IDR_HIGH ((volatile unsigned char *) GPIO_E_BASE + 0x11)
#define GPIO_E_OTYPER ((volatile unsigned short *) GPIO_E_BASE + 0x4)
#define GPIO_E_OSPEEDER ((volatile unsigned int *) GPIO_E_BASE + 0x8)
#define GPIO_E_PUPDR ((volatile unsigned int *) GPIO_E_BASE + 0xC)

// ASCII DISPLAY
#define B_E 0x40
#define B_SELECT 0x04
#define B_RW 0x02
#define B_RS 0x01

#define MAX_POINTS 1300
