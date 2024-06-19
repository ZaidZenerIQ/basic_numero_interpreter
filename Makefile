cc=gcc

extd: main.c calco.c vars.c
	$(cc) $^ -lm -o $@
