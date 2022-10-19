/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-19, 15:45, # CodeGen: 0
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
#include "AnodeLEDs.h"
#include "BitsIoLdd1.h"
#include "RowKeys.h"
#include "BitsIoLdd2.h"
#include "ColKeys.h"
#include "BitsIoLdd3.h"
#include "CathodeLEDs.h"
#include "BitsIoLdd4.h"
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
long int  x,y,i;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  CathodeLEDs_PutVal(0x0);
  AnodeLEDs_PutVal(0xf);
  /* Write your code here */
  while(1)
  {
	  RowKeys_SetDir(1);
	  ColKeys_SetDir(1);
	  RowKeys_PutVal(0x0);
	  ColKeys_PutVal(0xf);
	  
	  ColKeys_SetDir(0);
	  x=ColKeys_GetVal();
	  AnodeLEDs_PutVal(x);
	  for(i=0;i<=0x7ff;i++);
	  
	  RowKeys_SetDir(1);
	  ColKeys_SetDir(1);
	  RowKeys_PutVal(0xf);
	  ColKeys_PutVal(0x0);
	  
	  RowKeys_SetDir(0);
	  y=RowKeys_GetVal();
	  CathodeLEDs_PutVal(~y);
	  for(i=0;i<=0x7ff;i++);
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
 // for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
//
 //   } /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

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
