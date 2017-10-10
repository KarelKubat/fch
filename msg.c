#include <stdarg.h>
#include <stdio.h>
#include "fch.h"

/*
func(msg)
    (show message on tt(stderr) when in verbose mode)
    (void msg (int verb, char const *fmt, ...))
    (description(
		 dit(verb) is required verbosity to make the message appear
		 dit(fmt) is a format string a-la tt(printf())
		 dit(...) are optional remaining arguments))
    ()
    (The message appears on tt(stderr), prefixed by a program name (if
     one is set using tt(setprogname ())), if the required verbosity as
     indicated by the tt(verb) argument, is matched by the number of
     previous calls to tt(msg_on()).

     For example, a tt(msg()) call with a
     required verbosity 1 will appear if tt(msg_on()) was called at
     least once.

     See also tt(msg_and_log()) to log a message and optionally show it on
     tt(stderr).)
     (The following code snippet sets the verbosity to level 1. Then
      some messages are shown.
    verb(\
msg_on ();
msg (0, "this will always appear\n");
msg (1, "this will appear with this verbosity level\n");
msg (2, "this will only appear with a higher level\n");)

      The following code snippet is more elaborate. As long as tt(-v) flags
      appear in the program options, the verbosity is increased. Further on
      through the code, tt(msg()) calls are placed that during a run will
      appear only if the "verbosity level" at invocation was sufficiently
      high.
      
    verb(\
int opt;

while ( (opt = getopt (argc, argv, "vcd:g:")) > 0 ) {
    switch (opt) {
	case 'v':
	    msg_on ();
	    break;
	.
	. Other options, c, d and g would be handled
	. here
	.
    }
}
.
.
.
msg (1, "High-priority message\n");
msg (3, "This appears only when -vvv was given\n");))

*/

extern char *xx_progname;

void msg (int verb, char const *fmt, ...) {
    va_list args;

    if (verbose >= verb) {
	if (xx_progname)
	    fprintf (stderr, "%s: ", xx_progname);
	va_start (args, fmt);
	vfprintf (stderr, fmt, args);
	fflush (stderr);
    }
}
