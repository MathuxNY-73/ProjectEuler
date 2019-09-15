CC=gcc
CFLAGS=-W -Wall -pedantic -std=c11
LDFLAGS=-Wl,-soname,libmine.so.1
OSXLDFLAGS=-Wl,-install_name,libmine.so.1
EXEC=libmine.a
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

libmine.a: libmine.o
	ar rsc $@ $<

libmine.so.1: libmine-pic.o
	@$(CC) -shared $< -o $@ $(OSXLDFLAGS)

%-pic.o: $(SRC)
	$(CC) -fPIC -o $@ -c $< $(CFLAGS)

%.o : $(SRC)
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o *.a *.so.*

mrproper: clean
	@rm -rf $(EXEC)
