
#include "fch.h"

/*
    when a file wasn't changed: undo the preparations
    i.e. remove file, rename the backup file to original name
*/

void undo (char *backname, char *filename)
{
    if (unlink (filename))
        error ("can't remove redundant new file %s\n"
	       "\tthe original contents are in the backup %s", 
            filename, backname);
	   
    if (rename (backname, filename))
        error ("can't rename backup %s to original name %s",
	    backname, filename);
}
