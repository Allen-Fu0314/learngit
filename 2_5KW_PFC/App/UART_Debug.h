#include "spc1168.h"

typedef struct
{
    float Vinrms;
    float I;
    float PLLvalue;
    uint16_t Vout;
    uint16_t Pwm_period;
    uint8_t SysState;
    uint16_t FaultState;
    
}UART_TX_MESSAGE;

typedef struct
{
   uint8_t u8_RestartFlag;
    uint32_t u32_RestartCountMs;
}RESETVAL;

    
void MotorDebug_UART(void);
int16_t MotorDebug_UART_Command_Comm(uint8_t UART_Cmd);
int16_t MotorDebug_UART_Command_Special(UART_TX_MESSAGE tx_message, short UART_Cmd);
void UART_DataCollection(void);
void Sys_Restart(void);



