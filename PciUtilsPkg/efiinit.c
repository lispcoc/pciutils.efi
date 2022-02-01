#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Protocol/Shell.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <Library\ShellLib.h>

EFI_SHELL_PROTOCOL            *gEfiShellProtocol = NULL;

void my_printf(
  const char *fmt,
  ...
  )
  {
    CHAR16 *out = NULL;
    VA_LIST  Marker;
    mbtowc(out, fmt, 4096);
    VA_START (Marker, fmt);
    ShellPrintEx(-1, -1, out, Marker);
    VA_END(Marker);
  }

void efiinit()
{
  EFI_STATUS                  Status;

  Status = gBS->LocateProtocol (
    &gEfiShellProtocolGuid,
    NULL,
    (VOID **)&gEfiShellProtocol
  );

  if (gEfiShellProtocol) {
    gEfiShellProtocol->EnablePageBreak();
  }
}
