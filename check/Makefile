##
## Makefile for saw
## Made by nicuveo <crucuny@gmail.com>
##

include Makefile.rules



# VARS

PROJ = saw



# MAIN

all: run analysis coverage

run:
	@./test run      $(TESTS)

analysis:
	@./test analyse  $(ANALYSE_OPTS) $(CFIL)

coverage:
	@./test coverage $(COVERAGE_OPTS) $(COVERAGE_OUT) $(TESTS)



# CLEAN

clean:
	for e in $(TESTS) ; do (cd $$e && make clean) ; done

distclean:
	for e in $(TESTS) ; do (cd $$e && make distclean) ; done
	rm -f Makefile.rules default/Makefile.rules
	rm -f analysis.log coverage.log test.log coverage.info
	rm -Rf $(COVERAGE_OUT)



# SPECIALS

.PHONY: $(TESTS)
