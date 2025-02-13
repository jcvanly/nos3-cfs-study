/*******************************************************************************
** File:
**   client_msg.h
**
** Purpose:
**  Define CLIENT application commands and telemetry messages
**
*******************************************************************************/
#ifndef _CLIENT_MSG_H_
#define _CLIENT_MSG_H_

#include "cfe.h"
#include "client_device.h"


/*
** Ground Command Codes
** TODO: Add additional commands required by the specific component
*/
#define CLIENT_NOOP_CC                 0
#define CLIENT_RESET_COUNTERS_CC       1
#define CLIENT_ENABLE_CC               2
#define CLIENT_DISABLE_CC              3
#define CLIENT_CONFIG_CC               4


/* 
** Telemetry Request Command Codes
** TODO: Add additional commands required by the specific component
*/
#define CLIENT_REQ_HK_TLM              0
#define CLIENT_REQ_DATA_TLM            1


/*
** Generic "no arguments" command type definition
*/
typedef struct
{
    /* Every command requires a header used to identify it */
    CFE_MSG_CommandHeader_t CmdHeader;

} CLIENT_NoArgs_cmd_t;


/*
** CLIENT write configuration command
*/
typedef struct
{
    CFE_MSG_CommandHeader_t CmdHeader;
    uint32   DeviceCfg;

} CLIENT_Config_cmd_t;


/*
** CLIENT device telemetry definition
*/
typedef struct 
{
    CFE_MSG_TelemetryHeader_t TlmHeader;
    CLIENT_Device_Data_tlm_t Client;

} __attribute__((packed)) CLIENT_Device_tlm_t;
#define CLIENT_DEVICE_TLM_LNGTH sizeof ( CLIENT_Device_tlm_t )


/*
** CLIENT housekeeping type definition
*/
typedef struct 
{
    CFE_MSG_TelemetryHeader_t TlmHeader;
    uint8   CommandErrorCount;
    uint8   CommandCount;
    uint8   DeviceErrorCount;
    uint8   DeviceCount;
  
    /*
    ** TODO: Edit and add specific telemetry values to this struct
    */
    uint8   DeviceEnabled;
    CLIENT_Device_HK_tlm_t DeviceHK;

} __attribute__((packed)) CLIENT_Hk_tlm_t;
#define CLIENT_HK_TLM_LNGTH sizeof ( CLIENT_Hk_tlm_t )

#endif /* _CLIENT_MSG_H_ */
