#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

static vector<int> primes;


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
    primes.push_back( a );
    return 1;
}


int main(){
    int i;
    double sum = 0;
    for( i = 2; i < 2000000; ++i ){
        if( isPrime( i ) ){
            sum += i;
        }
    }
    
    printf( "%f\n", sum );
}
