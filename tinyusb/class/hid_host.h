/*
 * hid_host.h
 *
 *  Created on: Jan 18, 2013
 *      Author: hathach
 */

/*
 * Software License Agreement (BSD License)
 * Copyright (c) 2012, hathach (tinyusb.net)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the tiny usb stack.
 */

/** \file
 *  \brief TBD
 *
 *  \note TBD
 */

/** \ingroup TBD
 *  \defgroup TBD
 *  \brief TBD
 *
 *  @{
 */

#ifndef _TUSB_HID_HOST_H_
#define _TUSB_HID_HOST_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "host/usbd_host.h"
#include "hid.h"

//--------------------------------------------------------------------+
// APPLICATION API
//--------------------------------------------------------------------+
uint8_t tusbh_hid_keyboard_no_instances(tusb_handle_device_t const device_hdl);
tusb_error_t tusbh_hid_keyboard_get(tusb_handle_device_t const handle, uint8_t instance_num, tusb_keyboard_report_t * const report);

//--------------------------------------------------------------------+
// INTERNAL API
//--------------------------------------------------------------------+
typedef struct {
  pipe_handle_t pipe_in;
  uint8_t report_size;
  uint8_t buffer[TUSB_CFG_HOST_HID_KEYBOARD_ENDPOINT_SIZE];
}keyboard_interface_t;

typedef struct { // TODO internal structure
  uint8_t instance_count;
  keyboard_interface_t instance[TUSB_CFG_HOST_HID_KEYBOARD_NO_INSTANCES_PER_DEVICE];
} class_hid_keyboard_info_t;

tusb_error_t class_hid_keyboard_install(uint8_t const dev_addr, uint8_t const *descriptor);

#ifdef __cplusplus
}
#endif

#endif /* _TUSB_HID_HOST_H_ */

/** @} */