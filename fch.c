
#include "fch.h"

/*
    main function of program:
    parses flags, sets global vars search/replacestring,
    calls change() to process all files
*/

char *xx_progname = "fch";

int main (int argc, char **argv)
{
    register int
	opt,
        i;
    struct stat
	statbuf;

    
    while ( (opt = getopt (argc, argv, "ravh?ik:-xe")) != -1 )
	switch (opt)
	{
	case 'e':
	    avoid_vt100++;
	    break;
	case 'r':
	    remove_backup = 1;
	    break;
	case 'a':
	    silent = 0;
	    break;
	case 'v':
	    verbose++;
	    break;
	case '-':
	    break;
	case 'i':
	    ignorecase = 1;
	    break;
	case 'k':
	    kbdinput = optarg;
	    break;
	case 'x':
	    regex = 1;
	    break;
	case '?':
	default:
	    usage ();
	}
        
    if (argc - optind < 3)
        usage ();
	
    msg (1, remove_backup ? 
	 "backup files will be removed\n" : 
	 "backup files will be kept\n");
    msg (1, silent ? 
	 "only lines matching searchstring will be shown\n" :
	 "all lines in input will be shown\n");
    msg (1, ignorecase ?
	 "searching will be done without regard to casing\n" :
	 "while searching, casing will be respected\n");
    msg (1, regex ?
	 "searchstring will be treated as a regular expression\n" :
	 "searchstring will be treated literally\n");
	
    searchstring  = argv [optind];
    replacestring = argv [optind + 1];
    
    msg (1, "searchstring: [%s]\n", searchstring);
    msg (1, "replacement : [%s]\n", replacestring);
    
    for (i = optind + 2; i < argc; i++)
    {
        msg (1, "processing file: %s\n", argv [i]);

	if (stat (argv [i], &statbuf))
	    msg (0, "can't stat %s, skipped (%s)\n", 
		 argv [i], strerror (errno));
	else if (! S_ISREG (statbuf.st_mode))
	    msg(0, "%s is not a regular file, skipped\n", argv [i]);
	else
	{
	    change (argv [i]);
	    if (chmod (argv [i], statbuf.st_mode))
		msg (0,"problem resetting mode of %s (%s)\n", 
		     argv [i], strerror (errno));
	}
    }
	
    return (exit_status);
}
