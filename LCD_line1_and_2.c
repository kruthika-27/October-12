/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-20, 09:48, # CodeGen: 0
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
#include "DisplayKeys.h"
#include "BitsIoLdd1.h"
#include "RS.h"
#include "BitIoLdd1.h"
#include "RW.h"
#include "BitIoLdd2.h"
#include "Enable.h"
#include "BitIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
 void LCD_Delay()
  {
	  long int i; 
	  for(i=0;i<0x7fff;i++);
  }
  
  void LCD_command(unsigned char command)
  {
	  DisplayKeys_PutVal(command);
	  RS_PutVal(0);
	  RW_PutVal(0);
	  Enable_PutVal(1);
	  LCD_Delay(1);
	  Enable_PutVal(0);
  }
  
  void LCD_init()
  {
	  LCD_command(0x38);
	  LCD_command(0x0f);
	  LCD_command(0x01);
	  LCD_command(0x84);
	  LCD_command(0x06);
  }
  
  void lcd_data(unsigned char data)
  {
	  DisplayKeys_PutVal(data);
	  RS_PutVal(1);
	  RW_PutVal(0);
	  Enable_PutVal(1);
	  LCD_Delay(1);
	  Enable_PutVal(0);
  }
  
  void LCD_puts(unsigned char *lcd_string)
  {
	  while(*lcd_string)
	  {
		  lcd_data(*lcd_string++);
	  }
  }
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */


  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
	LCD_init();
	while(1)
	{
		LCD_puts("HELLO");
		LCD_command(0xc6);
		LCD_puts("BOSCH");
		while(1);
	}
  /*while(1)
  {
	  LCD_Init;
	  LCD_command;
	  LCD_data;
	  LCD_display;
  }
  */
  
 
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
