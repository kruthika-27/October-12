/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-14, 11:24, # CodeGen: 0
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
#include "Bit1.h"
#include "BitIoLdd1.h"
#include "Bit2.h"
#include "BitIoLdd2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
int i,j,k,Val;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  
  while(1)
     {
   	  if(Bit1_GetVal()==0)
   	  {
   		  while(Bit1_GetVal()==0);
   		  {
   			  k=0x01;
   			  for(j=0;j<=7;j++)
   			  {
   				  Bits1_PutVal(k^0x0f);
   			   	  for(i=0;i<=0xffff;i++);
   			   	  	  k=k<<1;
   			  }
   			     
   		  }
   		  //Bit1_NegVal();
   		  //for(i=0;i<0xffff;i++);
   	  }
   	  
   	  if(Bit2_GetVal()==0)
   	  {
   		  k=0x80;
   		  while(Bit2_GetVal()==0);
   		  {
   			  for(j=0;j<=7;j++)
   			  {
   				  Bits1_PutVal(k^0x0f);
   	  			  for(i=0;i<=0xffff;i++);
   	  			  	  k=k>>1;
   			  }
   		  }
   	  		  //Bit3_NegVal();
   	  		  //for(i=0;i<0xffff;i++);
   	  }
     }
 /* void Run_right()
     {
   	  k=0x01;
   	  for(j=0;j<=l;j++)
   	  {
   		  Bits1_PutVal(k^0x0f);
   		  for(i=0; i<=0x7ffff;i++);
   		  k=k<<1;
   	  }
     }
     
     void Run_left()
      {
    	  for(j=0;j<=l;j++)
    	  {
    		  Bits1_PutVal(k^0x0f);
    		  for(i=0; i<=0x7ffff;i++);
    		  k=k>>1;
    	  }
      }*/
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
