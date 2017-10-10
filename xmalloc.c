#include "fch.h"

/*
func(xmalloc)
    (Allocate memory or issue an out-of-memory error)
    (void *xmalloc (int size))
    (tt(size) is the number of bytes to allocate)
    (Pointer to allocated memory)
    (Allocates the memory or calls tt(out_of_memory()) to issue an error.
     Internally, this function uses tt(cmm_malloc()) so that the memory
     usage trail is recorded. Therefore, bf(note that) tt(xmalloc())-d memory
     may only be freed using tt(cmm_free()) or tt(cmm_cleanup()).
     
     See also tt(set_memerr(), out_of_memory(), x*(), cmm*()).)
    ()
*/

void *xmalloc (int sz) {
    void *ret;

    if (! (ret = malloc (sz)) )
	error("Out of memory\n");

    return (ret);
}
