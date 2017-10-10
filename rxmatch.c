
#include <regex.h>
#include "fch.h"

/*
func(rx_match)
    (match regular expression and a string)
    (int rx_match (char const *regex, char const *str))
    (tt(regex) is an extended regular expression to match string with,
     tt(str) is the string to compare to tt(regex))
    (description(
		 dit(RX_MATCH (0)) string matches regex,
		 dit(RX_NOMATCH (>0))  string does not match regex,
		 dit(RX_BADREGEX (<0)) bad regular expression))
    (Does a single match of a string against a regular expression.
     Notably, this function is NOT suitable for:
     itemization(
	     it() rematching strings with one regular expression. If you want
	      that, use the "standard" tt(regcomp()) and tt(regexec()).
	     it() determining WHAT PART of the string matches.
	      The function just returns whether it matches or not.
	     it() matching substrings and storing the result. The function
	      just returns whether the string matches or not.)
      
     This function heavily relies on the POSIX standard. Some "less
     than POSIXy" systems will lack the support for regular
     expressions.

     Normally, matching will be with regard to casing. Use
     tt(rx_ignorecase(1)) to match while ignoring casing, or switch
     back to case-sensitivity with tt(rx_ignorecase(0)).)
    ()
*/

int xx_rxflags;

int rx_match (char const *reg, char const *str) {
    regex_t myregex;
    int res = RX_MATCH;

    if (!reg || !*reg)
	return (RX_BADREGEX);
    if (!str || !*str)
	return (RX_NOMATCH);

    if (regcomp(&myregex, reg, REG_NOSUB | REG_EXTENDED | xx_rxflags))
	res = RX_BADREGEX;
    else if (regexec (&myregex, str, 0, 0, 0))
	res = RX_NOMATCH;

    regfree(&myregex);

    return (res);
}
	
