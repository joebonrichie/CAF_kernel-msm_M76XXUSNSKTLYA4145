/* Copyright (c) 2009, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __ASM__ARCH_OEM_RAPI_CLIENT_H
#define __ASM__ARCH_OEM_RAPI_CLIENT_H

/*
 * OEM RAPI CLIENT Driver header file
 */

#include <linux/types.h>
#include <mach/msm_rpcrouter.h>

enum {
	OEM_RAPI_CLIENT_EVENT_NONE = 0,

	/*
	 * list of oem rapi client events
	 */

	/*++ Huize - 20121107 Add for proximity threshold ++*/
	OEM_RAPI_CLIENT_EVENT_PROXIMITY_THRESHOLD_GET,
	OEM_RAPI_CLIENT_EVENT_PROXIMITY_THRESHOLD_SET,
	/*-- Huize - 20121107 Add for proximity threshold --*/

	/*++ FelexChing - 20120505 Add for wlan mac ++*/
	OEM_RAPI_CLIENT_EVENT_WLAN_MAC_GET,
	OEM_RAPI_CLIENT_EVENT_WLAN_MAC_SET,
	/*-- FelexChing - 20120505 Add for wlan mac --*/

	/*++ Huize - 20121107 Add for acceleromert axis calibrate ++*/
	OEM_RAPI_CLIENT_EVENT_ACCELEROMETER_AXIS_OFFSET_GET,
	OEM_RAPI_CLIENT_EVENT_ACCELEROMETER_AXIS_OFFSET_SET,
	/*-- Huize - 20121107 Add for acceleromert axis calibrate --*/

	/*++ FelexChing - 20120807 Add for wifi calibrate ++*/
	OEM_RAPI_CLIENT_EVENT_WIFI_CALI_GET,
	OEM_RAPI_CLIENT_EVENT_WIFI_CALI_SET,
	/*-- FelexChing - 20120807 Add for wifi calibrate --*/

	OEM_RAPI_CLIENT_EVENT_MAX

};

struct oem_rapi_client_streaming_func_cb_arg {
	uint32_t  event;
	void      *handle;
	uint32_t  in_len;
	char      *input;
	uint32_t out_len_valid;
	uint32_t output_valid;
	uint32_t output_size;
};

struct oem_rapi_client_streaming_func_cb_ret {
	uint32_t *out_len;
	char *output;
};

struct oem_rapi_client_streaming_func_arg {
	uint32_t event;
	int (*cb_func)(struct oem_rapi_client_streaming_func_cb_arg *,
		       struct oem_rapi_client_streaming_func_cb_ret *);
	void *handle;
	uint32_t in_len;
	char *input;
	uint32_t out_len_valid;
	uint32_t output_valid;
	uint32_t output_size;
};

struct oem_rapi_client_streaming_func_ret {
	uint32_t *out_len;
	char *output;
};

int oem_rapi_client_streaming_function(
	struct msm_rpc_client *client,
	struct oem_rapi_client_streaming_func_arg *arg,
	struct oem_rapi_client_streaming_func_ret *ret);

int oem_rapi_client_close(void);

/*++ Huize - 20130325 Add general API on kernel side for communicating with modem ++*/
int oem_rapi_client_rpc(uint32_t event, char* input, char** output, uint32_t buffSize);
/*-- Huize - 20130325 Add general API on kernel side for communicating with modem --*/

struct msm_rpc_client *oem_rapi_client_init(void);

#endif
