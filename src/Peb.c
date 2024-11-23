#include "Common.h"

/*!
 *
 * Purpose:
 *
 * Loops through the Process Environment Block InLoadOrderModuleList
 * to locate the requested module if it is loaded in memory.
 *
!*/
D_SEC( B ) PVOID PebGetModule( IN PCHAR ImageName )
{
	PLIST_ENTRY		LstEnt = NULL;
	PLIST_ENTRY		LstHdr = NULL;
	PLDR_DATA_TABLE_ENTRY	LdrEnt = NULL;

	/* Get the list header and first entry */
	LstHdr = & NtCurrentPeb()->Ldr->InLoadOrderModuleList;
	LstEnt = LstHdr->Flink;

	/* Loop through each entry in the list */
	for ( ; LstHdr != LstEnt ; LstEnt = LstEnt->Flink ) {
		/* Pointer to the table entry */
		LdrEnt = CONTAINING_RECORD( LstEnt, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks );

		/* Hash the current image name & compare to the current module entry */
		if ( HashString( ImageName, 0 ) == HashString( LdrEnt->BaseDllName.Buffer, LdrEnt->BaseDllName.Length ) ) {
			/* Return the pointer */
			return LdrEnt->DllBase;
		};
	};
	return NULL;
};
