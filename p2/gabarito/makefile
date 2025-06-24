# Nome do executável
EXEC = a

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Lista de arquivos objeto
OBJS = main.o fila.o pilha.o no.o abb.o

# Regra principal
all: $(EXEC)

# Como compilar o executável
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Como compilar os .o a partir dos .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -f *.o $(EXEC)