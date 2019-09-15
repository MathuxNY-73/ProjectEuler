CXX=g++
CXFLAGS=-Wc++17-extensions -Wall -stdlib=libc++ -std=c++17 -pedantic
LDFLAGS=-Wl,-soname,libmine.so.1
OSXLDFLAGS=-Wl,-install_name,libmine.so.1
EXEC=libmine.a
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

libmine.a: libmine.o
	ar rsc $@ $<

libmine.so.1: libmine-pic.o
	@$(CXX) -shared $< -o $@ $(OSXLDFLAGS)

%-pic.o: $(SRC)
	$(CXX) -fPIC -o $@ -c $< $(CXFLAGS)

%.o : $(SRC)
	$(CXX) -o $@ -c $< $(CXFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o *.a *.so.*

mrproper:
	@rm -rf $(EXEC)
