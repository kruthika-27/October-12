
/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "FRTOS1.h"
#include "MCUC1.h"
#include "UTIL1.h"
#include "UTIL2.h"
#include "ca.h"
#include "BitsIoLdd1.h"
#include "cc.h"
#include "BitsIoLdd2.h"
#include "ledcc.h"
#include "BitsIoLdd3.h"
#include "ledca.h"
#include "BitsIoLdd4.h"
#include "CsIO1.h"
#include "IO1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

SemaphoreHandle_t xSemaphore1;
SemaphoreHandle_t xSemaphore2;
void Task3();
void Task2();

void Task1()
{


printf("Entered task1\n");
printf("Taking semaphore for 1\n");
xSemaphoreTake( xSemaphore1,  portMAX_DELAY ) ;
      
printf("Starting medium priority task\n");
fflush(stdout);
xTaskCreate(Task2,"Task2",100,NULL,11,NULL);

printf("Starting high priority task\n");
fflush(stdout);
xTaskCreate(Task3,"Task3",100,NULL,12,NULL);

xSemaphoreTake( xSemaphore2,portMAX_DELAY ) ;

printf("Returning semaphore from 1\n");
xSemaphoreGive( xSemaphore1 );

printf("Exiting task1\n");
  fflush(stdout);
  vTaskDelay(1000/portTICK_PERIOD_MS);
}


void Task2()
{
printf("Entered medium priority task\n");

//printf("delay2\n");
vTaskDelay(20/portTICK_PERIOD_MS);

  printf("Exiting task2\n");
  fflush(stdout);
  vTaskDelay(1000/portTICK_PERIOD_MS);
}


void Task3()
{
printf("entered high priority task\n");

xSemaphoreTake( xSemaphore2,portMAX_DELAY ) ;

printf("Taking semaphore for 3\n");
xSemaphoreTake( xSemaphore1,  portMAX_DELAY ) ;
       
printf("Returning semaphore from 3\n");
xSemaphoreGive( xSemaphore1 );
       
printf("exiting 3\n");
fflush(stdout);
vTaskDelay(1000/portTICK_PERIOD_MS);
 }

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
 
  //vSemaphoreCreateBinary( xSemaphore );
  xSemaphore1 = xSemaphoreCreateMutex();
  xSemaphore2 = xSemaphoreCreateMutex();
  printf("starting low priority task\n");
  fflush(stdout);
xTaskCreate(Task1,"Task1",100,NULL,10,NULL);




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
