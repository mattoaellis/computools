import sys
import numpy as np

filename = sys.argv[1]

xcol = 0
ycol = 1

if( len(sys.argv) > 2 ):
    xcol = int(sys.argv[2]) - 1
    ycol = int(sys.argv[3]) - 1

print xcol, type(xcol)
print ycol, type(ycol)

xdata = np.array([])
ydata = np.array([])

infile = open(filename, 'r')

for line in infile:
    if ( line[0] != '#' ):
        words = line.split();
        if ( len(words) > 2):
            xdata = np.append( xdata, float(words[xcol]))
            ydata = np.append( ydata, float(words[ycol]))


Ndata = len(xdata)

for i in range(1,Ndata):
    print i, xdata[i], ydata[i], np.trapz( ydata[:i], x = xdata[:i] )

