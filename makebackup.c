
#include "fch.h"

/*
    makes backup name of file filename, renames file to backup name
    returns backupname

    backup names are file.bak
*/    

char *makebackup (char *filename)
{
    register char
        *ret;
	
    ret = malloc (strlen (filename) + 1 + 4);
    sprintf (ret, "%s.bak", filename);
    
    if (rename (filename, ret))
        error ("can't rename %s to backup file %s", filename, ret);
	
    return (ret);
}
