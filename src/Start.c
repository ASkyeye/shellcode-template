#include "Common.h"

/*!
 *
 * Purpose:
 *
 * Start of the shellcode to prepare the stack before executing the
 * real entrypoint.
 *
!*/
D_SEC( A ) __attribute__(( naked )) VOID Start( VOID )
{
	__asm__ __volatile__(
		#if defined( _WIN64 )
		".extern Entry\n"
		/* Prepare the stack and align it to 16 bytes */
		"pushq	%rsi\n"
		"movq	%rsp, %rsi\n"
		"andq	$-16, %rsp\n"

		/* Execute the entrypoint */
		"subq	$32, %rsp\n"
		"call	Entry\n"

		/* Cleanup the stack and return */
		"movq	%rsi, %rsp\n"
		"popq	%rsi\n"
		"ret"
		#else
		".extern _Entry\n"
		/* Prepare the stack */
		"pushl	%ebp\n"
		"movl	%esp, %ebp\n"

		/* Execute the entrypoint */
		"call	_Entry\n"

		/* Cleanup the stack and return */
		"movl	%ebp, %esp\n"
		"popl	%ebp\n"
		"ret"
		#endif
	);
}
