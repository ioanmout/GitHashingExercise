SHELL := /bin/bash


# ============================================
# COMMANDS

CC = gcc -O3
RM = rm -f

# ==========================================
# TARGETS

EXECUTABLES = mysigcatch mysigcatchmodified


all: $(EXECUTABLES)


mysigcatch: mysigcatch.c
	$(CC) $< -o $@

mysigcatchmodified: mysigcatchmodified.c
	$(CC) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLES)
