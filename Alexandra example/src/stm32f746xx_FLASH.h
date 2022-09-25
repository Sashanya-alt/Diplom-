///
/*
//file stm32h743xx.h

 line  951 register definition
 line  10503 bits definition

  doc en.DM00314099.pdf
	page 137 Embedded Flash
	page 229 FLASH register map
	*/
	#include <stdint.h>

#define FLASH_START        (0x08000000U)
#define FLASH_BANK_SIZE    (0x00100000U)
#define FLASH_SECTOR_SIZE   0x00020000

/* Flash Keys */
#define FLASH_KEY1           0x45670123  /* Flash key1 */
#define FLASH_KEY2           0xCDEF89AB  /* Flash key2: used with FLASH_KEY1 to unlock the FLASH registers access */
#define FLASH_PDKEY1         0x04152637  /* Flash power down key1 */
#define FLASH_PDKEY2         0xFAFBFCFD  /* Flash power down key2: used with FLASH_PDKEY1 to unlock the RUN_PD bit in FLASH_ACR */
#define FLASH_OPTKEY1        0x08192A3B  /* Flash option byte key1 */
#define FLASH_OPTKEY2        0x4C5D6E7F  /* Flash option byte key2: used with FLASH_OPTKEY1*/


////////////////////////////////////////////////////////////////
//FLASH access control register (FLASH_ACR)
//page 91
struct FLASH_ACR_BITS
{
	uint32_t LATENCY  : 4;
	uint32_t r0 			: 4;
	uint32_t PRFTEN 	: 1;
	uint32_t ARTEN  	: 1;
	uint32_t r1 			: 1;
	uint32_t ARTRST 	: 1;
	uint32_t r2 			: 20;
	
};
union FLASH_ACR_REG
{
	uint32_t all;
	struct FLASH_ACR_BITS bit;
};
////////////////////////////////////////////////////////////
//FLASH status register for bank 1 (FLASH_SR)
//page 93
struct FLASH_SR_BITS
{
	uint32_t EOP : 1;
	uint32_t OPERR : 1;
	uint32_t r0 : 2;
	uint32_t WRPERR : 1;
	uint32_t PGAERR : 1;
	uint32_t PGPERR : 1;
	uint32_t ERSERR : 1;
	uint32_t r1 : 8;
	uint32_t BSY : 1;
	uint32_t r2 : 15;
	
};

union FLASH_SR_REG
{
	uint32_t all;
	struct FLASH_SR_BITS bit;
};
////////////////////////////////////////////////////////////////
//Flash control register (FLASH_CR)
//page 94
struct FLASH_CR_BITS
{

	uint32_t PG : 1;
	uint32_t SER : 1;
	uint32_t MER : 1;
	uint32_t SNB : 4;
	uint32_t r0 : 1;
	uint32_t PSIZE : 2;
	uint32_t r1 : 6;
	uint32_t START1 : 1;
	uint32_t r2 : 7;
	uint32_t EOPIE : 1;
	uint32_t ERRIE : 1;
	uint32_t r3 : 5;
	uint32_t LOCK :1;
	
	
};
union FLASH_CR_REG
{
	uint32_t all;
	struct FLASH_CR_BITS bit;
};
////////////////////////////////////////////////////////////////
//FLASH option control register (FLASH_OPTCR)
//page 95
struct FLASH_OPTCR_BITS
{
	uint32_t OPTLOCK : 1;
	uint32_t OPTSTART : 1;
	uint32_t BOR_LEV  : 2;
	uint32_t WWDG_SW  : 1;
	uint32_t IWDG_SW : 1;
	uint32_t nRST_STOP : 1;
	uint32_t nRST_STDBY : 1;
	uint32_t RDP : 8;
	uint32_t nWRP : 8;
	uint32_t  r0 : 6;
	uint32_t IWDG_STDBY : 1;
	uint32_t IWDG_STOP : 1;
	
};
union FLASH_OPTCR_REG
{
	uint32_t all;
	struct FLASH_OPTCR_BITS bit;
};
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

typedef struct
{
	
  union FLASH_ACR_REG ACR;      /*!< FLASH access control register,                             offset: 0x00  */
  uint32_t KEYR;           			/*!< Flash Key Register for bank1,                              offset: 0x04  */
  uint32_t OPTKEYR;         		/*!< Flash Option Key Register,                                 offset: 0x08  */
	union FLASH_SR_REG SR;        /*!< Flash Status Register for bank1,                           offset: 0x0C  */
  
	union FLASH_CR_REG CR;         /*!< Flash Control Register for bank1,                          offset: 0x10  */
  union FLASH_OPTCR_REG  OPTCR;  /*!< Flash Option Control Register,                             offset: 0x14  */
	uint32_t OPTCR1;  

} FLASH_TypeDef2;
