// A hard-coded config file for the UDK porting.

// (c) 2019 Timothy Lin <timothy.gh.lin@gmail.com>, BSD 3-Clause License.

#pragma once

#include <X64/machine/int_fmtio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <Library\ShellLib.h>

#define PCI_IDS "pci.ids"
#define PCI_OS_GNU
#define PCILIB_VERSION "3.6.2"
#define PCI_PATH_IDS_DIR "."
#define PCI_HAVE_STDINT_H
#define PCI_HAVE_PM_INTEL_CONF

//BUGBUG: A crude ugly smelly patch.
#undef stderr
#define stderr stdout

//#define printf(fmt, ...) do{CHAR16 *out; mbtowc(out, fmt, 4096); ShellPrintEx(-1, -1, out, __VA_ARGS__);}while(0);
#define printf(fmt, ...) my_printf(fmt, __VA_ARGS__)

extern void my_printf(
  const char *fmt,
  ...
  );

extern void efiinit();

