/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_MODULES_RTP_RTCP_SOURCE_FEC_PRIVATE_TABLES_BURSTY_H_
#define WEBRTC_MODULES_RTP_RTCP_SOURCE_FEC_PRIVATE_TABLES_BURSTY_H_

// This file contains a set of packets masks for the FEC code. The masks in
// this table are specifically designed to favor recovery of bursty/consecutive
// loss network conditions. The tradeoff is worse recovery for random losses.
// These packet masks are currently defined to protect up to 12 media packets.
// They have the following property: for any packet mask defined by the
// parameters (k,m), where k = number of media packets, m = number of FEC
// packets, all "consecutive" losses of size <= m are completely recoverable.
// By consecutive losses we mean consecutive with respect to the sequence
// number ordering of the list (media and FEC) of packets. The difference
// between these masks (|kFecMaskBursty|) and |kFecMaskRandom| type, defined
// in fec_private_tables.h, is more significant for longer codes
// (i.e., more packets/symbols in the code, so larger (k,m), i.e.,  k > 4,
// m > 3).

#include "../typedefs.h"

namespace {

const uint8_t kMaskBursty1_1[2] = {
  0x80, 0x00
};

const uint8_t kMaskBursty2_1[2] = {
  0xc0, 0x00
};

const uint8_t kMaskBursty2_2[4] = {
  0x80, 0x00,
  0xc0, 0x00
};

const uint8_t kMaskBursty3_1[2] = {
  0xe0, 0x00
};

const uint8_t kMaskBursty3_2[4] = {
  0xc0, 0x00,
  0xa0, 0x00
};

const uint8_t kMaskBursty3_3[6] = {
  0x80, 0x00,
  0xc0, 0x00,
  0x60, 0x00
};

const uint8_t kMaskBursty4_1[2] = {
  0xf0, 0x00
};

const uint8_t kMaskBursty4_2[4] = {
  0xa0, 0x00,
  0xd0, 0x00
};

const uint8_t kMaskBursty4_3[6] = {
  0xc0, 0x00,
  0x60, 0x00,
  0x90, 0x00
};

const uint8_t kMaskBursty4_4[8] = {
  0x80, 0x00,
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00
};

const uint8_t kMaskBursty5_1[2] = {
  0xf8, 0x00
};

const uint8_t kMaskBursty5_2[4] = {
  0xd0, 0x00,
  0xa8, 0x00
};

const uint8_t kMaskBursty5_3[6] = {
  0x70, 0x00,
  0x90, 0x00,
  0xc8, 0x00
};

const uint8_t kMaskBursty5_4[8] = {
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x88, 0x00
};

const uint8_t kMaskBursty5_5[10] = {
  0x80, 0x00,
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00
};

const uint8_t kMaskBursty6_1[2] = {
  0xfc, 0x00
};

const uint8_t kMaskBursty6_2[4] = {
  0xa8, 0x00,
  0xd4, 0x00
};

const uint8_t kMaskBursty6_3[6] = {
  0x94, 0x00,
  0xc8, 0x00,
  0x64, 0x00
};

const uint8_t kMaskBursty6_4[8] = {
  0x60, 0x00,
  0x38, 0x00,
  0x88, 0x00,
  0xc4, 0x00
};

const uint8_t kMaskBursty6_5[10] = {
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x84, 0x00
};

const uint8_t kMaskBursty6_6[12] = {
  0x80, 0x00,
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00
};

const uint8_t kMaskBursty7_1[2] = {
  0xfe, 0x00
};

const uint8_t kMaskBursty7_2[4] = {
  0xd4, 0x00,
  0xaa, 0x00
};

const uint8_t kMaskBursty7_3[6] = {
  0xc8, 0x00,
  0x74, 0x00,
  0x92, 0x00
};

const uint8_t kMaskBursty7_4[8] = {
  0x38, 0x00,
  0x8a, 0x00,
  0xc4, 0x00,
  0x62, 0x00
};

const uint8_t kMaskBursty7_5[10] = {
  0x60, 0x00,
  0x30, 0x00,
  0x1c, 0x00,
  0x84, 0x00,
  0xc2, 0x00
};

const uint8_t kMaskBursty7_6[12] = {
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x82, 0x00
};

const uint8_t kMaskBursty7_7[14] = {
  0x80, 0x00,
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00
};

const uint8_t kMaskBursty8_1[2] = {
  0xff, 0x00
};

const uint8_t kMaskBursty8_2[4] = {
  0xaa, 0x00,
  0xd5, 0x00
};

const uint8_t kMaskBursty8_3[6] = {
  0x74, 0x00,
  0x92, 0x00,
  0xc9, 0x00
};

const uint8_t kMaskBursty8_4[8] = {
  0x8a, 0x00,
  0xc5, 0x00,
  0x62, 0x00,
  0x31, 0x00
};

const uint8_t kMaskBursty8_5[10] = {
  0x30, 0x00,
  0x1c, 0x00,
  0x85, 0x00,
  0xc2, 0x00,
  0x61, 0x00
};

const uint8_t kMaskBursty8_6[12] = {
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0e, 0x00,
  0x82, 0x00,
  0xc1, 0x00
};

const uint8_t kMaskBursty8_7[14] = {
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x81, 0x00
};

const uint8_t kMaskBursty8_8[16] = {
  0x80, 0x00,
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00
};

const uint8_t kMaskBursty9_1[2] = {
  0xff, 0x80
};

const uint8_t kMaskBursty9_2[4] = {
  0xd5, 0x00,
  0xaa, 0x80
};

const uint8_t kMaskBursty9_3[6] = {
  0x92, 0x00,
  0xc9, 0x00,
  0x74, 0x80
};

const uint8_t kMaskBursty9_4[8] = {
  0xc5, 0x00,
  0x62, 0x00,
  0x39, 0x00,
  0x8a, 0x80
};

const uint8_t kMaskBursty9_5[10] = {
  0x1c, 0x00,
  0x85, 0x00,
  0xc2, 0x80,
  0x61, 0x00,
  0x30, 0x80
};

const uint8_t kMaskBursty9_6[12] = {
  0x30, 0x00,
  0x18, 0x00,
  0x0e, 0x00,
  0x82, 0x80,
  0xc1, 0x00,
  0x60, 0x80
};

const uint8_t kMaskBursty9_7[14] = {
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x07, 0x00,
  0x81, 0x00,
  0xc0, 0x80
};

const uint8_t kMaskBursty9_8[16] = {
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00,
  0x80, 0x80
};

const uint8_t kMaskBursty9_9[18] = {
  0x80, 0x00,
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00,
  0x01, 0x80
};

const uint8_t kMaskBursty10_1[2] = {
  0xff, 0xc0
};

const uint8_t kMaskBursty10_2[4] = {
  0xaa, 0x80,
  0xd5, 0x40
};

const uint8_t kMaskBursty10_3[6] = {
  0xc9, 0x00,
  0x74, 0x80,
  0x92, 0x40
};

const uint8_t kMaskBursty10_4[8] = {
  0x62, 0x00,
  0x39, 0x00,
  0x8a, 0x80,
  0xc5, 0x40
};

const uint8_t kMaskBursty10_5[10] = {
  0x85, 0x00,
  0xc2, 0x80,
  0x61, 0x40,
  0x30, 0x80,
  0x18, 0x40
};

const uint8_t kMaskBursty10_6[12] = {
  0x18, 0x00,
  0x0e, 0x00,
  0x82, 0x80,
  0xc1, 0x40,
  0x60, 0x80,
  0x30, 0x40
};

const uint8_t kMaskBursty10_7[14] = {
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x07, 0x00,
  0x81, 0x40,
  0xc0, 0x80,
  0x60, 0x40
};

const uint8_t kMaskBursty10_8[16] = {
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00,
  0x80, 0x80,
  0xc0, 0x40
};

const uint8_t kMaskBursty10_9[18] = {
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00,
  0x01, 0x80,
  0x80, 0x40
};

const uint8_t kMaskBursty10_10[20] = {
  0x80, 0x00,
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00,
  0x01, 0x80,
  0x00, 0xc0
};

const uint8_t kMaskBursty11_1[2] = {
  0xff, 0xe0
};

const uint8_t kMaskBursty11_2[4] = {
  0xd5, 0x40,
  0xaa, 0xa0
};

const uint8_t kMaskBursty11_3[6] = {
  0x74, 0x80,
  0x92, 0x40,
  0xc9, 0x20
};

const uint8_t kMaskBursty11_4[8] = {
  0x39, 0x00,
  0x8a, 0x80,
  0xc5, 0x40,
  0x62, 0x20
};

const uint8_t kMaskBursty11_5[10] = {
  0xc2, 0xc0,
  0x61, 0x00,
  0x30, 0xa0,
  0x1c, 0x40,
  0x85, 0x20
};

const uint8_t kMaskBursty11_6[12] = {
  0x0e, 0x00,
  0x82, 0x80,
  0xc1, 0x40,
  0x60, 0xa0,
  0x30, 0x40,
  0x18, 0x20
};

const uint8_t kMaskBursty11_7[14] = {
  0x18, 0x00,
  0x0c, 0x00,
  0x07, 0x00,
  0x81, 0x40,
  0xc0, 0xa0,
  0x60, 0x40,
  0x30, 0x20
};

const uint8_t kMaskBursty11_8[16] = {
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x40,
  0x80, 0xa0,
  0xc0, 0x40,
  0x60, 0x20
};

const uint8_t kMaskBursty11_9[18] = {
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00,
  0x01, 0x80,
  0x80, 0x40,
  0xc0, 0x20
};

const uint8_t kMaskBursty11_10[20] = {
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00,
  0x01, 0x80,
  0x00, 0xc0,
  0x80, 0x20
};

const uint8_t kMaskBursty11_11[22] = {
  0x80, 0x00,
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00,
  0x01, 0x80,
  0x00, 0xc0,
  0x00, 0x60
};

const uint8_t kMaskBursty12_1[2] = {
  0xff, 0xf0
};

const uint8_t kMaskBursty12_2[4] = {
  0xaa, 0xa0,
  0xd5, 0x50
};

const uint8_t kMaskBursty12_3[6] = {
  0x92, 0x40,
  0xc9, 0x20,
  0x74, 0x90
};

const uint8_t kMaskBursty12_4[8] = {
  0x8a, 0x80,
  0xc5, 0x40,
  0x62, 0x20,
  0x39, 0x10
};

const uint8_t kMaskBursty12_5[10] = {
  0x61, 0x00,
  0x30, 0xa0,
  0x1c, 0x50,
  0x85, 0x20,
  0xc2, 0x90
};

const uint8_t kMaskBursty12_6[12] = {
  0x82, 0x90,
  0xc1, 0x40,
  0x60, 0xa0,
  0x30, 0x50,
  0x18, 0x20,
  0x0c, 0x10
};

const uint8_t kMaskBursty12_7[14] = {
  0x0c, 0x00,
  0x07, 0x00,
  0x81, 0x40,
  0xc0, 0xa0,
  0x60, 0x50,
  0x30, 0x20,
  0x18, 0x10
};

const uint8_t kMaskBursty12_8[16] = {
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00,
  0x80, 0xa0,
  0xc0, 0x50,
  0x60, 0x20,
  0x30, 0x10
};

const uint8_t kMaskBursty12_9[18] = {
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00,
  0x01, 0x80,
  0x80, 0x50,
  0xc0, 0x20,
  0x60, 0x10
};

const uint8_t kMaskBursty12_10[20] = {
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00,
  0x01, 0x80,
  0x00, 0xc0,
  0x80, 0x20,
  0xc0, 0x10
};

const uint8_t kMaskBursty12_11[22] = {
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00,
  0x01, 0x80,
  0x00, 0xc0,
  0x00, 0x60,
  0x80, 0x10
};

const uint8_t kMaskBursty12_12[24] = {
  0x80, 0x00,
  0xc0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0x0c, 0x00,
  0x06, 0x00,
  0x03, 0x00,
  0x01, 0x80,
  0x00, 0xc0,
  0x00, 0x60,
  0x00, 0x30
};

const uint8_t* kPacketMaskBursty1[1] = {
  kMaskBursty1_1
};

const uint8_t* kPacketMaskBursty2[2] = {
  kMaskBursty2_1,
  kMaskBursty2_2
};

const uint8_t* kPacketMaskBursty3[3] = {
  kMaskBursty3_1,
  kMaskBursty3_2,
  kMaskBursty3_3
};

const uint8_t* kPacketMaskBursty4[4] = {
  kMaskBursty4_1,
  kMaskBursty4_2,
  kMaskBursty4_3,
  kMaskBursty4_4
};

const uint8_t* kPacketMaskBursty5[5] = {
  kMaskBursty5_1,
  kMaskBursty5_2,
  kMaskBursty5_3,
  kMaskBursty5_4,
  kMaskBursty5_5
};

const uint8_t* kPacketMaskBursty6[6] = {
  kMaskBursty6_1,
  kMaskBursty6_2,
  kMaskBursty6_3,
  kMaskBursty6_4,
  kMaskBursty6_5,
  kMaskBursty6_6
};

const uint8_t* kPacketMaskBursty7[7] = {
  kMaskBursty7_1,
  kMaskBursty7_2,
  kMaskBursty7_3,
  kMaskBursty7_4,
  kMaskBursty7_5,
  kMaskBursty7_6,
  kMaskBursty7_7
};

const uint8_t* kPacketMaskBursty8[8] = {
  kMaskBursty8_1,
  kMaskBursty8_2,
  kMaskBursty8_3,
  kMaskBursty8_4,
  kMaskBursty8_5,
  kMaskBursty8_6,
  kMaskBursty8_7,
  kMaskBursty8_8
};

const uint8_t* kPacketMaskBursty9[9] = {
  kMaskBursty9_1,
  kMaskBursty9_2,
  kMaskBursty9_3,
  kMaskBursty9_4,
  kMaskBursty9_5,
  kMaskBursty9_6,
  kMaskBursty9_7,
  kMaskBursty9_8,
  kMaskBursty9_9
};

const uint8_t* kPacketMaskBursty10[10] = {
  kMaskBursty10_1,
  kMaskBursty10_2,
  kMaskBursty10_3,
  kMaskBursty10_4,
  kMaskBursty10_5,
  kMaskBursty10_6,
  kMaskBursty10_7,
  kMaskBursty10_8,
  kMaskBursty10_9,
  kMaskBursty10_10
};

const uint8_t* kPacketMaskBursty11[11] = {
  kMaskBursty11_1,
  kMaskBursty11_2,
  kMaskBursty11_3,
  kMaskBursty11_4,
  kMaskBursty11_5,
  kMaskBursty11_6,
  kMaskBursty11_7,
  kMaskBursty11_8,
  kMaskBursty11_9,
  kMaskBursty11_10,
  kMaskBursty11_11
};

const uint8_t* kPacketMaskBursty12[12] = {
  kMaskBursty12_1,
  kMaskBursty12_2,
  kMaskBursty12_3,
  kMaskBursty12_4,
  kMaskBursty12_5,
  kMaskBursty12_6,
  kMaskBursty12_7,
  kMaskBursty12_8,
  kMaskBursty12_9,
  kMaskBursty12_10,
  kMaskBursty12_11,
  kMaskBursty12_12
};

const uint8_t** kPacketMaskBurstyTbl[12] = {
  kPacketMaskBursty1,
  kPacketMaskBursty2,
  kPacketMaskBursty3,
  kPacketMaskBursty4,
  kPacketMaskBursty5,
  kPacketMaskBursty6,
  kPacketMaskBursty7,
  kPacketMaskBursty8,
  kPacketMaskBursty9,
  kPacketMaskBursty10,
  kPacketMaskBursty11,
  kPacketMaskBursty12
};

}  // namespace
#endif  // WEBRTC_MODULES_RTP_RTCP_SOURCE_FEC_PRIVATE_TABLES_BURSTY_H_
