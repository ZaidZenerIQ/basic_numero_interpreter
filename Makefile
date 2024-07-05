cc=gcc

ext: main.c calco.c vars.c func.c
	$(cc) $^ -lm -o $@
