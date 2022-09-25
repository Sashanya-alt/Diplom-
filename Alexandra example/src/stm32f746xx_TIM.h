#ifndef stm32f746xx_TIM_H
#define stm32f746xx_TIM_H

#include <stdint.h>

//стр 707 пункт 22.4.1
struct TIMx_CR1_BITS
{
	uint32_t  CEN 	: 1;
	uint32_t  UDIS 	: 1;
	uint32_t  URS 	: 1;
	uint32_t  OPM 	: 1;
	uint32_t  DIR 	: 1; 	
	uint32_t  CSM 	: 2;	
	uint32_t  ARPE 	: 1;
	uint32_t  CKD 	: 2;	
	uint32_t  r1 		: 1;
	uint32_t  UIFRE_MAP 	: 1;
	uint32_t  r2 		: 20;
	 
	//контрольная сумма 32
};

union TIMx_CR1
{
	uint32_t 							ALL;
	struct TIMx_CR1_BITS 	BIT;
};

//////////////////////////////////////


//стр 708 пункт 22.4.2
struct TIMx_CR2_BITS
{
	uint32_t  CCPC 	: 1;
	uint32_t  r1 		: 1;
	uint32_t  CCUS 	: 1;
	uint32_t  CCDS 	: 1;
	uint32_t  MMS 	: 3;
	uint32_t  TI1S 	: 1;
	uint32_t  OIS1 	: 1;
	uint32_t  OIS1N : 1;
	uint32_t  OIS2 	: 1;
	uint32_t  OIS2N : 1;
	uint32_t  OIS3 	: 1;
	uint32_t  OIS3N	: 1;
	uint32_t  OIS4 	: 1;
	uint32_t  r2 	: 1;
	uint32_t  OIS5	: 1;
	uint32_t  r3 	: 1;
	uint32_t  OIS6 	: 1;
	uint32_t  r4 	: 1;
	uint32_t  MMS2 	: 4;	
	uint32_t  r5 	: 8;

	//контрольная сумма 32
};

union TIMx_CR2
{
	uint32_t 							ALL;
	struct TIMx_CR2_BITS 	BIT;
};
///////////////////////////////////


//стр 711 пункт 22.4.3
struct TIMx_SMCR_BITS
{
	uint32_t  SMS_1 	: 3;
	uint32_t  OCCS 	: 1;
	uint32_t  TS 		: 3;
	uint32_t  MSM 	: 1;
	uint32_t  ETF		: 4;
	uint32_t  ETPS	: 2;
	uint32_t  ECE		: 1;
	uint32_t  ETP		: 1;
	uint32_t  SMS_2 	: 1;
	uint32_t  res2 	: 15;

	//контрольная сумма 32
};

union TIMx_SMCR
{
	uint32_t 							ALL;
	struct TIMx_SMCR_BITS 	BIT;
};
////////////////////////////////////

//стр 713 пункт 22.4.4
struct TIMx_DIER_BITS
{
	uint32_t  UIE 		: 1;
	uint32_t  CC1IE 	: 1;
	uint32_t  CC2IE 	: 1;
	uint32_t  CC3IE 	: 1;
	uint32_t  CC4IE 	: 1;
	uint32_t  COMIE 	: 1;
	uint32_t  TIE 		: 1;
	uint32_t  BIE 		: 1;
	uint32_t  UDE 		: 1;
	uint32_t  CC1DE 	: 1;
	uint32_t  CC2DE 	: 1;
	uint32_t  CC3DE 	: 1;
	uint32_t  CC4DE 	: 1;
	uint32_t  COMDE 	: 1;
	uint32_t  TDE 		: 1;
	uint32_t  res4 		: 17;
	//контрольная сумма 32
};

union TIMx_DIER
{
	uint32_t 							ALL;
	struct TIMx_DIER_BITS 	BIT;
};
////////////////////////////////////////////

