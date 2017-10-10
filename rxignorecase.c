/*

func(rx_ignorecase)
    (ignore casing in regular expression matching)
    (void rx_ignorecase (int onoff))
    (tt(onoff) is not-0 to select case-insensitive matching (ignoring),
     or 0 to select case-sensitive matching (the default))
    ()
    (This function selects case-sensitivity during regular expressions
     matching. The choice affects how tt(rx_match()) and tt(rx_find())
     match strings against regular expressions.)
    ()

*/


#include <regex.h>

extern int xx_rxflags;

void rx_ignorecase (int ignore) {
    if (ignore)
	xx_rxflags |= REG_ICASE;
    else
	xx_rxflags &= ~REG_ICASE;
}
