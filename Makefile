# Nome do arquivo de origem C
SRC=fractal_mandel.c
# Nome do arquivo de saída da biblioteca compartilhada
LIB=fractal_mandel.so
# Nome do arquivo Python
PYTHON_SCRIPT=fractal_mandel.py

# Compilador e flags
CC=gcc
CFLAGS=-shared -fPIC

# Alvo padrão
all: $(LIB)

# Compilação da biblioteca compartilhada
$(LIB): $(SRC)
	$(CC) $(CFLAGS) -o $(LIB) $(SRC)

# Executa o script Python (caso de estudo)
run: $(LIB)
	python $(PYTHON_SCRIPT)

# Limpeza dos arquivos gerados
clean:
	rm -f $(LIB)

.PHONY: all clean run