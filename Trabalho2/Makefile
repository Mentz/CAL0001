FILES=main.cpp
OUT=main
FLAGS=-std=c++17 -g -O2

all: clean build

clean:
	-rm $(OUT)

build: $(FILES)
	g++ -o $(OUT) $(FILES) $(FLAGS)

.PHONY: all clean build
