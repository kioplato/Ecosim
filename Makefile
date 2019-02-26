#!/usr/bin/make -f

SHELL = /bin/sh

objdir = obj
bindir = bin

VPATH = src:src/ecosystem:src/ecosystem/terrain:src/ecosystem/terrain/tile

CC = g++
CFLAGS = -Wall -Wextra -g -O2
LDFLAGS = -g

SRCS = main.cpp ecosystem.cpp terrain.cpp tile.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: ecosim

ecosim: $(OBJS)
	$(CC) $(LDFLAGS) -o $(bindir)/$@ $(addprefix $(objdir)/, $(OBJS))

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $(objdir)/$@

#$(OBJS): $(SRCS)
#	$(CC) $(CFLAGS) $(subst $(objdir)/,,$(@:.o=.cpp)) -o $@

.PHONY: clean
clean:
	rm -f $(objdir)/* $(bindir)/*
