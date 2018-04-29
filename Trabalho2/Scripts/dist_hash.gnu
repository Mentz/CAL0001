set term png size 1280,600 enhanced
set title "Gráfico de distribuição pela função de hash"
set xrange [0:521]
set xlabel "Posição no vetor"
set xlabel  offset character 0, 0.5, 0 font ""
set ylabel "Ocupação (núm. elementos)"
set ylabel  offset character 1, 0, 0 font ""
set output 'Imagens/dist_hash.png'
plot 'Scripts/dist.dat' with boxes fillstyle solid fillcolor "#0000FF"
