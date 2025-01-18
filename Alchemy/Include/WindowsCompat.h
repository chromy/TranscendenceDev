#pragma once

#if ALCHEMY_BUILDFLAG(ALCHEMY_OS_WINDOWS)
static_assert(false, "WindowsCompat.h must only be included on non-windows");
#endif // ALCHEMY_BUILDFLAG(ALCHEMY_OS_WINDOWS)

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
typedef long                LONG;
typedef const void*         LPVOID;
typedef const void*         LPCVOID;
typedef void*               HANDLE;
typedef int64_t             INT64;
typedef int64_t             LONGLONG;


typedef struct tagRECT {
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT;

typedef char* PSTR, *LPSTR;
typedef const char* LPCSTR;

#define FALSE               0
#define TRUE                1

typedef struct _SYSTEMTIME {
  WORD wYear;
  WORD wMonth;
  WORD wDayOfWeek;
  WORD wDay;
  WORD wHour;
  WORD wMinute;
  WORD wSecond;
  WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME;

// TODO(clang):
// Unclear what to do about these:
#define VK_CONTROL          0x11
#define CP_ACP              0
#define CP_UTF8             65001

