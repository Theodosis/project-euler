import math

count = 0
for i in range( 101 ):
    faci = math.factorial( i )
    for j in range( i ):
        facj = math.factorial( j )
        facij = math.factorial( i - j )
        if faci / facj / facij > 1000000:
            #print i, faci, facij, facj, faci / facj / facij
            count += 1

print count

