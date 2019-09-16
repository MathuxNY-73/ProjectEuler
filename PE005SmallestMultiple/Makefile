CC=gcc
MAKE=make -w
CFLAGS=-W -Wall -pedantic -std=c11
EXEC=main
LIB_PATH=../library/c
LDFLAGS=-L$(LIB_PATH) -lmine
LIBS=-I$(LIB_PATH)
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

main: main.o
	cd $(LIB_PATH) && $(MAKE) libmine.a
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LIBS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o
	@cd $(LIB_PATH) && $(MAKE) clean

mrproper: clean
	@rm -rf $(EXEC)
