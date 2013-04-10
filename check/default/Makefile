include Makefile.rules


# VARIABLES

EXE   = test
OBJS  = $(notdir $(CFIL:.cc=.o))
DEPS  = $(notdir $(CFIL:.cc=.d))


# MAIN

all: $(EXE)

clean:
	rm -f $(OBJS)

distclean: clean
	rm -f $(EXE) $(DEPS) *.o *.d *.out *.err Makefile.rules
	rm -f gmon.out
	rm -f *.gcno *.gcno *.gcov *.gcda


# COMPIL

$(EXE): $(OBJS) $(LIBS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(EXE)

$(OBJS):
	$(CC) $(CFLAGS) -M $< -MP -MT $@ -MF $(@:.o=.d)
	$(CC) $(CFLAGS) -c $< -o $@


# SELF

sinclude $(DEPS)

dependency_rule = $(notdir $(1:.cc=.o)): $1
$(foreach file,$(CFIL),$(eval $(call dependency_rule,$(file))))
