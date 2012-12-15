#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

int isPentagonal( unsigned long long num ){
    double res = ( 1 + sqrt( 1 + 24 * num ) ) / 6;
    return (int) res == res;
}
double getPentagonalId( unsigned long long num ){
    double res = ( 1 + sqrt( 1 + 24 * num ) ) / 6;
    return res;
}

unsigned long long getPentagonal( unsigned long long n ){
    return (unsigned long long) n * ( 3 * n - 1 ) / 2;
}

int main(){
    unsigned long a, b, min = 0, i, j;
    for( i = 2; i < 5000; ++i ){
        //cout << " ------------------- " << i << " ------------------- " << endl;
        a = getPentagonal( i );
        for( j = i - 1; j >= 1; --j ){
            b = getPentagonal( j );
            //if( isPentagonal( a + b ) ){
                //printf( "  (%ld,%ld) -> (%ld,%ld), %ld -> %f\n", i, j, a, b, a + b, getPentagonalId( a + b ) );
            //}
            //if( isPentagonal( a - b ) ){
                //printf( "- (%ld,%ld) -> (%ld,%ld), %ld -> %f\n", i, j, a, b, a + b, getPentagonalId( a - b ) );
            //}
            if( isPentagonal( a - b ) && isPentagonal( a + b )){
                printf( "# (%ld,%ld) -> (%ld,%ld), %ld -> %f, diff: %ld\n", i, j, a, b, a + b, getPentagonalId( a - b ), a - b );
            }
        }
    }
    cout << min << endl;
    return 0;
}
