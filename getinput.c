
#include "fch.h"

int getinput ()
{
    char
	ch = 0;
#   ifdef SIMPLEKEYS
    char
    	buf [80];
#   else
    struct termios
	tattr,
	saved;
#   endif

    /* Handle preloaded keyboard input. */ 
    if (kbdinput && *kbdinput) {
	ch = *kbdinput;
	memmove (kbdinput, kbdinput + 1, strlen(kbdinput) - 1);
	printf ("%c\n", ch);
	return (ch);
    }

    /* Otherwise: get input via the true keyboard. */
    
#ifdef SIMPLEKEYS
    /* without termios support */
    gets (buf);
    ch = buf [0];
    
#else
    /* for termios support */
    tcgetattr(fileno (stdin), &saved);
    tcgetattr(fileno (stdin), &tattr);   
    tattr.c_lflag &= ~(ICANON | ECHO);
    tattr.c_cc[VMIN] = 1;
    tattr.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);

    fflush (stdout);
    fflush (stderr);
    
    read (fileno (stdin), &ch, 1);
    printf ("%c\n", ch);

    fflush (stdout);

    tcsetattr(fileno (stdin), TCSANOW, &saved);
#endif	/* SIMPLEKEYS */

    return (ch);
}
