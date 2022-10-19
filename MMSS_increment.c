/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-19, 12:16, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Bits1.h"
#include "BitsIoLdd1.h"
#include "Bits2.h"
#include "BitsIoLdd2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#define seg1 Bits2_PutVal(0xe);
#define seg2 Bits2_PutVal(0xd);
#define seg3 Bits2_PutVal(0xb);
#define seg4 Bits2_PutVal(0x7);
/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	 int i[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	 unsigned char mm,ss;
	 int m1, m0, s1, s0, j, k;	

	  mm=50;
	  ss=20;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  int display(int a, int b, int c, int d)
  {
  	int i, j;
  	for(j=0;j<=100;j++)
  	{
  		Bits1_PutVal(~a);
  		seg1;
  		for(i=0;i<=0xfff;i++);
  		
  		Bits1_PutVal(~b);
  		seg2;	
  		for(i=0;i<=0xfff;i++);
  				
  		Bits1_PutVal(~c);
  		seg3;			
  		for(i=0;i<=0xfff;i++);
  						
  		Bits1_PutVal(~d);
  		seg4;					
  		for(i=0;i<=0xfff;i++);
  	}
  	return 0;
  }
   
  while(1)
  {
	  for(j=mm;j<59;j++)
	  {
		  m1=j/10;
		  m0=j%10;
		  for(k=ss;k<59;k++)
		  {
			  s1=k/10;
			  s0=k%10;
			  display (i[m1],i[m0],i[s1],i[s0]);
		  }
		  ss=0;
	  }
  }
  

  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
