#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int solutions( int p ){
    double a,b,c;
    int total = 0;
    for( a = 1; a < p / 2; ++a ){
        for( b = a; b < p / 2; ++b ){
            c = sqrt( a * a + b * b );
            if( a + b + c == p ){
                ++total;
            }
            else if( a + b + c > p ){
                break;
            }
        }
    }
    return total;
}

int main(){
    int max = 0, maxid = -1, res;
    for( int i = 1; i <= 1000; ++i ){
        res = solutions( i );
        if( max < res ){
            max = res;
            maxid = i;
        }
    }
    cout << maxid << endl;
    return 0;
}
