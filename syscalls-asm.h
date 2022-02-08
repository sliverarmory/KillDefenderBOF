#pragma once

#include <windows.h>

#if _WIN64

#define ZwOpenProcess NtOpenProcess
__asm__("NtOpenProcess: \n\
	push rcx \n\
	push rdx \n\
	push r8 \n\
	push r9 \n\
	sub rsp, 0x28 \n\
	call GetSyscallAddress \n\
	add rsp, 0x28 \n\
	push rax \n\
	sub rsp, 0x28 \n\
	mov ecx, 0xCD9B2A0F \n\
	call SW2_GetSyscallNumber \n\
	add rsp, 0x28 \n\
	pop r11 \n\
	pop r9 \n\
	pop r8 \n\
	pop rdx \n\
	pop rcx \n\
	mov r10, rcx \n\
	jmp r11 \n\
");

#define ZwClose NtClose
__asm__("NtClose: \n\
	push rcx \n\
	push rdx \n\
	push r8 \n\
	push r9 \n\
	sub rsp, 0x28 \n\
	call GetSyscallAddress \n\
	add rsp, 0x28 \n\
	push rax \n\
	sub rsp, 0x28 \n\
	mov ecx, 0x2252D33F \n\
	call SW2_GetSyscallNumber \n\
	add rsp, 0x28 \n\
	pop r11 \n\
	pop r9 \n\
	pop r8 \n\
	pop rdx \n\
	pop rcx \n\
	mov r10, rcx \n\
	jmp r11 \n\
");

#define ZwAdjustPrivilegesToken NtAdjustPrivilegesToken

__asm__("NtAdjustPrivilegesToken: \n\
push, rcx \n\
push, rdx \n\
push, r8 \n\
push, r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x06DD8BAE2 \n\
call SW2_GetSyscallNumber \n\
add rsp, 0x28 \n\
pop rcx \n\
pop rdx \n\
pop r8 \n\
pop r9 \n\
mov r10, rcx \n\
syscall \n\
ret \n\
");

#define ZwOpenProcess NtOpenProcess

__asm__("NtOpenProcess: \n\
push, rcx \n\
push, rdx \n\
push, r8 \n\
push, r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C9AAC628 \n\
call SW2_GetSyscallNumber \n\
add rsp, 0x28 \n\
pop rcx \n\
pop rdx \n\
pop r8 \n\
pop r9 \n\
mov r10, rcx \n\
syscall \n\
ret \n\
");

#endif
