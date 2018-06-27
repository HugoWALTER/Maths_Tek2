set terminal pngcairo
set title "Demography"
set key fixed left top vertical Left reverse enhanced autotitle nobox
set key noinvert samplen 1 spacing 1 width 0 height 0
set ylabel "Population in Million"
set xlabel "Year"
set output 'image.png'
f(x) = a*x + b
fit f(x) 'data' u 1:2 via a, b
title_f(a,b) = sprintf('f(x) = %.2fx + %.2f', a, b)
plot 'data' title "data" , f(x) t title_f(a,b)