//стр 715 пункт 22.4.5
struct TIMx_SR_BITS
{
	uint32_t  UIF 		: 1;
	uint32_t  CC1IF 	: 1;
	uint32_t  CC2IF 	: 1;
	uint32_t  CC3IF 	: 1;
	uint32_t  CC4IF 	: 1;
	uint32_t  COMIF 	: 1;
	uint32_t  TIF 		: 1;
	uint32_t  BIF 		: 1;
	uint32_t  B2IF 		: 1;
	uint32_t  CC1OF 	: 1;
	uint32_t  CC2OF 	: 1;
	uint32_t  CC3OF 	: 1;
	uint32_t  CC4OF 	: 1;
	uint32_t  SBIF 	: 1;	
	uint32_t  r1 		: 2;
	uint32_t  CC5IF 	: 1;
	uint32_t  CC6IF 	: 1;	
	uint32_t  r2 		: 14;
	//контрольная сумма 32
};

union TIMx_SR
{
	uint32_t 						ALL;
	struct TIMx_SR_BITS 	BIT;
};
///////////////////////////////////////

//стр 717 пункт 22.4.6
struct TIMx_EGR_BITS
{
	uint32_t  UG 		: 1;
	uint32_t  CC1G 	: 1;
	uint32_t  CC2G 	: 1;
	uint32_t  CC3G 	: 1;
	uint32_t  CC4G 	: 1;
	uint32_t  COMG 	: 1;
	uint32_t  TG 		: 1;
	uint32_t  BG 		: 1;
	uint32_t  B2G 	: 1;
	uint32_t  res2 	: 23;
	//контрольная сумма 32
};

union TIMx_EGR
{
	uint32_t 							ALL;
	struct TIMx_EGR_BITS 	BIT;
};
////////////////////////////////////

//стр 718 пункт 22.4.7
struct TIMx_CCMR1_BITS
{
	uint32_t  CC1S 		: 2;
	uint32_t  OC1FE 		: 1;
	uint32_t  OC1PE 	: 1;
	uint32_t  OC1M_1 		: 3;
	uint32_t  OC1CE 	: 1;
	uint32_t  CC2S 		: 2;
	uint32_t  OC2FE 	: 1;
	uint32_t  OC2PE 	: 1;
	uint32_t  OC2M_1 		: 3;
	uint32_t  OC2CE 	: 1;
	uint32_t  OC1M_2 	: 1;
	uint32_t  r1 		: 7;
	uint32_t  OC2M_2 	: 1;
	uint32_t  r2 		: 7;
	//контрольная сумма 32
};

union TIMx_CCMR1
{
	uint32_t 								ALL;
	struct TIMx_CCMR1_BITS 	BIT;
};
///////////////////////////////////


//стр 722 пункт 22.4.8
struct TIMx_CCMR2_BITS
{
	uint32_t  CC3S 		: 2;
	uint32_t  OC3FE 	: 1;
	uint32_t  OC3PE 	: 1;
	uint32_t  OC3M_1 		: 3;
	uint32_t  OC3CE 	: 1;
	uint32_t  CC4S 		: 2;
	uint32_t  OC4FE 	: 1;
	uint32_t  OC4PE 	: 1;
	uint32_t  OC4M_1 		: 3;
	uint32_t  OC4CE 	: 1;
	uint32_t  OC3M_2 	: 1;	
	uint32_t  r1 		: 7;
		uint32_t  OC4M_2 		: 1;
	uint32_t  r2 		: 7;	
	//контрольная сумма 32
};

union TIMx_CCMR2
{
	uint32_t 								ALL;
	struct TIMx_CCMR2_BITS 	BIT;
};
///////////////////////////////////

//стр 724 пункт 22.4.9
struct TIMx_CCER_BITS
{
	uint32_t  CC1E 		: 1;
	uint32_t  CC1P 		: 1;
	uint32_t  CC1NE 	: 1;
	uint32_t  CC1NP 	: 1;
	uint32_t  CC2E 		: 1;
	uint32_t  CC2P 		: 1;
	uint32_t  CC2NE 	: 1;
	uint32_t  CC2NP 	: 1;
	uint32_t  CC3E 		: 1;
	uint32_t  CC3P 		: 1;
	uint32_t  CC3NE 	: 1;
	uint32_t  CC3NP 	: 1;
	uint32_t  CC4E 		: 1;
	uint32_t  CC4P 		: 1;
	uint32_t  r1 		: 1;
	uint32_t  CC4NP 	: 1;
	uint32_t  CC5E 		: 1;
	uint32_t  CC5P 		: 1;	
	uint32_t  r2 		: 2;
	uint32_t  CC6E 		: 1;
	uint32_t  CC6P 		: 1;
	uint32_t  r3 		: 10;
	
