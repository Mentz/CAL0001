FILEG=gera_saidas.cpp
FILE=main.cpp
OUTG=gera_saidas
OUT=main
FLAGS=-std=c++17 -g -O2

all: clean build

clean:
	-rm $(OUTG)
	-rm $(OUT)
	-find Tempos/ -type f -delete

build: $(FILES)
	g++ -o $(OUTG) $(FILEG) $(FLAGS)
	g++ -o $(OUT) $(FILE) $(FLAGS)

run: $(OUT) $(OUTG)
	./$(OUTG)
	./$(OUT)
	./check_saidas.sh
	./avg_results.py

.PHONY: all clean build run
