
#include "fch.h"

/*
    scan a whole file, change if required
*/

int scan (FILE *inf, FILE *outf, char *fname)
{
    char
        buf [MAXBUF], *cp;
    int
	matchlen, fname_shown = 0, ret = 0, i;

    /* should we stop processing? */
    if (ans == ans_quit)
        return (0);

    /* reset answer if last response was Y or N */
    if (ans == ans_changethisfile || ans == ans_leavethisfile)
        ans = ans_none;

    if (ignorecase)
	rx_ignorecase (1);
    matchlen = strlen (searchstring);

    /* loop thru file */
    while (1)
    {
        if (! fgets (buf, MAXBUF - 1, inf))
	    break;
	    
	cp = buf;
	while (1)
	{
	    if (regex)
		cp = rx_find (searchstring, cp, &matchlen);
	    else {
		if (! ignorecase)
		    cp = strstr (cp, searchstring);
		else
		    cp = stristr (cp, searchstring);
	    }

	    if (! cp)
		break;

	    if (! fname_shown++) {
		printf ("fch: %s ", fname);
		for (i = 0; i < 73 - (int) strlen(fname); i++)
		    putchar ('-');
		putchar ('\n');
	    }
		
	    if (query (&ans, buf, cp, matchlen))
	    {
	        ret = 1;
	        changebuf (buf, cp, matchlen);
		cp += strlen (replacestring);
	    }
	    else
	        cp += matchlen;
	}
	
	if (! silent)
	    for (cp = buf; *cp; cp++)
		outputchar (*cp);
	fprintf (outf, "%s", buf);
    }
    
    return (ret);
}
