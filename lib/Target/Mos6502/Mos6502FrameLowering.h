//===-- Mos6502FrameLowering.h - Define frame lowering for Mos6502 --*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_MOS6502_MOS6502FRAMELOWERING_H
#define LLVM_LIB_TARGET_MOS6502_MOS6502FRAMELOWERING_H

#include "Mos6502.h"
#include "llvm/Target/TargetFrameLowering.h"

namespace llvm {

class Mos6502Subtarget;
class Mos6502FrameLowering : public TargetFrameLowering {
public:
  explicit Mos6502FrameLowering(const Mos6502Subtarget &ST);

  /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
  /// the function.
  void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const override;

  void
  eliminateCallFramePseudoInstr(MachineFunction &MF,
                                MachineBasicBlock &MBB,
                                MachineBasicBlock::iterator I) const override;

  bool hasReservedCallFrame(const MachineFunction &MF) const override;
  bool hasFP(const MachineFunction &MF) const override;
  void determineCalleeSaves(MachineFunction &MF, BitVector &SavedRegs,
                            RegScavenger *RS = nullptr) const override;

private:
  // Remap input registers to output registers for leaf procedure.
  void remapRegsForLeafProc(MachineFunction &MF) const;

  // Returns true if MF is a leaf procedure.
  bool isLeafProc(MachineFunction &MF) const;


  // Emits code for adjusting SP in function prologue/epilogue.
  void emitSPAdjustment(MachineFunction &MF,
                        MachineBasicBlock &MBB,
                        MachineBasicBlock::iterator MBBI,
                        int NumBytes, unsigned ADDrr, unsigned ADDri) const;

};

} // End llvm namespace

#endif
