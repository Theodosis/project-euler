import math
maximum = 0
for i in range( 100 ):
    for j in range( 100 ):
        number = i;
        for k in range( j ): number *= i

        summary = sum( int( i ) for i in str( number ).split( '.' )[ 0 ] )
        if( summary > maximum ):
            maximum = summary

print( maximum )
