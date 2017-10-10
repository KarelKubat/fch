#include <stdarg.h>
#include <stdio.h>
#include "fch.h"

/*
func(error)
    (print error message including program name and exit)
    (void error (char const *fmt, ...))
    (tt(fmt) is a tt(printf)-like format string, other arguments may follow)
    ()
    (Prints an error message to tt(stderr) in a formatted way. The program
     name, if set using tt(setprogname ()), is included. When logging is
     enabled using tt(log_setup ()), then the error message is also written
     to the log file before exiting.

     See also tt(setprogname (), log_setup (), logmsg ()).)
    (The following call:
   verb(\
error ("bad input: %s\n", buf);)

     will produce something similar to:

   verb(\
progname: bad input: whatever
progname: aborting...))
*/

extern char *xx_progname;
extern char *xx_logfname;
extern int xx_log_is_true_file;

void error(char const *fmt, ...)
{
    char *cp;
    va_list args;

    /* construct error message */
    va_start (args, fmt);
    cp = str_vprintf(fmt, args);

    /* log it 
    logmsg("Fatal error: %s", cp);
    */
    
    /* put the error to stderr, if we're on a tty */
    if (isatty(2)) {
	if (xx_progname)
	    fprintf(stderr, "%s: ", xx_progname);
	fprintf(stderr, "%s\n", cp);
    }
    exit(1);
}
