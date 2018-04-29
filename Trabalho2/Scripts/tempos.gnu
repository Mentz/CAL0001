set term png size 1280,600 enhanced
set output 'Imagens/tempos.png'
#set border 3 front lt black linewidth 1.000 dashtype solid
set boxwidth 0.8 absolute
set style fill   solid 1.00 noborder
set grid nopolar
set grid noxtics nomxtics ytics nomytics noztics nomztics nortics nomrtics \
 nox2tics nomx2tics noy2tics nomy2tics nocbtics nomcbtics
set grid layerdefault   lt 0 linecolor 0 linewidth 0.500,  lt 0 linecolor 0 linewidth 0.500
set key bmargin center horizontal Left reverse noenhanced autotitle columnhead nobox
set style histogram rowstacked title textcolor lt -1 offset character 0.5, 0.25
set datafile missing '-'
set style data histograms
set xtics border in scale 0,0 nomirror autojustify
set xtics  norangelimit  font ""
set xtics   ()
set ytics border in scale 0,0 mirror norotate  autojustify
set ytics  norangelimit autofreq  font ""
#set ztics border in scale 0,0 nomirror norotate  autojustify
#set cbtics border in scale 0,0 mirror norotate  autojustify
#set rtics axis in scale 0,0 nomirror norotate  autojustify
set title "Tempos de inserção e busca das estruturas de dados"
set xlabel "Caso de teste por estrutura de dados" 
set xlabel  offset character 0, -0.5, 0 font "" textcolor lt -1 norotate
set ylabel "Tempo (segundos)"
set ylabel  offset character 2, 0, 0 font ""
set yrange [*:*] noreverse nowriteback
#DEBUG_TERM_HTIC = 119
#DEBUG_TERM_VTIC = 119
plot newhistogram "Vetor", 'Tempos/average.dat' using "vet-ins":xtic(1) t col, '' u "vet-fnd" t col, newhistogram "AVL", '' u "avl-ins":xtic(1) t col, '' u "avl-fnd" t col, newhistogram "HashSet", '' u "hst-ins":xtic(1) t col, '' u "hst-fnd" t col, newhistogram "HashTree", '' u "htr-ins":xtic(1) t col, '' u "htr-fnd" t col
