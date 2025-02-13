/************************************************************************
** File:
**    client_events.h
**
** Purpose:
**  Define CLIENT application event IDs
**
*************************************************************************/

#ifndef _CLIENT_EVENTS_H_
#define _CLIENT_EVENTS_H_

/* Standard app event IDs */
#define CLIENT_RESERVED_EID              0
#define CLIENT_STARTUP_INF_EID           1
#define CLIENT_LEN_ERR_EID               2
#define CLIENT_PIPE_ERR_EID              3
#define CLIENT_SUB_CMD_ERR_EID           4
#define CLIENT_SUB_REQ_HK_ERR_EID        5
#define CLIENT_PROCESS_CMD_ERR_EID       6

/* Standard command event IDs */
#define CLIENT_CMD_ERR_EID               10
#define CLIENT_CMD_NOOP_INF_EID          11
#define CLIENT_CMD_RESET_INF_EID         12
#define CLIENT_CMD_ENABLE_INF_EID        13
#define CLIENT_ENABLE_INF_EID            14
#define CLIENT_ENABLE_ERR_EID            15
#define CLIENT_CMD_DISABLE_INF_EID       16
#define CLIENT_DISABLE_INF_EID           17
#define CLIENT_DISABLE_ERR_EID           18

/* Device specific command event IDs */
#define CLIENT_CMD_CONFIG_INF_EID        20

/* Standard telemetry event IDs */
#define CLIENT_DEVICE_TLM_ERR_EID        30
#define CLIENT_REQ_HK_ERR_EID            31

/* Device specific telemetry event IDs */
#define CLIENT_REQ_DATA_ERR_EID          32

/* Hardware protocol event IDs */
#define CLIENT_UART_INIT_ERR_EID         40
#define CLIENT_UART_CLOSE_ERR_EID        41

#endif /* _CLIENT_EVENTS_H_ */
