
#ifndef NOMALLOC			/* for systems that lack malloc.h */
//#include <malloc.h>
#endif

#ifdef NOOPTIND				/* forced declaration */
extern int optind;
extern int getopt (int ac, char **av, char *opt);
#endif

#ifndef VER				/* version, if undefined */
#define VER "-.--"
#endif

#ifndef YRS				/* same for the years */
#define YRS "----"
#endif

#define VT100_BOLD "\033[1m"		/* start of bold in VT100 terms */
#define VT100_NORM "\033[0m"		/* normal output */

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef SIMPLEKEYS
#   include <termios.h>
#endif
#include <unistd.h>
#include <sys/stat.h> 

#define MAXBUF                  (1024*20)
#define RX_MATCH	     0	    /* rx_match returns: match */
#define RX_NOMATCH	     1	    /* no match */
#define RX_BADREGEX	    -1	    /* bad regular expression */

typedef enum
{
    ans_none,
    ans_changethis,
    ans_leavethis,
    ans_changethisfile,
    ans_leavethisfile,
    ans_changeall,
    ans_quit,
} ANSWER_;

extern ANSWER_
    ans;

extern int
    exit_status,
    remove_backup,
    verbose,
    ignorecase,
    regex,
    silent,
    avoid_vt100;

extern char
    *replacestring,
    *searchstring,
    *kbdinput,
    version [],
    years [];

extern char
    *makebackup (char *filename),
    *rx_find(char const *reg, char const *str, int *lenp),
    *str_vprintf(char const *fmt, va_list args),
    *stristr (char const *buf, char const *what);
    
extern int
    getinput (void),
    query (ANSWER_ *ap, char *buf, char *where, int matchlen),
    rx_match(char const *reg, char const *str),
    scan (FILE *inf, FILE *outf, char *fname),
    strnicmp (char const *a, char const *b, int len);
    
extern void 
    change (char *filename),
    changebuf (char *buf, char *where, int matchlen),
    error(char const *fmt, ...),
    msg(int verb, char const *fmt, ...),
    outputchar (char ch),
    promote (char *backname, char *filename),
    rx_ignorecase(int ign),    
    undo (char *backname, char *filename),
    usage (void),
    *xmalloc(int sz),
    *xrealloc(void *mem, int sz);

    
