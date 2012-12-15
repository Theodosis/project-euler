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

string pattern( int number, int count ){
    vector<int> result;
    string perm = "", newperm = "", num = IntToStr( number );
    
    int length = floor( log10( number ) ) + 1;
    for( int i = 0; i < length; ++i ){
        if( i < length - count ){
            perm += "0";
        }
        else{
            perm += "1";
        }
    }
    return perm;
}



int main(){
    int i;
    int length, size, total;
    string pat, num, newnum;
    for( i = 2; i < 10000000; ++i ){
        if( isPrime( i ) ) {
            primes.push_back( i );
        }
    }

    cout << "primes calculated" << endl;


    for( int i = 1; i < primes.size(); ++i ){
        length = floor( log10( primes[ i ] ) ) + 1;
        num = IntToStr( primes[ i ] );
        
//        cout << num << endl;
        for( int j = 1; j <= length; ++j ){
//            cout << "    replacing " << j << endl;
            pat = pattern( primes[ i ], j );
            do{
//                cout << "        permutation " << pat << endl;
                total = 0;
                for( int k = 0; k < 10; ++k ){
                    newnum = "";
                    for( int i = 0; i < pat.size(); ++i ){
                        newnum += pat[ i ] == '1' ? (char)k + 48 : num[ i ];
                    }
//                    cout << "            newnum " << newnum << endl;
                    if( isPrime( StrToInt( newnum ) ) && floor( log10( StrToInt( newnum ) ) ) + 1 == length ){
                        ++total;
                    }
                }
                if( total == 8 ){
                    cout << num << " " << pat << endl;
                    return 0;
                }
            } while( next_permutation( pat.begin(), pat.end() ) );
        }
    }
}
