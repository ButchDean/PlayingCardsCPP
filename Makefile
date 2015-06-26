INCLUDES = -I includes

SRCLIST = $(wildcard src/*.cpp)

EXEC = cards

all:
	g++ $(INCLUDES) $(SRCLIST) -std=c++11 -o $(EXEC)