#!/usr/bin/make -f

SHELL = /bin/sh

objdir = obj
bindir = bin
srcdir = src

#VPATH = src:src/ecosystem:src/ecosystem/terrain:src/ecosystem/terrain/tile:src/ecosystem/plant:src/ecosystem/plant/seeded:src/ecosystem/plant/seedless:src/ecosystem/plant/seeded/oak:

CC = g++
CFLAGS = -Wall -Wextra -g -O2
LDFLAGS = -g

#SRCS = main.cpp ecosystem.cpp terrain.cpp tile.cpp
SRCS = $(shell find $(srcdir) -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: ecosim

ecosim: $(OBJS)
	$(CC) $(LDFLAGS) -o $(bindir)/$@ $(addprefix $(objdir)/, $(notdir $(OBJS)))

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $(objdir)/$(notdir $@)

.PHONY: clean
clean:
	rm -f $(objdir)/* $(bindir)/*
