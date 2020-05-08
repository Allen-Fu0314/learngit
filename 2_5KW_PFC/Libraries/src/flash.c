/******************************************************************************
 * @file     flash.c
 * @brief    FLASH firmware functions.
 * @version  V1.4.0
 * @date     18-July-2019
 *
 * @note
 * Copyright (C) 2019 Spintrol Limited. All rights reserved.
 *
 * @attention
 * THIS SOFTWARE JUST PROVIDES CUSTOMERS WITH CODING INFORMATION REGARDING 
 * THEIR PRODUCTS, WHICH AIMS AT SAVING TIME FOR THEM. SPINTROL SHALL NOT BE
 * LIABLE FOR THE USE OF THE SOFTWARE. SPINTROL DOES NOT GUARANTEE THE 
 * CORRECTNESS OF THIS SOFTWARE AND RESERVES THE RIGHT TO MODIFY THE SOFTWARE 
 * WITHOUT NOTIFICATION.
 *
 ******************************************************************************/

#include "flash.h"




/******************************************************************************
 * @brief      Read word data
 *
 * @param[in]  pu32Buf    :  Pointer to the array stored data to be readed
 * @param[in]  u32Addr    :  The start address to be readed
 * @param[in]  u32NumWords:  Number of words to be readed
 *
 * @return     none
 *
 ******************************************************************************/
void FLASH_Read(uint32_t *pu32Buf, uint32_t u32Addr, uint32_t u32NumWords)
{
  /* Variable for loop */
  uint32_t i;
  
  /* Disable XIP */
  FLASH_DisableXIP();

  /* Read data */
  for(i = 0; i < u32NumWords; i++)
  {
    /* Set command and address */
    FLASH->FLASHADDR.all = u32Addr + i*4;
    FLASH->FLASHCTL.all = (0x1UL << FLASHCTL_ALL_EXECUTION_Pos) | 
                            FLASH_CMD_READ;

    /* Wait for command execution finished */
    while(FLASH->FLASHCTL.all & FLASHCTL_ALL_EXECUTION_Msk);

    /* Get data */
    pu32Buf[i] = FLASH->FLASHDOUT.all;
  }
  
  /* Enable XIP */
  FLASH_EnableXIP();
  __NOP();
  __NOP();
}




/******************************************************************************
 * @brief      Program a word data
 *
 * @param[in]  u32Data:  Word data to be written
 * @param[in]  u32Addr:  The address to be written
 *
 * @return     SUCCESS or ERROR
 *
 ******************************************************************************/
ErrorStatus FLASH_ProgramWord(uint32_t u32Data, uint32_t u32Addr)
{
  /* Disable XIP */
  FLASH_DisableXIP();
  
  /* Set command and address */
  FLASH->FLASHADDR.all = u32Addr;
  FLASH->FLASHCTL.all = (0x1UL << FLASHCTL_ALL_EXECUTION_Pos) | 
                          FLASH_CMD_PROG_WORD;

  /* Check whether command is valid and accepted */
  if((FLASH->FLASHCTL.all & FLASHCTL_ALL_EXECUTION_Msk) == 0)
  {
    return ERROR;
  }

  /* Wait for data acceptable */
  while((FLASH->FLASHCTL.all & FLASHCTL_ALL_DATAACCEPT_Msk) == 0);

  /* Set data */
  FLASH->FLASHDIN.all = u32Data;

  /* Wait for command execution finished */
  while(FLASH->FLASHCTL.all & FLASHCTL_ALL_EXECUTION_Msk);
  
  /* Enable XIP */
  FLASH_EnableXIP();
  __NOP();
  __NOP();
  
  return SUCCESS;
}




/******************************************************************************
 * @brief      Program word data
 *
 * @param[in]  pu32Buf    :  Pointer to the array stored data to be written
 * @param[in]  u32Addr    :  The start address to be written
 * @param[in]  u32NumWords:  Number of words to be written
 *
 * @return     SUCCESS or ERROR
 *
 ******************************************************************************/
