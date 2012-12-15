#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <sstream>
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

string IntToStr( int n ){
    ostringstream r;
    r << n;
    return r.str();
}

int StrToInt( const string& s ){
    int r;
    istringstream ss( s );
    ss >> r;
    return r;
}

int main(){
    string num;
    vector<int> pr;
    for( unsigned long i = 2; i < 10000; ++i ){
        if( isPrime( i ) ){
            primes.push_back( i );
        }
    }
    
    
    for( int i = 0; i < primes.size(); ++i ){
        if( floor( log10( primes[ i ] ) ) + 1 != 4 ){
            continue;
        }
        pr.clear();

        num = string( IntToStr( primes[ i ] ) );
        
        
        do{
            if( isPrime( StrToInt( num ) ) ){
                pr.push_back( atol( num.c_str() ) );
            }
        } while( next_permutation( num.begin(), num.end() ) );

        
        if( pr.size() < 3 ){
            continue;
        }
        for( int j = 0; j < pr.size(); ++j ){
//            cout << pr[ j ] << ", ";
        }
//        cout << endl;


        for( int j = 0; j < pr.size(); ++j ){
            for( int k = j + 1; k < pr.size(); ++k ){
                int diff1 = pr[ k ] - pr[ j ];
//                printf( "    %d, %d -> %d\n", k, j, diff1 );
                for( int l = k + 1; l < pr.size(); ++l ){
//                    printf( "        %d, %d -> %d\n", l, k, pr[ l ] - pr[ k ] );
                    if( pr[ l ] - pr[ k ] == diff1 ){
                        printf( "%d%d%d\n", pr[ j ], pr[ k ], pr[ l ] );
                    }
                }
            }
        }
    }
}
