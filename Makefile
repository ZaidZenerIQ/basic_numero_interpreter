cc=gcc

ext: main.c calco.c vars.c
	$(cc) $^ -lm -o $@
