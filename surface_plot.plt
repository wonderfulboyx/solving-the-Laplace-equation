#グラフ設定
splot "output/output.dat" every 20:20 with lines

#出力
set terminal png
set output 'output/surface_output.png'
replot

#reset
reset
set terminal wxt
