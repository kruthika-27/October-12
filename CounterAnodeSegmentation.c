/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-18, 11:43, # CodeGen: 0
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

/* User includes (#include below this line is not maintained by Processor Expert) */
int counter (int a)
 {
	 Bits1_PutVal(~a);
	 Bits2_PutVal(0x07);
	 return 0;
 }
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	
  /* Write your local variable definition here */
	char k[]={0x3F,0x06,0x5b,0x4f,0x66,0x6D,0x7d,0x07,0x7f,0x6f,0x77,0x7f,0x39,0x3f,0x79,0x71};
		int a=0x3f;
		int b=0x3f;
		int c=0x3f;
		int d=0x3f;
int i,j,l,m,t;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  
  while(1)
    {
  	  for(j=0;j<16;j++)
  	  {
  		  for(t=0;t<200;t++)
  		  {
  			  Bits2_PutVal(0x0e);
  			  	  Bits1_PutVal(~a);
  			  for(i=0;i<0x7ff;i++);
  			  
  			  Bits2_PutVal(0x0d);
  			  	  Bits1_PutVal(~b);
  			  for(i=0;i<0x7ff;i++);
  			  			  
  			  Bits2_PutVal(0x0b);
  			  	  Bits1_PutVal(~c);
  			  for(i=0;i<0x7ff;i++);
  			  
  			  counter(k[j]);
  			  	for(l=0;l<0x7ff;l++);
  		  }
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
