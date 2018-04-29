set term png size 1280,600 enhanced
set title "Gráfico de distribuição pela função de hash"
set xrange [0:521]
set ylabel "Ocupação (núm. elementos)"
set xlabel "Posição no vetor"
set output 'Imagens/dist_hash.png'
plot 'Scripts/dist.dat' with boxes fillstyle solid fillcolor "#0000FF"
