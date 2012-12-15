#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>
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

int isSeperable( int num ){
    int i = -1;
    int temp, e;
    while( primes[ ++i ] < num );
    --i;

//    printf( "Number: %d\n", num );
    while( i >= 0 ){
        temp = primes[ i ];
//        printf( "    checking prime: %d\n", temp );
        e = 1;
        while( temp + 2 * e * e < num ){
//            printf( "        checking %d: %d < %d\n", e, temp + 2 * e * e, num );
            ++e;
        }
//        printf( "        stopped on %d, with %d\n", e, temp + 2 * e * e );
        if( temp + 2 * e * e == num ){
//            cout << "accepted!\n";
            return 1;
        }
        --i;
    }
    return 0;

}

int main(){
    int i;
    for( i = 2; i < 1000000; ++i ){
        if( isPrime( i ) ){
            primes.push_back( i );
        }
    }
    i = 3;
    while( isPrime( i ) || isSeperable( i ) ){
        i += 2;
//        cout << i << " ";
    }

    cout << i << endl;
}
