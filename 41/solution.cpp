#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
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

int isPandigital( unsigned long a ){
    char b[ 9 ];
    int len;
    int found;
    sprintf( b, "%lu", a );
//    cout << "number: " << b << endl;
    len = strlen( b );
    for( int i = 1; i <= len; ++i ){
//        cout << "    checking " << i << endl;
        found = 0;
        for( int j = 0; j < len; ++j ){
//            cout << "        checking num in position " << j << "... -> " << b[ j ] << endl;
            if( b[ j ] == i + 48 ){
                found = 1;
//                cout << "        found " << i << " in position " << j << endl;
                break;
            }
        }
        if( found == 0 ){
            return 0;
        }
    }
    return len;
}


int main(){
    int i, num, temp;
    for( i = 2; i < 10000000; ++i ){
        if( isPrime( i ) ){
            primes.push_back( i );
        }
    }
    cout << primes.size() << endl << endl;
    for( i = 0; i < primes.size(); ++i ){
        temp = isPandigital( primes[ i ] );
        cout << primes[ i ] << " -> " << temp << endl;
        if( !temp ){
            continue;
        }
        num = primes[ i ];
    }
    cout << num << endl;
}
