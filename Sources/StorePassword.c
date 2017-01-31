/**
 * \file
 * \brief Implementation of Non-Volatile-Memory storage
 * \author Erich Styger
 *
 * This provides an implementation to store and retrieve data from the on-chip memory.
 */

#include <StorePassword.h>
#include "Flash.h"

static bool isErased(char *ptr, int nofBytes) {
  while (nofBytes>0) {
    if (*ptr!=0xFF) {
      return FALSE; /* byte not erased */
    }
    ptr++;
    nofBytes--;
  }
  return TRUE;
}

char NVMC_SaveSSID_PASSData(void *data, int id) {
  return Flash_SetBlockFlash(data, (Flash_TAddress)(NVMC_SSID_PASS_DATA_START_ADDR) + (id * NVMC_SSID_PASS_DATA_SIZE), NVMC_SSID_PASS_DATA_SIZE);
}

void *NVMC_GetSSID_PASSData(int id) {
  if (isErased((char*)NVMC_SSID_PASS_DATA_START_ADDR + (id * NVMC_SSID_PASS_DATA_SIZE), NVMC_SSID_PASS_DATA_SIZE)) {
    return NULL;
  }
  return (void*)NVMC_SSID_PASS_DATA_START_ADDR;
}
