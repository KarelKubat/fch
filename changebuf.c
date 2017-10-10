
#include "fch.h"

/*
    change char buffer buf's occurrence of searchstring to replacestring
    at buf position where; where is assumed to point somewhere in buf
*/    

void changebuf (char *buf, char *where, int matchlen)
{
    char
        newbuf [MAXBUF];                        /* tmp buffer */
    register char
        *newwhere;                              /* where ptr in newbuf */

    strcpy (newbuf, buf);
    newwhere = newbuf + (int) (where - buf);
    strcpy (newwhere, replacestring);
    strcpy (newwhere + strlen (replacestring), where + matchlen);
	
    strcpy (buf, newbuf);
}
