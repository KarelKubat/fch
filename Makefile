##############################################################################
# Makefile for fch
##############################################################################

# Configurable options. Depending on what you tweak you can even build this
# on a Cygwin box. The below applies to Linux, MacOSX, and POSIX-y Unices.

# Define if your system has no malloc.h:
NOMALLOC = -DNOMALLOC

# Define if your system has optind, getopt() etc, but no header file
# for it:
# OPTIND = -DNOOPTIND

# Define if your system doesn't have good termios handling. If set,
# fch will do very simple key entry.
# SIMPLEKEYS = -DSIMPLEKEYS

# Directory where the binary goes
BINDIR = /usr/local/bin

# Extension of executables, cygwin32 needs .exe. Real unixes should have this
# line commented out.
# EXEPOSTFIX = .exe

# Configurable options end here. Now type "make".
##############################################################################

# Version number of this package, don't change:
VER = 2.07
YRS = 1996ff.

# Compilation flags, other than -c
CFLAGS = -Wall -DVER=\"$(VER)\" -DYRS=\"$(YRS)\" -I$(EINCDIR) \
	$(NOMALLOC) $(NOOPTIND) $(SIMPLEKEYS)

# Object files.
OBJ =	 change.o changebuf.o data.o fch.o getinput.o makebackup.o \
	 promote.o query.o scan.o undo.o usage.o outputchar.o \
	 rxfind.o rxignorecase.o rxmatch.o msg.o error.o stristr.o \
	 strvprintf.o xmalloc.o xrealloc.o strnicmp.o

# What are we doing here?
foo:
	@cat Makefile.help

# Make the program.
fch: $(OBJ)
	$(CC) -o fch $(OBJ) -lm
	@echo "Program construction complete."

install: $(BINDIR)/fch$(EXEPOSTFIX)

$(BINDIR)/fch$(EXEPOSTFIX): fch$(EXEPOSTFIX)
	install -s fch$(EXEPOSTFIX) $(BINDIR)
	@echo "Program installation complete."

clean:
	rm -f fch fch$(EXEPOSTFIX) *.o *~

dist: clean
	(cd .. && tar -c -v -z -f /tmp/fch-$(VER).tar.gz \
	              --exclude .git fch/)
	@echo
	@echo Distribution ready as: /tmp/fch-$(VER).tar.gz
	@echo

# How to get from *.c to *.o.
.c.o:
	$(CC) -c $(CFLAGS) $<

# Extra deps:
usage.o: usage.c Makefile
