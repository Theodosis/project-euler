summary = 0
for i in range( 1000000 ):
    idec = str( i )
    ibin = bin( i )[ 2 : ]
    if idec == idec[ : : -1 ] and ibin == ibin[ : : -1 ]:
        summary += i
print( summary )
