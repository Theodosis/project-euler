#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

static vector<unsigned long> primes;
int isPrime( unsigned long a ){
    double limit = sqrt( a );
    for( int i = 0; i < primes.size(); ++i ){
        if( primes[ i ] > limit ){
            break;
        }
        if( a % primes[ i ] == 0 && a != primes[ i ] ){
            return 0;
        }
    }
    return 1;
}

int isPandigital( string lema, string digits = "123456789" ){
    int found;
    for( int i = 0; i < digits.length(); ++i ){
        found = 0;
        for( int j = 0; j < lema.length(); ++j ){
            if( digits[ i ] == lema[ j ] ){
                found = 1;
                break;
            }
        }
        if( found == 0 ){
            return 0;
        }
    }
    return 1;
}

int main(){
    string pandigital;
    int num, is;
    unsigned long sum = 0;
    
    for( int i = 2; i < 18; ++i ){
        if( isPrime( i ) ){
            primes.push_back( i );
        }
    }
    
    pandigital = string( "0123456789" );
    do{
//        cout << pandigital << "->" << atol( pandigital.c_str() ) << endl;
        is = 1;
        for( int j = 1; j < 8; ++j ){
            num = atoi( pandigital.substr( j, 3 ).c_str() );
//            cout << "    " << num << " by " << primes[ j - 1 ];
            if( num % primes[ j - 1 ] != 0 ){
                is = 0;
//                cout << " nope" << endl;
                break;
            }
//            cout << " yep" << endl;
        }
        if( !is ){
            continue;
        }
        cout << pandigital << "->" << atol( pandigital.c_str() ) << endl;
        sum += atol( pandigital.c_str() );
    } while( next_permutation( pandigital.begin(), pandigital.end() ) );
    cout << sum;
    return 0;
}
