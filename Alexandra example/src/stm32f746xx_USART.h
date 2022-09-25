#ifndef STM32F746xx_USART_H
#define STM32F746xx_USART_H

#include <stdint.h>

//document reference manual page 1067
struct USART_CR1_BITS
{
	uint32_t  UE : 1;
	uint32_t  r1 : 1;
	uint32_t  RE  : 1;
	uint32_t  TE : 1;
	uint32_t  IDLEIE : 1;
	uint32_t  RXNEIE : 1;
	uint32_t  TCIE : 1;
	uint32_t  TXEIE : 1;
	uint32_t  PEIE : 1;
	uint32_t  PS : 1;
	uint32_t  PCE : 1;
	uint32_t  WAKE : 1;
	uint32_t  M0 : 1;
	uint32_t  MME : 1;
	uint32_t  CMIE : 1;
	uint32_t  OVER8 : 1;
	uint32_t  DEDT : 5;
	uint32_t  DEAT : 5;
	uint32_t  RTOIE : 1;
	uint32_t  EOBIE : 1;
	uint32_t  M1 : 1;
	uint32_t  r2 : 3;
	
	//контрольная сумма 32
};

union USART_CR1
{
	uint32_t ALL;
	struct USART_CR1_BITS BIT;
};
////////////////////////////////////

//document reference manual page 1070
struct USART_CR2_BITS
{
	uint32_t  r1 : 4;
	uint32_t  ADDM7 : 1;
	uint32_t  LBDL  : 1;
	uint32_t  LBDIE : 1;
	uint32_t  r2 : 1;
	uint32_t  LBCL : 1;
	uint32_t  CPHA : 1;
	uint32_t  CPOL : 1;
	uint32_t  CLKEN : 1;
	uint32_t  STOP : 2;
	uint32_t  LINEN : 1;
	uint32_t  SWAP : 1;
	uint32_t  RXINV : 1;
	uint32_t  TXINV : 1;
	uint32_t  DATAINV : 1;
	uint32_t  MSBFI_RST : 1;
	uint32_t  ABREN : 1;
	uint32_t  ABRMOD : 2;
	uint32_t  RTOEN : 1;
	uint32_t  ADD : 8;
	
	//контрольная сумма 32
};

union USART_CR2
{
	uint32_t ALL;
	struct USART_CR2_BITS BIT;
};
////////////////////////////////////

//document reference manual page 1073
struct USART_CR3_BITS
{
	uint32_t  EIE : 1;
	uint32_t  IREN  : 1;
	uint32_t  IRLP : 1;
	uint32_t  HDSEL : 1;
	uint32_t  NACK : 1;
	uint32_t  SCEN : 1;
	uint32_t  DMAR : 1;
	uint32_t  DMAT : 1;
	uint32_t  RTSE : 1;
	uint32_t  CTSE : 1;
	uint32_t  CTSIE : 1;
	uint32_t  ONE_BIT : 1;
	uint32_t  OVRDI_S : 1;
	uint32_t  DDRE : 1;
	uint32_t  DEM : 1;
	uint32_t  DEP : 1;
	uint32_t  r1 : 1;
	uint32_t  SCARC_NT0 : 1;
	uint32_t  SCARC_NT1 : 1;
	uint32_t  SCARC_NT2 : 1;
	uint32_t  r2 : 12;
	
	//контрольная сумма 32
};

union USART_CR3
{
	uint32_t ALL;
	struct USART_CR3_BITS BIT;
};
////////////////////////////////////

//document reference manual page 1076
struct USART_BRR_BITS
{
	uint32_t  BRR : 16;
	uint32_t  r1 : 16;
	
	//контрольная сумма 32
};

union USART_BRR
{
	uint32_t ALL;
	struct USART_BRR_BITS BIT;
};
////////////////////////////////////

//document reference manual page 1077
struct USART_GTPR_BITS
{
	uint32_t  PSC : 8;
	uint32_t  GT  : 8;
	uint32_t  r1 : 16;
	
	//контрольная сумма 32
};

