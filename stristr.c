#include "fch.h"

/*
func(stristr)
    (search for substring in a string without regard to casing)
    (char *stristr (char const *buf, char const *search))
    (description(
		 dit(buf) is the buffer to search in
		 dit(what) specifies what to search for))
    (Pointer within tt(buf) where tt(search) occurs, or 0 when tt(search)
     was not found. A pointer to the first character of tt(buf) is also
     returned when tt(search) is 0.)
    (Searches in tt(buf) for the first occurrence of search and returns
     a pointer to it. The string search is case-insensitive. This function is
     therefore similar to tt(strstr()), except for the insensitiveness.)
    ()
*/

char *stristr (char const *buf, char const *what) {
    int len = strlen (what);

    if (! buf)
	return (0);
    if (! what)
	return ( (char *) buf);

    /* Loop over the buffer. Try to match "what". */ 
    while (*buf) {
	if (! strnicmp (buf, what, len))
	    return ( (char *) buf);
	buf++;
    }

    /* Failure! */ 
    return (0);
}

	    
