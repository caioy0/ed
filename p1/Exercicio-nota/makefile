EXEC = estacionamento
# Arquivos fonte
SRC = main.c pilha.c

# Flags
CFLAGS = -Wall -Wextra -g

# Regra padrão??
all: $(EXEC)

# Como compilar o programa ?????
$(EXEC): $(SRC)
	gcc $(CFLAGS) -o $(EXEC) $(SRC)

# Limpa os arquivos gerados ok
clean:
	rm -f $(EXEC)