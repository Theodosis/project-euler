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
    for( int i = 2; i < 1000000; ++i ){
        if( isPrime( i ) ){
            primes.push_back( i );
        }
    }

    int max = 0, sum, prime;
    for( int i = 0; i < primes.size(); ++i ){
        sum = 0;
        for( int j = i; j < primes.size(); ++j ){
            sum += primes[ j ];
            if( sum >= 1000000 ){
                break;
            }
            if( isPrime( sum ) && j - i > max ){
                max = j - i;
                prime = sum;
            }
        }
        
    }
    cout << prime << endl;
}
