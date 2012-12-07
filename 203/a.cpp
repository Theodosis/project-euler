#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

vector<string> explode( const string &delimiter, const string &str );
int compare ( const void *a, const void *b ){
    return ( *(unsigned long long*)a - *(unsigned long long*)b );
}

int Primes[ 10000 ];
unsigned long long Coefs[ 51 * 51 ];


int squarefree( unsigned long long a ){
    int i = 0;
    int p = Primes[ i ];
    float temp;
    while( p * p <= a ){
        temp = a / pow( p, 2 );
        if( temp == (int) temp ){
            return 0;
        }
        p = Primes[ ++i ];
    }
    return 1;
}


void readprimes(){
    string total;
    vector<string> all;
    ifstream primes( "primes.lst" );
    primes >> total;
    
    all = explode( ",", total );

    for( int i = 0; i < 1000; ++i ){
        Primes[ i ] = atoi( all[ i ].c_str() );
    }
}

void loadcoefs(){
    for( int i = 0; i < 51; ++i ){
        Coefs[ i * 51 ] = 1;
        for( int j = 1; j < 51; ++j ){
            Coefs[ i * 51 + j ] = 0;
        }
    }
    for( int i = 1; i < 51; ++i ){
        for( int j = 1; j < 51; ++j ){
            Coefs[ i * 51 + j ] = Coefs[ ( i - 1 ) * 51 + j - 1 ] + Coefs[ ( i - 1 ) * 51 + j ];
        }
    }
}

void uniqsort(){
    vector<unsigned long long> temp( Coefs, Coefs + 51 * 51 );

    sort( temp.begin(), temp.end() );

    vector<unsigned long long>::iterator it;

    it = unique( temp.begin(), temp.end() );
    temp.resize( it - temp.begin() );
    for( int i = 0; i < 51 * 51; ++i ){
        Coefs[ i ] = 0;
    }
    int k = 0;
    for( it = temp.begin(); it != temp.end(); ++it ){
        Coefs[ k++ ] = *it;
    }
}

int main(){
    readprimes();
    loadcoefs();

    uniqsort();

    unsigned long long sum = 0;
    for( int i = 0; i < 51 * 51; ++i ){
        if( squarefree( Coefs[ i ] ) ){
            cout << Coefs[ i ] << " + ";
            sum += Coefs[ i ];
        }
    }

    cout << endl << (long)sum << endl;
    
    return 0;
}





vector<string> explode( const string &delimiter, const string &str){
    vector<string> arr;

    int strleng = str.length();
    int delleng = delimiter.length();
    if (delleng==0){
        return arr;//no change
    }

    int i=0; 
    int k=0;
    while( i<strleng ){
        int j=0;
        while (i+j<strleng && j<delleng && str[i+j]==delimiter[j])
            j++;
        if (j==delleng)//found delimiter
        {
            arr.push_back(  str.substr(k, i-k) );
            i+=delleng;
            k=i;
        }
        else
        {
            i++;
        }
    }
    arr.push_back(  str.substr(k, i-k) );
    return arr;
}
