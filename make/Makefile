# how make read makefiles
# GNU make does its work in two distinct phases. During the frst phase it reads all the makefles, 
# included makefles, etc. and internalizes all the variables and their values, implicit and
# explicit rules, and constructs a dependency graph of all the targets and their prerequisites.
# During the second phase, make uses these internal structures to determine what targets will
# need to be rebuilt and to invoke the rules necessary to do so.

# specify whitespace number before directive.
.RECIPEPREFIX = 

# turn on Secondary Expansion.
.SECONDEXPANSION:
.ONESHELL:
a = 1.c
main_obj := 1.o 2.o 3.o
lib_obj := 4.o 5.o
mains_src := 1.c 2.c 3.c
libs_src := 4.c 5.c

.PHONY: one
one: $(a) ; @echo $^

.PHONY: two
two: $$(a)
	@echo $^
	@echo ~ha/bin

.PHONY: main lib
main lib: $$($$@_obj)
	@echo $^

a = 2.c

.PHONY: mains libs
mains libs: $$(patsubst %.c,%.o,$$($$@_src))
	@echo $^

.PHONY: clean
clean:
	rm -rf *.o temp/*.o

# $$<, $$^, and $$+ expand to the empty string(first line).
.PHONY: foo
foo: 1.c 2.c $$< $$^ $$+
	@echo $<   
	@echo $^
	@echo $+

# foo: 3.c 4.c $$< $$^ $$+
# 	@echo $<  
# 	@echo $^
# 	@echo $+

# order-only prerequisites, specifed by placing a pipe symbol (|), 
# targets : normal-prerequisites | order-only-prerequisites.
# ~/bin expand to /home/user/bin ~luo/bin expand to /home/luo/bin in linux.
# $? is used to print only those files that have changed;
# lpr use Printer printing files. 
.PHONY: print
print: *.c
	lpr -p $?
	touch print

# Function:
# Function wildcard: $(wildcard pattern...).
# use like: $(wildcard *.c) $(patsubst %.c,%.o,$(wildcard *.c)).

# Function VPATH:
# use like: VPATH = src:../headers.
# vpath pattern directories specify the search path directories for fle names that match pattern.
# vpath pattern Clear out the search path associated with pattern.
# vpath Clear all search paths previously specifed with vpath directives.
# use like: vpath %.h ../headers. 
# example:
.PHONY: objs 
VPATH = temp
vpath %.h header

objs: $(patsubst %.c,%.o,$(wildcard *.c))\
      6.o 7.o 8.o 
	@echo $^

# Implicit Rules, don't need to write, only for gcc.
%.o: %.c
	@echo $<
	gcc -c $< -o $(patsubst %.c,%.o,$<)

# Here we’ve also declared that the foo sub-directory cannot be built until after the baz
# sub-directory is complete; this kind of relationship declaration is particularly important
# when attempting parallel builds.
# implicit rule is skipped for .PHONY.
SUBDIRS = foo1 bar baz
.PHONY: subdirs $(SUBDIRS)
subdirs: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@
foo1: baz

# Special Built-in Target Names:

# .PHONY make will run its recipe unconditionally, regardless of whether a fle with that name exists or what its
# last-modifcation time is.

# .SUFFIXES the list of suffixes to be used in checking for suffix rules.

# .DEFAULT used for any target for which no rules are found (either explicit rules or implicit rules).

# .PRECIOUS preserve intermediate fles created by rules whose target patterns match that fle’s name.

# .INTERMEDIATE  depends on are treated as intermediate files.

# .SECONDARY depends on are treated as intermediate files, except that they are never automatically deleted.

# .SECONDEXPANSION all prerequisite lists defined after it appears will be expanded a second time
# after all makefles have been read in.

# .DELETE_ON_ERROR make will delete the target of a rule if it has changed and its recipe exits with
# a nonzero exit status.

# .EXPORT_ALL_VARIABLES tells make to export all variables to child processes by default.

# .ONESHELL when a target is built all lines of the recipe will be given to a single invocation 
# of the shell rather than each line being invoked separately.

# .POSIX the makefle will be parsed and run in POSIX-conforming mode.

# Syntax of Static Pattern Rules:
# Each target specified must match the target pattern;
# targets ...: target-pattern: prereq-patterns ...
# 	recipe
# 	...
# example:
.PHONY:objs2
objs1 = 6.o 7.o
objs2: $(objs1)
$(objs1): %.o: %.c
	@echo $<
	@echo $@ 

# use $* in Static Pattern Rules.
.PHONY:bigput littleput
bigput littleput: %put: 1.c
	@echo $*
	@echo $^

# Create prerequisites auto.
# pattern rule to generate a fle of prerequisites (i.e., a makefle) called name.d
# from a C source fle called name.c.
# The ‘-e’ ﬂag to the shell causes it to exit immediately if the $(CC) command (or any other
# command) fails (exits with a nonzero status).
# $$$$ is the process pid.
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

#  make syntax and shell syntax.
# recipes are meant to be interpreted by the shell and so they are written using
# shell syntax. The make program does not try to understand shell syntax: it performs only
# a very few specific translations on the content of the recipe before handing it to the shell.
# A blank line that begins with a tab is not blank.
# A comment in a recipe is not a make comment.
# A variable defnition in a “rule context” which is indented by a tab as the first character
# on the line, will be considered part of a recipe, not a make variable definition, and passed
# to the shell.
# A conditional expression (ifdef, ifeq, etc.)
# in a “rule context” which is indented by a tab as the first character on the
# line, will be considered part of a recipe and be passed to the shell.
# Both the backslash and the newline characters are preserved and passed
# to the shell. How the backslash/newline is interpreted depends on your shell.
# If the frst character of the next line after the backslash/newline is the recipe prefx character (a tab
# by default), then that character (and only that character) is removed. Whitespace is never added to the recipe.
# backslash/newline pair was removed inside the string quoted with double
# quotes ("..."), but not from the string quoted with single quotes ('...').
# One simple way of handling this is to place the quoted string,
# or even the entire command, into a make variable then use the variable in the recipe.
# HELLO = ’hello \
world’
# all : ; @echo $(HELLO)
#example
syntax: ; @echo 'hello \
world' ; echo "hello \
    world"

# Recipe Echoing
# When a line starts with ‘@’, the echoing of that line is suppressed.
# The ‘-s’ or ‘--silent’ ﬂag to make prevents all echoing.

# Recipe Execution
# to update a target, they are executed by invoking a new
# sub-shell for each line of the recipe, unless the .ONESHELL special target is in effect.
# commands such as cd that set a context local to each process will not aﬀect the following 
# lines in the recipe. If you want to use cd to aﬀect the next statement, 
# put both statements in a single recipe line.
# Here we use the shell AND operator (&&) so that if the cd command fails, the script will fail
# without trying to invoke the gobble command in the wrong directory.
# like: foo : bar/lose ; cd $(@D) && gobble $(@F) > ../$@

# Using One Shell
# Sometimes you would prefer that all the lines in the recipe be passed to a single invocation
# of the shell.
# if @,-,+ is the first characters, it removed by make, but the special prefix characters are not legal
# at the beginning of a line in a POSIX shell 
# SHELL = /bin/sh, the variable SHELL is never set from the environment
# .SHELLFLAGS = -c
# example:
# .ONESHELL:
foo2 : temp
	@cd $<
	@echo $(@F) > ../$@

# Parallel Execution
# Normally, make will executeonly one recipe at a time, waiting for it to 
# fnish before executing the next. However, the‘-j’ or ‘--jobs’ option tells 
# make to execute many recipes simultaneously.
# ‘-l’ option to tell make to limit the number of jobs to run at once.

# Output During Parallel Execution
# use the ‘--output-sync’ (‘-O’) option. This option instructs make to save the
# output from the commands it invokes and print it all once the commands are completed.
# -O, four level, none, line, target, recurse.
# add the ‘--no-print-directory’ option to MAKEFLAGS to avoid enter/leave messages.

# Errors in Recipes
# To ignore errors in a recipe line, write a ‘-’ at the beginning of the line’s text (after the
# initial tab).
# ‘-i’ or ‘--ignore-errors’ ﬂag, errors are ignored in all recipes of all rules.
# -k’ or ‘--keep-going’ ﬂag will continue compiling other object fles after an error. 

#  Interrupting or Killing make
# If make gets a fatal signal while a shell is executing, it may delete the target fle that the
# recipe was supposed to update.

# Recursive Use of make
# subsystem: ; $(MAKE) -C subdir
# when GNU make starts (after it has processed any -C options)
# it sets the variable CURDIR to the pathname of the current working directory. 
# whenever a recipe line of a rule
# contains the variable MAKE, the ﬂags ‘-t’, ‘-n’ and ‘-q’ do not apply to that line.
# The usual MAKEFLAGS mechanism passes the ﬂags to the sub-make.

# Communicating Variables to a Sub-make
# The value of the make variable SHELL is not exported.Instead, the value of the SHELL
# variable from the invoking environment is passed to the sub-make
# The special variable MAKEFLAGS is always exported (unless you unexport it).
# make automatically passes down variable values that were defned on the command line,
# by putting them in the MAKEFLAGS variable.The options ‘-C’, ‘-f’, ‘-h’, ‘-o’, and ‘-W’ are 
# not put into MAKEFLAGS; these options are not passed down.
# If you want to export specifc variables to a sub-make, use the export directive, like this:
# export variable ...
# If you want to prevent a variable from being exported, use the unexport directive, like this:
# unexport variable ...
# export variable = value
# the variable MAKELEVEL is changed when it is passed down from
# level to level. This variable’s value is a string which is the depth of the level as a decimal
# number. The value is ‘0’ for the top-level make; ‘1’ for a sub-make, ‘2’ for a sub-sub-make,
# and so on. 
# If you do not want to pass the other ﬂags down, you must change the value of MAKEFLAGS,
# like this:
# subsystem:
# 	cd subdir && $(MAKE) MAKEFLAGS=
# The command line variable defnitions really appear in the variable MAKEOVERRIDES,
# and MAKEFLAGS contains a reference to this variable. If you do want to pass ﬂags down
# normally, but don’t want to pass down the command line variable defnitions, you can reset
# MAKEOVERRIDES to empty, like this:
# MAKEOVERRIDES =
# A similar variable MFLAGS exists also, for historical compatibility. It has the same
# value as MAKEFLAGS except that it does not contain the command line variable defnitions,
# MFLAGS was traditionally used explicitly in the recursive
# make command, like this:
# subsystem:
# 	cd subdir && $(MAKE) $(MFLAGS)
# if you not want to add GNU make-specifc ﬂags to the MAKEFLAGS variable, you can add them
# to the GNUMAKEFLAGS variable instead. When make constructs MAKEFLAGS to pass to a recursive make
# it will include all ﬂags, even those taken from GNUMAKEFLAGS.As a result, after parsing
# GNUMAKEFLAGS GNU make sets this variable to the empty string to avoid duplicating ﬂags
# during recursion.
# example
# note GNUMAKEFLAGS is only useful in linux
GNUMAKEFLAGS += --output-sync
.PHONY: flags
flags:
	@echo $(MAKE)
	@echo $(MAKEFLAGS)
	@echo $(MFLAGS)
	@echo $(MAKEOVERRIDES)
	@echo $(GNUMAKEFLAGS)
	@echo $(MAKELEVEL)
	@echo $(CURDIR)
	@$(MAKE) -C sub1

# Using Empty Recipes
# like: target: ;
# why: this is useful is to prevent a target from getting implicit recipes (from implicit rules or
# the .DEFAULT special target

# How to Use Variables
# Variables and functions in all parts of a makefle are expanded when read, except for
# in recipes, the right-hand sides of variable defnitions using ‘=’, and the bodies of variable
# defnitions using the define directive.
# Variable names are case-sensitive.
 
# The Two Flavors of Variables
# The frst ﬂavor of variable is a recursively expanded variable. Variables of this sort are
# defned by lines using ‘=’ or by the define
# directive.
# A major disadvantage is that you cannot append something on the end of a
# variable, as in:
# CFLAGS = $(CFLAGS) -O, it will cause an infnite loop in the variable expansion.
# Another disadvantage is that any functions referenced in the defnition will be executed 
# every time the variable is expanded. 
# Simply expanded variables are defned by lines using ‘:=’ or ‘::=’.
# They allow you to redefne a variable using its own value.
# if you do not want any whitespace characters at the end of your variable
# value, you must remember not to put a random comment on the end of the line after some
# whitespace, such as this:
# dir := /foo/bar    # directory to put the frobs in 
# the value of the variable dir is ‘/foo/bar ’ (with four trailing spaces)
# There is another assignment operator for variables, ‘?=’. This is called a conditional
# variable assignment operator, because it only has an eﬀect if the variable is not yet defned.
# Note that a variable set to an empty value is still defined.

# Appending More Text to Variables
# When the variable in question has not been defned before, ‘+=’ acts just like normal
# ‘=’: it defnes a recursively-expanded variable.
#example:
inc = a b c
temp = $(inc) d
temp += e f
inc1 := a b c
temp1 := $(inc) d
temp1 += e f
flavors:
	@echo $(temp)
	@echo $(temp1)
inc += g h
inc1 += g h

# To append more text to a variable defned on the command line, use:
# override variable += more text
# If you want variable defnitions made with define to take precedence over command-line
# variable defnitions, you can use the override directive together with define:
# override define two-lines =

# use the undefine directive to make a variable appear
# If you want to undefne a command-line variable defnition, you can use the override
# directive together with undefine, similar to how this is done for variable defnitions:
# override undefine CFLAGS

# By default, only variables that came from the environment or the command line are passed to 
# recursive invocations. You can use the export directive to pass other variables.

# Any variable marked private will be visible to its local target but will not be inherited by prerequisites
# of that target. A global variable marked private will be visible in the global scope but will
# not be inherited by any target, and hence will not be visible in any recipe
# like: EXTRA_CFLAGS =
# prog: private EXTRA_CFLAGS = -L/usr/local/lib
# prog: a.o b.o
# Due to the private modifier, a.o and b.o will not inherit the EXTRA_CFLAGS variable
# assignment from the prog target.

# Other Special Variables
# MAKEFILE_LIST: Contains the name of each makefle that is parsed by make.
# .DEFAULT_GOAL: default goal to be used if no targets were specifed on the command line
# .INCLUDE_DIRS: Expands to a list of directories that make searches for included makefles
# .FEATURES: Expands to a list of special features supported by this version of make
include build.mk
svar:
	@echo $(MAKEFILE_LIST)
	@echo $(.DEFAULT_GOAL)
	@echo $(.INCLUDE_DIRS)
	@echo $(.FEATURES)

# Conditional
# ifeq (arg1, arg2)
# ifeq ’arg1’ ’arg2’
# ifeq "arg1" "arg2"
# ifeq "arg1" ’arg2’
# ifeq ’arg1’ "arg2"
# ifneq
# ifdef variable-name
# ifdef only tests whether a variable has a value. It does not expand
# the variable to see if that value is nonempty
# ifndef variable-name
# If the variable variable-name has an empty value, the text-if-true is eﬀective;
# you cannot use automatic variables in the tests of conditionals because they are not 
# defined until recipes are run
# example:
var1 = a b c d e
archive:
ifneq (,$(findstring a,$(var1)))
	+touch archive.a
	+echo $(var)
else
	echo "not found"
endif

# Functions for String
# $(subst from,to,text)
# $(patsubst pattern,replacement,text)
# $(strip string)
# $(findstring find,in)
# $(filter pattern...,text)
# $(filter-out pattern...,text)
# $(sort list): Sorts the words of list in lexical order, removing duplicate words.
# $(word n,text): Returns the nth word of text. The legitimate values of n start from 1
# $(wordlist s,e,text)
# $(words text): Returns the number of words in text
# $(firstword names...) 
# $(lastword names...)

# Functions for File Names
# $(dir names...)
# $(notdir names...)
# $(suffix names...)
# $(basename names...)
# $(addsuffix suffix,names...)
# $(addprefix prefix,names...)
# $(join list1,list2)
# $(wildcard pattern)
# $(realpath names...)
# $(abspath names...)

# Functions for Conditionals
# $(if condition,then-part[,else-part])
# $(or condition1[,condition2[,condition3...]])
# $(and condition1[,condition2[,condition3...]])
# $(foreach var,list,text)
# example
temp2 := /temp/core/core.c
temp3 := a b c d e
con_test:
	@echo $(if $(tempaa) $(or $(temp2)),echo $(temp2),echo "not exist")
	@echo $(foreach name,$(temp3),echo $(name).c >> test.c)

# The file Function
# The file function allows the makefle to write to or read from a fle
# The operator op can be > to indicate the fle will be overwritten with new content, >> to
# indicate the current contents of the fle will be appended to, or < to indicate the contents of
# the fle will be read in
# $(file op filename[,text])

file_test = test
file_t:
	$(file >>$(file_test),"hello world")
	# @echo $(file <$(file_test))

# The value Function
# $(value variable)
temp5 = $PATH
value_test:
	@echo $(temp5)
	@echo $(value temp5)

# The eval Function
# The eval function is very special: it allows you to defne new makefle constructs that
# are not constant; which are the result of evaluating other variables and functions.
# It’s important to realize that the eval argument is expanded twice; frst by the eval
# function, then the results of that expansion are expanded again when they are parsed
# as makefle syntax. 
# examlpes
PROGRAMS = server client
server_OBJS := 1.o 2.o 3.o
server_LIBS = 1 2
client_OBJS = 4.o 5.o
client_LIBS = 4
# Everything after this is generic
.PHONY: eval_test
eval_test: $(PROGRAMS)

define PROGRAM_template =
$(1): $$($(1)_OBJS) $$($(1)_LIBS:%=-l%)
ALL_OBJS += $$($(1)_OBJS)
endef

$(foreach prog,$(PROGRAMS),$(eval $(call PROGRAM_template,$(prog))))
$(PROGRAMS):
	$(LINK.o) $^ $(LDLIBS) -o $@

# The origin Function
# Specifcally, it tells you where it came from.
# $(origin variable)
ori_test:
	@echo $(origin PATH)
	@echo $(origin PROGRAMS)
	@echo $(origin CC)
	@echo $(origin ABCDEF)

# The flavor Function
# Specifcally, it tells you the ﬂavor of a variable
# $(flavor variable)
flav_test:
	@echo $(flavor server_OBJS)
	@echo $(flavor server_LIBS)
	@echo $(flavor ABCDEF)

# Functions That Control Make
# $(error text...)
# $(warning text...)
# $(info text...)

# Instead of Executing Recipes
# ‘-n’
# ‘--just-print’
# ‘--dry-run’
# ‘--recon'
# Causes make to print the recipes that are needed to make the targets
# up to date, but not actually execute them
# With the ‘-t’ ﬂag, make ignores the recipes in the rules and uses (in eﬀect) the command
# touch for each target that needs to be remade
# With the ‘-q’ ﬂag, make prints nothing and executes no recipes,
# The ‘-n’, ‘-t’, and ‘-q’ options do not aﬀect recipe lines that begin with ‘+’ characters
# or contain the strings ‘$(MAKE)’ or ‘${MAKE}’.
# use the ‘-k’ or ‘--keep-going’ ﬂag. This tells make
# to continue to consider the other prerequisites of the pending targets, remaking them if
# necessary, before it gives up and returns nonzero status.
override com1 += hello
over_test:
	@echo $(com1)

# Using Implicit Rules
# The ‘-r’ or ‘--no-builtin-rules’ option cancels all predefned rules.
# give OUTPUT_OPTION the value ‘; mv $*.o $@’

# Variables Used by Implicit Rules
# You can cancel all variables used by implicit rules with the ‘-R’ or ‘--no-builtin-variables’
# option.

# Automatic Variables
# $@ The fle name of the target of the rule
# $% The target member name, when the target is an archive member
# $< The name of the frst prerequisite.
# $? The names of all the prerequisites that are newer than the target
# $^ The names of all the prerequisites
# $+ This is like ‘$^’, but prerequisites listed more than once 
# $| The names of all the order-only prerequisites,
# $* In a static pattern rule, the stem is part of the fle name that matched the ‘%’
# in the target pattern.
# In an explicit rule, there is no stem.You should generally avoid using ‘$*’ except in
# implicit rules or static pattern rules.
# $(@D)’ The directory part of the fle name of the target
# $(@F)’ The fle-within-directory part of the fle name of the target
# $(<D)’
# ‘$(<F)’ The directory part and the fle-within-directory part of the frst prerequisite.
# ‘$(^D)’
# ‘$(^F)’ Lists of the directory parts and the fle-within-directory parts of all prerequisites.
# $(?D)’
# ‘$(?F)’ Lists of the directory parts and the fle-within-directory parts of all prerequisites
# that are newer than the target.
temp6 = temp/6.c
temp7 = temp/7.c
temp8 = temp/8.c
$(temp8): $(temp6) $(temp7)
	@echo $@
	@echo $<
	@echo $*
	@echo $?
	@echo $|
	@echo $+
	@echo $^
	@echo $(@D)
	@echo $(@F)
	@echo $(<D)
	@echo $(<F)
	@echo $(^D)
	@echo $(^F)
	@echo $(?D)
	@echo $(?F)

# Canceling Implicit Rules
# You can defne a last-resort implicit rule by writing a terminal match-anything pattern rule
# with no prerequisites
# SHELL = /bin/sh
# .SUFFIXES:
# .SUFFIXES: .c .o
