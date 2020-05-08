;/**************************************************************************//**
; * @file     startup_ARMCM4.s
; * @brief    CMSIS Core Device Startup File for
; *           ARMCM4 Device Series
; * @version  V1.08
; * @date     23. November 2012
; *
; * @note
; *
; ******************************************************************************/
;/* Copyright (c) 2011 - 2012 ARM LIMITED
;
;   All rights reserved.
;   Redistribution and use in source and binary forms, with or without
;   modification, are permitted provided that the following conditions are met:
;   - Redistributions of source code must retain the above copyright
;     notice, this list of conditions and the following disclaimer.
;   - Redistributions in binary form must reproduce the above copyright
;     notice, this list of conditions and the following disclaimer in the
;     documentation and/or other materials provided with the distribution.
;   - Neither the name of ARM nor the names of its contributors may be used
;     to endorse or promote products derived from this software without
;     specific prior written permission.
;   *
;   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
;   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
;   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
;   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
;   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
;   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
;   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
;   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
;   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;   POSSIBILITY OF SUCH DAMAGE.
;   ---------------------------------------------------------------------------*/
;/*
;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
;*/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000400

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     MEM_IRQHandler            ;  0 Memory Error IRQHandler
                DCD     POWER_IRQHandler          ;  1 Power Error IRQHandler
                DCD     CLOCK_IRQHandler          ;  2 Clock Error IRQHandler
                DCD     WDT1_IRQHandler           ;  3 Watchdog 1 IRQHandler
                DCD     GPIO_LEVEL_IRQHandler     ;  4 GPIO Level IRQHandler
                DCD     GPIO_EDGE_IRQHandler      ;  5 GPIO Edge IRQHandler
                DCD     SIO0A_IRQHandler          ;  6 SIO0 Int A IRQHandler
                DCD     SIO0B_IRQHandler          ;  7 SIO0 Int B IRQHandler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     UART_IRQHandler           ; 12 UART IRQHandler
                DCD     SSP_IRQHandler            ; 13 SSP IRQHandler
                DCD     I2C_IRQHandler            ; 14 I2C IRQHandler
                DCD     ADC0_IRQHandler           ; 15 ADC EOC0  IRQHandler
                DCD     ADC1_IRQHandler           ; 16 ADC EOC1  IRQHandler
                DCD     ADC2_IRQHandler           ; 17 ADC EOC2  IRQHandler
                DCD     ADC3_IRQHandler           ; 18 ADC EOC3  IRQHandler
                DCD     ADC4_IRQHandler           ; 19 ADC EOC4  IRQHandler
                DCD     ADC5_IRQHandler           ; 20 ADC EOC5  IRQHandler
                DCD     ADC6_IRQHandler           ; 21 ADC EOC6  IRQHandler
                DCD     ADC7_IRQHandler           ; 22 ADC EOC7  IRQHandler
                DCD     ADC8_IRQHandler           ; 23 ADC EOC8  IRQHandler
                DCD     ADC9_IRQHandler           ; 24 ADC EOC9  IRQHandler
                DCD     ADC10_IRQHandler          ; 25 ADC EOC10 IRQHandler
                DCD     ADC11_IRQHandler          ; 26 ADC EOC11 IRQHandler
                DCD     ADC12_IRQHandler          ; 27 ADC EOC12 IRQHandler
                DCD     ADC13_IRQHandler          ; 28 ADC EOC13 IRQHandler
                DCD     ADC14_IRQHandler          ; 29 ADC EOC14 IRQHandler
                DCD     ADC15_IRQHandler          ; 30 ADC EOC15 IRQHandler
                DCD     ADCPPU0_IRQHandler        ; 31 ADC PPU0 IRQHandler
                DCD     ADCPPU1_IRQHandler        ; 32 ADC PPU1 IRQHandler
                DCD     ADCPPU2_IRQHandler        ; 33 ADC PPU2 IRQHandler
                DCD     ADCPPU3_IRQHandler        ; 34 ADC PPU3 IRQHandler
                DCD     ADCPPU4_IRQHandler        ; 35 ADC PPU4 IRQHandler
                DCD     ADCPPU5_IRQHandler        ; 36 ADC PPU5 IRQHandler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PWM0_IRQHandler           ; 39 PWM0 IRQHandler
                DCD     PWM1_IRQHandler           ; 40 PWM1 IRQHandler
                DCD     PWM2_IRQHandler           ; 41 PWM2 IRQHandler
                DCD     PWM3_IRQHandler           ; 42 PWM3 IRQHandler
                DCD     PWM4_IRQHandler           ; 43 PWM4 IRQHandler
                DCD     PWM5_IRQHandler           ; 44 PWM5 IRQHandler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PWM0TZ_IRQHandler         ; 47 PWM0 Trip-Zone IRQHandler
                DCD     PWM1TZ_IRQHandler         ; 48 PWM1 Trip-Zone IRQHandler
                DCD     PWM2TZ_IRQHandler         ; 49 PWM2 Trip-Zone IRQHandler
                DCD     PWM3TZ_IRQHandler         ; 50 PWM3 Trip-Zone IRQHandler
                DCD     PWM4TZ_IRQHandler         ; 51 PWM4 Trip-Zone IRQHandler
                DCD     PWM5TZ_IRQHandler         ; 52 PWM5 Trip-Zone IRQHandler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     ECAP_IRQHandler           ; 55 ECAP IRQHandler
                DCD     TIMER0_IRQHandler         ; 56 Timer0 IRQHandler
                DCD     TIMER1_IRQHandler         ; 57 Timer1 IRQHandler
                DCD     TIMER2_IRQHandler         ; 58 Timer2 IRQHandler
                DCD     CRC_IRQHandler            ; 59 CRC IRQHandler
                DCD     AES_IRQHandler            ; 60 AES IRQHandler
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                
                ; Remap vector table
                LDR     R0, =__Vectors
                LDR     R1, =0xE000ED08 ;*VTOR register
                STR     R0,[R1]

                ;* C routines are likely to be called. Setup the stack now
                LDR     SP,=__initial_sp

                LDR     R0, = SystemInit
                BLX     R0

                ;* Reset stack pointer before zipping off to user application
                LDR     SP,=__initial_sp
                
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  MEM_IRQHandler            [WEAK]
                EXPORT  POWER_IRQHandler          [WEAK]
                EXPORT  CLOCK_IRQHandler          [WEAK]
                EXPORT  WDT1_IRQHandler           [WEAK]
                EXPORT  GPIO_LEVEL_IRQHandler     [WEAK]
                EXPORT  GPIO_EDGE_IRQHandler      [WEAK]
                EXPORT  SIO0A_IRQHandler          [WEAK]
                EXPORT  SIO0B_IRQHandler          [WEAK]
                EXPORT  UART_IRQHandler           [WEAK]
                EXPORT  SSP_IRQHandler            [WEAK]
                EXPORT  I2C_IRQHandler            [WEAK]
                EXPORT  ADC0_IRQHandler           [WEAK]
                EXPORT  ADC1_IRQHandler           [WEAK]
                EXPORT  ADC2_IRQHandler           [WEAK]
                EXPORT  ADC3_IRQHandler           [WEAK]
                EXPORT  ADC4_IRQHandler           [WEAK]
                EXPORT  ADC5_IRQHandler           [WEAK]
                EXPORT  ADC6_IRQHandler           [WEAK]
                EXPORT  ADC7_IRQHandler           [WEAK]
                EXPORT  ADC8_IRQHandler           [WEAK]
                EXPORT  ADC9_IRQHandler           [WEAK]
                EXPORT  ADC10_IRQHandler          [WEAK]
                EXPORT  ADC11_IRQHandler          [WEAK]
                EXPORT  ADC12_IRQHandler          [WEAK]
                EXPORT  ADC13_IRQHandler          [WEAK]
                EXPORT  ADC14_IRQHandler          [WEAK]
                EXPORT  ADC15_IRQHandler          [WEAK]
                EXPORT  ADCPPU0_IRQHandler        [WEAK]
                EXPORT  ADCPPU1_IRQHandler        [WEAK]
                EXPORT  ADCPPU2_IRQHandler        [WEAK]
                EXPORT  ADCPPU3_IRQHandler        [WEAK]
                EXPORT  ADCPPU4_IRQHandler        [WEAK]
                EXPORT  ADCPPU5_IRQHandler        [WEAK]
                EXPORT  PWM0_IRQHandler           [WEAK]
                EXPORT  PWM1_IRQHandler           [WEAK]
                EXPORT  PWM2_IRQHandler           [WEAK]
                EXPORT  PWM3_IRQHandler           [WEAK]
                EXPORT  PWM4_IRQHandler           [WEAK]
                EXPORT  PWM5_IRQHandler           [WEAK]
                EXPORT  PWM0TZ_IRQHandler         [WEAK]
                EXPORT  PWM1TZ_IRQHandler         [WEAK]
                EXPORT  PWM2TZ_IRQHandler         [WEAK]
                EXPORT  PWM3TZ_IRQHandler         [WEAK]
                EXPORT  PWM4TZ_IRQHandler         [WEAK]
                EXPORT  PWM5TZ_IRQHandler         [WEAK]
                EXPORT  ECAP_IRQHandler           [WEAK]
                EXPORT  TIMER0_IRQHandler         [WEAK]
                EXPORT  TIMER1_IRQHandler         [WEAK]
                EXPORT  TIMER2_IRQHandler         [WEAK]
                EXPORT  CRC_IRQHandler            [WEAK]
                EXPORT  AES_IRQHandler            [WEAK]

