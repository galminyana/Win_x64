# Console App Example 01
---




### `SYSTEM_INFO` struct
---

Defined on `sysinfoapi.h`:

```c
typedef struct _SYSTEM_INFO {
  union {
    DWORD dwOemId;
    struct {
      WORD wProcessorArchitecture;
      WORD wReserved;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
  DWORD     dwPageSize;
  LPVOID    lpMinimumApplicationAddress;
  LPVOID    lpMaximumApplicationAddress;
  DWORD_PTR dwActiveProcessorMask;
  DWORD     dwNumberOfProcessors;
  DWORD     dwProcessorType;
  DWORD     dwAllocationGranularity;
  WORD      wProcessorLevel;
  WORD      wProcessorRevision;
} SYSTEM_INFO, *LPSYSTEM_INFO;

```

### `getnativesysinfo` function
---

Defined in `sysinfoapi.h`:

```c
void GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
```

Where `lpSystemInfo` is a pointer to a `SYSTEM_INFO` structure.

### Strings. UTF-16
---
Windows uses UTF-16 by default, even in the kernel. Hence each character is represented by 2 bytes.

### `GetComputerName` 
---
```c
BOOL GetComputerNameA(
  LPSTR   lpBuffer,
  LPDWORD nSize
);
```
- Returns: 
 - Non Zero if all ok
 - Value if error, extend with `GetLastError`
 
- Parameter:
 - Pointer to buffer to store the computer name
 - A word pointer to buffer value. Updated with the real buffer size with computer name

### `GetWindowsDirectory`
---
```c 
UINT GetWindowsDirectoryA(
  LPSTR lpBuffer,
  UINT  uSize
);
```
- Parameters
 - A pointer to a buffer that receives the path
 - The maximum size of the buffer specified by the 1st parameter
Returns the length of the string copied to the buffer if everything went ok, zero if failed.

### ' QueryPerformanceCounter`
---
Retrieves the current value of the performance counter, which is a high resolution (<1us) time stamp that can be used for time-interval measurements.

```c 
BOOL QueryPerformanceCounter(
  LARGE_INTEGER *lpPerformanceCount
);
```
Parameters:
- `lpPerformanceCount`: A pointer to a variable that receives the current performance-counter value, in counts.

Return value

- If the function succeeds, the return value is nonzero.
- If the function fails, the return value is zero. To get extended error information, call `GetLastError`.

### `LARGE_INTEGER` 
---
```c 
typedef union _LARGE_INTEGER {
  struct {
    DWORD LowPart;
    LONG  HighPart;
  } DUMMYSTRUCTNAME;
  struct {
    DWORD LowPart;
    LONG  HighPart;
  } u;
  LONGLONG QuadPart;
} LARGE_INTEGER;
```
On 64-bits, the `QuadPArt` stores the integer value.


### References
---

- [MSDN]
