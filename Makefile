INCDIR := inc
SOURCEDIR := src
BUILDDIR := build

MODULES := list contact cli utils

CC=gcc
CFLAGS=-Wall -I$(INCDIR)
EXENAME=list

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

run:
	./list

clean:
	rm -rf $(BUILDDIR)