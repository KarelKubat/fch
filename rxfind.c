
#include <regex.h>

/*
func(rx_find)
    (find a regular expression in a string)
    (char *rx_find (char const *regex, char const *str, int *lenp))
    (tt(regex) is an extended regular expression to match string with,
     tt(str) is the string to search in, tt(lenp) points to an
     tt(int) where the matched length is stored (when tt(lenp) is
     not 0))
    (The return value points into tt(str) where tt(regex) was matched,
     or 0 when
     itemization(
         it() the regular expression wasn't matched in tt(str), or when
	 it() the regular expression was invalid ) )
    (This function attempts to find tt(regex) in tt(str). A pointer to
     the first occurrence is returned. When tt(lenp) is not 0,
     then the number of matched tt(char)s is stored there.

     To test whether an expression is valid, use tt(rx_match()), whose
     return value may not be tt(RX_BADREGEX). This function
     tt(rx_find()) doesn't provide that capability; the return value 0
     is used for situations where the match cannot be made bf(and) for
     situations where tt(regex) is invalid.

     This function heavily relies on the POSIX standard. Some "less
     than POSIXy" systems will lack the support for regular
     expressions.

     Normally, matching will be with regard to casing. Use
     tt(rx_ignorecase(1)) to match while ignoring casing, or switch
     back to case-sensitivity with tt(rx_ignorecase(0)).)
    ()
*/

extern int xx_rxflags;

char *rx_find (char const *reg, char const *str, int *lenp) {
    regex_t myregex;
    regmatch_t match;

    if (regcomp(&myregex, reg, REG_EXTENDED | xx_rxflags))
	return (0);
    if (regexec (&myregex, str, 1, &match, 0))
	return (0);

    regfree(&myregex);
    if (lenp)
	*lenp = match.rm_eo - match.rm_so;
    return ( (char*) str + match.rm_so);
}
	
