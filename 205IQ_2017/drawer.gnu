set terminal pngcairo
set title "IQ calculator with Gaussian Distribution"
set style data lines
set key fixed left top vertical Left reverse enhanced autotitle nobox
set key noinvert samplen 1 spacing 1 width 0 height 0
set ylabel "Density"
set xlabel "IQ"
set output 'image.png'
plot 'data' title "data"