ErrorStatus FLASH_Program(uint32_t *pu32Buf, uint32_t u32Addr, uint32_t u32NumWords)
{
  /* Variable for loop */
  uint32_t i;
  
  /* Disable XIP */
  FLASH_DisableXIP();
  
  /* Program data */
  for(i = 0; i < u32NumWords; i++)
  {
    /* Set command and address */
    FLASH->FLASHADDR.all = u32Addr + i*4;
    FLASH->FLASHCTL.all = (0x1UL << FLASHCTL_ALL_EXECUTION_Pos) | 
                            FLASH_CMD_PROG_WORD;

    /* Check whether command is valid and accepted */
    if((FLASH->FLASHCTL.all & FLASHCTL_ALL_EXECUTION_Msk) == 0)
    {
      /* Enable XIP */
      FLASH_EnableXIP();
      __NOP();
      __NOP();
      
      return ERROR;
    }

    /* Wait for data acceptable */
    while((FLASH->FLASHCTL.all & FLASHCTL_ALL_DATAACCEPT_Msk) == 0);

    /* Set data */
    FLASH->FLASHDIN.all = pu32Buf[i];

    /* Wait for command execution finished */
    while(FLASH->FLASHCTL.all & FLASHCTL_ALL_EXECUTION_Msk);
  }
  
  /* Enable XIP */
  FLASH_EnableXIP();
  __NOP();
  __NOP();
  
  return SUCCESS;
}




/******************************************************************************
 * @brief      Erase flash sector
 *
 * @param[in]  u32SectorAddr:  Sector address, align in 128 words
 *
 * @return     none
 *
 ******************************************************************************/
void FLASH_EraseSector(uint32_t u32SectorAddr)
{
  /* Disable XIP */
  FLASH_DisableXIP();
  
  /* Set command and address */
  FLASH->FLASHADDR.all = u32SectorAddr;
  FLASH->FLASHCTL.all = (0x1UL << FLASHCTL_ALL_EXECUTION_Pos) | 
                          FLASH_CMD_ERASE_SECTOR;

  /* Wait for command execution finished */
  while(FLASH->FLASHCTL.all & FLASHCTL_ALL_EXECUTION_Msk);
  
  /* Enable XIP */
  FLASH_EnableXIP();
  __NOP();
  __NOP();
}




/******************************************************************************
 * @brief      Erase flash chip
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
void FLASH_EraseChip(void)
{
  /* Disable XIP */
  FLASH_DisableXIP();
  
  /* Set command and address */
  FLASH->FLASHADDR.all = FLASH_START_ADDR;
  FLASH->FLASHCTL.all  = (0x1UL << FLASHCTL_ALL_EXECUTION_Pos) | 
                          FLASH_CMD_ERASE_CHIP;

  /* Wait for command execution finished */
  while(FLASH->FLASHCTL.all & FLASHCTL_ALL_EXECUTION_Msk);
  
  /* Enable XIP */
  FLASH_EnableXIP();
  __NOP();
  __NOP();
}




/******************************************************************************
 * @brief      Enable write protect for the specified area
 *
 * @param[in]  u32StartAddr:  Flash protect start address
 * @param[in]  u32EndAddr  :  Flash protect end address
 *
 * @return     none
 *
 ******************************************************************************/
void FLASH_WriteProtect(uint32_t u32StartAddr, uint32_t u32EndAddr)
{
  uint32_t i;
  uint32_t u32StartUnit;
  uint32_t u32EndUnit;
  
  /* Get Flash start and end unit for protect */
  u32StartUnit = u32StartAddr / 0x400;
  u32EndUnit   = u32EndAddr / 0x400;
  
  /* Set Write Protect */
  for(i = u32StartUnit; i <= u32EndUnit; i++)
  {
    if(i < 32)
    {
      FLASH->FLASHWP0.all |= (0x1UL << i);
    }
    else if(i < 64)
    {
      FLASH->FLASHWP1.all |= (0x1UL << (i - 32));
    }
    else if(i < 96)
    {
      FLASH->FLASHWP2.all |= (0x1UL << (i - 64));
    }
    else if(i < 128)
    {
      FLASH->FLASHWP3.all |= (0x1UL << (i - 96));
    }
  }
}




/******************************************************************************
 * @brief      Set Flash timing parameters
 *
 * @param[in]  u32ClkFreq:  System clock frequency (Hz)
 *
 * @return     SUCCESS or ERROR
 *
 ******************************************************************************/
