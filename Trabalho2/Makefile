FILES=main.cpp
OUT=main
FLAGS=-std=c++14 -g

all: clean build

clean:
	-rm $(OUT)

build: $(FILES)
	g++ -o $(OUT) $(FILES) $(FLAGS)

.PHONY: all clean build
