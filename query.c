
#include "fch.h"

/*
    ask for user response; return 1 if change should be made else 0
*/    

int query (ANSWER_ *ap, char *buf, char *where, int matchlen)
{
    register int
        ch;
    register char
        *cp;

    /* ask if the previous answer was not Y, N or A */
    if (*ap < ans_changethisfile)
    {
        /* show found searchstring enclosed in <> or in VT100 sequences */
        printf (">> ");
	for (cp = buf; cp < where; cp++)
	    putchar (isprint(*cp) ? *cp : 'x');
	if (regex) {
	    printf (avoid_vt100 ? "<" : VT100_BOLD);
	    for (cp = where; cp - where < matchlen; cp++)
		outputchar (*cp);
	    printf (avoid_vt100 ? ">" : VT100_NORM);
	} else 
	    printf ("%s%s%s",
		    avoid_vt100 ? "<" : VT100_BOLD,
		    searchstring,
		    avoid_vt100 ? ">" : VT100_NORM);
	for (cp = where + matchlen; *cp; cp++)
	    outputchar (*cp);
	putchar ('\n');

        /* ask for response */
        while (1)
	{
	    printf ("Change [ynYNAq or ? for help]: ");
	    ch = getinput ();
	    
	    if (strchr ("ynYNAq", ch))
	        break;
		
	    if (ch == '?')
	        printf ("Answer with: y -- yes, change it this once and "
        		                                "ask next time\n"
		        "             n -- no,  leave it this once and ask "
			                                "next time\n"
			"             Y -- yes, change it in this file and "
			                                "ask in next file\n"
			"             N -- no,  leave it in this file and "
			                                "ask in next file\n"
			"             A -- yes, change this and in all files "
			                                "(use with caution)\n"
			"             q -- aaaaaaaaaaargh, quit NOW\n");
        }

        /* return 1 in all cases where change should be made */
        switch (ch)
        {
            case 'y':
    	        *ap = ans_changethis;
        	return (1);
            case 'n':
    	        *ap = ans_leavethis;
    	        return (0);
            case 'Y':
    	        *ap = ans_changethisfile;
    	        return (1);
            case 'N':
    	        *ap = ans_leavethisfile;
    	        return (0);
            case 'A':
	        *ap = ans_changeall;
		return (1);
            case 'q':
                *ap = ans_quit;
    	        return (0);
	    default:
	        return (0);
	 }
    }
    else                                /* if previous answer was Y,N,A,q: */
        switch (*ap)
	{
	    case ans_changethisfile:    /* for Y,A: return 1 to as signal */
	    case ans_changeall:         /* to perform changes */
	        return (1);
	    default:                    /* for N,q: return 0 to leave it */
	        return (0);
	}
}
