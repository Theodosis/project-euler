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

int isPandigital( unsigned long a, int from = 1, int to = -1 ){
    char b[ 9 ];
    int len;
    int found;
    sprintf( b, "%lu", a );
    len = strlen( b );
    if( to == -1 ){
        to = len;
    }
    for( int i = from; i <= to; ++i ){
        found = 0;
        for( int j = 0; j < len; ++j ){
            if( b[ j ] == i + 48 ){
                found = 1;
                break;
            }
        }
        if( found == 0 ){
            return 0;
        }
    }
    return len;
}


int isPandigital( string lema, string digits = "123456789" ){
    int found;
    for( int i = 0; i < digits.length(); ++i ){
        found = 0;
        for( int j = 0; j < lema.length(); ++j ){
            if( digits[ i ] == lema[ i ] ){
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
