
#include "fch.h"

/*
    change all searchstrings into replacestrings
    in file filename
*/

void change (char *filename)
{
    register char
        *backupname;                        /* name of backup file */
    register int
        changed;                            /* file changed or not? */
    register FILE
        *inf,                               /* in/out files */
	*outf;
	
    backupname = makebackup (filename);     /* make backup name */

    /* open backupfile for as input file, original file for output */
    if (! (inf  = fopen (backupname, "r")) )
        error ("can't open %s for reading", backupname);
    if (! (outf = fopen (filename, "w")) )
        error ("can't open %s for writing\n"
	       "\told file contents are in %s", filename, backupname);
	       
    changed = scan (inf, outf, filename);      /* do the changes */
    
    fclose (inf);                              /* close files */
    fclose (outf);
    
    if (! changed)
        undo (backupname, filename);           /* rename .bak to org if */
    else                                       /* not changed */
        promote (backupname, filename);
	
    free (backupname);
}
