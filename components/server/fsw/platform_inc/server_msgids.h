/************************************************************************
** File:
**   $Id: server_msgids.h  $
**
** Purpose:
**  Define SERVER Message IDs
**
*************************************************************************/
#ifndef _SERVER_MSGIDS_H_
#define _SERVER_MSGIDS_H_

/* 
** CCSDS V1 Command Message IDs (MID) must be 0x18xx
*/
#define SERVER_CMD_MID              0x18F1

/* 
** This MID is for commands telling the app to publish its telemetry message
*/
#define SERVER_REQ_HK_MID           0x18F2

/* 
** CCSDS V1 Telemetry Message IDs must be 0x08xx
*/
#define SERVER_HK_TLM_MID           0x08F1 
#define SERVER_DEVICE_TLM_MID       0x08F2 

#endif /* _SERVER_MSGIDS_H_ */
