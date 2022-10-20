/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-20, 14:50, # CodeGen: 0
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
#include "RowKeys.h"
#include "BitsIoLdd2.h"
#include "ColKeys.h"
#include "BitsIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
void LCD_Delay()
  {
	  long int i; 
	  for(i=0;i<0x7ff;i++);
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
	  LCD_command(0x80);
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
	  int i;
	  char row;
	  char column;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  LCD_init();
  	while(1)
  	{
  	  RowKeys_SetDir(1);
  	  ColKeys_SetDir(1);
  	  RowKeys_PutVal(0x0);
  	  ColKeys_PutVal(0xf);
  	  ColKeys_SetDir(0);
  	  column=ColKeys_GetVal();
	  
	  RowKeys_SetDir(1);
	  ColKeys_SetDir(1);
  	  RowKeys_PutVal(0xf);
  	  ColKeys_PutVal(0x0);
	  RowKeys_SetDir(0);
	  row=RowKeys_GetVal();
	  
	  LCD_command(0x80);
		  if(column==0xe)
		  {
			  lcd_data('1');
		  }
		  else if(column==0xd)
		  {
			  lcd_data('2');
		  }
		  else if(column==0xb)
		  {
			  lcd_data('3');
		  }
		  else if(column==0x7)
		  {
			  lcd_data('4');
		  }
	  
	  LCD_command(0xc0);
	  	  if(row==0xe)
	  	  {
	  		  lcd_data('1');
	  	  }
	  	  else if(row==0xd)
	  	  {
	  		  lcd_data('2');
	  	  }
	  	  else if(row==0xb)
	  	  {
	 		  lcd_data('3');
	  	  }
	  	  else if(row==0x7)
	  	  {
	  		  lcd_data('4');
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
