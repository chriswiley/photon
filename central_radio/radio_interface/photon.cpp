// Copyright (c) 2016, Robert Banz
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//    * Neither the name of Robert Banz nor the
//      names of its contributors may be used to endorse or promote products
//      derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL ROBERT BANZ BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "photon.h"

namespace photon {

const unsigned char kPsync = 0xc5;
const unsigned char kGsync = 0xca;
const unsigned char kEsync = 0xdd;

const char* kPsyncName = "PSYNC";
const char* kGsyncName = "GSYNC";
const char* kEsyncName = "ESYNC";
const char* kUnknownName = "UNKNOWN";

unsigned int kNumSlots = 67;

unsigned int kRedRfStart = 5;
unsigned int kGreenRfStart = 31;

unsigned char kRedBase = 0x35;
unsigned char kGreenBase = 0x2b;

unsigned char kRedIrStart = 0x42;
unsigned char kGreenIrStart = 0x80;

const char* GetSyncNameFromByte(const unsigned char byte) {
  switch (byte) {
    case 0xc5:
      return kPsyncName;
      break;
    case 0xca:
      return kGsyncName;
      break;
    case 0xdd:
      return kEsyncName;
      break;
  }
  return kUnknownName;
}

unsigned char GetSyncByteFromName(const char* name) {
  if (!strcmp(kPsyncName, name)) {
    return 0xc5;
  } else if (!strcmp(kGsyncName, name)) {
    return 0xca;
  } else if (!strcmp(kEsyncName, name)) {
    return 0xdd;
  } else {
    return 0x00;
  }
}

}  // namespace photon