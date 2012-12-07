/*
 *
 *  BlueZ - Bluetooth protocol stack for Linux
 *
 *  Copyright (C) 2004-2010  Marcel Holtmann <marcel@holtmann.org>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include "att.h"
#include "gattrib.h"
#include "gatt.h"

#define HSP_HS_UUID		"00001108-0000-1000-8000-00805F9B34FB"
#define HID_UUID		"00001124-0000-1000-8000-00805f9b34fb"
/* HID LE UUID's */
#define HIDLE_UUID		"00001812-0000-1000-8000-00805f9b34fb"
#define HIDLE_REPORT_MAP_CHAR	"00002A4B-0000-1000-8000-00805f9b34fb"
#define HIDLE_REPORT_CHAR	"00002A4D-0000-1000-8000-00805f9b34fb"
#define DEVICE_INFO_UUID	"0000180A-0000-1000-8000-00805f9b34fb"

#define HIDLE_REPORT_REF_DESC	0x2908
#define PNP_CHAR_UUID		0x2A50

#define L2CAP_PSM_HIDP_CTRL	0x11
#define L2CAP_PSM_HIDP_INTR	0x13

struct input_device;
struct input_conn;

struct fake_input {
	int		flags;
	GIOChannel	*io;
	int		uinput;		/* uinput socket */
	int		rfcomm;		/* RFCOMM socket */
	uint8_t		ch;		/* RFCOMM channel number */
	gboolean	(*connect) (struct input_conn *iconn, GError **err);
	int		(*disconnect) (struct input_conn *iconn);
	void		*priv;
	const struct input_device *idev;
};

int fake_input_register(DBusConnection *conn, struct btd_device *device,
			const char *path, bdaddr_t *src, bdaddr_t *dst,
			const char *uuid, uint8_t channel);
int input_device_register(DBusConnection *conn, struct btd_device *device,
			const char *path, const bdaddr_t *src,
			const bdaddr_t *dst, const char *uuid,
			uint32_t handle, int timeout);
int input_device_unregister(const char *path, const char *uuid);

int input_device_set_channel(const bdaddr_t *src, const bdaddr_t *dst, int psm,
							GIOChannel *io);
int input_device_close_channels(const bdaddr_t *src, const bdaddr_t *dst);
