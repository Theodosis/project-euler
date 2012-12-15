def isLychrel( number ):
    for i in range( 50 ):
        number = int( str( number )[::-1] ) + number
        if number == int( str( number )[::-1] ):
            return False
    return True
count = 0
for i in range(10000):
    if isLychrel( i ):
        count += 1
print( count )
