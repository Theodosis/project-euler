#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


static vector<unsigned long> primes;
int isPrime( unsigned long a ){
    int i;
    double limit = sqrt( a );
    for( i = 0; i < primes.size(); ++i ){
        if( primes[ i ] > limit ){
            break;
        }
        if( a % primes[ i ] == 0 && a != primes[ i ] ){
            return 0;
        }
    }
    return 1;
}


int main(){
    int i, consecutive = 4, consec, dinstinct = 4, dinst;
    for( i = 2; i < 1000000; ++i ){
        if( isPrime( i ) ){
            primes.push_back( i );
        }
    }
    i = 1;
    consec = 0;
    while( consec < consecutive ){
//        printf( "checking %d. Consecutives: %d\n", i, consec );
        dinst = 0;
        for( int j = 0; j < primes.size(); ++j ){
//            printf( "    checking prime %d\n", (int)primes[ j ] );
            if( primes[ j ] > i ){
                break;
            }
            if( i % primes[ j ] == 0 ){
                ++dinst;
//                printf( "        got it! dinstinct: %d\n", dinst );
            }
            if( dinst == dinstinct ){
                ++consec;
                break;
            }
        }
        if( dinst != dinstinct ){
            consec = 0;
        }
        ++i;
    }
    cout << i - consecutive << endl;
    
}