MEM_IRQHandler
POWER_IRQHandler
CLOCK_IRQHandler
WDT1_IRQHandler
GPIO_LEVEL_IRQHandler
GPIO_EDGE_IRQHandler
SIO0A_IRQHandler
SIO0B_IRQHandler
UART_IRQHandler
SSP_IRQHandler
I2C_IRQHandler
ADC0_IRQHandler
ADC1_IRQHandler
ADC2_IRQHandler
ADC3_IRQHandler
ADC4_IRQHandler
ADC5_IRQHandler
ADC6_IRQHandler
ADC7_IRQHandler
ADC8_IRQHandler
ADC9_IRQHandler
ADC10_IRQHandler
ADC11_IRQHandler
ADC12_IRQHandler
ADC13_IRQHandler
ADC14_IRQHandler
ADC15_IRQHandler
ADCPPU0_IRQHandler
ADCPPU1_IRQHandler
ADCPPU2_IRQHandler
ADCPPU3_IRQHandler
ADCPPU4_IRQHandler
ADCPPU5_IRQHandler
PWM0_IRQHandler
PWM1_IRQHandler
PWM2_IRQHandler
PWM3_IRQHandler
PWM4_IRQHandler
PWM5_IRQHandler
PWM0TZ_IRQHandler
PWM1TZ_IRQHandler
PWM2TZ_IRQHandler
PWM3TZ_IRQHandler
PWM4TZ_IRQHandler
PWM5TZ_IRQHandler
ECAP_IRQHandler
TIMER0_IRQHandler
TIMER1_IRQHandler
TIMER2_IRQHandler
CRC_IRQHandler
AES_IRQHandler
                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END
