##
## Makefile for zolver
## Made by nicuveo <crucuny@gmail.com>
##



# MAIN

PROJ = zolver

$(PROJ): all

sinclude Makefile.rules



# VARIABLES

EXE   = bin/$(PROJ)
LIBA  = bin/lib$(PROJ).a
LIBSO = bin/lib$(PROJ).so
DYLIB = bin/lib$(PROJ).dylib

OBJS  = $(addprefix $(BUILD_DIR)/, $(notdir $(CFIL:.cc=.o)))
DEPS  = $(addprefix $(BUILD_DIR)/, $(notdir $(CFIL:.cc=.d)))

CLEAN += '*~' '\#*' '.\#*' '.DS_Store' '.gdb_history' '*.stackdump' \
'.gdb_history' 'gmon.out' '*.dSYM' '*.gcno' '*.gcda'
DISTCLEAN += '*.o' '*.d' 'Makefile.rules'



# ALL

all: $(TARGETS)

install: all
	if [ -x ./install ] ; then ./install "$(PREFIX)" ; else cp $(TARGETS) $(PREFIX) ; fi



# COMPIL

$(EXE): $(LIBS) $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(EXE)

$(LIBA): $(LIBS) $(OBJS)
	ar -scr $(LIBA) $(OBJS)

$(LIBSO): $(LIBS) $(OBJS)
	$(CC) -shared $(OBJS) $(LDFLAGS) -o $(LIBSO)

$(DYLIB): $(LIBS) $(OBJS)
	$(CC) -dynamiclib $(OBJS) $(LDFLAGS) -o $@

$(OBJS):
	$(CC) $(CFLAGS) -M $< -MP -MT $@ -MF $(@:.o=.d)
	$(CC) $(CFLAGS) -c $< -o $@



# DISPATCH

sub_call_func = (cd ./$1 && $2)
sub_call_rule = $(call sub_call_func,$1,$(MAKE) $2)
define sub_make_rule
$1: all
	$(call sub_call_rule,$1,all)
endef


$(foreach sub,$(SUB_DIRS),$(eval $(call sub_make_rule,$(sub))))

$(LIBS): libs


libs:
	$(foreach lib,$(LIBS_DIRS),$(call sub_call_rule,$(lib),all);)

conf_libs:
	$(foreach lib,$(LIBS_DIRS),$(call sub_call_func,$(lib),./configure $(CONF_LIBS));)

clean: do_clean
	$(foreach lib,$(LIBS_DIRS),$(call sub_call_rule,$(lib),-k clean);)
	$(foreach sub,$(SUB_DIRS) ,$(call sub_call_rule,$(sub),-k clean);)
	for f in ${CLEAN} ; do find . -name "$$f" | xargs rm -Rf ; done

distclean: do_distclean
	$(foreach lib,$(LIBS_DIRS),$(call sub_call_rule,$(lib),-k distclean);)
	$(foreach sub,$(SUB_DIRS) ,$(call sub_call_rule,$(sub),-k distclean);)
	for f in ${DISTCLEAN} ; do find . -name "$$f" | xargs rm -Rf ; done



# CLEAN

do_clean:
	rm -f $(OBJS)

do_distclean: do_clean
	rm -f $(EXE) $(LIBA) $(LIBSO) $(DYLIB) $(DEPS)
	rm -Rf doc/doxygen/*



# DOC

export:
	svn export --force . $(or $(EXPORT), "export")

tarball:
	./scripts/tarball . $(PROJ)



# SELF

sinclude $(DEPS)

dependency_rule = $(BUILD_DIR)/$(notdir $(1:.cc=.o)): $1
$(foreach file,$(CFIL),$(eval $(call dependency_rule,$(file))))

Makefile.rules:
	./configure $(CONFIGURE_ARGS)



# MISC

flower:
	@cat ./scripts/flower

todo:
	@./scripts/todo



# SPECIALS

.PHONY: todo flower export $(LIBS_DIRS) $(SUB_DIRS)
