
#include "fch.h"

/*
    print usage and die
*/    

void usage ()
{
    fprintf (stderr, 
"\n"
"Interactive Filechanger  V%s\n"
"Copyright (c) Karel Kubat, ICCE/e-tunity %s. All rights reserved.\n"
"Another MegaHard Production.\n"
"The fch program was originally written at the State University of\n"
"Groningen, Netherlands. It is now maintained by e-tunity. Contact\n"
"info@e-tunity.com / karel@e-tunity.com for more information.\n"
"\n"
"fch by Karel Kubat (karel@e-tunity.com).\n"
"\n"
"Usage: fch [flags] [--] searchstring replacestring file(s)\n"
"where:\n"
"       -r:              backup files will be removed, default is to leave\n"
"                        .bak files\n"	     
"       -a:              all lines in input file are shown, default is to\n"
"                        show only lines with searchstring\n"
"       -v:              increases verbosity\n"
"       -i:              searchstring is matched without regard to casing\n"
"       -x:              searchstring is treated as a regular expression\n"
"                        default is to treat literally\n"	     
"       -k input:        'preloads' input as if it were typed from the\n"
"                        keyboard\n"
"       -e               will not use VT100 escape sequences to mark matches\n"
"                        of the searchstring, default is to show matches\n"
"                        in bold\n"	     
"       --               stop processing options, incase your strings or\n"
"                        files start with a hyphen\n"	     
"       searchstring:    the string to search for\n"
"       replacestring:   the string to replace searchstring with\n"
"       file(s):         files to process\n"
"The searchstring must exactly match the contents of the file(s) in order\n"
"to be found. When files are changed, .bak backup versions are kept (unless\n"
"the -r flag is given).\n"
"\n"
        , VER, YRS);
	
    exit (1);
}	

