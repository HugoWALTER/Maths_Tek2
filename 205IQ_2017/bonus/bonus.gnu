set terminal pngcairo
set title "IQ calculator with Gaussian Distribution"
set style data lines
set style fill  transparent solid 0.50 noborder
set key fixed left top vertical Left reverse enhanced autotitle nobox
set key noinvert samplen 1 spacing 1 width 0 height 0
set style function filledcurves y1=0
set ylabel "Population (%)"
set xlabel "IQ"
set yrange[0 : 100]
set output 'image.png'
plot 'data' smooth cumulative lc rgb "forest-green" title "Repartition"
