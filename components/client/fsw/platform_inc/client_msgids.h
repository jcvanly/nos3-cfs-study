/************************************************************************
** File:
**   $Id: client_msgids.h  $
**
** Purpose:
**  Define CLIENT Message IDs
**
*************************************************************************/
#ifndef _CLIENT_MSGIDS_H_
#define _CLIENT_MSGIDS_H_

/* 
** CCSDS V1 Command Message IDs (MID) must be 0x18xx
*/
#define CLIENT_CMD_MID              0x18F3 

/* 
** This MID is for commands telling the app to publish its telemetry message
*/
#define CLIENT_REQ_HK_MID           0x18F4 

/* 
** CCSDS V1 Telemetry Message IDs must be 0x08xx
*/
#define CLIENT_HK_TLM_MID           0x08F3
#define CLIENT_DEVICE_TLM_MID       0x08F4

#endif /* _CLIENT_MSGIDS_H_ */
