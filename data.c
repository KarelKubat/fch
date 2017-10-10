
#include "fch.h"

ANSWER_
    ans = ans_none;                     /* user's answer */

int
    exit_status = 0,                    /* exit status of prog, != 0 on
                                           errors or warnings */

    silent = 1,				/* 0 if -a flag given, note:
					   by default fch is silent */
                                           
    verbose = 0,                        /* verbosity level, 0 is off */

    ignorecase = 0,			/* ignore case when searching?
					   default: respect casing */ 
					   
    remove_backup = 0,                  /* 1 if -r flag given */

    regex = 0, 				/* use regular expressions match */

    avoid_vt100 = 0;			/* 1 if -e flag given: will print */
					/* <searchstring> instead of */
					/* vt100 codes */

char
    *replacestring,                     /* search/replace strings */
    *searchstring,
    *kbdinput;				/* preloaded -k input */ 
    
