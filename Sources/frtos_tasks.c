
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

/* Begin of <includes> initialization, DO NOT MODIFY LINES BELOW */

#include "TSK1.h"
#include "FRTOS1.h"
#include "frtos_tasks.h"

/* End <includes> initialization, DO NOT MODIFY LINES ABOVE */

#include "utils.h"
#include "BT_actions.h"
#include "WIFI_actions.h"
#include "SW1.h"
#include "SW2.h"
#include "SW3.h"
#include "SW4.h"
#include "SW5.h"
#include "SW6.h"
#include "UTIL1.h"
#include "LCD/LCDConfig.h"
static portTASK_FUNCTION(GatewayTask, pvParameters) {

  initGateway();
  for(;;) {
    xSemaphoreTake(xSemaphoreWifiATCommand, portMAX_DELAY);
    readBuffer();
  }
  /* Destroy the task */
  vTaskDelete(GatewayTask);
}

static portTASK_FUNCTION(HMITask, pvParameters) {
  char menuConectado[MENUMAXLENGHT][64] = {"Switch 1", "Switch 2", "Switch 3", "Switch 4", "Switch 5", "Switch 6", "Desconectar"};
  char opcionHIM[30];
  int i;
  /* Write your task initialization code here ... */
  BT_init();
  MySegLCDPtr = SegLCD1_Init(NULL);


  for(;;) {
	  setLCD("9991");
	  SymbolON(11,0);
	  xSemaphoreTake(xSemaphoreWifiRefresh, portMAX_DELAY);
	  switch (connection.status)
	  {
	  	  case WIFI_DISCONNECTED:
		    // necesito obtener los spots
	  		BT_sendSaltoLinea();BT_sendSaltoLinea();BT_sendSaltoLinea();BT_sendSaltoLinea();
	  		BT_showString("Agro Robots WiFi Spot");
	  		BT_sendSaltoLinea();BT_sendSaltoLinea();
	  		FRTOS1_vTaskDelay(1000/portTICK_RATE_MS);
	  		refreshWifiSpots();
	  		xSemaphoreTake(xSemaphoreWifiRefresh, portMAX_DELAY);
	  		if (SSIDStoredVisible())
	  		{
	  			strcpy(connection.ssid, storeSSID);
	  			strcpy(connection.password, storePassword);
	  		} else {
				// mostrar los SSIDs
				if (BT_showMenu(&spotSSID, &connection.ssid[0]) != -69)
				{
					// setPassword
					BT_sendSaltoLinea();
					BT_showString("Seleccion: ");
					BT_showString(&connection.ssid[0]);
					BT_sendSaltoLinea();
					BT_askValue("Password: ", &connection.password[0]);
					// showDetails
					BT_sendSaltoLinea();BT_sendSaltoLinea();
					BT_showString("SSID: ");
					BT_showString(&connection.ssid[0]);
					BT_sendSaltoLinea();
					BT_showString("PASSWORD: ");
					BT_showString(&connection.password[0]);
					BT_sendSaltoLinea();
			  		// try to connect
					tryToConnect();
				} else {
					xSemaphoreGive(xSemaphoreWifiRefresh);
					for (i = 0; i < 100; i++) BT_sendSaltoLinea();
				}
	  		}
		  break;
	  	  case WIFI_CONNECTING:
	  		FRTOS1_vTaskDelay(2000/portTICK_RATE_MS);
	  		connectionMode();
			xSemaphoreTake(xSemaphoreWifiRefresh, portMAX_DELAY);
			FRTOS1_vTaskDelay(1000/portTICK_RATE_MS);
			connectingToServer();
		  break;
	  	  case WIFI_CONNECTED:
	  		switch (BT_showMenu(&menuConectado, &opcionHIM[0]))
	  		{
				case 0:
					SW1_NegVal();
					if (SW1_GetVal())
						sendInfo("1|1");
					else
						sendInfo("1|0");
				break;
				case 1:
					SW2_NegVal();
					if (SW1_GetVal())
						sendInfo("2|1");
					else
						sendInfo("2|0");
				break;
				case 2:
					SW3_NegVal();
					if (SW1_GetVal())
						sendInfo("3|1");
					else
						sendInfo("3|0");
				break;
				case 3:
					SW4_NegVal();
					if (SW1_GetVal())
						sendInfo("4|1");
					else
						sendInfo("4|0");
				break;
				case 4:
					SW5_NegVal();
					if (SW1_GetVal())
						sendInfo("5|1");
					else
						sendInfo("5|0");
				break;
				case 5:
					SW6_NegVal();
					if (SW1_GetVal())
						sendInfo("6|1");
					else
						sendInfo("6|0");
				break;
				case 6:
					disconectFromSpot();
				break;
				case -69:
					xSemaphoreGive(xSemaphoreWifiRefresh);
					for (i = 0; i < 100; i++) BT_sendSaltoLinea();
				break;
	  		}
		  break;
	  }
  }
  /* Destroy the task */
  vTaskDelete(HMITask);
}

void CreateTasks(void) {
  if (FRTOS1_xTaskCreate(
     GatewayTask,  /* pointer to the task */
      "Gateway", /* task name for kernel awareness debugging */
      1200, /* task stack size */
      (void*)NULL, /* optional task startup argument */
      tskIDLE_PRIORITY + 1,  /* initial priority */
      (xTaskHandle*)NULL /* optional task handle to create */
    ) != pdPASS) {
      /*lint -e527 */
      for(;;){}; /* error! probably out of memory */
      /*lint +e527 */
  }

  if (FRTOS1_xTaskCreate(
     HMITask,  /* pointer to the task */
      "HMI", /* task name for kernel awareness debugging */
      1200, /* task stack size */
      (void*)NULL, /* optional task startup argument */
      tskIDLE_PRIORITY + 0,  /* initial priority */
      (xTaskHandle*)NULL /* optional task handle to create */
    ) != pdPASS) {
      /*lint -e527 */
      for(;;){}; /* error! probably out of memory */
      /*lint +e527 */
  }
}

