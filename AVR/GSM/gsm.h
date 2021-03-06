
#ifndef __gsm_h__
#define __gsm_h__

#include "uart.h"
#include "timer.h"
#include "avr/io.h"

// Note : For timer use TIMER1

#define GSM_REGISTER_STATUS_TRIAL_MAX 100
#define GSM_PWR_KEY_COUNT             1000
#define GSM_RST_KEY_COUNT             1000

// Gsm Modem timeout delay in microseconds
#define __GSM_MODEM_TIMEOUT_US        1000

#define __GSM_MODEM_TIMEOUT_COUNT      2000 // ( So total timeout : (__GSM_MODEM_TIMEOUT_US * __GSM_MODEM_TIMEOUT_COUNT)us, or __GSM_MODEM_TIMEOUT_COUNT ms (If __GSM_MODEM_TIMEOUT_US is 1000)


// Power Pin
#define MODEM_PWR_KEY_DIR  DDRD
#define MODEM_PWR_KEY_PORT PORTD
#define MODEM_PWR_KEY_BIT  1 << 3

// Reset Pin
#define MODEM_RST_KEY_DIR  DDRB
#define MODEM_RST_KEY_PORT PORTB
#define MODEM_RST_KEY_BIT  1 << 5


// Gsm Initiation
#define gsmBegin(osc,baud) Serialbegin(osc,baud)

extern void          gsmTimerStart(void);
extern void          gsmTimerStop(void);
extern unsigned char gsmGetTimeout(void);

extern unsigned char gsmDetectModem(void);
extern unsigned char gsmEchoOff(void);
extern unsigned char gsmEnableDtmf(void);
extern unsigned char gsmGetRegStatus(void);
extern unsigned char gsmNtwkStatus(void);
extern unsigned char gsmSetSmsFormat(unsigned char);
extern unsigned char gsmSignalStrength(void);
extern unsigned int  gsmSendSms(char*,char*);


extern unsigned char gsmDetectCall(void);
extern unsigned char gsmCallDisStatus(void);
extern unsigned char gsmConnectCall(void);
extern unsigned char gsmReadDtmf(void);

extern void gsmSendSmsTemp(unsigned char);

#define SEND_SMS_STRING_ERROR                 65535
#define SEND_SMS_UNKNWN_ERROR                 65534
#define SEND_SMS_TIMEOUT_ERROR                65533
#define SEND_SMS_TIMEOUT_ERROR_WHILE_SENDING  65532
#define SEND_SMS_STRING_ERROR_WHILE_SENDING   65531
#define SEND_SMS_ERROR_WHILE_READING_LOC      65530

#define SMS_PDU_MODE                          0
#define SMS_TXT_MODE                          1

#endif