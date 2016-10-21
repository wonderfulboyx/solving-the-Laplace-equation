#グラフ設定
set contour base
set view 0,0
set nosurface
set cntrparam levels incremental 0,0.1,1
unset key
splot "output/output.dat" every 10:10 with lines

#出力
set terminal png
set output 'output/contour_output.png'
replot

#reset
reset
set terminal wxt
