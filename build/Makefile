##
## Makefile for zolver
## Made by nicuveo <crucuny@gmail.com>
##

include Makefile.rules



# VARIABLES

PROJ  = zolver

EXE   = ../bin/$(PROJ)
LIBA  = ../bin/lib$(PROJ).a
LIBSO = ../bin/lib$(PROJ).so
DYLIB = ../bin/lib$(PROJ).dylib

OBJS  = $(notdir $(CFIL:.cc=.o))
DEPS  = $(notdir $(CFIL:.cc=.d))



# MAIN

all: $(TARGET)

clean: do_clean

distclean: do_distclean



# CLEAN

do_clean:
	rm -f $(OBJS)  $(DEPS)

do_distclean: do_clean
	rm -f $(EXE) $(LIBA) $(LIBSO) $(DYLIB)
	rm -f Makefile.rules Makefile.deps



# COMPIL

$(EXE): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(EXE)

$(LIBA): $(OBJS)
	ar -scr $(LIBA) $(OBJS)

$(LIBSO): $(OBJS)
	$(CC) -shared $(OBJS) $(LDFLAGS) -o $(LIBSO)

$(DYLIB): $(OBJS)
	$(CC) -dynamiclib $(OBJS) $(LDFLAGS) -o $@

$(OBJS):
	$(CC) $(CFLAGS) -c $< -o $@



# SELF

sinclude $(DEPS)

dependency_rule = $(notdir $(1:.cc=.d)): $1
$(foreach file,$(CFIL),$(eval $(call dependency_rule,$(file))))

$(DEPS):
	$(CC) $(CFLAGS) -M $< -MP -MT "$(@:.d=.o) $@" -MF $@
