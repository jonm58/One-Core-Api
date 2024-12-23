  /*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 *
 */
 
#define NDEBUG

#include <main.h>

NTSTATUS 
NTAPI
RtlRegisterThreadWithCsrss()
{
	// NTSTATUS Status;
	// PCSR_API_MESSAGE ApiMessage;
	// if ( !CsrClientProcess && CsrInitOnceDone && CsrServerApiRoutine ){
		// ApiMessage->Header.ClientId = NtCurrentTeb()->ClientId;
	// }else{
		// Status = STATUS_SUCCESS;
	// }
	DbgPrint("UNIMPLEMENTED: RtlRegisterThreadWithCsrss");
	return ERROR_SUCCESS;	
}

NTSTATUS
NTAPI
RtlRemovePrivileges(
	HANDLE TokenHandle, 
	PULONG PrivilegesToKeep, 
	ULONG PrivilegeCount
)
{
	DbgPrint("UNIMPLEMENTED: RtlRemovePrivileges");
	return ERROR_SUCCESS;	
}

// Required for cabinet.dll Windows 8, which unlocks an useful, next-generation compression API used by programs.
// Why I think it is fine: The extra parameter "WorkSpace" is application-allocated. The non-Ex API allocates the size automatically and frees automatically. So, only very slight memory penalties exist. The application eventually frees the buffer when it finishes it's decompression operations, so no behavior changes.
NTSTATUS 
NTAPI 
RtlDecompressBufferEx(
	USHORT CompressionFormat, 
	PUCHAR UncompressedBuffer, 
	ULONG UncompressedBufferSize, 
	PUCHAR CompressedBuffer, 
	ULONG  CompressedBufferSize, 
	PULONG FinalUncompressedSize, 
	PVOID  WorkSpace
) {
    return RtlDecompressBuffer(CompressionFormat, UncompressedBuffer, UncompressedBufferSize, CompressedBuffer, CompressedBufferSize, FinalUncompressedSize);
}