union USART_GTPR
{
	uint32_t ALL;
	struct USART_GTPR_BITS BIT;
};
////////////////////////////////////

//document reference manual page 1078
struct USART_RTOR_BITS
{
	uint32_t  RTO : 24;
	uint32_t  BLEN  : 8;
	
	//контрольная сумма 32
};

union USART_RTOR
{
	uint32_t ALL;
	struct USART_RTOR_BITS BIT;
};
////////////////////////////////////

//document reference manual page 1079
struct USART_RQR_BITS
{
	uint32_t  ABRRQ : 1;
	uint32_t  SBKRQ : 1;
	uint32_t  MMRQ : 1;
	uint32_t  RXFRQ : 1;
	uint32_t  TXFRQ : 1;
	uint32_t  r1  : 27;
	
	//контрольная сумма 32
};

union USART_RQR
{
	uint32_t ALL;
	struct USART_RQR_BITS BIT;
};
////////////////////////////////////

//document reference manual page 1080
struct USART_ISR_BITS
{
	uint32_t  PE : 1;
	uint32_t  FE : 1;
	uint32_t  NF : 1;
	uint32_t  ORE : 1;
	uint32_t  IDLE : 1;
	uint32_t  RXNE : 1;
	uint32_t  TC : 1;
	uint32_t  TXE : 1;
	uint32_t  LBDF : 1;
	uint32_t  CTSIF : 1;
	uint32_t  CTS : 1;
	uint32_t  RTOF : 1;
	uint32_t  EOBF : 1;
	uint32_t  r1 : 1;
	uint32_t  ABRE : 1;
	uint32_t  ABRF : 1;
	uint32_t  BUSY : 1;
	uint32_t  CMF : 1;
	uint32_t  SBKF : 1;
	uint32_t  RWU : 1;
	uint32_t  r2 : 1;
	uint32_t  TEACK : 1;
	uint32_t  r3  : 10;
	
	//контрольная сумма 32
};

union USART_ISR
{
	uint32_t ALL;
	struct USART_ISR_BITS BIT;
};
////////////////////////////////////


//document reference manual page 1084
struct USART_ICR_BITS
{
	uint32_t  PECF : 1;
	uint32_t  FECF : 1;
	uint32_t  NFCF : 1;
	uint32_t  ORECF : 1;
	uint32_t  IDLECF : 1;
	uint32_t  r1 : 1;
	uint32_t  TCCF : 1;
	uint32_t  r2 : 1;
	uint32_t  LBDCF : 1;
	uint32_t  CTSICF : 1;
	uint32_t  r3 : 1;
	uint32_t  RTOCF : 1;
	uint32_t  EOBCF : 1;
	uint32_t  r4 : 4;
	uint32_t  CMCF : 1;
	uint32_t  r5  : 14;
	
	//контрольная сумма 32
};

union USART_ICR
{
	uint32_t ALL;
	struct USART_ICR_BITS BIT;
};
////////////////////////////////////

//document reference manual page 1085
struct USART_RDR_BITS
{
	uint32_t  RDR : 9;
	uint32_t  r1  : 24;
	
	//контрольная сумма 32
};

union USART_RDR
{
	uint32_t ALL;
	struct USART_RDR_BITS BIT;
};
////////////////////////////////////

//document reference manual page 1086
struct USART_TDR_BITS
{
	uint32_t  TDR : 9;
	uint32_t  r1  : 24;
	
	//контрольная сумма 32
};

union USART_TDR
{
	uint32_t ALL;
	struct USART_TDR_BITS BIT;
};
////////////////////////////////////

typedef struct 
{
	union USART_CR1 				CR1;
	union USART_CR2 				CR2;
	union USART_CR3 				CR3;
	union USART_BRR 				BRR;
	union USART_GTPR 				GTPR;
	union USART_RTOR 				RTOR;
	union USART_RQR 				RQR;
	union USART_ISR 				ISR;
	union USART_ICR 				ICR;
	union USART_RDR 				RDR;
	union USART_TDR 				TDR;
	
} USART_TypeDef_TIS;
	#endif