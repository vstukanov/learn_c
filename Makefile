SOURCEDIR := src
BUILDDIR := build

CC=gcc
CFLAGS=-Wall -I$(SOURCEDIR)
EXENAME=list

MODULES := list \
					 contact \
					 cli

MODOBJS := $(addprefix $(BUILDDIR)/,$(MODULES:=.o))

all: $(MODOBJS)
	$(CC) $(CFLAGS) $(SOURCEDIR)/main.c $(MODOBJS) -o $(EXENAME)

# General rule how to compile object
$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

# Compile only MODULES files, but first create build directory
$(MODOBJS): | $(BUILDDIR)

$(BUILDDIR):
	mkdir $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)