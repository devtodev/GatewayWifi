/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TSK1.c
**     CDE edition : Community
**     Project     : GatewayWifi
**     Processor   : MKL46Z256VMC4
**     Component   : FreeRTOS_Tasks
**     Version     : Component 01.008, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-01-16, 01:10, # CodeGen: 0
**     Abstract    :
**
**     Settings    :
**          Component Name                                 : TSK1
**          FreeRTOS                                       : FRTOS1
**          Number of tasks                                : 2
**            FreeRTOS task                                : HMITaskTask
**              Task name                                  : HMITask
**              Stack size (plus configMINIMAL_STACK_SIZE) : 1200
**              Initial Priority                           : 0
**            FreeRTOS task                                : GatewayTaskTask
**              Task name                                  : GatewayTask
**              Stack size (plus configMINIMAL_STACK_SIZE) : 1200
**              Initial Priority                           : 0
**     Contents    :
**         CreateTasks - void TSK1_CreateTasks(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Omar Isaí Pinales Ayala, 2014, all rights reserved.
**     http      : http://www.mcuoneclipse.com
**     This an open source software driver for Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file TSK1.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup TSK1_module TSK1 module documentation
**  @{
*/         

/* MODULE TSK1. */

#include "TSK1.h"
#include "frtos_tasks.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
** ===================================================================
**     Method      :  TSK1_CreateTasks (component FreeRTOS_Tasks)
**     Description :
**         Creates the tasks.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TSK1_CreateTasks(void)
{
  CreateTasks();
}


#ifdef __cplusplus
}  /* extern "C" */
#endif
/* END TSK1. */

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
