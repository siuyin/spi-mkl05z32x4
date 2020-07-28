/* ###################################################################
 **     Filename    : main.c
 **     Project     : spi-mkl05z32x4
 **     Processor   : MKL05Z32VLF4
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2020-07-28, 11:29, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.01
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "SM1.h"
#include "Bit1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdbool.h>

LDD_TDeviceData* ncs;
LDD_TDeviceData* spi;

void writeAndReadSPI(uint8_t* txBuf, uint8_t* rxBuf) {
	Bit1_ClrVal(ncs);
	SM1_SendBlock(spi, txBuf, 2);
	for (int i = 0; i < 500; i++) {
	}
	SM1_ReceiveBlock(spi, rxBuf, 2);
	Bit1_SetVal(ncs);
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
	ncs = Bit1_Init(NULL);
	spi = SM1_Init(NULL);
	uint8_t txBuf[2];
	uint8_t rxBuf[2];

	txBuf[0] = 0x03;
	txBuf[1] = 0x40;
	writeAndReadSPI(txBuf, rxBuf);
	while (1) {
		txBuf[0] = 0x0f;
		txBuf[1] = 0xff;
		writeAndReadSPI(txBuf, rxBuf);
//		Bit1_ClrVal(ncs);
//		SM1_SendBlock(spi, txBuf, 2);
//		for (int i = 0; i < 1000; i++) {
//		}
//		SM1_ReceiveBlock(spi, rxBuf, 2);
//		Bit1_SetVal(ncs);
	}

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
	/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
	PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of RTOS startup code.  ***/
	/*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
	for (;;) {
	}
	/*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.5 [05.21]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
