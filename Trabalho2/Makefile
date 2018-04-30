FILEG=gera_saidas.cpp
FILEH=dist_hash.cpp
FILE=main.cpp
OUTG=gera_saidas
OUTH=dist_hash
OUT=main
FLAGS=-std=c++17 -O2

all: clean build

clean:
	-rm $(OUTG)
	-rm $(OUTH)
	-rm $(OUT)

build: $(FILE) $(FILEG)
	g++ -o $(OUTG) $(FILEG) $(FLAGS)
	g++ -o $(OUTH) $(FILEH) $(FLAGS)
	g++ -o $(OUT) $(FILE) $(FLAGS)

run: $(OUT) $(OUTG)
	./$(OUTG)
	./check_saidas.sh
	./gera_grafico_dist_hash.sh
	./$(OUT)
	./benchmark.sh

.PHONY: all clean build run
