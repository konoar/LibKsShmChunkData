############################################
#
# LibKsShmChunkData
#   copyright 2021.04.04 konoar
#
############################################

SHELL   := /bin/bash
BINDIR  := ./bin/
LIBDIR	:= ./lib/
INCDIR	:= ./include/
SRCDIR	:= ./src/
TSTDIR	:= ./test/
OBJDIR	:= ./obj/
CFLAGS	:= -I$(INCDIR) -I/usr/local/include -O0 
CPPFLAGS:= -I$(INCDIR) -I/usr/local/include -O0 
LDFLAGS	:= -L$(LIBDIR) -lksshmchunkdata
LDFLAGS += -L/usr/local/lib -lstdc++ -lpthread -lgtest -lgtest_main
TGTLIB	:= $(LIBDIR)libksshmchunkdata.a
TGTTST	:= $(BINDIR)TestShmChunkData

.PHONY: all dirs clean run

all: dirs clean run

dirs:
	@mkdir -p $(LIBDIR) $(BINDIR) $(OBJDIR)

clean:
	@rm -f $(TGTLIB)
	@rm -f $(TGTTST)
	@rm -f $(OBJDIR)*.o

run: $(TGTLIB) $(TGTTST)
	@$(TGTTST)

$(TGTLIB): $(patsubst %.c,  $(OBJDIR)%.o, $(notdir $(shell ls $(SRCDIR)*.c)))
	@ar rcs $@ $^

$(TGTTST): $(patsubst %.cc, $(OBJDIR)%.o, $(notdir $(shell ls $(TSTDIR)*.cc)))
	@gcc -o $@ $^ $(LDFLAGS)

$(OBJDIR)%.o:: $(SRCDIR)%.c
	@gcc -o $@ -c $< $(CFLAGS)

$(OBJDIR)%.o:: $(TSTDIR)%.cc
	@g++ -o $@ -c $< $(CFLAGS)

