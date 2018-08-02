/*----------------------------------------------------------------------------
 * Copyright (c) <2018>, <Huawei Technologies Co., Ltd>
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific prior written
 * permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *---------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * Notice of Export Control Law
 * ===============================================
 * Huawei LiteOS may be subject to applicable export control laws and regulations, which might
 * include those applicable to Huawei LiteOS of U.S. and the country in which you are located.
 * Import, export and usage of Huawei LiteOS in any manner by you shall be in compliance with such
 * applicable export control laws and regulations.
 *---------------------------------------------------------------------------*/

/**@defgroup atiny_adapter Agenttiny Adapter
 * @ingroup agent
 */

#ifndef _FOTA_PACKAGE_CHECKSUM_H_
#define _FOTA_PACKAGE_CHECKSUM_H_

#include "fota_package_storage_device.h"


struct fota_pack_checksum_tag_s;

struct fota_pack_checksum_tag_s;
typedef struct fota_pack_checksum_tag_s fota_pack_checksum_s;

struct fota_pack_head_tag_s;

typedef struct fota_pack_checksum_alg_tag_s
{
    void (*reset)(struct fota_pack_checksum_alg_tag_s *thi);
    int (*update)(struct fota_pack_checksum_alg_tag_s *thi, const uint8_t *buff, uint16_t len);
    int (*check)(struct fota_pack_checksum_alg_tag_s *thi, const uint8_t  *checksum, uint16_t checksum_len);
    void (*destroy)(struct fota_pack_checksum_alg_tag_s *thi);
}fota_pack_checksum_alg_s;




#if defined(__cplusplus)
extern "C" {
#endif


fota_pack_checksum_s * fota_pack_checksum_create(struct fota_pack_head_tag_s *head);
void fota_pack_checksum_delete(fota_pack_checksum_s * thi);
int fota_pack_checksum_update_head(fota_pack_checksum_s *thi, struct fota_pack_head_tag_s *head);
int fota_pack_checksum_update_data(fota_pack_checksum_s *thi, uint32_t offset, const uint8_t *buff, uint16_t len,  fota_hardware_s *hardware);
int fota_pack_checksum_check(fota_pack_checksum_s *thi, const uint8_t *expected_value, uint16_t len);


#if defined(__cplusplus)
}
#endif

#endif //_FOTA_PACKAGE_CHECKSUM_H_

