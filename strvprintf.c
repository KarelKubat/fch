#include "fch.h"

/*
func(str_vprintf)
    (fill a string using vprintf capabilities)
    (char *str_vprintf (char const *fmt, va_list args))
    (tt(fmt) and tt(args) are tt(vprintf())-like arguments)
    (pointer to a formatted string)
    (This function is similar to tt(vsprintf()), except that the string is
     created using allocated memory. There is therefore no risk of buffer
     overflow.)
    ()
*/

#define STR_BLOCK 512

char *str_vprintf (char const *fmt, va_list arguments) {
    int size = STR_BLOCK;	    /* initial size guess */
    char *buffer = xmalloc (size);   /* initial buffer */
    int nchars;			    /* return value of vsnprintf */

    while (1) {			    /* try to make string */
	nchars = vsnprintf (buffer, size, fmt, arguments);

	/* if this worked, return string */
	if (nchars > -1 && nchars < size)
	    return (buffer);

	/* try again with more space */
	if (nchars > -1)
	    size = nchars + 1;
	else
	    size += STR_BLOCK;

	buffer = xrealloc (buffer, size);
    }

    return (0);			    /* to satisfy prototype */
}

/* E O F
 */
