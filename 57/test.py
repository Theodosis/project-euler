from fractions import Fraction
import parser
import math

ns = vars( math ).copy()
ns[ '__builtins__' ] = None

s = '1 + 1/2'
limit = 2.5
counter = 0
for i in range( 1000 ):
    s = s.replace( '1/2', '1/(2+1/2)', 1 )
    limit *= 2.5
    a = parser.expr( s ).compile()
    test = Fraction( eval( a ) ).limit_denominator( int( limit ) )
    if len( str( test.numerator ) ) > len( str( test.denominator ) ):
        counter += 1
        print( s, test )

print( counter )
