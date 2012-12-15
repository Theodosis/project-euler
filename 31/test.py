def init( dic, l ):
    for i in l:
        dic[ i ] = 0
    return dic

count = 0
total = {}
for p100 in range( 3 ):
    total[ 100 ] = p100
    print( total )
    for p50 in range( 5 - p100 * 2 ):
        total[ 50 ] = p50
        print( total )
        for p20 in range( 11 - p100 * 5 - p50 * 2 ):
            total[ 20 ] = p20
            for p10 in range( 21 - p100 * 10 - p50 * 5 - p20 * 2 ):
                total = init( total, ( 1, 2, 5 ) )
                total[ 10 ] = p10
                for p5 in range( 41 - p100 * 20 - p50 * 10 - p20 * 4 - p10 * 2 ):
                    total = init( total, ( 1, 2 ) )
                    total[ 5 ] = p5
                    for p2 in range( 101 - p100 * 50 - p50 * 25 - p20 * 10 - p10 * 5 - p5 * 2 ):
                        total[ 1 ] = 0
                        total[ 2 ] = p2
                        for p1 in range( 201 - p100 * 100 - p50 * 50 - p20 * 20 - p10 * 10 - p5 * 5 - p2 * 2 ):
                            total[ 1 ] = p1
                            temp = sum( key * total[ key ] for key in total.keys() )
                            if temp == 200:
                                count += 1
print( count + 1 )
