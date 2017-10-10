#include "fch.h"

/*
func(strnicmp)
    (compare two strings over a given length, ignoring casing)
    (int strnicmp (char const *a, char const *b, int len))
    (description(
		 dit(a) is the first string
		 dit(b) is the second
		 dit(len) is the length over which to compare))
    (itemize(
	     it() 0 when both strings are equal,
	     it() >0 when tt(a) is "bigger",
	     it() <0 when tt(b) is "bigger"))
    (Strings tt(a) and tt(b) are compared over tt(len) bytes, without regard
     to casing. This function is similar to tt(strstr()), except that the
     comparisons are case-insensitive.)
    ()
*/

int strnicmp (char const *a, char const *b, int len) {
    int i;

    if (! a || ! b)
	return (a - b);

    for (i = 0; i < len; i++) {
	if (toupper (a[i]) != toupper (b[i]))
	    return (toupper (a[i]) != toupper (b[i]));
	if (! a[i])
	    return (0);
    }

    return (0);
}
