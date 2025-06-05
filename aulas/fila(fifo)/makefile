CC = gcc
CFLAGS = -Wall -g
OBJETOS = teste_fila.o fila.o fila.h
PROG = programa.out

all: $(PROG)

$(PROG): $(OBJETOS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(PROG)
