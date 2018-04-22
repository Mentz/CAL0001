FILES=main.cpp
OUT=run_test
FLAGS=-std=c++14

all: clean build

clean:
	-rm $(OUT)

build: $(FILES)
	g++ -o $(OUT) $(FILES) $(FLAGS)

.PHONY: all clean build
