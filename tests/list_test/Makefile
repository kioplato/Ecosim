#!/usr/bin/make -f

SHELL = /bin/sh

CC = g++
CFLAGS = -Wall -Wextra -g -O2
LDFLAGS = -g

SRCS = main.cpp
AUXS = list.hpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: test

test: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.cpp $(AUXS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o test
