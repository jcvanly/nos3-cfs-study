/************************************************************************
** File:
**   $Id: client_platform_cfg.h  $
**
** Purpose:
**  Define client Platform Configuration Parameters
**
** Notes:
**
*************************************************************************/
#ifndef _CLIENT_PLATFORM_CFG_H_
#define _CLIENT_PLATFORM_CFG_H_

/*
** Default CLIENT Configuration
*/
#ifndef CLIENT_CFG
    /* Notes: 
    **   NOS3 uart requires matching handle and bus number
    */
    #define CLIENT_CFG_STRING           "usart_16"
    #define CLIENT_CFG_HANDLE           16
    #define CLIENT_CFG_BAUDRATE_HZ      115200
    #define CLIENT_CFG_MS_TIMEOUT       50            /* Max 255 */
    /* Note: Debug flag disabled (commented out) by default */
    //#define CLIENT_CFG_DEBUG
#endif

#endif /* _CLIENT_PLATFORM_CFG_H_ */
