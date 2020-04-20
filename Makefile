# ------------------------------------------------
# Generic Makefile
#
# Author: aswanthramamoorthy@cmail.carleton.ca
# Date  : 2020-04-10
#
# Changelog :
# 2020-04-10: Inital Draft
# 2020-04-15: Makefile final draft
#
# ------------------------------------------------

# project name (generate executable with this name)
TARGET   = EPoll

# change these to proper directories where each file should be
SRCDIR     	 = src
#SRCTESTDIR	 = test
OBJDIR    	 = obj
BINDIR    	 = bin
INCDIR	  	 = include
#INCTESTDIR	 = test/include

CC       = gcc
# compiling flags here
CFLAGS   = -Wall

INC      := -I$(INCDIR) #-I$(INCTESTDIR)
SOURCES  := $(wildcard $(SRCDIR)/*.c)
OBJECTS1 := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS1) 
	@mkdir -p $(BINDIR)
	@$(CC) $(OBJECTS1)  -o $@
	@echo "Linking complete!"

$(OBJECTS1): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS1)  $(BINDIR)/$(TARGET)
	@echo "Cleanup complete!"
