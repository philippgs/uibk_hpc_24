set terminal gif animate delay 50 # set gif to animate in a frame delay of 50 ms
set output 'output.gif' # write to the file output.gif

set style line 2 lc rgb 'black' pt 7 # set line to be a filled circle of color black
stats 'data.dat' nooutput # read data from data.dat file 
set xrange [-0.5:100.5] # print data values for x axis from range [-0.5:100.5]
set yrange [-0.5:100.5] # print data values for y axis from range [-0.5:100.5]
set zrange [-0.5:100.5] # print data values for z axis from range [-0.5:100.5]

do for [i=1:int(STATS_blocks)] {
   splot 'data.dat' index (i-1) with points ls 2 ps 0.4 # for each datapoint plot the point
}