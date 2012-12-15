import glob
import pprint
import numpy
from collections import Counter

def chunks( l, n ):
    return [ l [ i : i + n ] for i in range( 0, len( l ), n ) ]

def cins( full, query ):
    for i in query:
        if full.count( i ) == 0:
            return False
        else:
            full = full.replace( i, "X", 1 )
    return True

order = '23456789ABCDE';

def hand( l ):
    full = ''.join( l )
    full = full.replace( 'H', 'Z' )
    full = full.replace( 'C', 'Y' )
    full = full.replace( 'S', 'X' )
    full = full.replace( 'D', 'W' )
    full = full.replace( 'A', 'E' )
    full = full.replace( 'T', 'A' )
    full = full.replace( 'J', 'B' )
    full = full.replace( 'Q', 'C' )
    full = full.replace( 'K', 'D' )
    full = ''.join( sorted( full ) )
    numbers = full[ 0 : 5 ]
    revnum = sorted( numbers, reverse=True )
    histNum = Counter( numbers )
    letters = full[ 5 : 10 ];
    histLet = Counter( letters )
    if numbers == 'ABCDE' and max( histLet.values() ) == 5:
        return [ 10 ]
    if numbers == order[ order.index( numbers[ 0 ] ) : ] [ 0 : 5 ] and max( histLet.values() ) == 5:
        return [ 9, max( numbers ) ]
    if max( histNum.values() ) == 4:
        return [ 8, max( numbers ) ]
    if sorted( histNum.values(), reverse=True )[ 0 : 2 ] == [ 3, 2 ]:
        inv = { v:k for k, v in histNum.items() }
        return [ 7, inv[ 3 ], inv[ 2 ] ]
    if max( histLet.values() ) == 5:
        return [ 6 ] + revnum
    if numbers == order[ order.index( numbers[ 0 ] ) : ] [ 0 : 5 ]:
        return [ 5, numbers[ 4 ] ]
    if max( histNum.values() ) == 3:
        return [ 4 ] + revnum
    if sorted( histNum.values(), reverse=True )[ 0 : 2 ] == [ 2, 2 ]:
        return [ 3 ] + revnum
    if max( histNum.values() ) == 2:
        inv = { v:k for k, v in histNum.items() }
        return [ 2 ] + [ inv[ 2 ] ] + revnum
    return [ 1 ] + revnum
    

    
    

f = open( 'poker.txt' )
counter = 0
for line in f:
    cards = line.strip().split( ' ' )
    ( p1, p2 ) = chunks( cards, 5 )
    res1 = hand( p1 )
    res2 = hand( p2 )

    for key in range( len( res1 ) ):
        if res1[ key ] > res2[ key ]:
            counter += 1
            break
        if res1[ key ] < res2[ key ]:
            break

print( counter )
