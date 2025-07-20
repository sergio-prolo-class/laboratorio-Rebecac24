CC=gcc			
CFLAGS=-Wall -g

# Nome do executável
TARGET=estoque

# Fontes do projeto
SRCS=estoque.c estoque_funcoes.c util.c

# Regra padrão
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)