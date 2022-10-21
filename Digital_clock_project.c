/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-21, 12:32, # CodeGen: 0
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
#include "Setmode.h"
#include "BitIoLdd4.h"
#include "Increment.h"
#include "BitIoLdd5.h"
#include "Decrement.h"
#include "BitIoLdd6.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
char tens, units;
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
  
  void to_char(unsigned int value)
  {
	  
	  tens= value/10;
	  units= value%10;
	//lcd_data=(units+48);
  }
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	  int i;
	  char set;
	  char add;
	//char sub;
	//unsigned char units, tens;
	  unsigned char HH=11,MM=42,SS=10;
	  int start_flag=0;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  LCD_init();
  while(1)
  {
  	  Setmode_SetDir(1);
  	  Increment_SetDir(1);
    //Decrement_SetDir(1);
  	  Setmode_PutVal(0x0);
  	  Increment_PutVal(0x0);
    //Decrement_PutVal(0x0);
  	  Setmode_SetDir(0);
  	  set=Setmode_GetVal();
  	  
  	  Setmode_SetDir(1);
  	  Increment_SetDir(1);
  	//Decrement_SetDir(1);
  	  Setmode_PutVal(0x0);
  	  Increment_PutVal(0xf);
    //Decrement_PutVal(0xf);
  	  Increment_SetDir(0);
  	  add=Increment_GetVal();
  	   	  	   	  
  	 /* Setmode_SetDir(1);
  	  Increment_SetDir(1);
  	  Decrement_SetDir(1);
  	  Setmode_PutVal(0x0);
  	  Increment_PutVal(0xf);
  	  Decrement_PutVal(0xf);
  	  Decrement_SetDir(0);
  	  sub=Decrement_GetVal();*/
  	  
  	  
  	
  	  LCD_command(0x80);
  	  to_char(HH);
  	  lcd_data(tens+48);
  	  LCD_command(0x81);
  	  lcd_data(units+48);
  	
  	  
  	  LCD_command(0x82);
  	  LCD_puts(":");
		
  	  LCD_command(0x83);
  	  to_char(MM);
  	  lcd_data(tens+48);
  	  LCD_command(0x84);
  	  lcd_data(units+48);
  
  	  
  	  LCD_command(0x85);
  	  LCD_puts(":");
  	 
  	  LCD_command(0x86);
  	  to_char(SS);
  	  lcd_data(tens+48);
  	  LCD_command(0x87);
  	  lcd_data(units+48);
  	  LCD_Delay;
  	  
  	if(Setmode_GetVal()==0)
  	{
  		start_flag=1;
    }
  	
  	
  	if(Increment_GetVal()==0)
  		{
  			SS=SS+1;
  			/*a=mm/10;
  			b=mm%10;
  			c=ss/10;
  			d=ss%10;*/
  		}
  		
  	if(Increment_GetVal()==0)
  		{
  				MM=MM+1;	
  				/*a=mm/10;
  				b=mm%10;
  				c=ss/10;
  				d=ss%10;*/	
  		}
  	
  	if(Increment_GetVal()==0)
  	  	{
  	  			HH=HH+1;	
  	  		  /*a=mm/10;
  	  			b=mm%10;
  	  			c=ss/10;
  	  			d=ss%10;*/	
  	  	}
  		
  		if(start_flag==1)
  		{		
  			SS=SS+1;
  			if(SS==60)
  			{
  				SS=0;
  				MM=MM+1;
  			}
  		  /*a=mm/10;
  			b=mm%10;
  			c=ss/10;
  			d=ss%10;*/
  			
  			if(MM==60)
  			{
  				MM=0;
  				HH=HH+1;
  			}
  			
  			if(MM==60)
  			{
  				HH=0;
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
