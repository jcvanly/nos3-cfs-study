/*******************************************************************************
** File: client_app.h
**
** Purpose:
**   This is the main header file for the CLIENT application.
**
*******************************************************************************/
#ifndef _CLIENT_APP_H_
#define _CLIENT_APP_H_

/*
** Include Files
*/
#include "cfe.h"
#include "client_device.h"
#include "client_events.h"
#include "client_platform_cfg.h"
#include "client_perfids.h"
#include "client_msg.h"
#include "client_msgids.h"
#include "client_version.h"
#include "hwlib.h"


/*
** Specified pipe depth - how many messages will be queued in the pipe
*/
#define CLIENT_PIPE_DEPTH            32


/*
** Enabled and Disabled Definitions
*/
#define CLIENT_DEVICE_DISABLED       0
#define CLIENT_DEVICE_ENABLED        1


/*
** CLIENT global data structure
** The cFE convention is to put all global app data in a single struct. 
** This struct is defined in the `client_app.h` file with one global instance 
** in the `.c` file.
*/
typedef struct
{
    /*
    ** Housekeeping telemetry packet
    ** Each app defines its own packet which contains its OWN telemetry
    */
    CLIENT_Hk_tlm_t   HkTelemetryPkt;   /* CLIENT Housekeeping Telemetry Packet */
    
    /*
    ** Operational data  - not reported in housekeeping
    */
    CFE_MSG_Message_t * MsgPtr;             /* Pointer to msg received on software bus */
    CFE_SB_PipeId_t CmdPipe;            /* Pipe Id for HK command pipe */
    uint32 RunStatus;                   /* App run status for controlling the application state */

    /*
	** Device data 
    ** TODO: Make specific to your application
	*/
    CLIENT_Device_tlm_t DevicePkt;      /* Device specific data packet */

    /* 
    ** Device protocol
    ** TODO: Make specific to your application
    */ 
    uart_info_t ClientUart;             /* Hardware protocol definition */

} CLIENT_AppData_t;


/*
** Exported Data
** Extern the global struct in the header for the Unit Test Framework (UTF).
*/
extern CLIENT_AppData_t CLIENT_AppData; /* CLIENT App Data */


/*
**
** Local function prototypes.
**
** Note: Except for the entry point (CLIENT_AppMain), these
**       functions are not called from any other source module.
*/
void  CLIENT_AppMain(void);
int32 CLIENT_AppInit(void);
void  CLIENT_ProcessCommandPacket(void);
void  CLIENT_ProcessGroundCommand(void);
void  CLIENT_ProcessTelemetryRequest(void);
void  CLIENT_ReportHousekeeping(void);
void  CLIENT_ReportDeviceTelemetry(void);
void  CLIENT_ResetCounters(void);
void  CLIENT_Enable(void);
void  CLIENT_Disable(void);
int32 CLIENT_VerifyCmdLength(CFE_MSG_Message_t * msg, uint16 expected_length);

#endif /* _CLIENT_APP_H_ */
