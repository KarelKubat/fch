
/*
func(xrealloc)
    (Reallocate memory or issue an error)
    (void *xrealloc (void *oldmem, int size))
    (description(
		 dit(oldmem) is a pointer to previously allocated memory,
		    or 0 if no allocated memory yet present
		 dit(size) is the number of bytes to allocate))
    (Pointer to reallocated memory)
    (Allocates the memory or calls tt(out_of_memory()) to issue an error.
     When tt(oldmem) is 0, the memory is just allocated. Internally, the
     function maps to the tt(cmm*()) functions so that a memory usage
     trail is available. Therefore bf(note that) you may only free
     tt(xrealloc())-d memory with tt(cmm_free()) or tt(with cmm_cleanup()),
     and not with the standard tt(free()).

     See also tt(set_memerr(), out_of_memory(), x*(), cmm*()).)
    ()
*/

#include "fch.h"

void *xrealloc (void *oldmem, int sz) {
    void *ret;

    if (! oldmem)
	return (xmalloc (sz));

    if (! (ret = realloc (oldmem, sz)) )
	error("Out of memory\n");

    return (ret);
}