ErrorStatus FLASH_SetTiming(uint32_t u32ClkFreq)
{
  uint32_t cycle_ps;
  uint32_t cycle_us;
  uint32_t cycle_ms;
  uint32_t tnvschip;
  uint32_t tnvssec;
  uint32_t taa;
  uint32_t taeph;
  uint32_t tms;
  uint32_t tus;
  uint32_t tsce;
  uint32_t tsbe;
  uint32_t tsse;
  uint32_t trcvprog;
  uint32_t tpgh;
  uint32_t tprog;
  uint32_t tpgs;
  uint32_t tconfen;
  uint32_t tcfs;
  uint32_t taar;
  uint32_t taps;
  uint32_t tpreprog;
  uint32_t tcfh;
  uint32_t tcfl;
  uint32_t trw;
  uint32_t tds;
  uint32_t trcverase;
  uint32_t trsvread;
  uint32_t trsrecall;
  uint32_t taavr;
  uint32_t flashtiming0;
  uint32_t flashtiming1;
  uint32_t flashtiming2;
  uint32_t flashtiming3;
  uint32_t flashtiming4;
  uint32_t flashtiming5;

  /* Calculate timing parameters */
  cycle_ps     = (uint32_t)(1000000000000ULL / u32ClkFreq);
  
  tus          = (uint32_t)(500000 / cycle_ps);          // Tus: Resolution is 0.5us
  cycle_us     = cycle_ps * (tus + 1);
  tms          = (uint32_t)(130000000 / cycle_us);       // Tms: Resolution is 0.13ms
  cycle_ms     = cycle_us * (tms + 1) / 1000;
  tsbe         = (uint32_t)(4000000 / cycle_ms);         // From 4ms to 6ms
  tsse         = (uint32_t)(3200000 / cycle_ms);         // From 3.2ms to 4ms
  flashtiming1 = (tms << 21) | (tus << 12) | (tsbe << 6) | tsse;

  tnvschip     = (uint32_t)(10000000 / cycle_us);        // Above 10us
  tnvssec      = (uint32_t)(4000000 / cycle_us);         // Above 4us
  taeph        = (uint32_t)(10000 / cycle_ps);           // Above 10ns
  taa          = (uint32_t)(35000 / cycle_ps) - taeph;   // Above 35ns
  if(taa > 0)
  {
    taa        = taa - 1;
  }
  flashtiming0 = (tnvschip << 24) | (tnvssec << 18) | (taa << 6) | taeph;

  trcvprog     = (uint32_t)(5000000 / cycle_us);         // Above 5us
  tpgh         = (uint32_t)(15000 / cycle_ps);           // Above 15ns
  tprog        = (uint32_t)(8000000 / cycle_us);         // From 8us to 10us
  tpgs         = (uint32_t)(20000000 / cycle_us);        // Above 20us
  tsce         = (uint32_t)(8000000 / cycle_ms);         // From 8ms to 10ms
  flashtiming2 = (trcvprog << 24) | (tpgh << 18) | (tprog << 12) | (tpgs << 6) | tsce;

  tconfen      = (uint32_t)(15000 / cycle_ps);           // Above 15ns
  tcfs         = (uint32_t)(15000 / cycle_ps);           // Above 15ns
  taar         = (uint32_t)(200000 / cycle_ps);          // Below 200ns
  taps         = (uint32_t)(15000 / cycle_ps);           // Above 15ns
  tpreprog     = (uint32_t)(2500000 / cycle_us);         // From 2.5us to 3.5us
  flashtiming3 = (tconfen << 24) | (tcfs << 18) | (taar << 12) | (taps << 6) | tpreprog;

  tcfh         = (uint32_t)(15000 / cycle_ps);           // Above 15ns
  tcfl         = (uint32_t)(10000000 / cycle_us);        // Above 10us
  trw          = (uint32_t)(100000 / cycle_ps);          // Above 100ns
  tds          = (uint32_t)(15000 / cycle_ps);           // Above 15ns
  trcverase    = (uint32_t)(50000000 / cycle_us);        // Above 50us
  flashtiming4 = (trcverase << 24) | (tcfl << 18) | (tcfh << 12) | (trw << 6) | tds;

  trsvread     = (uint32_t)(10000000 / cycle_us);        // Above 10us
  trsrecall    = (uint32_t)(10000 / cycle_ps);           // Above 10ns
  taavr        = (uint32_t)(200000 / cycle_ps);          // Above 200ns
  flashtiming5  = (trsvread << 12) | (trsrecall << 6) | taavr;

  /* Set timing parameters */
  FLASH->FLASHTIMING0.all = flashtiming0;
  FLASH->FLASHTIMING1.all = flashtiming1;
  FLASH->FLASHTIMING2.all = flashtiming2;
  FLASH->FLASHTIMING3.all = flashtiming3;
  FLASH->FLASHTIMING4.all = flashtiming4;
  FLASH->FLASHTIMING5.all = flashtiming5;

  /* Check timing parameters */
  if((FLASH->FLASHTIMING0.all == flashtiming0) &&
     (FLASH->FLASHTIMING1.all == flashtiming1) &&
     (FLASH->FLASHTIMING2.all == flashtiming2) &&
     (FLASH->FLASHTIMING3.all == flashtiming3) &&
     (FLASH->FLASHTIMING4.all == flashtiming4) &&
     (FLASH->FLASHTIMING5.all == flashtiming5))
  {
    return SUCCESS;
  }
  else
  {
    return ERROR;
  }
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
