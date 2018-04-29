set term png size 1000,600 enhanced
set xrange [0:521]
set ylabel "Ocupação (núm. elementos)"
set xlabel "Posição no vetor"
set output 'Imagens/dist_hash.png'
plot 'Scripts/dist.dat' with boxes fillstyle solid fillcolor "#0000FF"
