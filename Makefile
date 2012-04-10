##
## Makefile for zolver
## Made by nicuveo <crucuny@gmail.com>
##

include Makefile.rules



# VARS

CLEAN = '*~' '\#*' '.\#*' '.DS_Store' '.gdb_history' '*.stackdump'\
'.gdb_history' 'gmon.out' '*.dSYM'



# MAIN

all:
	cd ./build/ && make all

clean: do_clean
	cd ./build/ && make -k clean

distclean: do_distclean
	cd ./build/ && make -k distclean



# CLEAN

do_clean:
	for f in ${CLEAN} ; do find . -name "$$f" | xargs rm -Rf ; done

do_distclean: do_clean
	rm -f Makefile.rules
