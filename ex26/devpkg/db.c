#include <unistd.h>
#include <apr_errno.h>
#include <apr_file_io.h>

#include "db.h"
#include "dbg.h"
#include "bstrlib.h"

static FILE DB_open(const char *path, const char *mode)
{
    return fopen(path, mode);
}

static void DB_close(FILE *db)
{
    fclose(db);
}
