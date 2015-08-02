//===-- Mos6502FixupKinds.h - Mos6502 Specific Fixup Entries --------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_MOS6502_MCTARGETDESC_MOS6502FIXUPKINDS_H
#define LLVM_LIB_TARGET_MOS6502_MCTARGETDESC_MOS6502FIXUPKINDS_H

#include "llvm/MC/MCFixup.h"

namespace llvm {
  namespace Mos6502 {
    enum Fixups {
      // fixup_mos6502_call30 - 30-bit PC relative relocation for call
      fixup_mos6502_call30 = FirstTargetFixupKind,

      /// fixup_mos6502_br22 - 22-bit PC relative relocation for
      /// branches
      fixup_mos6502_br22,

      /// fixup_mos6502_br19 - 19-bit PC relative relocation for
      /// branches on icc/xcc
      fixup_mos6502_br19,

      /// fixup_mos6502_bpr  - 16-bit fixup for bpr
      fixup_mos6502_br16_2,
      fixup_mos6502_br16_14,

      /// fixup_mos6502_hi22  - 22-bit fixup corresponding to %hi(foo)
      /// for sethi
      fixup_mos6502_hi22,

      /// fixup_mos6502_lo10  - 10-bit fixup corresponding to %lo(foo)
      fixup_mos6502_lo10,

      /// fixup_mos6502_h44  - 22-bit fixup corresponding to %h44(foo)
      fixup_mos6502_h44,

      /// fixup_mos6502_m44  - 10-bit fixup corresponding to %m44(foo)
      fixup_mos6502_m44,

      /// fixup_mos6502_l44  - 12-bit fixup corresponding to %l44(foo)
      fixup_mos6502_l44,

      /// fixup_mos6502_hh  -  22-bit fixup corresponding to %hh(foo)
      fixup_mos6502_hh,

      /// fixup_mos6502_hm  -  10-bit fixup corresponding to %hm(foo)
      fixup_mos6502_hm,

      /// fixup_mos6502_pc22 - 22-bit fixup corresponding to %pc22(foo)
      fixup_mos6502_pc22,

      /// fixup_mos6502_pc10 - 10-bit fixup corresponding to %pc10(foo)
      fixup_mos6502_pc10,

      /// fixup_mos6502_got22 - 22-bit fixup corresponding to %got22(foo)
      fixup_mos6502_got22,

      /// fixup_mos6502_got10 - 10-bit fixup corresponding to %got10(foo)
      fixup_mos6502_got10,

      /// fixup_mos6502_wplt30
      fixup_mos6502_wplt30,

      /// fixups for Thread Local Storage
      fixup_mos6502_tls_gd_hi22,
      fixup_mos6502_tls_gd_lo10,
      fixup_mos6502_tls_gd_add,
      fixup_mos6502_tls_gd_call,
      fixup_mos6502_tls_ldm_hi22,
      fixup_mos6502_tls_ldm_lo10,
      fixup_mos6502_tls_ldm_add,
      fixup_mos6502_tls_ldm_call,
      fixup_mos6502_tls_ldo_hix22,
      fixup_mos6502_tls_ldo_lox10,
      fixup_mos6502_tls_ldo_add,
      fixup_mos6502_tls_ie_hi22,
      fixup_mos6502_tls_ie_lo10,
      fixup_mos6502_tls_ie_ld,
      fixup_mos6502_tls_ie_ldx,
      fixup_mos6502_tls_ie_add,
      fixup_mos6502_tls_le_hix22,
      fixup_mos6502_tls_le_lox10,

      // Marker
      LastTargetFixupKind,
      NumTargetFixupKinds = LastTargetFixupKind - FirstTargetFixupKind
    };
  }
}

#endif
