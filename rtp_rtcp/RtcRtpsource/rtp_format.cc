/*
 *  Copyright (c) 2014 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "rtp_format.h"

#include "rtp_format_h264.h"
#include "rtp_format_video_generic.h"
#include "rtp_format_vp8.h"

namespace webrtc {
RtpPacketizer* RtpPacketizer::Create(RtpVideoCodecTypes type,
                                     size_t max_payload_len,
                                     const RTPVideoTypeHeader* rtp_type_header,
                                     FrameType frame_type) {
  switch (type) {
    case kRtpVideoH264:
      return new RtpPacketizerH264(frame_type, max_payload_len);
    case kRtpVideoVp8:
      assert(rtp_type_header != NULL);
      return new RtpPacketizerVp8(rtp_type_header->VP8, max_payload_len);
    case kRtpVideoGeneric:
      return new RtpPacketizerGeneric(frame_type, max_payload_len);
    case kRtpVideoNone:
      assert(false);
  }
  return NULL;
}

RtpDepacketizer* RtpDepacketizer::Create(RtpVideoCodecTypes type) {
  switch (type) {
    case kRtpVideoH264:
      return new RtpDepacketizerH264();
    case kRtpVideoVp8:
      return new RtpDepacketizerVp8();
    case kRtpVideoGeneric:
      return new RtpDepacketizerGeneric();
    case kRtpVideoNone:
      assert(false);
  }
  return NULL;
}
}  // namespace webrtc
