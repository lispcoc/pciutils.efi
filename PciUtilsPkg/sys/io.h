// UDK's IO functions.

// (c) 2019 Timothy Lin <timothy.gh.lin@gmail.com>, BSD 3-Clause License.

#pragma once

#include <Library/IoLib.h>

#define inb(x) IoRead8(x)
#define inw(x) IoRead16(x)
#define inl(x) IoRead32(x)

#define outb(x,y) IoWrite8(y, x)
#define outw(x,y) IoWrite16(y, x)
#define outl(x,y) IoWrite32(y, x)

static inline int ioperm(int x, int y, int z) {return 0;}

#define PCI_ECAM_ADDRESS(Bus,Device,Function,Offset) \
  (((Offset) & 0xfff) | (((Function) & 0x07) << 12) | (((Device) & 0x1f) << 15) | (((Bus) & 0xff) << 20))
#define PCI_EXPRESS_LIB_ADDRESS(Bus,Device,Function,Offset) PCI_ECAM_ADDRESS ((Bus), (Device), (Function), (Offset))

UINT8
EFIAPI
PciExpressRead8 (
  IN      UINTN                     Address
  );

UINT8
EFIAPI
PciExpressWrite8 (
  IN      UINTN                     Address,
  IN      UINT8                     Value
  );

UINT16
EFIAPI
PciExpressRead16 (
  IN      UINTN                     Address
  );

UINT16
EFIAPI
PciExpressWrite16 (
  IN      UINTN                     Address,
  IN      UINT16                    Value
  );

UINT32
EFIAPI
PciExpressRead32 (
  IN      UINTN                     Address
  );

UINT32
EFIAPI
PciExpressWrite32 (
  IN      UINTN                     Address,
  IN      UINT32                    Value
  );

//BUGBUG: A crude ugly smelly patch.
#undef stderr
#define stderr stdout
