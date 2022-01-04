set terminal gif animate delay 5
set output 'DistribucionNormal.gif'

set grid
set title "Distribución Normal."
set xlabel "Eje X"
set ylabel "Eje Y"
set xrange[-4:4]
set yrange[0:0.6]

do for [i=1:200] {
    plot "grafica_gif.dat" index i using 2:4 with boxes lw 3 title "f(x)", "grafica_gif.dat" index i using 2:3 with boxes lw 3 title "f(x)"
}

do for[i=1:50]{
plot "grafica_gif.dat" using 2:4 with lines lw 3 lt 1 notitle, "grafica_gif.dat" using 2:3 with boxes lw 3 lt 2 notitle 
}

