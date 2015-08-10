INCLUDES = -I includes

SRCLIST = $(wildcard src/*.cpp)

EXEC = cards

.PHONY: clean

all:
	g++ -std=c++11 $(INCLUDES) $(SRCLIST) -o $(EXEC)

clean:
	rm $(EXEC)
