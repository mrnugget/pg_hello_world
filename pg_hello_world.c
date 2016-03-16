#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"
#include "funcapi.h"
#include "miscadmin.h"

#define BUF_SIZE 1024

// The structure which we will share between processes
typedef struct pgHelloworldSharedState
{
    char      buffer[BUF_SIZE];
} pgHelloworldSharedState;

// The pointer to our shared memory structure
static pgHelloworldSharedState *hwss = NULL;

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(hello_world);
Datum hello_world(PG_FUNCTION_ARGS)
{
    PG_RETURN_TEXT_P(cstring_to_text("Hello World!"));
}

PG_FUNCTION_INFO_V1(hello_world_shared_memory);
Datum hello_world_shared_memory(PG_FUNCTION_ARGS)
{
    PG_RETURN_TEXT_P(cstring_to_text(hwss->buffer));
}

// The init hook for this extension
void _PG_init(void);
void _PG_init(void)
{
    bool found;

    // Reset our global shared memory pointer
    hwss = NULL;

    /* if (!process_shared_preload_libraries_in_progress) { */
    /*     ereport(ERROR, */
    /*             (errcode(ERRCODE_OBJECT_NOT_IN_PREREQUISITE_STATE), */
    /*          errmsg("pg_hello_world must be loaded via shared_preload_libraries"))); */
    /* } */

    // Request shared memory in the size of `pgHelloworldSharedState`
    RequestAddinShmemSpace(sizeof(pgHelloworldSharedState));

    // To avoid race-conditions, we acquire the exclusive "shared memory" lock
    LWLockAcquire(AddinShmemInitLock, LW_EXCLUSIVE);

    // Allocate shared memory
    hwss = ShmemInitStruct("pg_hello_world",
                           sizeof(pgHelloworldSharedState),
                           &found);
    // The memory wasn't allocated before, so we actually allocated it
    if (!found)
    {
        // Now we initialize our shared memory
        memset(hwss->buffer, 0, BUF_SIZE);
        strncpy(hwss->buffer, "Hello World From Shared Memory!", BUF_SIZE);
    }

    // Release the "shared memory" lock again
    LWLockRelease(AddinShmemInitLock);
}
