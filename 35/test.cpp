#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static vector<int> primes;

int intlength( int num ){
    return ceil( log10( num ) ) + 1;
}

int isPrime( int a ){
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

int rotate( int a, int b ){
    string d;
    char c[ 20 ];
    sprintf( c, "%d", a );
    d.assign( c );
    rotate( d.begin(), d.begin() + b, d.end() );
    return atoi( d.c_str() );
}


int main(){
    int length = 0;
    int isCircular = 1;
    int count = 0;
    for( int i = 2; i < 1000000; ++i ){
        if( isPrime( i ) ){
            primes.push_back( i );
        }
    }
    
    for( int i = 0; i < primes.size(); ++i ){
        length = intlength( primes[ i ] );
        isCircular = 1;
        for( int j = 1; j < length; ++j ){
            if( !isPrime( rotate( primes[ i ], j ) ) ){
                isCircular = 0;
            }
        }
        if( isCircular ){
            cout << primes[ i ] << endl;
            ++count;
        }
    }
    cout << count << endl;
}
