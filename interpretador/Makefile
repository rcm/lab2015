CFLAGS=-ansi -Wall -Wextra -pedantic -g
OBJS=interp.o comandos.o erros.o
MAIN=main

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

clean:
	rm -rf $(MAIN) $(OBJS) html latex
