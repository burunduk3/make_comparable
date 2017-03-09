.PHONY: all

all: example

example: example.c++ make_comparable.h++ Makefile
	g++ -O2 -Wall -Wextra -Werror -o $@ -x c++ -pedantic -fconcepts $<
