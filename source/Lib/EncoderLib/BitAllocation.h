/* -----------------------------------------------------------------------------
The copyright in this software is being made available under the BSD
License, included below. No patent rights, trademark rights and/or 
other Intellectual Property Rights other than the copyrights concerning 
the Software are granted under this license.

For any license concerning other Intellectual Property rights than the software,
especially patent licenses, a separate Agreement needs to be closed. 
For more information please contact:

Fraunhofer Heinrich Hertz Institute
Einsteinufer 37
10587 Berlin, Germany
www.hhi.fraunhofer.de/vvc
vvc@hhi.fraunhofer.de

Copyright (c) 2019-2021, Fraunhofer-Gesellschaft zur Förderung der angewandten Forschung e.V.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
 * Neither the name of Fraunhofer nor the names of its contributors may
   be used to endorse or promote products derived from this software without
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
THE POSSIBILITY OF SUCH DAMAGE.


------------------------------------------------------------------------------------------- */
/** \file     BitAllocation.h
\brief    Bit allocation class for QP adaptation and, possibly, rate control (header)
*/

#pragma once

#include "CommonLib/Slice.h"
#include "CommonLib/Unit.h"

//! \ingroup EncoderLib
//! \{

//struct VVEncCfg;

namespace vvenc {

  // BitAllocation functions
  namespace BitAllocation
  {
    int applyQPAdaptationChroma (const Slice* slice, const VVEncCfg* encCfg, const int sliceQP,
                                 std::vector<int>& ctuPumpRedQP, int optChromaQPOffset[2], double* picVisActY = nullptr);
    int applyQPAdaptationLuma   (const Slice* slice, const VVEncCfg* encCfg, const int savedQP, const double lambda,
                                 std::vector<int>& ctuPumpRedQP, std::vector<uint8_t>* ctuRCQPMemory,
                                 const uint32_t ctuStartAddr, const uint32_t ctuBoundingAddr);
    int applyQPAdaptationSubCtu (const Slice* slice, const VVEncCfg* encCfg, const Area& lumaArea);
    int getCtuPumpingReducingQP (const Slice* slice, const CPelBuf& origY, const Distortion uiSadBestForQPA,
                                 std::vector<int>& ctuPumpRedQP, const uint32_t ctuRsAddr, const int baseQP);
    double getPicVisualActivity (const Slice* slice, const VVEncCfg* encCfg);
  }

} // namespace vvenc

//! \}
