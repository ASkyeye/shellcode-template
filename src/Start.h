#pragma once

/*!
 *
 * Purpose:
 *
 * Start of the shellcode to prepare the stack before executing the
 * real entrypoint.
 *
!*/
D_SEC( A ) __attribute__(( naked )) VOID Start( VOID );
