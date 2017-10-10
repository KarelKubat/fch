
#include "fch.h"

/*
    promote the made changes in a file:
    keep the changed orgfile, remove backup file if -r flag given
*/    

void promote (char *backname, char *filename)
{
    if (remove_backup)
        if (unlink (backname))
            error ("can't remove backup file %s", backname);
}
