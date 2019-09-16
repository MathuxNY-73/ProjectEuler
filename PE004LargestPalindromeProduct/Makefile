CXX=g++
MAKE=make -w
CXFLAGS=-Wc++17-extensions -Wall -stdlib=libc++ -std=c++17 -pedantic
LIB_PATH=../library/cpp
LDFLAGS=-L$(LIB_PATH) -lmine
LIBS=-I$(LIB_PATH)
EXEC=main
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

main: main.o
	cd $(LIB_PATH) && $(MAKE) libmine.a
	@$(CXX) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXFLAGS) $(LIBS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o
	@cd $(LIB_PATH) && $(MAKE) clean

mrproper:
	@rm -rf $(EXEC)
