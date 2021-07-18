/*
*  First program made with VS for Win. 
*  Just prints some system information:
*  Good to understand basic data types for strings and integers on Win64 bits.
*  To notice:
*	- WCHAR: to declare characters. This is a datatype of wchar_t (unicode) and char (ascii)
*   - The use of %ws to print wchar_t strings
*   - The use of %lld for LARGE_INTEGERS type
* 
* 
*  Author: Guillem Alminyana 
*  License: GPL v3
* 
* 
*/


#include <windows.h>
#include <stdio.h>



int main()
{
	SYSTEM_INFO sys_information;		//<- SYSINFO type contains info about current computer system

	WCHAR computer_name[256];       //<- To store the computer name
	DWORD computer_name_size = 256;       //<- Size of the buffer

	WCHAR directory_name[256];
	UINT directory_name_size = 256;

	LARGE_INTEGER performance_counter;

	DWORD OS_version = NULL;        //<- To store os version integer value
	DWORD OS_major = 6;
	DWORD OS_minor = 1;
	DWORD SP_major = NULL;
	DWORD SP_minor = NULL;
	DWORD product_type = NULL;

	WCHAR computer_object_name[256];
	ULONG computer_object_name_size = 256;


	::GetNativeSystemInfo(&sys_information);

	printf("\n* System Information:\n");
	printf("   Number of Logical Processors: %d\n", sys_information.dwNumberOfProcessors);
	printf("   Processor Type: %d\n", sys_information.dwProcessorType);
	printf("   Processor Mask: 0x%p\n", (PVOID)sys_information.dwActiveProcessorMask);
	printf("   Processor Level: %d\n", sys_information.wProcessorLevel);
	printf("   Processor Revision: %d\n", sys_information.wProcessorRevision);

	printf("   Page size: %d Bytes\n", sys_information.dwPageSize);	
	printf("   Minimum process address: 0x%p\n", sys_information.lpMinimumApplicationAddress);
	printf("   Maximum process address: 0x%p\n", sys_information.lpMaximumApplicationAddress);
	
	::GetComputerName(computer_name, &computer_name_size);

	printf("\n* Computer name: %ws\n", computer_name);                //<- %ws stants for UNICODE char on 64 bits
	printf("   Computer Name Size: %d\n", computer_name_size);

	::GetWindowsDirectory(directory_name, directory_name_size);

	printf("\n* Windows directory: %ws\n", directory_name);

	::QueryPerformanceCounter(&performance_counter);

	printf("\n* Value of performance counter: %lld.\n", performance_counter.QuadPart);

	/* Deprecated
	OS_version = ::GetVersion();
	OS_major = (DWORD)(LOBYTE(LOWORD(OS_version)));
	OS_minor = (DWORD)(HIBYTE(LOWORD(OS_version)));
	*/

	::GetProductInfo(OS_major, OS_minor,SP_major,SP_minor,&product_type);

	printf("\n* Product Type: %ld.\n", product_type);

	::GetComputerNameEx(ComputerNameDnsDomain, computer_object_name, &computer_object_name_size);

	printf("\n* ComputerNameDNSDomain: %ws.\n", computer_object_name);

	printf("\n\n");
}