	//контрольная сумма 32
};

union TIMx_CCER
{
	uint32_t 							ALL;
	struct TIMx_CCER_BITS 	BIT;
};
////////////////////////////////////////////

//стр 728 пункт 22.4.10
struct TIMx_CNT_BITS
{
	uint32_t  CNT_1 	: 16;
	uint32_t	CNT_2	: 15;
	uint32_t  UIFCPY 	: 1;	

	//контрольная сумма 32
};

union TIMx_CNT
{
	uint32_t 							ALL;
	struct TIMx_CNT_BITS 	BIT;
};
/////////////////////////////////////

//стр 728 пункт 22.4.11
struct TIMx_PSC_BITS
{
	uint32_t  PSC 	: 16;
	uint32_t	res1 	: 16;

	//контрольная сумма 32
};

union TIMx_PSC
{
	uint32_t 							ALL;
	struct TIMx_PSC_BITS 	BIT;
};
///////////////////////////////////////

//стр 728 пункт 22.4.12
struct TIMx_ARR_BITS
{
	uint32_t  ARR_1 	: 16;
	uint32_t	ARR_2 	: 16;

	//контрольная сумма 32
};

union TIMx_ARR
{
	uint32_t 							ALL;
	struct TIMx_ARR_BITS 	BIT;
};
///////////////////////////////////////

//стр 728 пункт 22.4.13
struct TIMx_RCR_BITS
{
	uint32_t  REP 	: 16;
	uint32_t	r1 	: 16;

	//контрольная сумма 32
};

union TIMx_RCR
{
	uint32_t 							ALL;
	struct TIMx_RCR_BITS 	BIT;
};
/////////////////////////////////////////////

//стр 729 пункт 22.4.14
struct TIMx_CCR1_BITS
{
	uint32_t  CCR1_1 	: 16;
	uint32_t	CCR1_2 	: 16;

	//контрольная сумма 32
};

union TIMx_CCR1
{
	uint32_t 							ALL;
	struct TIMx_CCR1_BITS 	BIT;
};
//////////////////////////////////

//стр 730 пункт 22.4.15
struct TIMx_CCR2_BITS
{
	uint32_t  CCR2_1 	: 16;
	uint32_t	CCR2_2	: 16;

	//контрольная сумма 32
};

union TIMx_CCR2
{
	uint32_t 							ALL;
	struct TIMx_CCR2_BITS 	BIT;
};
/////////////////////////////////////

//стр 730 пункт 22.4.16
struct TIMx_CCR3_BITS
{
	uint32_t  CCR3_1 	: 16;
	uint32_t	CCR3_2 	: 16;

	//контрольная сумма 32
};

union TIMx_CCR3
{
	uint32_t 							ALL;
	struct TIMx_CCR3_BITS 	BIT;
};
////////////////////////////////////////////

//стр 730 пункт 22.4.17
struct TIMx_CCR4_BITS
{
	uint32_t  CCR4_1 	: 16;
	uint32_t	CCR4_2 	: 16;

	//контрольная сумма 32
};

union TIMx_CCR4
{
	uint32_t 							ALL;
	struct TIMx_CCR4_BITS 	BIT;
};
///////////////////////////////////////

//стр 730 пункт 22.4.18
struct TIMx_BDTR_BITS
{
	uint32_t  DTG 	: 8;
	uint32_t	LOCK 	: 2;
	uint32_t	OSSI 	: 1;
	uint32_t	OSSR 	: 1;
	uint32_t	BKE 	: 1;
	uint32_t	BKP 	: 1;
	uint32_t	AOE 	: 1;
	uint32_t	MOE 	: 1;
	uint32_t	BKF 	: 4;
	uint32_t	BK2F 	: 4;
	uint32_t	BK2E 	: 1;
	uint32_t	BK2P 	: 1;
	uint32_t	r1 	: 6;

	//контрольная сумма 32
};

union TIMx_BDTR
{
	uint32_t 							ALL;
	struct TIMx_BDTR_BITS 	BIT;
};
///////////////////////////////////

