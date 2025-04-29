CC = gcc
CFLAGS = -Wall -g
OBJETOS = main.o oo.o pessoa.o cachorro.o gato.o
PROG = programa

all: $(PROG)

$(PROG): $(OBJETOS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(PROG)
