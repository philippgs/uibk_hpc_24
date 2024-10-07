CC=gcc
CFLAGS=-O2 -std=gnu11 -Wall -Wextra -pedantic

.PHONY: all
all: heat_stencil_1D_seq

heat_stencil_1D_seq: heat_stencil_1D_seq.c
	@$(CC) $(CFLAGS) $< -o heat_stencil_1D_seq

.PHONY: clean
clean:
	@rm heat_stencil_1D_seq

.PHONY: run
run: all
	@echo "Sequential:"
	@./heat_stencil_1D_seq
	@echo
