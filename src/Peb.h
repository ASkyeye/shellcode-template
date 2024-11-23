#pragma once

/*!
 *
 * Purpose:
 *
 * Loops through the Process Environment Block InLoadOrderModuleList
 * to locate the requested module if it is loaded in memory.
 *
!*/
D_SEC( B ) PVOID PebGetModule( IN PCHAR ImageName );
