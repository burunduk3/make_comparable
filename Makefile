.PHONY: all

all: example

example: example.c++ make_comparable.h++
	g++ -O2 -Wall -Wextra -Werror -o $@ -x c++ -std=c++17 -fconcepts $<
