/*******************************************************************************
** File: client_device.h
**
** Purpose:
**   This is the header file for the CLIENT device.
**
*******************************************************************************/
#ifndef _CLIENT_DEVICE_H_
#define _CLIENT_DEVICE_H_

/*
** Required header files.
*/
#include "device_cfg.h"
#include "hwlib.h"
#include "client_platform_cfg.h"


/*
** Type definitions
** TODO: Make specific to your application
*/
#define CLIENT_DEVICE_HDR              0xDEAD
#define CLIENT_DEVICE_HDR_0            0xDE
#define CLIENT_DEVICE_HDR_1            0xAD

#define CLIENT_DEVICE_NOOP_CMD         0x00
#define CLIENT_DEVICE_REQ_HK_CMD       0x01
#define CLIENT_DEVICE_REQ_DATA_CMD     0x02
#define CLIENT_DEVICE_CFG_CMD          0x03

#define CLIENT_DEVICE_TRAILER          0xBEEF
#define CLIENT_DEVICE_TRAILER_0        0xBE
#define CLIENT_DEVICE_TRAILER_1        0xEF

#define CLIENT_DEVICE_HDR_TRL_LEN      4
#define CLIENT_DEVICE_CMD_SIZE         9

/*
** CLIENT device housekeeping telemetry definition
*/
typedef struct
{
    uint32_t  DeviceCounter;
    uint32_t  DeviceConfig;
    uint32_t  DeviceStatus;

} __attribute__((packed)) CLIENT_Device_HK_tlm_t;
#define CLIENT_DEVICE_HK_LNGTH sizeof ( CLIENT_Device_HK_tlm_t )
#define CLIENT_DEVICE_HK_SIZE CLIENT_DEVICE_HK_LNGTH + CLIENT_DEVICE_HDR_TRL_LEN


/*
** CLIENT device data telemetry definition
*/
typedef struct
{
    uint32_t  DeviceCounter;
    uint16_t  DeviceDataX;
    uint16_t  DeviceDataY;
    uint16_t  DeviceDataZ;

} __attribute__((packed)) CLIENT_Device_Data_tlm_t;
#define CLIENT_DEVICE_DATA_LNGTH sizeof ( CLIENT_Device_Data_tlm_t )
#define CLIENT_DEVICE_DATA_SIZE CLIENT_DEVICE_DATA_LNGTH + CLIENT_DEVICE_HDR_TRL_LEN


/*
** Prototypes
*/
int32_t CLIENT_ReadData(uart_info_t* device, uint8_t* read_data, uint8_t data_length);
int32_t CLIENT_CommandDevice(uart_info_t* device, uint8_t cmd, uint32_t payload);
int32_t CLIENT_RequestHK(uart_info_t* device, CLIENT_Device_HK_tlm_t* data);
int32_t CLIENT_RequestData(uart_info_t* device, CLIENT_Device_Data_tlm_t* data);


#endif /* _CLIENT_DEVICE_H_ */
