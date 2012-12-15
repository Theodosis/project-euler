from collections import Counter

number = 10
for i in range( 3000 ): number *= 10

maxx = 0
maxid = 0
for z in range( 7, 1000 ):
    testme = str( number // z )
    hist = Counter( testme )
    for j in range( 1000 ): # begin at
        gotit = False
        for i in range( 1, 1000 ): # length
            test = {}
            counter = 0
            for k in range( ( len( testme ) - j ) // i ): 
                test[ testme[ j + k * i : j + k * i + i ] ] = True
                counter += 1
            if len( test ) == 1 and counter > 1:
                #print( z, i, j, testme[ j : i + j ] )
                if maxx < i:
                    maxid = z
                    maxx = i
                gotit = True
                break
        if gotit:
            break

print( maxid, maxx )
