#include "fch.h"

void outputchar (char ch) {
    switch (ch) {
    case '\t':
	printf ("\\t");
	break;
    case '\a':
	printf ("\\a");
	break;
    case '\b':
	printf ("\\b");
	break;
    case '\r':
	printf ("\\r");
	break;
    case '\n':
	printf ("\\n");
	break;
    default:
	putchar (isprint(ch) ? ch : 'x');
    }
}
