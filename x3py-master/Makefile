# The simplest way to compile x3c on MinGW, Linux, Mac OS X or Unix is:
#
# 1. `cd' to the directory containing the file of 'Makefile'.
# 2. Type `make' to compile C++ plugins.
#    The program binaries files are outputed to './build/plugins'.
# 
# 3. Type `make all python' to compile C++ plugins and swig projects.
#    The swig projects binaries files are outputed to './build/python'.
# 
# 4. You can remove the program object files from the source code
#    directory by typing `make clean'.
#    Type `make touch' can change the modification time of files to the current time.
#
# Readme about variables: https://github.com/rhcad/x3py/wiki/MakeVars
#

ROOTDIR =.
include $(ROOTDIR)/config.mk

SWIGS  =python perl5 java csharp ruby php lua r
CLEANSWIGS =$(addsuffix .clean, $(SWIGS))

.PHONY:	source clean cleanall touch py $(SWIGS)

#==============================================================================
# The default build target.
#==============================================================================
all:	source
source:
	@test -d $(INSTALL_DIR) || mkdir $(INSTALL_DIR)
	@test -d $(PLUGINS_DIR) || mkdir $(PLUGINS_DIR)
	@$(MAKE) -C source

py:     python
$(SWIGS):
	@test -d $(INSTALL_DIR) || mkdir $(INSTALL_DIR)
	@export SWIG_TYPE=$@; $(MAKE) -C source swig

#==============================================================================
# Clean up the targets built by 'make all'.
# Type `make touch' can change the modification time of files to the current time.
#==============================================================================
clean:
	@export clean=1; $(MAKE) -C source clean
cleanall:
	@export cleanall=1; $(MAKE) clean
touch:
	touch -c *
	@export touch=1; $(MAKE) clean

#==============================================================================
# Type `make python.clean' to clean up the targets built by 'make python'.
#==============================================================================
$(CLEANSWIGS):
	@export SWIG_TYPE=$(basename $@); export cleanall=1; $(MAKE) clean
