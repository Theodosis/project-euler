#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

int main(){
    stringstream fraction;
    string fr;
    int i = 0, prod = 1, num, length = 0;
    while( length < 2500000 ){
        fraction << ++i;
        length += floor( log( i ) ) + 1;
    }
    fr = fraction.str();
    
    for( int i = 0; i < 7; ++i ){
        num = fr[ (int) exp( i * log( 10 ) ) - 1 ] - 48;
        prod *= num;
        cout << exp( i * log( 10 ) ) << ", " << num << endl;
    }
    cout << endl << prod << endl;
}