//стр 734 пункт 22.4.19
struct TIMx_DCR_BITS
{
	uint32_t  DBA 	: 5;
	uint32_t	r1 	: 3;
	uint32_t  DBL 	: 5;
	uint32_t	r2 	: 19;

	//контрольная сумма 32
};

union TIMx_DCR
{
	uint32_t 								ALL;
	struct TIMx_DCR_BITS 		BIT;
};
///////////////////////////////////

//стр 734 пункт 22.4.20
struct TIMx_DMAR_BITS
{
	uint32_t  DMAB_1 	: 16;
	uint32_t	DMAB_2 	: 16;

	//контрольная сумма 32
};

union TIMx_DMAR
{
	uint32_t 							ALL;
	struct TIMx_DMAR_BITS 	BIT;
};
////////////////////////////////////

//стр 736 пункт 22.4.21
struct TIMx_CCMR3_BITS
{
	uint32_t	r1 			: 2;
	uint32_t 	OC5FE 	: 1;
	uint32_t 	OC5PE 	: 1;	
	uint32_t 	OC5M_1	: 3;
	uint32_t 	OC5CE 	: 1;
	uint32_t	r2 			: 2;
	uint32_t	OC6FE 	: 1;	
	uint32_t	OC6PE 	: 1;	
	uint32_t	OC6M_1 	: 3;
	uint32_t 	OC6CE 	: 1;
	uint32_t 	OC5M_2 	: 1;
	uint32_t	r3 			: 7;
	uint32_t	OC6M_2 	: 1;
	uint32_t	r4 			: 7;
	//контрольная сумма 32
};

union TIMx_CCMR3
{
	uint32_t 						ALL;
	struct TIMx_CCMR3_BITS 	BIT;
};
///////////////////////////////////////

//стр 737 пункт 22.4.22
struct TIMx_CCR5_BITS
{
	uint32_t	CCR5 			: 16;
	uint32_t	r1 			: 13;
	uint32_t	GC5C1 	: 1;
	uint32_t	GC5C2 	: 1;
	uint32_t	GC5C3 	: 1;
	//контрольная сумма 32
};

union TIMx_CCR5
{
	uint32_t 						ALL;
	struct TIMx_CCR5_BITS 	BIT;
};
///////////////////////////////////////


//стр 738 пункт 22.4.23
struct TIMx_CCR6_BITS
{
	uint32_t	CCR6 			: 16;
	uint32_t	r1 			: 16;
	//контрольная сумма 32
};

union TIMx_CCR6
{
	uint32_t 						ALL;
	struct TIMx_CCR6_BITS 	BIT;
};
///////////////////////////////////////

//стр 809 пункт 23.4.19
struct TIMx_OR_BITS
{
	uint32_t	TI1_RMP 			: 2;
	uint32_t	r0 			: 4;
	uint32_t	ITR1_RMP_1 			: 2;
	uint32_t	r1 			: 2;
	uint32_t	ITR1_RMP_2 			: 2;	
	uint32_t  r2 		: 20;
	//контрольная сумма 32
};

union TIMx_OR
{
	uint32_t 						ALL;
	struct TIMx_OR_BITS 	BIT;
};
///////////////////////////////////////


typedef struct 
{
	union TIMx_CR1 		CR1;
	union TIMx_CR2 		CR2;
	union TIMx_SMCR		SMCR;			
	union TIMx_DIER 		DIER;
	union TIMx_SR 			SR;
	union TIMx_EGR 		EGR;
	union TIMx_CCMR1		CCMR1;
	union TIMx_CCMR2		CCMR2;
	union TIMx_CCER 		CCER;		
	union TIMx_CNT 		CNT;
	union TIMx_PSC 		PSC;
	union TIMx_ARR 		ARR;
	union TIMx_RCR			RCR;
	union TIMx_CCR1		CCR1;
	union TIMx_CCR2		CCR2;
	union TIMx_CCR3		CCR3;
	union TIMx_CCR4		CCR4;
	union TIMx_BDTR		BDTR;
	union TIMx_DCR			DCR;
	union TIMx_DMAR		DMAR;
	union TIMx_OR		OR;	
	union TIMx_CCMR3			CCMR3;
	union TIMx_CCR5			CCR5;	
		union TIMx_CCR6			CCR6;	
	
}	TIM_TypeDef_TIS;
#endif
