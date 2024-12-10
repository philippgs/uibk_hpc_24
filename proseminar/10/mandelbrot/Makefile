CC=gcc
CFLAGS=-std=gnu11 -Wall -Wextra -lm -O3 -ffast-math -march=native -g3

.PHONY: all
all: mandelbrot_seq

.PHONY: clean
clean:
	$(RM) mandelbrot_seq mandelbrot_seq.png

mandelbrot_seq: mandelbrot_seq.c
