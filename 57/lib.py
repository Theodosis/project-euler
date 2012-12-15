from fractions import Fraction


s = '1 + 1/2'
limit = 3
counter = 0
t = {}
f1 = Fraction( 1 )
f2 = Fraction( 2 )
t[ 1 ] = Fraction( '2/5' )
for i in range( 1, 1000 ):
    if len( str( t[ i ].numerator + t[ i ].denominator ) ) > len( str( t[ i ].denominator ) ):
        counter += 1
    t[ i + 1 ] = f1/( f2 + t[ i ] )
    
print( counter )
