#ifndef PERSISTENCE_CLIENT_LIBRARY_DBUS_CMD_H_
#define PERSISTENCE_CLIENT_LIBRARY_DBUS_CMD_H_

/******************************************************************************
 * Project         Persistency
 * (c) copyright   2012
 * Company         XS Embedded GmbH
 *****************************************************************************/
/******************************************************************************
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed
 * with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
******************************************************************************/
 /**
 * @file           persistence_client_library_dbus_cmd.h
 * @ingroup        Persistence client library
 * @author         Ingo Huerner
 * @brief          Header of the persistence client library dbus command functions.
 * @see
 */

#include <dbus/dbus.h>

#include "persistence_client_library_dbus_service.h"

/**
 * @brief process a shutdown message (close all open files, open databases, ...
 *
 * @param complete The mode: Shutdown_Partial=0; Shutdown_Full=1
 */
void process_prepare_shutdown(int complete);


/**
 * @brief send notification signal
 *
 * @param conn the dbus connection
 */
void process_send_notification_signal(DBusConnection* conn, unsigned int notifyLdbid, unsigned int notifyUserNo,
                                                            unsigned int notifySeatNo, unsigned int notifyReason, const char* notifyKey);


/**
 * @brief register for notification signal
 *
 * @param conn the dbus connection
 */
void process_reg_notification_signal(DBusConnection* conn, unsigned int notifyLdbid, unsigned int notifyUserNo,
                                                           unsigned int notifySeatNo, unsigned int notifyPolicy, const char* notifyKey);


void process_send_lifecycle_request(DBusConnection* conn, unsigned int requestId, unsigned int status);


void process_send_lifecycle_register(DBusConnection* conn, int regType, int shutdownMode);



/**
 * @brief block persistence access and write data back to device
 *
 * @param requestId the requestID
 * @param status the status
 */
void process_block_and_write_data_back(unsigned int requestID, unsigned int status);



/**
 * @brief process a request of the persistence admin service
 *
 * @param requestId the requestID
 * @param status the status
 */
void process_send_pas_request(DBusConnection* conn, unsigned int requestID, int status);



/**
 * @brief process a request of the persistence admin service
 *
 * @param regType the registration type (1 for register; 0 for unregister)
 * @param notification flag the notificatin flag
 */
void process_send_pas_register(DBusConnection* conn, int regType, int notificationFlag);



#endif /* PERSISTENCE_CLIENT_LIBRARY_DBUS_CMD_H_ */
